package controller;

import model.HttpUrl;
import model.conngraph.ConnGraph;
import org.apache.http.HttpStatus;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.conn.ConnectTimeoutException;
import org.apache.http.conn.HttpHostConnectException;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.util.EntityUtils;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import java.io.IOException;
import java.net.SocketTimeoutException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class HttpTools {
    private final Integer maxSkipTime = 4;
    private final Integer maxUrlNumPerPage = 6;
    private final Integer defaultTimeout = 1000;
    private final ArrayList<String> errorUrls = new ArrayList<>();

    public HttpTools() {
        errorUrls.add("mp.weixin.qq.com");
        errorUrls.add("http://3101100178.age06.com/x310110/25372/index.aspx");
        errorUrls.add("https://www.youvisit.com/#/vte/?data-platform=v&data-link-type=immersive&data-inst=63731&data-image-width=100%&data-image-height=100%&data-loc=141509&");
    }

    public boolean isOK(String url) {
        for (String s : errorUrls) {
            if (url.contains(s)) {
                return false;
            }
        }
        CloseableHttpClient client = HttpConnPool.getHttpClient(defaultTimeout);
        HttpGet httpGet = new HttpGet(url);
        CloseableHttpResponse response = null;
        try {
            response = client.execute(httpGet);
            if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
                return true;
            }
        } catch (Exception ignored) {
            System.out.println("try to connect " + url + " error");
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
        HttpConnPool.getConnectedSet().add(url.getUrl());
        // 获取base
        String baseUrl = url.getBaseSuffix();

        // 获取HTML
        CloseableHttpClient client = HttpConnPool.getHttpClient(defaultTimeout);
        HttpGet httpGet = new HttpGet(url.getUrl());
        String page = "";
        CloseableHttpResponse response = null;
        try {
            response = client.execute(httpGet);
            if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
                System.out.println("connect " + url.getUrl() + " success, " + "skip time: " + url.getCount());
                page = EntityUtils.toString(response.getEntity(), "utf-8");
            } else {
                System.err.println("connect " + url.getUrl() + " error");
            }
        } catch (HttpHostConnectException e) {
            System.err.println("Unknown Host");
            e.printStackTrace();
        } catch (SocketTimeoutException | ConnectTimeoutException e) {
            System.err.println("Connection Time Out");
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (response != null) {
                try {
                    EntityUtils.consume(response.getEntity());
                } catch (IOException e) {
                    System.err.println("释放连接错误");
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
                        HttpUrl nxtUrl = new HttpUrl(str, url.getCount() + 1);
                        /*if (HttpConnPool.getConnectedSet().contains(nxtUrl.getUrl())) {
                            return;
                        }*/
                        ConnGraph.addEdge(url, nxtUrl);
                        if (isOK(nxtUrl.getUrl())) {
                            num++;
                            if (num > maxUrlNumPerPage || nxtUrl.getCount() >= maxSkipTime) {
                                return;
                            }
                            HttpConnPool.getConnQueue().addLast(nxtUrl);
                        }
                    }
                }
            }
        }
    }
}

