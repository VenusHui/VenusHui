package controller;

import model.HttpUrl;
import org.apache.http.HttpEntityEnclosingRequest;
import org.apache.http.HttpRequest;
import org.apache.http.NoHttpResponseException;
import org.apache.http.client.HttpRequestRetryHandler;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.protocol.HttpClientContext;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.conn.PoolingHttpClientConnectionManager;
import org.apache.http.protocol.HttpContext;

import javax.net.ssl.SSLException;
import javax.net.ssl.SSLHandshakeException;
import java.io.IOException;
import java.io.InterruptedIOException;
import java.net.UnknownHostException;
import java.util.HashSet;
import java.util.Set;
import java.util.concurrent.LinkedBlockingDeque;

public class HttpConnPool {
    private static final String TJUURL = "https://www.tongji.edu.cn";
    private static final String FDUURL = "https://www.fudan.edu.cn";
    private static final String SJTUURL = "https://www.sjtu.edu.cn";
    private static final String MITURL = "https://www.mit.edu";
    private static final PoolingHttpClientConnectionManager connectionManager = new PoolingHttpClientConnectionManager();
    private static final LinkedBlockingDeque<HttpUrl> connQueue = new LinkedBlockingDeque<>();
    private static final Set<String> connectedSet = new HashSet<>();

    static {
        // 最大同时连接数
        connectionManager.setMaxTotal(2000);
        // 每个路由最大连接数
        connectionManager.setDefaultMaxPerRoute(20);
        // 初始化连接队列
        connQueue.add(new HttpUrl(TJUURL, 0));
        connQueue.add(new HttpUrl(FDUURL, 0));
        connQueue.add(new HttpUrl(SJTUURL, 0));
        connQueue.add(new HttpUrl(MITURL, 0));
    }

    public HttpConnPool() {
    }

    public static CloseableHttpClient getHttpClient(Integer timeOut) {
        // 创建Http请求配置参数
        RequestConfig requestConfig = RequestConfig.custom()
                // 获取连接超时时间
                .setConnectionRequestTimeout(timeOut)
                // 请求超时时间
                .setConnectTimeout(timeOut)
                // 响应超时时间
                .setSocketTimeout(timeOut)
                .build();
        /*
           测出超时重试机制为了防止超时不生效而设置
           如果直接放回false,不重试
           这里会根据情况进行判断是否重试
         */
        HttpRequestRetryHandler retry = new HttpRequestRetryHandler() {
            @Override
            public boolean retryRequest(IOException exception, int executionCount, HttpContext context) {
                if (executionCount >= 3) {// 如果已经重试了3次，就放弃
                    return false;
                }
                if (exception instanceof NoHttpResponseException) {// 如果服务器丢掉了连接，那么就重试
                    return true;
                }
                if (exception instanceof SSLHandshakeException) {// 不要重试SSL握手异常
                    return false;
                }
                if (exception instanceof InterruptedIOException) {// 超时
                    return true;
                }
                if (exception instanceof UnknownHostException) {// 目标服务器不可达
                    return false;
                }
                if (exception instanceof SSLException) {// ssl握手异常
                    return false;
                }
                HttpClientContext clientContext = HttpClientContext.adapt(context);
                HttpRequest request = clientContext.getRequest();
                // 如果请求是幂等的，就再次尝试
                return !(request instanceof HttpEntityEnclosingRequest);
            }
        };

        return HttpClients.custom()
                // 把请求相关的超时信息设置到连接客户端
                .setDefaultRequestConfig(requestConfig)
                // 把请求重试设置到连接客户端
                // .setRetryHandler(retry)
                // 配置连接池管理对象
                .setConnectionManager(connectionManager)
                .build();
    }

    public static LinkedBlockingDeque<HttpUrl> getConnQueue() {
        return connQueue;
    }

    public static Set<String> getConnectedSet() {
        return connectedSet;
    }

    public static void printQueue() {
        for (HttpUrl url : connQueue) {
            System.out.print(url.getUrl());
        }
        System.out.println();
    }

    public static void getPoolStats() {
        System.out.println(connectionManager.getTotalStats());
    }
}
