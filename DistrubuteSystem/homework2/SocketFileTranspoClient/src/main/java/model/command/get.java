package model.command;

import controller.Client;

import java.io.IOException;

import static controller.Controller.*;

public class get extends Command{
    public get(String command) {
        super(command);
    }

    @Override
    public String execute(String command) {
        StringBuilder msg = new StringBuilder();
        Client.connect(IP_ADDRESS, START_PORT_NUMBER);
        String fileName = command.trim();
        try {
            msg.append(Client.sendMessage(CONNECT_TRANSFER_GET + " " + fileName));
            msg.append(Client.receiveFile(fileName));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return msg.toString();
    }

    @Override
    public String helpDoc() {
        StringBuilder msg = new StringBuilder();
        msg.append("Usage: ")
                .append("get [fileName]")
                .append(NEWLINE)
                .append("Download the file of [fileName] from the remote file server (by default the current directory: ")
                .append(BASE_PATH)
                .append(")")
                .append(NEWLINE);
        return msg.toString();
    }
}
