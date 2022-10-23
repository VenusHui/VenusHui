package model.command;

import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;

import static controller.Controller.NEWLINE;
import static controller.Controller.PACKAGE_NAME;

public class help extends Command {
    private static final ArrayList<String> commandList = new ArrayList<>();
    static {
        commandList.add("check");
        commandList.add("put");
        commandList.add("get");
        commandList.add("help");
    }

    public help(String command) {
        super(command);
    }

    @Override
    public String execute(String command) {
        StringBuilder msg = new StringBuilder();
        for (String c : commandList) {
            try {
                Class<?> commandClass = Class.forName(PACKAGE_NAME + c);
                Command cmd = (Command) commandClass.getDeclaredConstructor(String.class).newInstance(c);
                msg.append(cmd.helpDoc())
                        .append(NEWLINE);
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }  catch (InvocationTargetException | InstantiationException | IllegalAccessException | NoSuchMethodException e) {
                throw new RuntimeException(e);
            }
        }
        return msg.toString();
    }

    @Override
    public String helpDoc() {
        StringBuilder msg = new StringBuilder();
        msg.append("Usage: ")
                .append("help")
                .append(NEWLINE)
                .append("look up the usage of all commands")
                .append(NEWLINE);
        return msg.toString();
    }
}
