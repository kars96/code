import com.jaunt.*;
import com.jaunt.component.*;
//import com.jaunt.io.*;

public class google
{
	public static void main(String arg[])
	{
		try{
		UserAgent u=new UserAgent();
		u.visit("https://en.wikipedia.org/wiki/Main_Page");
		u.settings.autoSaveAsHTML=true;
		u.doc.apply("Data structures");
		u.doc.submit();
		Element e=u.doc.findFirst("<a href>");
		String site=e.getAt("href");
		u.visit(site);
		System.out.println(u.doc.findFirst("<body>").innerHTML());
		System.out.println(u.getLocation());
		}
		catch(JauntException e)
		{
		System.err.print(e);
		}
	}
}
		
		
