import com.jaunt.*;
import com.jaunt.component.*;
import java.io.*;
import java.util.regex.*;
//import org.w3c.dom.Element;
//import org.w3c.dom.Node;

public class wiki2
{
	public static void main(String args[])throws IOException
	{	try{
		String s = new String();
		s="";
		Pattern r=Pattern.compile("See also.*");
		UserAgent u= new UserAgent();
		//u.open(new File("/home/karthik/java/wiki.html"));
		u.visit("https://en.wikipedia.org/wiki/Data_structure");
		Elements e1=u.doc.findEvery("<p|h2|li>");
		for(Element e: e1)
		{
		
		if(e.getName().equals("h2"))
		{
		if(e.innerText().matches("See also.*"))break;
		s=s+"\n------------------\n"+e.innerText()+":\n-------------------\n";
		}
		else
		s=s+"\n"+e.innerText();
		//System.out.println(e.innerText());
		//System.out.println("======================================================");
		
		
		}
		s=s.replaceAll("\n+","\n");
		s=s.replaceAll("[ ]+|\\[[a-zA-Z0-9 ]+\\]"," ");
		//s=s.replaceAll("See also :(\n|.)*","");
		System.out.println(s);
	}
	catch(JauntException e)
	{
	System.err.println(e);
	}
	/*catch(IOException e)
	{
	System.err.println(e);
	}*/
	/*catch(ResponseException e)
	{
	System.err.println(e);
	}*/
	}
}
		
