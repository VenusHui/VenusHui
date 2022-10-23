import controller.Controller;

import java.io.IOException;

public class AppRun {
    public AppRun() {
    }

    public static void main(String[] args) {
        System.out.println("Client Run!");
        System.out.println("Type [help] to look up all the command usage");

        try {
            Controller.Terminal();
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Client End!");
    }
}
