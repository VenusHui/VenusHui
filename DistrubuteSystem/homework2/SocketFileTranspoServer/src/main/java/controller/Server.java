package controller;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

import static controller.Controller.*;

public class Server {
    private static ServerSocket serverSocket;
    private static Socket clientSocket;
    private static DataInputStream  in;
    private static DataOutputStream  out;

    public Server(int port) {
        try {
            serverSocket = new ServerSocket(port);
            while (true) {
                clientSocket = serverSocket.accept();
                in = new DataInputStream(clientSocket.getInputStream());
                out = new DataOutputStream(clientSocket.getOutputStream());
                String line = in.readUTF();
                final int index = line.indexOf(' ') != -1 ? line.indexOf(' ') : line.length();
                String oper = line.substring(0, index);
                String text = line.substring(index).trim();
                switch (oper) {
                    case CONNECT_GREET_MSG -> out.writeUTF(CONNECT_VERDICT_OK + NEWLINE);
                    case CONNECT_CHECK_FILE -> out.writeUTF(checkFile(text));
                    case CONNECT_TRANSFER_PUT -> {
                        out.writeUTF(CONNECT_VERDICT_OK + NEWLINE);
                        out.writeUTF(receiveFile(text));
                    }
                    case CONNECT_TRANSFER_GET -> {
                        out.writeUTF("receiving " + text + "..." + NEWLINE);
                        out.writeUTF(sendFile(text));
                    }
                    default -> out.writeUTF("unrecognised greeting" + NEWLINE);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static String checkFile(String fileName) {
        StringBuilder msg = new StringBuilder();
        File file = new File(BASE_PATH + fileName);
        if (file.exists()) {
            msg.append("\"")
                    .append(fileName)
                    .append("\" verdict: ok")
                    .append(NEWLINE);
        }
        else {
            msg.append("\"")
                    .append(fileName)
                    .append("\" ")
                    .append("not found on the server")
                    .append(NEWLINE);
        }
        return msg.toString();
    }
    public static String sendFile(String fileName) {
        StringBuilder msg = new StringBuilder();
        int bytes = 0;
        File file = new File(BASE_PATH + fileName);
        try(FileInputStream fileInputStream = new FileInputStream(file)) {
            out.writeLong(file.length());
            byte[] buffer = new byte[BUFFER_SIZE];
            while ((bytes = fileInputStream.read(buffer)) != -1) {
                out.write(buffer, 0, bytes);
                out.flush();
            }
            msg.append(fileName)
                    .append(" received");
        } catch (FileNotFoundException e) {
            msg.append("\"")
                    .append(fileName)
                    .append("\" ")
                    .append("not found on server")
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
                    .append(" received");
        } catch (IOException e) {
            e.printStackTrace();
        }
        return msg.toString();
    }
}
