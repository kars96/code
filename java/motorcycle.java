class motorcycle{
String make;
String color;
boolean state;
motorcycle()
{
	System.out.println("motorcycle created");
}
void startEngine()
{
	if(state==true)
		System.out.println("Motorcycle is already running");
		else{
		state=true;
		System.out.println("Motorcycle has been started");
		}
}
void showAtt()
{
	System.out.println("make is "+make+"\ncolor is "+color+"\nstate is "+state);
}
public static void main(String args[])
{
	motorcycle m= new motorcycle();
	m.color="red";
	m.make="avenger FLG";
	m.startEngine();
	m.showAtt();
	m.startEngine();
	motorcycle[] mo=new motorcycle[3];
	mo[1]=new motorcycle();
	mo[0]=new motorcycle();
	mo[2]=new motorcycle();
}

}
