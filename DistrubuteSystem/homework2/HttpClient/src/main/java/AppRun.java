import controller.HttpConnPool;
import controller.HttpTools;
import model.HttpUrl;
import model.conngraph.ConnGraph;

import java.io.IOException;

public class AppRun {
    public static void main(String[] args) {
        System.out.println("App Start!");

        long startTime = System.currentTimeMillis();
        HttpTools tools = new HttpTools();
        while (!HttpConnPool.getConnQueue().isEmpty()) {
            HttpUrl url = HttpConnPool.getConnQueue().removeFirst();
            if (url != null) {
                tools.getOuterUrls(url);
            }
        }
        try {
            ConnGraph.makeGraph();
            ConnGraph.showGraph();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        long endTime = System.currentTimeMillis();
        System.out.println("有向图的的结点数量为：" + ConnGraph.getVertexNum() + ", 有向边的数量为：" + ConnGraph.getEdgeNum());
        System.out.println("包含入边数量最多的结点url为：" + ConnGraph.getMaxInDegreeUrl().getUrl());
        System.out.println("访问url的总时间为：" + (endTime - startTime) / 1000 + " 秒");
        System.out.println("有向图已成功生成在：" + ConnGraph.getGraphPath());

        System.out.println("App End!");
    }
}
