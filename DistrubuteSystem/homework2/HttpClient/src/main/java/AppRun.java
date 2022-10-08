import controller.HttpConnPool;
import controller.HttpTools;
import model.HttpUrl;

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
    }
}
