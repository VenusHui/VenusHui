package model.command;

import controller.Client;

import java.io.IOException;

import static controller.Controller.*;

public class put extends Command {
    public put(String command) {
        super(command);
    }

    @Override
    public String execute(String command) {
        StringBuilder msg = new StringBuilder();
        Client.connect(IP_ADDRESS, START_PORT_NUMBER);
        String fileName = command.trim();
        try {
            msg.append(Client.sendMessage(CONNECT_TRANSFER_PUT + " " + fileName));
            msg.append(Client.sendFile(fileName));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return msg.toString();
    }

    @Override
    public String helpDoc() {
        StringBuilder msg = new StringBuilder("");
        msg.append("Usage: ")
                .append("put [fileName]")
                .append(NEWLINE)
                .append("Upload the file of [fileName] to the remote file server (by default the current directory: ")
                .append(BASE_PATH)
                .append(")")
                .append(NEWLINE);
        return msg.toString();
    }
}
