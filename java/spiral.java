class spiral
{
	int n;
	int i,x=0,y=0, t;
	int[][] s;
	spiral(int n)
	{	i=n-1;
		this.n=n;
		s=new int[n][n];
		t=n*n;
		draw();
	}
	void draw()
	{
		
		while(t!=0&&i>=0)
		{
			if(t!=0) right();
			if(t!=0) down();
			if(t!=0) left();
			if(t!=0) up();	
			x++;y++;
			i-=2;
			if(i<0)s[n/2][n/2]=t;
			
		}
	}
	void right()
	{
		for(int k=0;k<i;k++) {System.out.println("RRRSetting "+x+""+y+""+t);s[x][y++]=t--;
		}
	}
	void down()
	{
		for(int k=0;k<i;k++) {
		System.out.println("DDDSetting "+x+""+y+""+t);s[x++][y]=t--;
		}
	}
	void left()
	{
		for(int k=0;k<i;k++) {System.out.println("LLLSetting "+x+""+y+""+t);s[x][y--]=t--;
		}
	}
	
	
	void up()
	{
		for(int k=0;k<i;k++) {System.out.println("UUUSetting "+x+""+y+""+t);s[x--][y]=t--;
		}
	}
	void ps()
	{
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++) System.out.print(s[a][b]+"\t");
			System.out.println();
		}
	}
	public static void main(String args[])
	{	int a;
		if(args.length>0)
		 a=Integer.parseInt(args[0]);
		else  a=2;
		/*spiral s1=new spiral(4);
		s1.ps();
		spiral s2=new spiral(3);
		s2.ps();
		spiral s3=new spiral(5);
		s3.ps();
		spiral s4=new spiral(7);
		s4.ps();
		*/
		spiral s2=new spiral(a);
		s2.ps();
	}
}
