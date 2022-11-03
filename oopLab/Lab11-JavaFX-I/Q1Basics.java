import javafx.scene.control.*;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;


public class Q1Basics extends Application {
    public void start(Stage primaryStage) {
        Label label = new Label("Welcome to JavaFX programming");
        label.setTextFill(Color.MAGENTA);
        FlowPane root = new FlowPane(10,10);
        root.getChildren().add(label);
        root.setAlignment(Pos.CENTER);
        Scene scene = new Scene(root,500,200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("This is the first JavaFX Application");
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}
