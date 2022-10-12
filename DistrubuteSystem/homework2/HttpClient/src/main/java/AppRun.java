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
        System.out.println("����ͼ�ĵĽ������Ϊ��" + ConnGraph.getVertexNum() + ", ����ߵ�����Ϊ��" + ConnGraph.getEdgeNum());
        System.out.println("��������������Ľ��urlΪ��" + ConnGraph.getMaxInDegreeUrl().getUrl());
        System.out.println("����url����ʱ��Ϊ��" + (endTime - startTime) / 1000 + " ��");
        System.out.println("����ͼ�ѳɹ������ڣ�" + ConnGraph.getGraphPath());

        System.out.println("App End!");
    }
}
