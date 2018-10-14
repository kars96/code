import com.jaunt.*;
import com.jaunt.component.*;
//import com.jaunt.io.*;

class Google
{
	public static void main(String arg[])
	{
		try{
		UserAgent u=new UserAgent();
		u.visit("http://google.com/");
		u.settings.autoSaveAsHTML=true;
		u.doc.apply("Data structures");
		u.doc.submit();
		System.out.println(u.getLocation());
		}
		catch(JauntException e)
		{
		System.err.print(e);
		}
	}
}
		
		
