package controller;

import model.HttpUrl;
import model.conngraph.ConnGraph;
import org.apache.http.HttpStatus;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.util.EntityUtils;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import java.io.IOException;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class HttpTools {
    private final Integer defaultTimeout = 1000;
    public boolean isOK(String url) {
        CloseableHttpClient client = HttpConnPool.getHttpClient(defaultTimeout);
        HttpGet httpGet = new HttpGet(url);
        CloseableHttpResponse response = null;
        try {
            response = client.execute(httpGet);
            if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
                return true;
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (response != null) {
                try {
                    EntityUtils.consume(response.getEntity());
                } catch (IOException e) {
                    System.out.println("释放连接错误");
                    e.printStackTrace();
                }
            }
        }
        return false;
    }

    public void getOuterUrls(HttpUrl url) {
        if (url.getCount() > 4) {
            return;
        }

        // 获取base
        String baseUrl = url.getBaseSuffix();

        // 获取HTML
        Integer defaultTimeOut = 1000;
        CloseableHttpClient client = HttpConnPool.getHttpClient(defaultTimeout);
        HttpGet httpGet = new HttpGet(url.getUrl());
        String page = "";
        CloseableHttpResponse response = null;
        try {
            response = client.execute(httpGet);
            if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
                System.out.println("connect " + url.getUrl() + " success");
                page = EntityUtils.toString(response.getEntity(), "utf-8");
            } else {
                System.out.println("connect " + url.getUrl() + " error");
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (response != null) {
                try {
                    EntityUtils.consume(response.getEntity());
                } catch (IOException e) {
                    System.out.println("释放连接错误");
                    e.printStackTrace();
                }
            }
        }

        // 解析HTML获取外部链接
        int num = 0;
        if (!page.isEmpty()) {
            Document document = Jsoup.parse(page);
            List<Element> elements = document.getElementsByTag("a");

            for (Element element : elements) {
                for (Element e : element.getElementsByTag("a")) {
                    String str = e.attr("href");
                    String pattern = "^((https|http|ftp|rtsp|mms)?://)[^\\s]+";
                    Pattern r = Pattern.compile(pattern);
                    Matcher m = r.matcher(str);
                    if (m.matches() && !str.contains(baseUrl)) {
                        if (ConnGraph.getIndex(str) == -1) {
                            HttpUrl nxtUrl = new HttpUrl(str, url.getCount() + 1);
                            if (isOK(nxtUrl.getUrl())) {
                                ConnGraph.addEdge(url, nxtUrl);
                                HttpConnPool.getConnQueue().add(nxtUrl);
                                num++;
                                if (num >= 6) {
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

