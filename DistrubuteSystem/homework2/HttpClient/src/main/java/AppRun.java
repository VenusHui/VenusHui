import controller.HttpConnPool;
import controller.HttpTools;
import model.HttpUrl;
import model.conngraph.ConnGraph;

import java.io.IOException;

public class AppRun {
    public static void main(String[] args) {
        System.out.println("App Running!");

        HttpTools tools = new HttpTools();
        HttpConnPool pool = new HttpConnPool();
        while (!HttpConnPool.getConnQueue().isEmpty()) {
            HttpUrl url = HttpConnPool.getConnQueue().remove();
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
    }
}
