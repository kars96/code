import com.jaunt.*;
import com.jaunt.component.*;
import java.io.*;
public class wiki
{
	public static void main(String args[])throws IOException
	{	try{
		String s = new String();
		s="";
		UserAgent u= new UserAgent();
		u.open(new File("/home/karthik/java/wiki.html"));
		Elements e1=u.doc.findEvery("<p|h2>");
		for(Element e: e1)
		{if(e.innerText()!=null&&!e.innerText().equals("\n")){
		s=s+" "+e.innerText();
		//System.out.println(e.innerText());
		//System.out.println("======================================================");
		}
		
		}
		System.out.println(s.replaceAll("[ \n]+|\\[[a-zA-Z0-9 ]+\\]"," "));
	}
	catch(JauntException e)
	{
	System.err.println(e);
	}
	catch(IOException e)
	{
	System.err.println(e);
	}
	/*catch(ResponseException e)
	{
	System.err.println(e);
	}*/
	}
}
		
