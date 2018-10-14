import java.util.Random;
import java.io.*;
public class legend{
	public static void main(String args[]) throws IOException
	{
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader b = new BufferedReader(in);
		System.out.println("Enter the number of outcomes");
		int n = Integer.parseInt(b.readLine());
		System.out.println("You have entered "+n);
		Random r = new Random(30);
		for(int i = 0; i < n ; i++)
		{
			int p = r.nextInt(1000);
			if(p>900)
				System.out.println("You got legendary");
			else if(p>600)
				System.out.println("You got a  super-rare card");
			else
				System.out.println("You got ordinary card");

		}

	}
}