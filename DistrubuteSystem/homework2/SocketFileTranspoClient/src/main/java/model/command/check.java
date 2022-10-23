package model.command;

import controller.Client;

import java.io.IOException;

import static controller.Controller.*;

public class check extends Command {
    private static final String commandName = "check";

    public check(String command) {
        super(command);
    }

    @Override
    public String execute(String command) {
        StringBuilder msg = new StringBuilder();
        if (commandOper == null) {
            msg.append("wrong")
                    .append(NEWLINE);
        }
        else if (commandOper.equals("-s")) {
            int serverNumber;
            try {
                serverNumber = Integer.parseInt(commandTarget);
                if (!(serverNumber >= 1 && serverNumber <= 5)) {
                    msg.append("wrong server number")
                            .append(NEWLINE);
                }
                else {
                    msg.append("Server")
                            .append(serverNumber)
                            .append(": ")
                            .append(Client.socketTest(IP_ADDRESS, START_PORT_NUMBER + serverNumber - 1))
                            .append(NEWLINE);
                }
            } catch (NumberFormatException e) {
                msg.append("wrong server number")
                        .append(NEWLINE);
            }
        }
        else if (commandOper.equals("-f")) {
            String fileName = commandTarget;
            try {
                boolean flag = false;
                for (int i = 0; i < MAX_SERVER_NUM; i++) {
                    if (Client.connect(IP_ADDRESS, START_PORT_NUMBER + i)) {
                        if (Client.sendMessage(CONNECT_CHECK_FILE + " " + fileName).contains(CONNECT_VERDICT_OK)) {
                            flag = true;
                            msg.append("\"")
                                    .append(fileName)
                                    .append("\" found on server")
                                    .append(i + 1)
                                    .append(NEWLINE);
                        }
                    }
                }
                if (!flag) {
                    msg.append("\"")
                            .append(fileName)
                            .append("\" was not on server")
                            .append(NEWLINE);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return msg.toString();
    }

    @Override
    public String helpDoc() {
        StringBuilder doc = new StringBuilder();
        doc.append("Usage: ")
                .append("check [options] [target]")
                .append(NEWLINE);
        doc.append("Check status of target file or file server")
                .append(NEWLINE);
        doc.append("Options: ")
                .append(NEWLINE)
                .append(TAB)
                .append("-s [serverNumber]: check the target server ([serverNumber] is from 1 to 5 excluded)")
                .append(NEWLINE)
                .append(TAB)
                .append("-f [fileName]: check the target file on the server")
                .append(NEWLINE);
        return doc.toString();
    }
}