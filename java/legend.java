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
		Random r = new Random();
		int t = 10000000;

		for(int i = 0; i < n ; i++)
		{
			int p = r.nextInt(t);
			if(p>.9*t)
				System.out.println(p+" You got legendary");
			else if(p>.6*t)
				System.out.println(p+" You got a  super-rare card");
			else
				System.out.println(p+" You got ordinary card");

		}

	}
}