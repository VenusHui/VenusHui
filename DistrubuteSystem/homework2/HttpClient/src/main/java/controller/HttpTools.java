package controller;

import model.HttpUrl;
import org.apache.http.HttpStatus;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.util.EntityUtils;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class HttpTools {
    private final Integer defaultTimeOut = 1000;

    public List<HttpUrl> getOuterUrls(HttpUrl url) {
        if (url.getCount() > 4) {
            return null;
        }

        // 获取base
        String baseUrl = url.getBaseSuffix();

        // 获取HTML
        CloseableHttpClient client = HttpConnPool.getHttpClient(defaultTimeOut);
        HttpGet httpGet = new HttpGet(url.getUrl());
        String page = "";
        CloseableHttpResponse response = null;
        try {
            response = client.execute(httpGet);
            if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
                System.out.println("访问 " + url.getUrl() + " 成功");
                page = EntityUtils.toString(response.getEntity(), "utf-8");
            } else {
                System.out.println("访问 " + url.getUrl() + " 出错");
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (response != null) {
                try {
                    EntityUtils.consume(response.getEntity());
                }
                catch (IOException e) {
                    System.out.println("释放连接错误");
                    e.printStackTrace();
                }
            }
        }

        // 解析HTML获取外部链接
        List<HttpUrl> outerUrls = new ArrayList<>();
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
                        // System.out.println(str);
                        outerUrls.add(new HttpUrl(str, url.getCount() + 1));
                    }
                }
            }
        }
        return outerUrls;
    }
}

