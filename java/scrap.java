import java.util.Scanner;
import java.io.*;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class gjs {

	public static final String GOOGLE_SEARCH_URL = "https://www.google.com/search";
	public static void main(String[] args) throws IOException  {
		
		//Taking search term input from console
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please enter the search term.");
		String searchTerm = scanner.nextLine();
		System.out.println("Please enter the number of results. Example: 5 10 20");
		int num = scanner.nextInt();
		scanner.close();
		PrintWriter o=new PrintWriter(new File(searchTerm+".txt"));
		try{
		String searchURL = GOOGLE_SEARCH_URL + "?q="+searchTerm+"&num="+num;
		//without proper User-Agent, we will get 403 error
		Document doc = Jsoup.connect(searchURL).userAgent("Mozilla/5.0").get();
		
		//below will print HTML data, save it to a file and open in browser to compare
		//System.out.println(doc.html());
		
		//If google search results HTML change the <h3 class="r" to <h3 class="r1"
		//we need to change below accordingly
		Elements results = doc.select("h3.r > a");
		//results=results.nextAll();
		for(Element result:results) {
			String linkHref = result.attr("href");
			linkHref=linkHref.substring(7,linkHref.indexOf("&"));
			String linkText = result.text();
			System.out.println(linkHref);
			if(linkHref.matches("https?://.*"))
			{
			o.println("Text::" + linkText + ", URL->" + linkHref);
			Document d1=Jsoup.connect(linkHref).userAgent("Mozilla/5.0").get();
			//Document d1=Jsoup.connect(linkHref).userAgent("Mozilla/5.0").get();
			
			String s="";
			Elements txt=d1.select("p,li,td");
			for(Element t1:txt)
			{
				s=s+"\n"+t1.text();
			}
			o.println(s.replaceAll("[ \n]+|\\[[a-zA-Z0-9 ]+\\]"," "));
			o.println("---------------------------------------------------------------------------------------------------");
			}
			}
		}
		finally
		{
		o.close();
		}
		}
	}

