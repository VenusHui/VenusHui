import controller.HttpConnPool;
import controller.HttpTools;

public class AppRun {

    public AppRun() {

    }

    public static void main(String[] args) {
        System.out.println("App Running!");

        HttpTools tools = new HttpTools();
        HttpConnPool connPool = new HttpConnPool();

    }
}
