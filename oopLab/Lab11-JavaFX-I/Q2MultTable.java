import javafx.scene.control.*;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;

public class Q2MultTable extends Application {
    public void start(Stage primaryStage) {
        Label multTable = new Label();
        multTable.setAlignment(Pos.CENTER);
        TextField txtField = new TextField();
        Label label = new Label("Enter an integer");
        Button submit = new Button("Submit");

        submit.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
               
                int n = Integer.parseInt(txtField.getText());
                String s = "Multiplication table: ";
                for (int i=1;i<=10;i++) 
                    s = s + Integer.toString(i*n) +" ";
                multTable.setText(s);
            }
        });

        HBox hb = new HBox(label,txtField,submit);
        VBox vb = new VBox(hb,multTable);
        hb.setSpacing(10);
        FlowPane root = new FlowPane(10,10);
        root.getChildren().add(vb);
        root.setAlignment(Pos.CENTER);
        Scene scene = new Scene(root,700,200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Multiplication Table");
        primaryStage.show();
    }
    public static void main(String args[]) {
        launch(args);
    }
}
