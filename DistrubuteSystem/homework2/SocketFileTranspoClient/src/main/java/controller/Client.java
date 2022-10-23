package controller;

import java.io.*;
import java.net.Socket;

import static controller.Controller.*;

public class Client {
    private static Socket clientSocket;
    private static DataInputStream in;
    private static DataOutputStream out;
    public static boolean connect(String address, int port) {
        try {
            clientSocket = new Socket(address, port);
            in = new DataInputStream(clientSocket.getInputStream());
            out = new DataOutputStream(clientSocket.getOutputStream());
        } catch (IOException e) {
            return false;
        }
        return true;
    }
    public static String socketTest(String address, int port) {
        StringBuilder msg = new StringBuilder();
        if (connect(address, port)) {
            try {
                msg.append(sendMessage(CONNECT_GREET_MSG))
                        .append("Connected Success to ")
                        .append(clientSocket.getInetAddress())
                        .append(":")
                        .append(clientSocket.getPort())
                        .append(NEWLINE);
            } catch (IOException e) {
                msg.append("Connect Error");
            }
        }
        return msg.toString();
    }

    public static String sendMessage(String message) throws IOException {
        out.writeUTF(message);
        return in.readUTF();
    }

    public static String sendFile(String fileName) throws IOException {
        StringBuilder msg = new StringBuilder();
        int bytes = 0;
        File file = new File(BASE_PATH + fileName);
        try(FileInputStream fileInputStream = new FileInputStream(file)) {
            Client.getOutputStream().writeLong(file.length());
            byte[] buffer = new byte[BUFFER_SIZE];
            while ((bytes = fileInputStream.read(buffer)) != -1) {
                Client.getOutputStream().write(buffer, 0, bytes);
                Client.getOutputStream().flush();
            }
        } catch (FileNotFoundException e) {
            msg.append("\"")
                    .append(fileName)
                    .append("\" ")
                    .append("not found")
                    .append(NEWLINE);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return msg.toString();
    }

    public static String receiveFile(String fileName) {
        StringBuilder msg = new StringBuilder();
        int bytes = 0;
        File file = new File(BASE_PATH + fileName);
        try (FileOutputStream fileOutputStream = new FileOutputStream(BASE_PATH + fileName)){
            long size = in.readLong();
            byte[] buffer = new byte[BUFFER_SIZE];
            while (size > 0 && (bytes = in.read(buffer, 0, (int)Math.min(buffer.length, size))) != -1) {
                fileOutputStream.write(buffer, 0, bytes);
                size -= bytes;
            }
            msg.append(fileName)
                    .append(" received")
                    .append(NEWLINE);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return msg.toString();
    }

    public static DataInputStream getInputStream() {
        return in;
    }

    public static DataOutputStream getOutputStream() {
        return out;
    }
}
