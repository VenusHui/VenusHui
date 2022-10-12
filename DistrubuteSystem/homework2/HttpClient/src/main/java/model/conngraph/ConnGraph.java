package model.conngraph;

import guru.nidi.graphviz.engine.Format;
import guru.nidi.graphviz.engine.Graphviz;
import guru.nidi.graphviz.model.MutableGraph;
import guru.nidi.graphviz.model.MutableNode;
import model.HttpUrl;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;

import static guru.nidi.graphviz.model.Factory.mutGraph;
import static guru.nidi.graphviz.model.Factory.mutNode;

public class ConnGraph {

    private static final int maxn = 20;
    private static final String resPath = ".\\HttpClient\\resources\\";
    private static final String fileName = "ConnectGraph";
    private static final ArrayList<HttpUrl> map = new ArrayList<>();
    private static final ArrayList<ArrayList<Integer>> graph = new ArrayList<>(new ArrayList<>());

    private static Integer vertexNum = 0;
    private static Integer edgeNum = 0;

    public static void addVertex(HttpUrl url) {
        for (HttpUrl u : map) {
            if (Objects.equals(u.getUrl(), url.getUrl())) {
                return;
            }
        }
        vertexNum++;
        map.add(url);
        graph.add(new ArrayList<>());
    }

    public static Integer getIndex(String url) {
        for (int i = 0; i < map.size(); i++) {
            if (Objects.equals(map.get(i).getUrl(), url)) {
                return i;
            }
        }
        return -1;
    }

    public static void addEdge(HttpUrl u, HttpUrl v) {
        edgeNum++;
        addVertex(u);
        addVertex(v);
        graph.get(getIndex(u.getUrl())).add(getIndex(v.getUrl()));
    }

    public static String getStringByIndex(Integer index) {
        if (index >= 0 && index < map.size()) {
            String url = map.get(index).getUrl();
            url = url.substring(url.indexOf("//") + 2);
            if (url.length() > maxn) {
                url = url.substring(0, maxn);
                url += "...";
            }
            return url;
        }
        return "";
    }

    public static Integer getVertexNum() {
        return vertexNum;
    }

    public static Integer getEdgeNum() {
        return edgeNum;
    }

    public static HttpUrl getMaxInDegreeUrl() {
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        for (HttpUrl ignored : map) {
            tmp.add(0);
        }
        for (ArrayList<Integer> integers : graph) {
            if (integers.size() != 0) {
                for (Integer j : integers) {
                    tmp.set(j, tmp.get(j) + 1);
                }
            }
        }

        int ans = 0, num = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp.get(i) >= num) {
                ans = i;
                num = tmp.get(i);
            }
        }
        System.out.println(num);
        return map.get(ans);
    }

    public static void makeGraph() throws IOException {
        MutableGraph connectGraph = mutGraph(fileName).setDirected(true);
        for (int i = 0; i < graph.size(); i++) {
            if (graph.get(i).size() != 0) {
                for (Integer j : graph.get(i)) {
                    MutableNode node = mutNode(getStringByIndex(i)).addLink(mutNode(getStringByIndex(j)));
                    connectGraph.add(node);
                }
            }
        }
        Graphviz.fromGraph(connectGraph)
                .render(Format.PNG)
                .toFile(new File(resPath + fileName));
    }

    public static void showGraph() throws IOException {
        Runtime.getRuntime().exec("mspaint " + resPath + fileName + ".png");
    }

    public static String getGraphPath() {
        return resPath + fileName + ".png";
    }
}
