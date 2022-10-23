import controller.Server;

import static controller.Controller.PORT_NUMBER;

public class AppRun {
    public AppRun() {
    }

    public static void main(String[] args) {
        System.out.println("Server Run!");

        Server server = new Server(PORT_NUMBER);

        System.out.println("Server End!");
    }
}
