import javafx.scene.control.*;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;

public class Q4GCD extends Application {
    public void start(Stage primaryStage) {

        Label num1Label = new Label("First Number:");
        Label num2Label = new Label("Second Number:");
        Label answerLabel = new Label();
        answerLabel.setWrapText(true);
        answerLabel.setMaxWidth(200);
        TextField num1TXTField = new TextField();
        TextField num2TXTField = new TextField();
        Button submit = new Button("Calculate");

        submit.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                String n1Str = num1TXTField.getText();
                String n2Str = num2TXTField.getText();
                String s = "Numbers entered are: " + n1Str + " and " + n2Str + " and the GCD is: ";
                int n1 = Integer.parseInt(n1Str);
                int n2 = Integer.parseInt(n2Str);
                if (n2 < n1) {
                    int temp = n1;
                    n1 = n2;
                    n2 = temp;
                }
                int gcd = 1;
                for(int i=1;i<=n1;i++) 
                    if ((n1%i == 0) && (n2%i == 0))
                        gcd = i;
                s = s + Integer.toString(gcd);
                answerLabel.setText(s);
            }
        });
        GridPane grid = new GridPane();
        grid.setPadding(new Insets(10, 10, 10, 10));
        grid.setVgap(5);
        grid.setHgap(5);
        GridPane.setConstraints(num1Label, 0, 0);
        GridPane.setConstraints(num1TXTField, 1, 0);
        GridPane.setConstraints(num2Label, 0, 1);
        GridPane.setConstraints(num2TXTField, 1, 1);
        GridPane.setConstraints(answerLabel, 1, 2);
        GridPane.setConstraints(submit, 0, 2);
        grid.getChildren().addAll(num1Label,num1TXTField,num2Label,num2TXTField,answerLabel,submit);
        grid.setAlignment(Pos.CENTER);
        Scene scene = new Scene(grid,500,200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("GCD Calculator");
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}
