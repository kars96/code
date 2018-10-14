class passbyref
{
	public static void main(String args[])
	{
		Integer i=new Integer(5);
		System.out.println(i);
		change(i);
		System.out.println(i);
	}
	static void change(Integer i)
	{
		i=10;
	}
}
