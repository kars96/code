import java.util.StringTokenizer;
class tokenize
{
	public static void main(String args[])
	{
		String time="23:34:32",t;
		StringTokenizer s = new StringTokenizer(time,":");
		while((t=s.nextToken()) !=null)
		{
			System.out.println(t);
		}
	}
}	
