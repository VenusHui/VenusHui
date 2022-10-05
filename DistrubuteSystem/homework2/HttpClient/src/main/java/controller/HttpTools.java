package controller;

import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
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
    public List<String> getOuterUrls(String url) {
        // 获取base
        int start = url.indexOf("//") + 2;
        int end = url.indexOf('/', start) == -1 ? url.length() : url.indexOf('/', start + 2);
        int pos = url.length(), flag = 3;
        for (int i = end - 1; i >= start && flag >= 0; i--) {
            if (url.charAt(i) == '.') {
                flag--;
                pos = Math.min(pos, i);
            }
        }
        String baseUrl = url.substring(pos, end);

        // 获取HTML
        CloseableHttpClient client = HttpClients.createDefault();
        HttpGet httpGet = new HttpGet(url);
        String page = "";
        try {
            HttpResponse response = client.execute(httpGet);
            if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
                System.out.println("访问 " + url + " 成功");
                page = EntityUtils.toString(response.getEntity(), "utf-8");
            } else {
                System.out.println("访问 " + url + " 出错");
            }
            client.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // 解析HTML获取外部链接
        List<String> outerUrls = new ArrayList<>();
        if (!page.isEmpty()) {
            Document document = Jsoup.parse(page);
            List<Element> elements = document.getElementsByTag("a");

            elements.forEach(element -> {
                for (Element e : element.getElementsByTag("a")) {
                    String str = e.attr("href");
                    String pattern = "^((https|http|ftp|rtsp|mms)?://)[^\\s]+";
                    Pattern r = Pattern.compile(pattern);
                    Matcher m = r.matcher(str);
                    if (m.matches() && !str.contains(baseUrl)) {
                        outerUrls.add(str);
                    }
                }
            });
        }
        return outerUrls;
    }
}

