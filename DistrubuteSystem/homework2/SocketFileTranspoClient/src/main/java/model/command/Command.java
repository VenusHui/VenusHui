package model.command;

import model.CommandInterface;

public abstract class Command implements CommandInterface {
    protected static String commandName;
    protected static String commandText;

    protected static String commandOper;
    protected static String commandTarget;

    public Command(String command) {
        command = command.trim();
        if (!command.equals("")) {
            commandText = command.substring(command.indexOf(' ') != -1 ? command.indexOf(' ') : command.length()).trim();
        }
        final int startIndex = commandText.indexOf('-');
        final int endIndex = commandText.indexOf(' ');
        if (!(startIndex < 0 || endIndex < 0 || startIndex > endIndex)) {
            commandOper = commandText.substring(startIndex, endIndex).trim();
            commandTarget = commandText.substring(endIndex).trim();
        }
    }

    public String getCommandName() {
        return commandName;
    }

    public String getCommandText() {
        return commandText;
    }
}
