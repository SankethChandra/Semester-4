package university;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class LoginController {

    @FXML
    private Button exit_id;

    @FXML
    private Button instructor_id;

    @FXML
    private Button dept_id;

    @FXML
    void instructor_method() {
    	try {
			AnchorPane root = (AnchorPane)FXMLLoader.load(getClass().getResource("Login2.fxml"));
			Stage stg=new Stage();
			Scene scene = new Scene(root,400,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			stg.setScene(scene);
			stg.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
    }

    @FXML
    void dept_method() {
    	try {
			AnchorPane root = (AnchorPane)FXMLLoader.load(getClass().getResource("Login1.fxml"));
			Stage stg=new Stage();
			Scene scene = new Scene(root,400,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			stg.setScene(scene);
			stg.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
    }

    @FXML
    void exit_method() {
    	Platform.exit();
    	System.exit(0);
    }

}
