import controller.HttpTools;

public class AppRun {
    private static final String TJUURL = "https://www.tongji.edu.cn";
    private static final String FDUURL = "https://www.fudan.edu.cn";
    private static final String SJTUURL = "https://www.sjtu.edu.cn";
    private static final String MITURL = "https://www.mit.edu";

    public AppRun() {
    }

    public static void main(String[] args) {
        System.out.println("App Running");

        HttpTools tools = new HttpTools();
        tools.getOuterUrls(TJUURL);
    }
}
