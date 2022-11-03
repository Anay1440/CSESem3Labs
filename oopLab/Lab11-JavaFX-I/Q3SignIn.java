import javafx.scene.control.*;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;

public class Q3SignIn extends Application {
    public void start(Stage primaryStage) {

        Label welcome = new Label("Welcome");
        Label userNameLabel = new Label("User Name:");
        Label pwdLabel = new Label("Password:");
        Label successLabel = new Label();
        TextField userNameTXTField = new TextField();
        PasswordField pwdTXTField = new PasswordField();
        Button submit = new Button("Sign in");

        submit.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
               String s = "Welcome ";
               s = s + userNameTXTField.getText();
               successLabel.setText(s);
            }
        });
        GridPane grid = new GridPane();
        grid.setPadding(new Insets(10, 10, 10, 10));
        grid.setVgap(5);
        grid.setHgap(5);
        GridPane.setConstraints(welcome, 0, 0);
        GridPane.setConstraints(userNameLabel, 0, 1);
        GridPane.setConstraints(userNameTXTField, 1, 1);
        GridPane.setConstraints(pwdLabel, 0, 2);
        GridPane.setConstraints(pwdTXTField, 1, 2);
        GridPane.setConstraints(successLabel, 1, 3);
        GridPane.setConstraints(submit, 2, 3);
        grid.getChildren().addAll(welcome,userNameLabel,userNameTXTField,pwdLabel,pwdTXTField,successLabel,submit);
        grid.setAlignment(Pos.CENTER);
        Scene scene = new Scene(grid,500,200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("JavaFX Welcome");
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}
