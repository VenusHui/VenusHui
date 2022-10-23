package controller;

import model.command.Command;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.InvocationTargetException;

public class Controller {
    public static final int MAX_SERVER_NUM = 5;
    public static final int START_PORT_NUMBER = 20000;
    public static final String IP_ADDRESS = "127.0.0.1";
    public static final String NEWLINE = "\n";
    public static final String TAB = "    ";
    public static final String PACKAGE_NAME = "model.command.";
    public static final String BASE_PATH = ".\\SocketFileTranspoClient\\resources\\";
    public static final String CONNECT_GREET_MSG = "greet";
    public static final String CONNECT_VERDICT_OK = "ok";
    public static final String CONNECT_TRANSFER_PUT = "transferput";
    public static final String CONNECT_TRANSFER_GET = "transferget";
    public static final String CONNECT_CHECK_FILE = "checkfile";
    public static final int BUFFER_SIZE = 4 * 1024;

    public static void Terminal() throws IOException {
        String line = "";
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            line = reader.readLine().trim();
            if (line.equals("end")) { // ��������
                break;
            }
            else if (line.equals("")) {
                continue;
            }
            final int index = line.indexOf(' ') != -1 ? line.indexOf(' ') : line.length();
            String commandName = line.substring(0, index).trim(); // ��ȡ��������
            String commandText = line.substring(index).trim(); // ��ȡ��������
            try {
                // ִ�е�ǰ����
                Class<?> commandClass = Class.forName(PACKAGE_NAME + commandName);
                Command command = (Command) commandClass.getDeclaredConstructor(String.class).newInstance(line);
                System.out.print(command.execute(commandText));
            } catch (ClassNotFoundException e) {
                // ����Ϸ���help��ʾ
                System.out.println("command \"" + commandName + "\" was not found, enter [help] to check the document");
            } catch (InvocationTargetException | InstantiationException | IllegalAccessException | NoSuchMethodException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
