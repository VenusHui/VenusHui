package model;

public class HttpUrl {
    private final String url;
    private final Integer count;

    public HttpUrl(String url, Integer count) {
        this.url = url;
        this.count = count;
    }

    public String getUrl() {
        return url;
    }

    public Integer getCount() {
        return count;
    }

    public String getBaseSuffix() {
        int start = url.indexOf("//") + 2;
        int end = url.indexOf('/', start) == -1 ? url.length() : url.indexOf('/', start + 2);
        int pos = url.length(), flag = 3;
        for (int i = end - 1; i >= start && flag >= 0; i--) {
            if (url.charAt(i) == '.') {
                flag--;
                pos = Math.min(pos, i);
            }
        }
        return url.substring(pos, end);
    }
}
