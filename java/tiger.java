class cat
{	
	cat(){
	sound();}
	public void sound()
	{
		System.out.println("meow");
	}
}
public class tiger extends cat
{	
	tiger()
	{
	super();
	sound();
	}
	public void sound()
	{
		System.out.println("Roar");
	}
	public static void main(String args[])
	{
		tiger t=new tiger();
		//t.sound();
	}
}
