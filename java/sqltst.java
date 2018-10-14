import java.sql.*;
//import java.sql.DriverManager;

class sqltst
{
	private static final String url="jdbc:mysql://localhost";
	private static final String user="root";
	private static final String password="Kar$";
	
	public static void main(String args[])throws SQLException
	{
		try{
			Connection c=DriverManager.getConnection(url,user,password);
			System.out.println("Success");
			System.out.println("Creating statement...");
      Statement stmt = c.createStatement();
      String sql;
      sql = "SELECT * FROM test.emp1";
      ResultSet rs = stmt.executeQuery(sql);

      //STEP 5: Extract data from result set
      while(rs.next()){
         //Retrieve by column name
         int id  = rs.getInt("id");
 //        int age = rs.getInt("age");
         String first = rs.getString("name");
   //      String last = rs.getString("last");

         //Display values
         System.out.print("ID: " + id);
      //   System.out.print(", Age: " + age);
         System.out.print(", First: " + first);
      //   System.out.println(", Last: " + last);
      }
      //STEP 6: Clean-up environment
      rs.close();
      stmt.close();
      c.close();
		}
		catch(Exception e){e.printStackTrace();
		}
		
	}
}
