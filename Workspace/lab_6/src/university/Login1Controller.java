package university;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class Login1Controller {

	//connecting the database to application
	static Connection dbConnect()
	{
		Connection con=null;
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			con=DriverManager.getConnection("jdbc:oracle:thin:@172.16.58.32:1521:cseorcl","A45","A45");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		return con;
	}
    @FXML
    private Button update_id;

    @FXML
    private Button delete_id;

    @FXML
    private TextField txt2;

    @FXML
    private Button insert_id;

    @FXML
    private TextField txt3;

    @FXML
    private TextField txt1;

    @FXML
    private Button clear_id;

    @FXML
    void insertRecord() {

    
    try
    {
    	Connection conn=dbConnect();
    	String s1=txt1.getText().toString();

    	String s2=txt2.getText().toString();
    	
    	int b=Integer.parseInt(txt3.getText());
    	PreparedStatement ps=conn.prepareStatement("insert into department values('"+s1+"','"+s2+"',"+b+")");
    		ps.execute();
    	System.out.println("INserted");
    	
    }
    catch(Exception e) {
    	System.out.println(e);
    }
    }
    @FXML
    void deleteRecord() {

        try
        {
        	Connection conn=dbConnect();
        	String s1=txt1.getText().toString();

        	//String s2=txt2.getText().toString();
        	
        	//int b=Integer.parseInt(txt3.getText());
        	PreparedStatement ps=conn.prepareStatement("delete from department where dept_name='"+s1+"'");
        		ps.execute();
        	System.out.println("deleted");
        	
        }
        catch(Exception e) {
        	System.out.println(e);
        }
    }

    @FXML
    void UpdateRecord() {
        try
        {
        	Connection conn=dbConnect();
        	String s1=txt1.getText().toString();

        	String s2=txt2.getText().toString();
        	
        	int b=Integer.parseInt(txt3.getText());
       PreparedStatement ps=conn.prepareStatement("update department set budget='"+b+"',building='"+s2+"' where dept_name='"+s1+"'");
        		ps.execute();
        	System.out.println("updated");
        	
        }
        catch(Exception e) {
        	System.out.println(e);
        }
    }

    @FXML
    void clearText() {
    	txt1.clear();
    	txt2.clear();
    	txt3.clear();
    }

}
