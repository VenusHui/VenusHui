package model;

public interface CommandInterface {
    String execute(String command);
    String helpDoc();
}
