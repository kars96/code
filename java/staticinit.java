import java.io.*;

class b{
	static int a;
	static{
		System.out.println("hi");
		a=34;
	}
}

class staticinit{
	public static void main(String args[]){
		b x = new b();
		b y = new b();
		System.out.println(x.a);
	}
}