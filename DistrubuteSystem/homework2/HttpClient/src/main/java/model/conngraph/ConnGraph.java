package model.conngraph;

import model.HttpUrl;

import java.util.ArrayList;
import java.util.Objects;

public class ConnGraph {
    private static final ArrayList<HttpUrl> map = new ArrayList<>();
    private static final ArrayList<ArrayList<Integer>> graph = new ArrayList<>(new ArrayList<>());

    public static void addVertex(HttpUrl url) {
        for (HttpUrl u : map) {
            if (Objects.equals(u.getUrl(), url.getUrl())) {
                return;
            }
        }
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
        addVertex(u);
        addVertex(v);
        graph.get(getIndex(u.getUrl())).add(getIndex(v.getUrl()));
    }
}
