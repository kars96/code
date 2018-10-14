interface p1{
	int a  = 50;
}

interface p2{
	int a  = 60;
}
 

public class diamond implements p1, p2{
	public static void main(String args[])
	{
		System.out.println(p1.a);
	}
}