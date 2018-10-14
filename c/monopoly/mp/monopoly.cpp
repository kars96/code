#define TH_COLOR RGB(45,145,121)
#define TH_COLOR2 RGB(245,255,250)
// #define TH_COLOR2 RGB(45+90,145+90,121+90)

// #define TH_COLOR RGB(244,67,54)

#define TH_IMG "bg6.tiff"
/*
#ifdef _WIN32
#include <windows.h>
#endif
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <fcntl.h>
#include <FreeImage.h>
#include <malloc.h>
#include <time.h>
#include <set>
#include <math.h>
#include <ctype.h>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

GLfloat pat[11][2]={
		{0,0},
		 {2000.000000, 0.000000},
 		{1969.000000, 347.000000},
 		{1879.000000, 684.000000},
 		{1732.000000 ,1000.000000},
 		{1532.000000, 1285.000000},
 		{1285.000000, 1532.000000},
 		{1000.000000, 1732.000000},
 		{684.000000, 1879.000000},
		{347.000000, 1969.000000},
 		{0.000000 ,2000.000000}
	};
float sx,sy;
int WW= 1366;
int WH= 685;
#define RGB(r,g,b) (r)/255.0f,(g)/255.0f,(b)/255.0f
#define CM2PIX 40
double val=M_PI/180;
int cargc;char **cargv;
typedef GLfloat v[2][500];
typedef GLfloat trans[3][3];
int resx=1366,resy=766,cm2pix=40;
v  p[100][200];
v ln; int n1;
int col[100][100];
int n[100];
int wid,swid1,swid2=0,swid3;
 GLuint texture,texture2;
 class board;
int startFlag;
int overviewFlag;
int msgFlag;
float reduction;
GLfloat colr1[][3]={
	{TH_COLOR},
	{TH_COLOR2}
};
	GLfloat colr[][3]={
		{RGB(244,67,54)},
		{RGB(255,87,34)},
		{RGB(255,152,0)},
		{RGB(255,193,7)},
		{RGB(0,199,140)},
		{RGB(0,150,136)},
		{RGB(3,169,244)},
		{RGB(28,134,238)},
		{RGB(63,81,181)},
		{RGB(156,39,176)},
		{RGB(233,30,90)},
		{RGB(220,20,60)},
		{RGB(96,125,139)},
		{RGB(1,0,0)}
	};
	GLfloat colr2[][3]={
		{RGB(244,67,54)},
		{RGB(255,87,34)},
		{RGB(255,152,0)},
		{RGB(255,193,7)},
		{RGB(0,199,140)},
		{RGB(0,150,136)},
		{RGB(3,169,244)},
		{RGB(28,134,238)},
		{RGB(63,81,181)},
		{RGB(156,39,176)},
		{RGB(233,30,90)},
		{RGB(220,20,60)},
		{RGB(96,125,139)},
		{RGB(1,0,0)}
	};
typedef struct {
	GLubyte r, g, b;
} pixel;
typedef struct {
	pixel *data;
	int w, h;
} glob;
glob global,global2;
glob bg;
int yes;
int step;
bool spin_lock=false;
int ang=0;
int swactive=0;

typedef struct{
	int scorei;
	int score[20];
	int name[10];
	int ns;
	int nn;
}lbentry;

vector<lbentry> rankList;

bool back_lock=false;
GLfloat colr_red[3]={RGB(220,20,60)};
GLfloat colr_yellow[3]={RGB(255,193,7)};
GLfloat colr_green[3]={RGB(0,199,140)};
GLfloat colr_blue[3]={RGB(28,134,238)};
GLfloat colr_orange[3]={RGB(255,87,34)};
GLfloat colr_pink[3]={RGB(238,18,137)};
GLfloat colr_brown[3]={RGB(165,42,42)};
GLfloat colr_gray[3]={RGB(130,130,130)};
GLfloat colr_black[3]={.1,.1,.1};

#define START 1
#define OVERVIEW 2
#define HELP 3
#define CREDITS 4
#define EXIT 5
#define BG 6
#define SPIN 7
#define MONOPOLY 8
#define BACK 99

#define MONO 0
#define POLY 1
#define PESO 2
#define DOLLAR 3
#define CENT 4
#define RUPEE 5
#define BUTTON 6
#define BUILD1 7
#define BUILD2 8
#define BUILD3 9
#define A 10
#define B 11
#define E 12
#define H 13
#define I 14
#define L 15
#define O 16
#define P 17
#define R 18
#define T 19
#define U 20
#define V 21
#define W 22
#define S 23
#define X 24
#define C 25
#define D 26
#define ARROW 27
#define SPINNER 28
#define ZERO 29
#define ONE 30
#define TWO 31
#define THREE 32
#define FOUR 33
#define FIVE 34
#define SIX 35
#define SEVEN 36
#define EIGHT 37
#define NINE 38
#define PIE 39
#define K 40
#define M 41
#define N 42
#define G 43
#define S2 44
#define CIRCLE 45
#define J 46
#define F 47
#define HOUSE 48
#define Z 49
#define Y 50
#define Q 51
#define MINUS 52
#define WB 53
#define QMARK 54
#define BOLT 55
#define CHEST 56
#define CHEST1 57
#define COLON 58
#define XYZ 59

int  containsPoint(int,int,int,int,int,int);

void d1(int,int);
void init();
void init2();
void startupTimer(int);
void mainScreen();
void mainScreenkb(unsigned char,int,int);
void rasterText(const char*,int ,int);
void mainScreenm(int,int,int,int);
void start();
void startkb(unsigned char, int,int);
void startm(int,int,int,int);
void overview();
void overviewkb(unsigned char, int,int);
void overviewm(int,int,int,int);
void leaderboard();
void leaderboardkb(unsigned char, int,int);
void leaderboardm(int,int,int,int);
void credits();
void creditskb(unsigned char, int,int);
void creditsm(int,int,int,int);
void exit1();
void exitkb(unsigned char, int,int);
void exitm(int,int,int,int);
void leave();
void leavekb(unsigned char, int,int);
void leavem(int,int,int,int);
void spinner();
void spinnerm(int , int ,int ,int);
void spinnerkb(unsigned char,int ,int);
void spinTimer(int);
void voids(unsigned char,int,int){}
void message( char *,int);
void dispmsg();
void confirm(char ms[20],int);
void confirmw();
void confirmwm(int,int,int,int);
void strokeText(const char *txt,int x,int y);
void rasterText2(const char *txt,int x,int y);
void strokeText2(const char *txt,int x,int y);
void moveTimer(int);
void moveTimer2(int);
void status();
void statusm(int,int,int,int);
void result();
void resultm(int,int,int,int);
void myText(int *,int);
void myTextCaps(int *,int);
void getNames();
static float t1=100,t2=100,t3=100;

int team[]={T,E,A,M},karthik[]={K,A,R,T,H,I,K,-1,S2},chandan[]={C,H,A,N,D,A,N,-1,M,-1,N};
int support[]={S2,U,P,P,O,R,T},rashmi[]={R,A,S2,H,M,I,-1,B,-1,N},sharan[]={S2,H,A,R,A,N,-1,B,-1,G};
int thanks[]={S,P,E,C,I,A,L,-1,T,H,A,N,K,S2,-1,T,O,-1,J,S2,S2,A,T,E,B};
int startt[]={S,T,A,R,T};
int overviewt[]={O,V,E,R,V,I,E,W};
int lb[]={L,E,A,D,E,R,B,O,A,R,D};
int exitt[]={E,X,I,T};
int creditst[]={C,R,E,D,I,T,S2};
int go[]={G,O};
int free1[]={F,R,E,E};
int park[]={P,A,R,K,I,N,G};
int jail[]={J,A,I,L};
char *temp1;

int ccode[200];

class player
{
	char name[10];
	int pid;
	int pos;
	int bail;
	float amt;
	bool prisoned;
	int redcrd=3;
	int orangecrd=3;
	int browncrd=2;
	int greencrd=3;
	int yellowcrd=3;
	int pinkcrd=3;
	int bluecrd=2;
	int graycrd=3;
	int redh;
	int orangeh;
	int brownh;
	int greenh;
	int yellowh;
	int pinkh;
	int utilityn;
	int name2[20];
	char amtcc[10];
	int tempamt[11];
	float* c;
	int sellFlag=0;
	int houseFlag=0;
	int bailcrd=0;
	int deptFlag=0;
	set<int> propowned;
	int statusFlag=0;
	float rentfactor=0;
	float totalMoves=0;
	float totalGain=0;
	float totalExpense=0;
	float lastGain=0;
	float lastExpense=0;
	float totalTax=0;

public:
	~player()
	{
		printf("player deleted\n");
	}
	player(){}
	player(char* name,int pid, float * pc)
	{prisoned=false;
		this->amt=40000;
		c=pc;strcpy(this->name,name);bail=1000;
		pos=0;
		this->pid=pid;
		for(int i=0;i<strlen(name);i++)name2[i]=ccode[(int)name[i]];
	}void amtc()
	{tempamt[0]=S;
		snprintf(amtcc,sizeof(amtcc),"%d",(int)amt);
		
		for(int i=0;i<strlen(amtcc);i++)tempamt[i+1]=ccode[(int)amtcc[i]];}
	int spend(int expense)
	{
		if(amt<expense)
		{
			
			return 0;
		}
		else
		{
			amt-=expense;
			totalExpense+=expense;
			lastExpense=expense;
			return 1;
		}
	}

	int spend2(int expense)
	{
		amt-=expense;
		totalExpense+=expense;
		lastExpense=expense;
	}
	int gain(int a)
	{
		amt+=a;
		totalGain+=a;
		lastGain=a;
		return 1;
	}
	int jailed()
	{
		prisoned=true;
	}
	int unjailed()
	{
		bail+=bail*.25;
		prisoned=false;
	}
	int moveme()
	{
		pos++;
		if(pos>35){ gain(1500);}
		pos%=36;
		totalMoves++;
		return pos;
	}
	int moveback()
	{
		pos--;
		if(pos<0)pos+=36;
		totalMoves++;
		return pos;
	}
	friend class box;
	friend class board;
	friend void start();
	friend void startm(int ,int ,int,int);
	friend void startkb(unsigned char,int ,int);
	friend void overview();
	friend void overviewm(int,int,int,int);
	friend void overviewkb(unsigned char, int ,int);
	friend void moveTimer(int);
	friend void moveTimer2(int);
	friend void status();
	friend void statusm(int,int,int,int);
	friend void result();
	
	friend void resultm(int ,int , int, int);
	friend void resultkb(unsigned char, int , int);
};

  enum type{t_prop,t_jail,t_chance,t_chest,t_freepark,t_start,t_it,t_utility,t_casino,t_go};
 	enum clr{red,green,yellow,blue,orange,pink,gray,brown,none};
class box
{
public:
	int bid;
	char name[30];
	float price;
	float rent[4];
	float bcost;
	float scost;
	float* cc;
	float ccost;
	int hno;
	int quad;
	type t;
	char msg[100],msg2[100]="";
	clr c;
	int owner;
public:
		GLfloat posv[4][2];
	int (*action)(int);

	~box()
	{
		printf("Box deleted\n");
	}
	box()
	{}
	box(GLfloat s[][2],int i,char typ[20],char color[20],char nam[20],float cst)
	{
		bid=i;owner=-1;hno=-1;
		if(!strcmp(typ,"prop")) t=t_prop;
		if(!strcmp(typ,"it")){ t=t_it; 
			if(i==4) {bcost=1000;strcpy(msg,"You have to pay a fine of 1,000 ");}
			else {bcost=2000;strcpy(msg,"You have to pay a fine of 2,000 ");}
			strcpy(msg2,"when you land here.");}
		if(!strcmp(typ,"utility"))
		{ t=t_utility; if(bid==24) strcpy(msg,"Buy the Water reservoir to reduce ");
		else strcpy(msg,"Buy the Electric company to reduce ");
		strcpy(msg2,"your utility bills. (cost:10000 rent:2000)");
		bcost=10000;rent[0]=.2*cst;scost=-1;}
		if(!strcmp(typ,"freepark")){ t=t_freepark; strcpy(msg,"You will not be charged when you land ");strcpy(msg2,"here.");}
		if(!strcmp(typ,"casino")) {t=t_casino; strcpy(msg,"Invest \% of your earning to ");strcpy(msg2,"earn 10 times the amount or nothing!");}
		if(!strcmp(typ,"chest")) {t=t_chest; strcpy(msg,"These chests will surely help you.");}
		if(!strcmp(typ,"chance")) {t=t_chance; strcpy(msg,"Are you fortunate?");}
		if(!strcmp(typ,"start")) {t=t_go; strcpy(msg,"Collect 1,500 as you pass this space.");}
		if(!strcmp(typ,"jail")) {t=t_jail; strcpy(msg,"Your activities won't take you here ");strcpy(msg2,"but your luck does take you here.");}

		if(i>=1&&i<=8)quad=1;
		if(i>=10&&i<=17)quad=2;
		if(i>=19&&i<=26)quad=3;
		if(i>=28&&i<=35)quad=4;
		cc=colr_black;
		if(t==t_prop)
		{ 
			if(!strcmp(color,"red")){ c=red;cc=colr_red;}
			else if(!strcmp(color,"yellow")){ c=yellow;cc=colr_yellow;}
			else if(!strcmp(color,"orange")){ c=orange; cc=colr_orange;}
			else if(!strcmp(color,"gray")){ c=gray; cc=colr_gray;}
			else if(!strcmp(color,"brown")){ c=brown; cc=colr_brown;}
			else if(!strcmp(color,"blue")){ c=blue; cc=colr_blue;}
			else if(!strcmp(color,"green")){ c=green;cc=colr_green;}
			else if(!strcmp(color,"pink")){ c=pink;cc=colr_pink;}
			else cc=colr_black;
			strcpy(name,nam);
	bcost=cst;
	scost=.5*cst;
	rent[0]=.1*cst;
	rent[1]=.2*cst;
	rent[2]=.3*cst;
	rent[3]=.35*cst;
	
		}
		else if(t==t_jail) strcpy(name,"Jail");
		else if(t==t_freepark) strcpy(name,"Free parking");
		else if(t==t_chance)strcpy(name,"Chance");
		else if(t==t_chest)strcpy(name,"Community chest");
		else if (t==t_utility)
		{
			if(bid==11)strcpy(name,"Electric Company");
			else if(bid==25)strcpy(name,"Water Works");
		}
		else if(t_it==t)strcpy(name,"Income Tax");
		else if(t==t_casino)strcpy(name,"Casino");
		else if(t==t_go)strcpy(name,"Go!");if(i>=0 && i<=9)
		{
			quad=1;
		posv[0][0]=s[0][0];
		posv[0][1]=s[0][1];
		posv[1][0]=s[1][0];
		posv[1][1]=s[1][1];
		posv[2][0]=s[3][0];
		posv[2][1]=s[3][1];
		posv[3][0]=s[2][0];
		posv[3][1]=s[2][1];
		}
		if(i>=10 && i<=18)
		{
			quad=2;
		posv[0][0]=s[1][0];
		posv[0][1]=s[1][1];
		posv[1][0]=s[2][0];
		posv[1][1]=s[2][1];
		posv[2][0]=s[0][0];
		posv[2][1]=s[0][1];
		posv[3][0]=s[3][0];
		posv[3][1]=s[3][1];
		}
		if(i>=19 && i<=27)
		{
			quad=3;
			posv[0][0]=s[2][0];
		posv[0][1]=s[2][1];
		posv[1][0]=s[3][0];
		posv[1][1]=s[3][1];
		posv[2][0]=s[1][0];
		posv[2][1]=s[1][1];
		posv[3][0]=s[0][0];
		posv[3][1]=s[0][1];
		}
		if(i>=28&&i<=35)
		{
			quad=4;
			posv[0][0]=s[3][0];
		posv[0][1]=s[3][1];
		posv[1][0]=s[0][0];
		posv[1][1]=s[0][1];
		posv[2][0]=s[2][0];
		posv[2][1]=s[2][1];
		posv[3][0]=s[1][0];
		posv[3][1]=s[1][1];
		}
	}friend class player;
	friend class board;
	friend void  start();
	friend void startm(int,int,int,int);
	friend void startkb(unsigned char,int ,int);
	friend void overview();
	friend void overviewm(int,int,int,int);
	friend void overviewkb(unsigned char, int ,int);
	friend void status();
	friend void statusm(int,int,int,int);
	friend void result();
	friend void resultm();
	friend void resultkb();
};class board
{
public:
	player* p=new player[2];
	char btext[10]="buy?";
	char stext[10]="sell?";
	box* b=new box[36];
	player* me;
	player * opp;
	
	player * loser;
	int step;
	int spinover;
	int spinFlag=1;
	char headline[100]="";public:
		player* winner;
	board()
	{
		
		spinover=0;
		GLfloat x,y;int flag,i,j;
		GLfloat s[4][2];char nam[20]="";float cst=0;
	FILE* f=fopen("BOARD.txt","r");
	FILE* f1=fopen("BOARD-DET.txt","r");
		if(f==NULL || f==NULL)
		{
			
			exit(1);
		}
		flag=1;
		int id;
		char typ[20],color[20]="";
		for(i=0;i<36;i++)
		{
			j=0;
			if(flag==0)break;
			while(1)
			{
				if(fscanf(f,"%f %f",&x,&y)==EOF){
					flag=0;
					break;
				}
				if(x==-111111.0 && y==-111111.0)
				{
					
					fscanf(f1,"%d\n%s",&id,typ);
					if(!strcmp(typ,"prop")) fscanf(f1,"%s\n%s\n%f",color,nam,&cst);
					b[i]=box(s,id,typ,color,nam,cst);
					break;
				}
				else
				{
				s[j][0]=x;
				s[j][1]=y;
				
				j++;
				}
			}
			
		}
		
		fclose(f);
		fclose(f1);
		p[0]=player("M",13,colr_red);
		p[1]=player("K",14,colr_green);
		opp=&p[1];
		me=&p[0];
		strcpy(headline,p[0].name);
		strcat(headline,"'s turn");
	}

	board(char* p1t, char* p2t)
	{
		
		spinover=0;
		GLfloat x,y;int flag,i,j;
		GLfloat s[4][2];char nam[20]="";float cst=0;
	FILE* f=fopen("BOARD.txt","r");
	FILE* f1=fopen("BOARD-DET.txt","r");
		if(f==NULL || f==NULL)
		{
			
			exit(1);
		}
		flag=1;
		int id;
		char typ[20],color[20]="";
		for(i=0;i<36;i++)
		{
			j=0;
			if(flag==0)break;
			while(1)
			{
				if(fscanf(f,"%f %f",&x,&y)==EOF){
					flag=0;
					break;
				}
				if(x==-111111.0 && y==-111111.0)
				{
					
					fscanf(f1,"%d\n%s",&id,typ);
					if(!strcmp(typ,"prop")) fscanf(f1,"%s\n%s\n%f",color,nam,&cst);
					b[i]=box(s,id,typ,color,nam,cst);
					break;
				}
				else
				{
				s[j][0]=x;
				s[j][1]=y;
				
				j++;
				}
			}
			
		}
		
		fclose(f);
		fclose(f1);
		p[0]=player(p1t,13,colr_red);
		p[1]=player(p2t,14,colr_green);
		opp=&p[1];
		me=&p[0];
		strcpy(headline,p[0].name);
		strcat(headline,"'s turn");
	}int rent()
	{
		if(this->b[this->me->pos].owner==this->opp->pid)
		{
			int r=this->b[this->me->pos].rent[this->b[this->me->pos].hno]+this->b[this->me->pos].rent[this->b[this->me->pos].hno]*this->opp->rentfactor;
			this->me->spend2(r);
			this->opp->gain(r);
			strcpy(headline,this->me->name);
			strcat(headline," paid a rent of ");
			char ree[10];
			snprintf(ree,10,"%d",r);
			strcat(headline,ree);
		}
	}

	int advanceRand()
	{
		
		int d=rand()%6+1;
		char tt[3];
		snprintf(tt,3,"%d",d);
		strcpy(headline,"Advance ");
		strcat(headline,tt);
		strcat(headline," spaces");
		glutTimerFunc(1000,moveTimer,d);
	}
	int gobackrand()
	{
		
		int d=rand()%6+1;
		char tt[3];
		snprintf(tt,3,"%d",d);
		strcpy(headline,"Go back ");
		strcat(headline,tt);
		strcat(headline," spaces");
		glutTimerFunc(1000,moveTimer2,d);
	}
	int gotojail()
	{
		strcpy(headline,"Go to JAIL.");
		int j=27-this->me->pos;
		if(j>0)glutTimerFunc(1000,moveTimer,j);
		else glutTimerFunc(1000,moveTimer2,-j);
	}
	int prize()
	{
		
		int p=rand()%2000;
		char ff[10];
		snprintf(ff,10,"%d",p);
		strcpy(headline,"You won the lottery, collect ");
		strcat(headline,ff);
		this->me->gain(p);
	}
	int fine()
	{
		strcpy(headline,"Fined for illegal construction of property, pay 1500.");
		this->me->spend2(1500);
	}
	int transferto()
	{
		strcpy(headline,"Its your birthday receive 500 from opponent");
		this->me->gain(500);
		this->opp->spend2(500);
	}
	int transferfrom()
	{
		strcpy(headline,"Its your opponent's birthday give 500 to opponent");
		this->me->spend2(500);
		this->opp->gain(500);
	}

	int renthike()
	{
		this->me->rentfactor+=.1;
		strcpy(headline,"You will receive 10\% extra rent on all your properties ");
	}

	int rentdrop()
	{
		this->me->rentfactor-=.1;
		strcpy(headline,"Rent amount on all your properties is dropped by 10\%");
	}

	int turn()
	{
		this->spinFlag=1;
		strcpy(headline,"You can spin the spinner once more.");
	}

	int treasure()
	{
		int p=rand()%2500+500;
		char ff[10];
		snprintf(ff,10,"%d",p);
		strcpy(headline,"You found ");
		strcat(headline,ff);
		strcat(headline," in treasure chest");
		this->me->gain(p);
	}

	int buy()
	{
		if(this->b[this->me->pos].owner!=this->p[0].pid && this->b[this->me->pos].owner!=this->p[1].pid  && (this->b[this->me->pos].t==t_prop || this->b[this->me->pos].t==t_utility))
		{
			
			char temp23[100]="            Buy now? cost:",temp19[20];
			snprintf(temp19,10,"%d",(int)this->b[this->me->pos].bcost);
			strcat(temp23,temp19);if(1)
			{
				yes=0;
			int flag=this->me->spend(this->b[this->me->pos].bcost);
			if(flag){
				if(this->b[this->me->pos].t==t_prop)
				{
				if(this->b[this->me->pos].c==yellow)this->me->yellowcrd--;
				if(this->b[this->me->pos].c==red)this->me->redcrd--;
				if(this->b[this->me->pos].c==brown)this->me->browncrd--;
				if(this->b[this->me->pos].c==blue)this->me->bluecrd--;
				if(this->b[this->me->pos].c==gray)this->me->graycrd--;
				if(this->b[this->me->pos].c==orange)this->me->orangecrd--;
				if(this->b[this->me->pos].c==pink)this->me->pinkcrd--;
				if(this->b[this->me->pos].c==green)this->me->greencrd--;
				this->b[this->me->pos].hno++;
				}
				else if(this->b[this->me->pos].t==t_utility)
					this->b[this->me->pos].hno++;
				this->me->propowned.insert(this->me->pos);this->b[this->me->pos].owner=this->me->pid;
				if(this->me->propowned.size()==(size_t)6)
				{
					this->me->rentfactor+=.3;
					strcpy(headline,"On buying the 5th property, you receive 30\% extra rent.");
				}
				else if(this->me->propowned.size()==(size_t)15)
				{	
					this->me->rentfactor+=.3;
					strcpy(headline,"On buying the 15th property, you receive 30\% extra rent.");
				}
				else{
				strcpy(headline,this->me->name);
			strcat(headline," bought a property in ");
			strcat(headline,this->b[this->me->pos].name);
			}
				glutPostRedisplay();
			}
			else message("Insufficient Funds.",sizeof("Insufficient Funds."));
		}
		}
}
	
int buyHouse(int h)
{
	printf("%d\n",h);
	int flag=0;
	if(this->b[h].c==red&&!this->me->redcrd)flag=1;
	if(this->b[h].c==green&&!this->me->greencrd)flag=1;
	if(this->b[h].c==gray&&!this->me->graycrd)flag=1;
	if(this->b[h].c==orange&&!this->me->orangecrd)flag=1;
	if(this->b[h].c==pink&&!this->me->pinkcrd)flag=1;
	if(this->b[h].c==yellow&&!this->me->yellowcrd)flag=1;
	if(this->b[h].c==blue&&!this->me->bluecrd)flag=1;
	if(this->b[h].c==brown&&!this->me->browncrd)flag=1;
	if(flag )
	{
		if(this->b[h].hno<3 && this->b[h].hno>=0 )
			{
				if(this->me->spend(1000))this->b[h].hno++;

			}
	}
	else message("You cant build a house here.",sizeof("You cant build a house here."));
}
	int sell(int h)
	{
		if(this->b[h].owner==this->me->pid and h!=-1 && this->b[h].t==t_prop)
		{
			this->me->gain(this->b[h].scost);
			this->b[h].owner=-1;
			if(this->b[h].t==t_prop)
			{
			this->b[h].hno=-1;
				if(this->b[h].c==yellow)this->me->yellowcrd++;
				if(this->b[h].c==red)this->me->redcrd++;
				if(this->b[h].c==brown)this->me->browncrd++;
				if(this->b[h].c==blue)this->me->bluecrd++;
				if(this->b[h].c==gray)this->me->graycrd++;
				if(this->b[h].c==orange)this->me->orangecrd++;
				if(this->b[h].c==pink)this->me->pinkcrd++;
				if(this->b[h].c==green)this->me->greencrd++;
			}
			this->me->propowned.erase(h);
			if(this->me->propowned.size()==5)
			{
				this->me->rentfactor-=.3;
				strcpy(headline,"On selling your 6th property, you receive 30\% lesser rent.");
			}
			else if(this->me->propowned.size()==14)
			{
				this->me->rentfactor-=.3;
				strcpy(headline,"On selling your 15th property, you receive 30\% lesser rent.");
			}
			else
			{
			strcpy(headline,this->me->name);
			strcat(headline," sold his/her property in ");
			strcat(headline,this->b[h].name);
			strcat(headline,".");
			}
		}
		else if (h!=-1)message("You dont cant sell this property.",sizeof("You dont cant sell this property."));
	}

	int jailing()
	{
		
		this->me->jailed();
	}
	void play()
	{
		if(!this->me->prisoned)
		{
			
		step=(rand()%100+rand()%100)%12;
			// step=8;
		swid2=glutCreateSubWindow(wid,(300+4)*sx,(0)*sy,(WH+80)*sx,(WH)*sy);
		glutSetWindow(swid2);
		swactive=1;
	init2();
	glutDisplayFunc(spinner);
	glutMouseFunc(spinnerm);
	glutKeyboardFunc(spinnerkb);
	glutSetWindow(swid2);
	glutPostRedisplay();
	}}
	friend class box;
	friend class player;
	friend void  start();
	friend void startm(int,int,int,int);
	friend void startkb(unsigned char,int ,int);
	friend void overview();
	friend void overviewm(int,int,int,int);
	friend void overviewkb(unsigned char, int ,int);
	friend void spinner();
	friend void spinnerm();
	friend void moveTimer(int);
	friend void moveTimer2(int);
	friend void status();
	friend void statusm(int,int,int,int);
	friend void result();
	friend void resultm(int, int, int, int);
	friend void resultkb(unsigned char, int, int);

};
 board* brd;

void dispmsg()
{
	glClearColor(.9,.9,.9,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,400);
	glVertex2f(resx,400);
	glVertex2f(resx,700);
	glVertex2f(0,700);
	glEnd();
	glTranslatef(0,550,0);
	glScalef(.4,.5,2.5);
	glLineWidth(1);
	glColor3f(1,1,1);
	strokeText(temp1,0,0);
	glPopMatrix();

	glPushMatrix();
	glPushMatrix();
	glTranslatef(20*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(TH_COLOR,.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((20+2.35)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(1,.8,1);
	glColor3f(1,1,1);
	rasterText2("Ok",0,0);
	glPopMatrix();
	glPopMatrix();

	 glutSwapBuffers();

}

int temp12=0;
void choice()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	int numbers[][2]={
		{ONE},
		{TWO},
		{THREE},
		{FOUR},
		{FIVE},
		{SIX},
		{SEVEN},
		{EIGHT},
		{NINE},
		{ONE,ZERO},
		{ONE,ONE},
		{ONE,TWO}
	};
	int k=0;
	float x=((resx/2)-(10*CM2PIX/2))/6;
	float y=((resy/2)-(5*CM2PIX/2))/2;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=6;j++)
		{
			
			glColor3fv(colr2[k]);
			glBegin(GL_QUADS);
			glVertex2f(0+x*(j-1),0);
			glVertex2f(0+x*(j)+3,0);
			glVertex2f(0+x*j+3,y+1);
			glVertex2f(0+x*(j-1),y+1);
			glEnd();

			if(k<9)
			{
			glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(x*(j-1)+.3*x,y/4,0);
			glScalef(.7,.7,.7);
			myText(*(numbers+k),1);
			glPopMatrix();
			}
			else
			{
			glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(x*(j-1)+.1*x,y/4,0);
			glScalef(.7,.7,.7);
			myTextCaps(*(numbers+k),2);
			glPopMatrix();
			}
			k++;
		}
		glTranslatef(0,y,0);
	}
	glutSwapBuffers();
}

void spinTimer2(int step)
{	
	if(ang!=(360*3+30*step))
	{
	ang+=5;
	glutSetWindow(swid2);
	glutPostRedisplay();
	glutTimerFunc(5,spinTimer2,step);
	}
	else
	{
		sleep(2);
		ang=0;
		brd->spinFlag=0;
		spin_lock=false;
		back_lock=false;
		glutSetWindow(wid);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutDestroyWindow(swid2);
	swactive=0;

		if(temp12==step)
		{
			strcpy(brd->headline,"You won ");
			char tt[10];
			snprintf(tt,10,"%f",reduction*10);
			strcat(brd->headline,tt);
			brd->me->gain(reduction*10);
		}
		else
			strcpy(brd->headline,"You lost the bet.");
		
		glutPostRedisplay();
		brd->spinover=1;
	}

}

void spinnerm2(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN && b==GLUT_LEFT_BUTTON && !spin_lock)
	{
		spin_lock=true;
		
		glutTimerFunc(5,spinTimer2,step);
	}
}

void spinnerkb2(unsigned char b,int x,int y)
{
	if(b==' ' && !spin_lock)
	{
		spin_lock=true;
		
		glutTimerFunc(5,spinTimer2,step);
	}
}

void choicem(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN)
	{
		float x1=((resx/2)-(10*CM2PIX/2))/6;
		float y1=((resy/2)-(5*CM2PIX/2))/2;
		
		for(int i=0;i<7;i++)
		{
			if(containsPoint(3+i*59,103,63+i*59,197,x,y))
			{
				printf("%d\n",i+1);
				temp12=i;
				break;
			}

		}
		for(int i=0;i<7;i++)
		{
			if(containsPoint(1+i*59,5,63+i*59,95,x,y))
			{
				printf("%d\n",i+7);
				temp12=i+6;
				break;
			}
		}
		for(int i=0;i<5;i++)
		{
		step=rand()%12;
		printf("(%d)\n",step );
		if(step==temp12)break;
		}
		printf("step=%d\n",step);
		 printf("choice=%d\n",temp12 );
			swactive=1;
	glutPostRedisplay();
		swid2=glutCreateSubWindow(wid,(300+4)*sx,(0)*sy,(WH+80)*sx,(WH)*sy);
		glutSetWindow(swid2);

		swactive=1;
		glutSetWindow(swid2);
		glutDestroyWindow(swid3);
	swactive=0;

	init2();
	glutDisplayFunc(spinner);
	glutMouseFunc(spinnerm2);
	glutKeyboardFunc(spinnerkb2);
	
	glutSetWindow(swid2);
	glutPostRedisplay();

	}
}
void choicekb(int k, int x,int y)
{
	if(k==GLUT_KEY_F1)temp12=0;
	if(k==GLUT_KEY_F2)temp12=1;
	if(k==GLUT_KEY_F3)temp12=2;
	if(k==GLUT_KEY_F4)temp12=3;
	if(k==GLUT_KEY_F5)temp12=4;
	if(k==GLUT_KEY_F6)temp12=5;
	if(k==GLUT_KEY_F7)temp12=6;
	if(k==GLUT_KEY_F8)temp12=7;
	if(k==GLUT_KEY_F9)temp12=8;
	if(k==GLUT_KEY_F10)temp12=9;
	if(k==GLUT_KEY_F11)temp12=10;
	if(k==GLUT_KEY_F12)temp12=11;
	for(int i=0;i<10;i++)
		{
		step=rand()%12;
		printf("(%d)\n",step );
		if(step==temp12)break;
		}swactive=1;
	glutPostRedisplay();
		swid2=glutCreateSubWindow(wid,(300+4)*sx,(0)*sy,(WH+80)*sx,(WH)*sy);
		glutSetWindow(swid2);

		swactive=1;
		glutSetWindow(swid2);
		glutDestroyWindow(swid3);
	swactive=0;

	init2();
	glutDisplayFunc(spinner);
	glutMouseFunc(spinnerm2);
	glutKeyboardFunc(spinnerkb2);
	glutSpecialFunc(NULL);
	
	glutSetWindow(swid2);
	glutPostRedisplay();

}
void casino()
{
		swactive=1;
	glutPostRedisplay();
	swid3=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,(resx/2)-(10*CM2PIX/2),0,(resy/2)-(5*CM2PIX/2));
	
	glMatrixMode(GL_MODELVIEW);
	glutSetWindow(swid3);
	glutDisplayFunc(choice);
	glutMouseFunc(choicem);
	glutKeyboardFunc(NULL);
	glutSpecialFunc(choicekb);
	glutPostRedisplay();
}
int tempbid;
void detail()
{
	char temp[100],temp2[100];;
	glClearColor(.9,.9,.9,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glColor3fv(brd->b[tempbid].cc);
	glBegin(GL_QUADS);
	glVertex2f(0,0);
	glVertex2f(resx,0);
	glVertex2f(resx,WH);
	glVertex2f(0,WH);
	glEnd();
	glTranslatef(20,550,0);
	glPushMatrix();
	glScalef(.8,.8,1);
	glLineWidth(2);
	glColor3f(1,1,1);
	strokeText(brd->b[tempbid].name,0,0);
	glPopMatrix();
	if(brd->b[tempbid].t==t_prop)
	{
		glTranslatef(0,-70,0);
		strcpy(temp,"");
		glPushMatrix();
	glScalef(.5,.5,.5);
	glLineWidth(1);
	glColor3f(1,1,1);
	strcpy(temp,"Cost of property is ");
	snprintf(temp2,sizeof(temp2),"%d",(int)brd->b[tempbid].bcost);
	strcat(temp,temp2);
	rasterText2(temp,0,0);
	glPopMatrix();
	glTranslatef(0,-70,0);
		strcpy(temp,"");
		glPushMatrix();
	glScalef(.5,.5,.5);
	glLineWidth(1);
	glColor3f(1,1,1);
	strcpy(temp,"Rent is ");
	snprintf(temp2,sizeof(temp2),"%d",(int)brd->b[tempbid].rent[0]);
	strcat(temp,temp2);
	rasterText2(temp,0,0);
	glPopMatrix();
	glTranslatef(0,-70,0);
		strcpy(temp,"");
		glPushMatrix();
	glScalef(.5,.5,.5);
	glLineWidth(1);
	glColor3f(1,1,1);
	strcpy(temp,"Rent with one house: ");
	snprintf(temp2,sizeof(temp2),"%d",(int)brd->b[tempbid].rent[1]);
	strcat(temp,temp2);
	rasterText2(temp,0,0);
	glPopMatrix();
	glTranslatef(0,-70,0);
		strcpy(temp,"");
		glPushMatrix();
	glScalef(.5,.5,.5);
	glLineWidth(1);
	glColor3f(1,1,1);
	strcpy(temp,"Rent with two houses: ");
	snprintf(temp2,sizeof(temp2),"%d",(int)brd->b[tempbid].rent[2]);
	strcat(temp,temp2);
	rasterText2(temp,0,0);
	glPopMatrix();
	glTranslatef(0,-70,0);
		strcpy(temp,"");
		glPushMatrix();
	glScalef(.5,.5,.5);
	glLineWidth(1);
	glColor3f(1,1,1);
	strcpy(temp,"Rent with three houses: ");
	snprintf(temp2,sizeof(temp2),"%d",(int)brd->b[tempbid].rent[3]);
	strcat(temp,temp2);
	rasterText2(temp,0,0);
	glPopMatrix();
	glTranslatef(0,-70,0);
		strcpy(temp,"");
		glPushMatrix();
	glScalef(.5,.5,.5);
	glLineWidth(1);
	glColor3f(1,1,1);
	strcpy(temp,"Selling cost of property is ");
	snprintf(temp2,sizeof(temp2),"%d",(int)brd->b[tempbid].scost);
	strcat(temp,temp2);
	rasterText2(temp,0,0);
	glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glTranslatef(0,-70,0);
		glPushMatrix();
	glLineWidth(1);
		glScalef(.5,.5,.5);
		rasterText2(brd->b[tempbid].msg,0,0);
		glPopMatrix();
		glTranslatef(0,-70,0);
		glPushMatrix();
	glLineWidth(1);
		glScalef(.4,.5,.5);
		rasterText2(brd->b[tempbid].msg2,0,0);
		glPopMatrix();
		glPopMatrix();
	}
	glPopMatrix();


	// glPushMatrix();
	// glTranslatef(27*CM2PIX,1.5*CM2PIX,0);
	// glScalef(1.5,2.5,3);
	
	// d1(BUTTON,9);
	// glPopMatrix();
	// glColor3f(1,1,1);
	// glPushMatrix();
	// glTranslatef((26+.3)*CM2PIX,(1.5+.7)*CM2PIX,0);
	// glScalef(.5,.5,.5);
	// glColor3f(0,0,0);
	// // glColor3fv(brd->b[tempbid].cc);
	// rasterText("Ok",0,0);
	// glPopMatrix();
	glutSwapBuffers();

}
void dispmsgm(int b,int s,int x,int y)
{if( s==GLUT_DOWN)
	{
	swactive=0;
			glutDestroyWindow(glutGetWindow());
			msgFlag=0;
			glutSetWindow(wid);
			if(startFlag){
			glutDisplayFunc(start);glutMouseFunc(startm);glutKeyboardFunc(startkb);}
			else if(overviewFlag) {glutDisplayFunc(overview);glutMouseFunc(overviewm);glutKeyboardFunc(overviewkb);}glutPostRedisplay();
	}
}

void dispmsgkb(unsigned char k, int x, int y)
{
	if(k)
	{

	swactive=0;
			glutDestroyWindow(glutGetWindow());
			msgFlag=0;
			glutSetWindow(wid);
			if(startFlag){
			glutDisplayFunc(start);glutMouseFunc(startm);;glutKeyboardFunc(startkb);}
			else if(overviewFlag) {glutDisplayFunc(overview);glutMouseFunc(overviewm);glutKeyboardFunc(overviewkb);}glutPostRedisplay();
	
	}
}
void message(char* msg,int n)
{
		swactive=1;
	glutPostRedisplay();
	swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;

	temp1=msg;
		glutDisplayFunc(dispmsg);
		
		glutKeyboardFunc(dispmsgkb);
		glutMouseFunc(dispmsgm);
		init();
		glutWarpPointer(177,143);	
	
}
void confirm(char* msg,int n)
{
		swactive=1;
	glutPostRedisplay();
	swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;

	temp1=msg;
	msgFlag=1;
		glutDisplayFunc(confirmw);glutMouseFunc(confirmwm);
		init();
		glutWarpPointer(177,143);

}

void confirmwm(int b,int s ,int x, int y)
{
	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)
	{
		
	if(containsPoint(84,131,166 ,156,x,y))
	{	
		yes=1;
		glutDestroyWindow(glutGetWindow());
	swactive=0;

		msgFlag=0;
			glutSetWindow(wid);
			glutDisplayFunc(start);
			glutKeyboardFunc(startkb);
			glutMouseFunc(startm);
			
	}
	if(containsPoint(236,130,322,157,x,y))	
	{
		yes=0;
			glutDestroyWindow(glutGetWindow());
	swactive=0;

			msgFlag=0;
			glutSetWindow(wid);
			glutDisplayFunc(start);
			glutKeyboardFunc(startkb);
			glutMouseFunc(startm);
			
	}
	}
	
}

void confirmw()
{	
	
	glClearColor(.9,.9,.9,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,400);
	glVertex2f(resx,400);
	glVertex2f(resx,700);
	glVertex2f(0,700);
	glEnd();
	glTranslatef(20,550,0);
	glScalef(2.5,2.5,2.5);
	glLineWidth(2);
	glColor3f(1,1,1);
	rasterText(temp1,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(TH_COLOR,.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((7+2)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.4,.5,2.5);
	glColor3f(1,1,1);
	strokeText("Yes",0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(TH_COLOR,.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((20+2.35)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.4,.5,2.5);
	glColor3f(1,1,1);
	strokeText("No",0,0);
	glPopMatrix();

	glutSwapBuffers();
}

void message2()
{
		swactive=1;
	glutPostRedisplay();
	swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;

	// msgFlag=1;
	
		glutDisplayFunc(detail);glutKeyboardFunc(dispmsgkb);
		glutMouseFunc(dispmsgm);
		init();
		glutWarpPointer(177,143);
	glutPostRedisplay();}

pixel *read_img(const char *name, int *width, int *height,FREE_IMAGE_FORMAT type) {
	FIBITMAP *image;
	int i, j, pnum;
	RGBQUAD aPixel;
	pixel *data;

	if ((image = FreeImage_Load(type, name, 0)) == NULL) {
		return NULL;
	}
	*width = FreeImage_GetWidth(image);
	*height = FreeImage_GetHeight(image);

	data = (pixel *)malloc((*height)*(*width)*sizeof(pixel *));
	pnum = 0;
	for (i = 0; i < (*height); i++) {
		for (j = 0; j < (*width); j++) {
			FreeImage_GetPixelColor(image, j, i, &aPixel);
			data[pnum].r = (aPixel.rgbRed);
			data[pnum].g = (aPixel.rgbGreen);
			data[pnum++].b = (aPixel.rgbBlue);
		}
	}
	FreeImage_Unload(image);
	return data;
}

void multiply(trans t,int k)
{
	v r;
	int sum,i,j,q;
	for(int s=0;s<n[k];s++)
	{
	for(i=0;i<3;i++)
	{
		for(j=0;j<col[k][s];j++)
		{
			sum=0;
			for(q=0;q<3;q++)
				sum+=t[i][q]*p[k][s][q][j];
			r[i][j]=sum;
		}
		for(j=0;j<col[k][i];j++)
		{
			p[k][s][0][j]=r[0][j];
			p[k][s][1][j]=r[0][j];
		}
	}
	}
}

bool compByScore(const lbentry &a, const lbentry &b)
{
	return a.scorei > b.scorei;
}

void myText(int* arr,int  an)
{
	if(an!=0)
	{
		glPushMatrix();
		glTranslatef(0,0,0);
		if(arr[0]==A | arr[0]==V | arr[0]==W | arr[0]==M | arr[0]==Y)
		glScalef(.444445,.5,.5);
		else
		glScalef(.5,.5,.5);
		d1(arr[0],9);
		glPopMatrix();
		glPushMatrix();
		
			glTranslatef(47,0,0);
		
		for(int i=1;i<an;i++)
		{
			if(arr[i]!=-1){
			glPushMatrix();
			if(arr[i]==A | arr[i]==V | arr[i]==W | arr[i]==M | arr[i]==Y)
		glScalef(.311111,.35,.35);
		else
			glScalef(.35,.35,.35);
			d1(arr[i],9);
			glPopMatrix();
			
			if(arr[i+1]==A)
					glTranslatef(32,0,0);
				else if(arr[i]==R)
				glTranslatef(35,0,0);
				else
					glTranslatef(38,0,0);
			}
			else
				glTranslatef(15,0,0);
			
		}
		glPopMatrix();
		}
}

void myTextCaps(int* arr,int  an)
{
	glPushMatrix();
	glTranslatef(0,0,0);
	if(arr[0]==A | arr[0]==V | arr[0]==W | arr[0]==M | arr[0]==Y)
	glScalef(.444445,.5,.5);
	else
	glScalef(.5,.5,.5);
	d1(arr[0],9);
	glPopMatrix();
	glPushMatrix();
	
		glTranslatef(47,0,0);
	
	for(int i=1;i<an;i++)
	{
		if(arr[i]!=-1){
		glPushMatrix();
		if(arr[i]==A | arr[i]==V | arr[i]==W | arr[i]==M | arr[i]==Y)
		glScalef(.444445,.5,.5);
		else
		glScalef(.5,.5,.5);
		d1(arr[i],9);
		glPopMatrix();
		
		if(arr[i+1]==A)
				glTranslatef(32,0,0);
			else if(arr[i]==R)
			glTranslatef(35,0,0);
			else
				glTranslatef(60,0,0);
		}
		else
			glTranslatef(25,0,0);
		
	}
	glPopMatrix();
}
char pname[2][10];
int pt=0;
 vector<int> vect;
 vector<char> vect1;
void getNames()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(sx,sy,sy);

	glScalef(1,.88,1);
	glPushMatrix();
	glCallList(BG);
	glPopMatrix();
	glCallList(BACK);
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,550);
	glVertex2f(resx,550);
	glVertex2f(resx,200-100);
	glVertex2f(0,200-100);
	glEnd();
	if(pt!=2)
	{
		glColor3f(1,1,1);
	int p1[]={P,L,A,Y,E,R,ONE};
	int p2[]={P,L,A,Y,E,R,TWO};
	int name[]={N,A,M,E,COLON};
	glPushMatrix();
	glTranslatef(20,500,0);
	glPushMatrix();
	glScalef(.65,.65,1);
	if(pt==0) myText(p1,7); else if(pt==1) myText(p2,7);
	glPopMatrix();
	glTranslatef(0,-90,0);
	glPushMatrix();
	glScalef(.65,.65,1);
	myText(name,5);
	glPopMatrix();
	glTranslatef(150,0,0);
	int vv[10];
	int k=0;
	for(vector<int>::iterator i=vect.begin();i!=vect.end();i++,k++) vv[k]=*i;
	myText(vv,k);
	glPopMatrix();

	}
	else
	{
		pt=0;
		board *bd=new board(pname[0],pname[1]);
		brd=bd;
		glutDisplayFunc(start);
		
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutPostRedisplay();
	}

	 glPushMatrix();
	 glTranslatef(830,WH-548,0);
	
	glScalef(.7,.7,1);
	glColor3f(1,1,1);
	d1(BUTTON,9);
	glPopMatrix();
	glPushMatrix();
	
	 glTranslatef(830+10+10+5,WH-548+5,0);
	
	glColor4f(TH_COLOR,.75);
	rasterText("Ok",0,0);
	glPopMatrix();

	glutSwapBuffers();
}
void getNameskb(unsigned char c, int x, int y)
{
	if( ( (c>='A' && c<='Z') || (c>='a' && c<='z')) && vect.size()!=7)
	{
		c=toupper(c);
		vect.push_back(ccode[c]);
		vect1.push_back(c);
	}
	else if(c=='\b' && !vect.empty()){
		vect.pop_back();
		vect1.pop_back();
	}
	else if(c==13&& vect.size()>0)
	{
		
		if(pt!=2)
		{
		int k=0;
		for(vector<char>::iterator i=vect1.begin();i!=vect1.end();i++,k++) pname[pt][k]=*i;
		pname[pt][k]='\0';
		vect.clear();
		vect1.clear();
		pt++;
		}

	}
	else if(c==27)
	{
		pt=0;

		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	
	}
	glutPostRedisplay();
}

void getNamesm(int b, int s, int x, int y)
{
	if(containsPoint(830,541,914,562,x,y) && vect.size()>0)
	{
		if(pt!=2)
		{
		int k=0;
		for(vector<char>::iterator i=vect1.begin();i!=vect1.end();i++,k++) pname[pt][k]=*i;
		pname[pt][k]='\0';
		vect.clear();
		vect1.clear();
		pt++;
		}
	}
	if(s==GLUT_DOWN &&containsPoint(5,60,137,144,x,y))
	{
		pt=0;
		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}
	glutPostRedisplay();
}
void d1(int k,int mode)
{	int i,j;
	for(i=0;i<n[k];i++)
	{
		glBegin(mode);
		for(j=0;j<col[k][i];j++)
			glVertex2f(p[k][i][0][j],p[k][i][1][j]);
		glEnd();
	}		
}

void strokeText(const char *txt,int x,int y)
{	int i;
	glRasterPos2f(x,y);
	for(i=0;i<strlen(txt);i++)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,txt[i]);
}
void strokeText2(const char *txt,int x,int y)
{	int i;
	glRasterPos2f(x,y);
	for(i=0;i<strlen(txt);i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,txt[i]);
}
void moveTimer(int a)
{
	if(a){
	if(brd->me->moveme()==0){
		strcpy(brd->headline,brd->me->name); strcat(brd->headline," received 1,500.");
		if(brd->me->amt<0 || brd->me->deptFlag)
		{
			if(brd->me->deptFlag && brd->me->amt<0)
			{
				brd->winner=brd->opp;
				brd->loser=brd->me;
				message("You didn't clear your dept. You got eliminated.",1);
				startFlag=0;
		glutDestroyWindow(glutGetWindow());
	swactive=0;

		glutSetWindow(wid);
		glutDisplayFunc(result);
		
		glutMouseFunc(resultm);
		glutPostRedisplay();

			}
			else if(brd->me->amt<0){message("Please clear your depts otherwise you will be eliminated",sizeof("Please clear your depts otherwise you will be eliminated"));brd->me->deptFlag=1;}
		}
		if(brd->me->amt>0)brd->me->deptFlag=0;
	}

	glutPostRedisplay();
	glutTimerFunc(200,moveTimer,--a);
	}
	else
	{
		if(brd->b[brd->me->pos].t==t_prop)
		{
			brd->rent();
		}
		else if(brd->b[brd->me->pos].t==t_utility)
		{
			brd->rent();
		}
		else if(brd->b[brd->me->pos].t==t_jail)
		{
			brd->jailing();
		}
		else if(brd->b[brd->me->pos].t==t_chance)
		{
			
			int k=rand()%10;
			if(k==0)
			{
				brd->turn();
			}
			if(k==1)brd->rentdrop();
			if(k==2)brd->renthike();
			if(k==3)brd->transferfrom();
			if(k==4)brd->transferto();
			if(k==5)brd->fine();
			if(k==6)brd->prize();
			if(k==7)brd->gotojail();
			if(k==8)brd->gobackrand();
			if(k==9)brd->advanceRand();
		}
		else if (brd->b[brd->me->pos].t==t_chest)
		{
			
			brd->treasure();
		}
		else if(brd->b[brd->me->pos].t==t_it)
		{
			brd->me->spend2(brd->b[brd->me->pos].bcost);
			brd->me->totalTax+=brd->b[brd->me->pos].bcost;
			strcpy(brd->headline,brd->me->name);
			strcat(brd->headline," paid ");
			char rer[10];
			snprintf(rer,10,"%d",(int)brd->b[brd->me->pos].bcost);
			strcat(brd->headline,rer);
			strcat(brd->headline," as Income tax.");
		}
		else if(brd->b[brd->me->pos].t==t_casino)
		{
			strcpy(brd->headline,"You entered casino. You spent ");
			reduction=.05*brd->me->amt;
			
			if(reduction<0)
			{
				strcpy(brd->headline,"You dont have enough amount to invest in casino.");
			}else
			{
				strcpy(brd->headline,"You entered casino. You spent ");
				char tt[10];
				snprintf(tt, 10,"%.1f",reduction);
				strcat(brd->headline,tt);
				brd->me->spend(reduction);
				casino();
			}
		}
	}
}

void moveTimer2(int a)
{
	if(a){
	if(brd->me->moveback());

	glutPostRedisplay();
	glutTimerFunc(200,moveTimer2,--a);
	}
	else
	{
		if(brd->b[brd->me->pos].t==t_prop)
		{
			brd->rent();
		}
		else if(brd->b[brd->me->pos].t==t_utility)
		{
			brd->rent();
		}
		else if(brd->b[brd->me->pos].t==t_jail)
		{
			brd->jailing();
		}
		else if(brd->b[brd->me->pos].t==t_chance)
		{
			
			int k=rand()%10;
			if(k==0)
			{
				brd->turn();
			}
			if(k==1)brd->rentdrop();
			if(k==2)brd->renthike();
			if(k==3)brd->transferfrom();
			if(k==4)brd->transferto();
			if(k==5)brd->fine();
			if(k==6)brd->prize();
			if(k==7)brd->gotojail();
			if(k==8)brd->gobackrand();
			if(k==9)brd->advanceRand();
		}
		else if (brd->b[brd->me->pos].t==t_chest)
		{
			
			brd->treasure();
		}
		else if(brd->b[brd->me->pos].t==t_it)
		{
			brd->me->spend2(brd->b[brd->me->pos].bcost);
			strcpy(brd->headline,brd->me->name);
			strcat(brd->headline," paid ");
			char rer[10];
			snprintf(rer,10,"%d",(int)brd->b[brd->me->pos].bcost);
			strcat(brd->headline,rer);
			strcat(brd->headline," as Income tax.");
		}
	}

}

void status()
{
	char tt[100],ttt[100];
		glClearColor(TH_COLOR,0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
	glScalef(sx,sy,sy);

		glPushMatrix();
		glPushMatrix();
		glTranslatef(10,WH-100,0);
		glScalef(.1,.1,1);
		strokeText(brd->me->name,0,0);
		glPopMatrix();
		strcpy(tt,"Total number of properties owned: ");
		snprintf(ttt,10,"%d",(int)brd->me->propowned.size());
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-120,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Rent hike: ");
		snprintf(ttt,10,"%.2f",brd->me->rentfactor*100);
		strcat(tt,ttt);
		strcat(tt,"\%");
		glPushMatrix();
		glTranslatef(10,WH-140,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,0);
		glPopMatrix();
		strcpy(tt,"Bail cards you own: ");
		snprintf(ttt,10,"%d",brd->me->bailcrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-140-20,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,0);
		glPopMatrix();
		strcpy(tt,"Bail amount: ");
		snprintf(ttt,10,"%d",brd->me->bail);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-180,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,0);
		glPopMatrix();
		strcpy(tt,"Total expense: ");
		snprintf(ttt,10,"%d",(int)brd->me->totalExpense);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-220,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Total gain: ");
		snprintf(ttt,10,"%d",(int)brd->me->totalGain);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-200,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Last expense: ");
		snprintf(ttt,10,"%d",(int)brd->me->lastExpense);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-260,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Last gain: ");
		snprintf(ttt,10,"%d",(int)brd->me->lastGain);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-240,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Tax paid: ");
		snprintf(ttt,10,"%d",(int)brd->me->totalTax);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-280,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Total moves: ");
		snprintf(ttt,10,"%d",(int)brd->me->totalMoves);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-300,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Red: ");
		snprintf(ttt,10,"%d",3-(int)brd->me->redcrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-320,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Orange: ");
		snprintf(ttt,10,"%d",3-(int)brd->me->orangecrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-340,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Yellow: ");
		snprintf(ttt,10,"%d",3-(int)brd->me->yellowcrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-360,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Pink: ");
		snprintf(ttt,10,"%d",3-(int)brd->me->pinkcrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-380,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Green: ");
		snprintf(ttt,10,"%d",3-(int)brd->me->greencrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-400,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Gray: ");
		snprintf(ttt,10,"%d",3-(int)brd->me->graycrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-420,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Blue: ");
		snprintf(ttt,10,"%d",2-(int)brd->me->bluecrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-440,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		strcpy(tt,"Brown: ");
		snprintf(ttt,10,"%d",2-(int)brd->me->browncrd);
		strcat(tt,ttt);
		glPushMatrix();
		glTranslatef(10,WH-460,0);
		glScalef(.1,.1,.1);
		strokeText(tt,0,-10);
		glPopMatrix();
		glPopMatrix();
		glutSwapBuffers();

}
	void statusm(int m,int s,int x,int y)
	{
		printf("inside\n");
		if(s==GLUT_DOWN)
		{
		printf("inside2\n");

			glutSetWindow(wid);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutDestroyWindow(swid3);
	swactive=0;

		glutPostRedisplay();
		}
	}

void start()
{	startFlag=1;
	GLfloat mat_ambient[4];
	GLfloat mat_diffuse[4];
	GLfloat mat_specular[4];
	GLfloat mat_shininess[]={50.0f};
	mat_ambient[3]=1;
	mat_diffuse[3]=1;
	mat_specular[3]=1;static int temp_ang=0,temp_ang2=0;brd->p[0].amtc();brd->p[1].amtc();float p0x,p0y,p1x,p1y;
	glClearColor (TH_COLOR,0);
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(sx,sy,sy);

	glScalef(1,.89,1);
    glColor3f(1,1,1);
	if(!swactive)
	{
    glPushMatrix();
    glTranslatef(610,-500,0);
    glRotatef(45,0,0,1);
    glCallList(MONOPOLY);
    glPopMatrix();
	}
	glPushMatrix();
	glPushMatrix();
	glTranslatef(100,00,0);
	glScalef(.8,1,1);
    rasterText(brd->headline,410,WH-110+50);
    glPopMatrix();
    glColor4f(1,1,1,.5);
    rasterText("Status-t       Spin-<space>  Bail-l  Buy-b Sell-s",410,140);
    rasterText("BuildHouse-h   EndTurn-e     Quit-q",410,120);
    glPopMatrix();
    glPushMatrix();
	glTranslatef(305,10,0);
	glScalef(2.35,2.35,1);
	for(int i=0;i<36;i++)
	{
		if(brd->me->sellFlag && brd->b[i].owner!=brd->me->pid ) glColor4f(1,1,1,.2);
		else if(brd->me->houseFlag && brd->b[i].owner!=brd->me->pid ) glColor4f(1,1,1,.2);else glColor4f(1,1,1,.9);glBegin(GL_POLYGON);
		glVertex2f(brd->b[i].posv[0][0],brd->b[i].posv[0][1]);
		glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
		glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
		glVertex2f(brd->b[i].posv[2][0],brd->b[i].posv[2][1]);
		glEnd();

		if(brd->b[i].t==t_prop)
		{if(brd->b[i].c==gray || brd->b[i].c==brown)
			{
				if(brd->b[i].c==gray)glColor3fv(colr_gray);
				if(brd->b[i].c==brown)glColor3fv(colr_brown);
			glBegin(GL_POLYGON);
			glVertex2f(brd->b[i].posv[0][0],(brd->b[i].posv[0][1]+brd->b[i].posv[1][1])/1.45);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f(brd->b[i].posv[2][0],(brd->b[i].posv[2][1]+brd->b[i].posv[3][1])/1.45);
			glEnd();
			}
			 if(brd->b[i].c==yellow || brd->b[i].c==pink)
			{
				if(brd->b[i].c==pink)glColor3fv(colr_pink);
			if(brd->b[i].c==yellow)glColor3fv(colr_yellow);
			glBegin(GL_POLYGON);
			glVertex2f((brd->b[i].posv[0][0]+brd->b[i].posv[1][0])/1.45,brd->b[i].posv[0][1]);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f((brd->b[i].posv[2][0]+brd->b[i].posv[3][0])/1.45,brd->b[i].posv[2][1]);
			glEnd();
			}
			if(brd->b[i].c==red || brd->b[i].c==orange )
			{
			if(brd->b[i].c==red)glColor3fv(colr_red);
			if(brd->b[i].c==orange)glColor3fv(colr_orange);
			glBegin(GL_POLYGON);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f(brd->b[i].posv[2][0],brd->b[i].posv[3][1]+abs(brd->b[i].posv[3][1]-brd->b[i].posv[2][1])*.3);
			glVertex2f(brd->b[i].posv[0][0],brd->b[i].posv[1][1]+abs(brd->b[i].posv[0][1]-brd->b[i].posv[1][1])*.3);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);glEnd();
			}
			if(brd->b[i].c==green || brd->b[i].c==blue)
			{
			if(brd->b[i].c==blue)glColor3fv(colr_blue);
			
			if(brd->b[i].c==green)glColor3fv(colr_green);
			glBegin(GL_POLYGON);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f(brd->b[i].posv[3][0]+abs(brd->b[i].posv[3][0]-brd->b[i].posv[2][0])*.3,brd->b[i].posv[2][1]);
			glVertex2f(brd->b[i].posv[1][0]+abs(brd->b[i].posv[0][0]-brd->b[i].posv[1][0])*.3,brd->b[i].posv[0][1]);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);glEnd();
			}
			char tempscost[10]="$";
			char tttt[10];
			snprintf(tttt,10,"%d",(int)brd->b[i].bcost);
			strcat(tempscost,tttt);
			if(brd->b[i].quad==1)
			{
					glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]+20,0);
	glRotatef(0,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]+20-10,0);
	glRotatef(0,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();
			}	
			else if (brd->b[i].quad==2)
			{
					glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+20,brd->b[i].posv[0][1]-5,0);
	glRotatef(-90,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+20-10,brd->b[i].posv[0][1]-5,0);
	glRotatef(-90,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();
	
			}
			else if(brd->b[i].quad==3)
			{
					glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]-20,0);
	glRotatef(-180,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	glTranslatef(0,10,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]-20+10,0);
	glRotatef(-180,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();

						}
			else
			{
						glPushMatrix();
						if(i!=33)
	glTranslatef(brd->b[i].posv[0][0]-20,brd->b[i].posv[0][1]+5,0);
	else glTranslatef(brd->b[i].posv[0][0]-20,brd->b[i].posv[0][1],0);
	glRotatef(-270,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	glTranslatef(10,0,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]-20+10,brd->b[i].posv[0][1]+5,0);
	glRotatef(-270,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();
			}
		
		}
		glColor3f(0,0,0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(brd->b[i].posv[0][0],brd->b[i].posv[0][1]);
		glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
		glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
		glVertex2f(brd->b[i].posv[2][0],brd->b[i].posv[2][1]);
		glEnd();
		if(brd->b[i].t==t_it)
			{
				if(brd->b[i].quad==1)
				{
				
					glColor3f(0,0,0);
					glPushMatrix();
					glTranslatef(brd->b[i].posv[0][0]+3,brd->b[i].posv[1][1]-10,0);
					glScalef(.035,.035,0);
					strokeText("INCOME",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[0][0]+7,brd->b[i].posv[1][1]-17,0);
					glScalef(.035,.035,0);
					strokeText("TAX",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[0][0]+2,brd->b[i].posv[1][1]-30,0);
					glScalef(.026,.026,0);
					strokeText("Pay 1,000",0,0);
					glPopMatrix();
				}
				else if(brd->b[i].quad==4)
				{
					glPushMatrix();glColor3f(0,0,0);
					glPushMatrix();
					glTranslatef(brd->b[i].posv[1][0]+10,brd->b[i].posv[1][1]+3,0);
					glRotatef(90,0,0,1);
					glScalef(.035,.035,0);
					strokeText("INCOME",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[1][0]+17,brd->b[i].posv[1][1]+7,0);
					glRotatef(90,0,0,1);
					glScalef(.035,.035,0);
					strokeText("TAX",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[1][0]+30,brd->b[i].posv[1][1]+2,0);
					glRotatef(90,0,0,1);
					glScalef(.026,.026,0);
					strokeText("Pay 2,000",0,0);
					glPopMatrix();
					glPopMatrix();
				}
			}
		if(i==brd->p[0].pos)
		{
			int soms=brd->p[0].pos;
			if(brd->b[i].quad==1)
			{
				p0x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p0y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.25;
			}
			else if(brd->b[i].quad==2)
			{
				p0x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.25;
				p0y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			else if(brd->b[i].quad==3)
			{
				p0x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p0y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.25;
			}
			else if(brd->b[i].quad==4)
			{
				p0x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.25;
				p0y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			glPushMatrix();
			glTranslatef(p0x,p0y,100);
			glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
			mat_ambient[3]=1;
	mat_diffuse[3]=1;
	mat_specular[3]=1;mat_ambient[0]=brd->p[0].c[0];
		mat_ambient[1]=brd->p[0].c[1];
				mat_ambient[2]=brd->p[0].c[2];	
				mat_diffuse[0]=brd->p[0].c[0];
				mat_diffuse[1]=brd->p[0].c[1];
				mat_diffuse[2]=brd->p[0].c[2];
				mat_specular[0]=brd->p[0].c[0];
				mat_specular[1]=brd->p[0].c[1];
				mat_specular[2]=brd->p[0].c[2];

glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
GLfloat lightint[]={1.f,01.f,01.f,1.0f};
GLfloat lightpos[]={p0x,p0y,200.0f,0.0f};

glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);

	glPushMatrix();glutSolidCone(7,20,40,40);glTranslatef(0,0,+100+21);if(brd->p[0].prisoned)
	{
		mat_ambient[0]=1;
		mat_ambient[1]=1;
				mat_ambient[2]=1;	
				mat_diffuse[0]=1;
				mat_diffuse[1]=1;
				mat_diffuse[2]=1;
				mat_specular[0]=1;
				mat_specular[1]=1;
				mat_specular[2]=1;
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
	}
	glutSolidCube(7);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	
			glPopMatrix();
		}

		if(i==brd->p[1].pos)
		{
			int soms=brd->p[0].pos;
			if(brd->b[i].quad==1)
			{
				p1x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p1y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.75;
			}
			else if(brd->b[i].quad==2)
			{
				p1x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.75;
				p1y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			else if(brd->b[i].quad==3)
			{
				p1x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p1y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.75;
			}
			else if(brd->b[i].quad==4)
			{
				p1x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.75;
				p1y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			glPushMatrix();
			glTranslatef(p1x,p1y,100);
			glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
			mat_ambient[3]=1;
	mat_diffuse[3]=1;
	mat_specular[3]=1;mat_ambient[0]=brd->p[1].c[0];
		mat_ambient[1]=brd->p[1].c[1];
				mat_ambient[2]=brd->p[1].c[2];	
				mat_diffuse[0]=brd->p[1].c[0];
				mat_diffuse[1]=brd->p[1].c[1];
				mat_diffuse[2]=brd->p[1].c[2];
				mat_specular[0]=brd->p[1].c[0];
				mat_specular[1]=brd->p[1].c[1];
				mat_specular[2]=brd->p[1].c[2];

glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
GLfloat lightint[]={1.f,01.f,01.f,1.0f};
GLfloat lightpos[]={p1x,p1y,200.0f,0.0f};

glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);

	glPushMatrix();glutSolidCone(7,20,40,40);glTranslatef(0,0,+100+21);if(brd->p[1].prisoned)
	{
		mat_ambient[0]=1;
		mat_ambient[1]=1;
				mat_ambient[2]=1;	
				mat_diffuse[0]=1;
				mat_diffuse[1]=1;
				mat_diffuse[2]=1;
				mat_specular[0]=1;
				mat_specular[1]=1;
				mat_specular[2]=1;
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
	}
	glutSolidCube(7);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	
			glPopMatrix();
		
		}
		
		if(brd->b[i].owner==brd->p[0].pid)
			glColor3fv(brd->p[0].c);
		else if(brd->b[i].owner==brd->p[1].pid)
			glColor3fv(brd->p[1].c);
		else
			glColor4f(1,1,1,0);
		
		if(brd->b[i].hno==0)
		{
		glPushMatrix();
		glBegin(GL_QUADS);
		
			if(brd->b[i].quad==1)
			{
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]+1.5);
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]+1.5+4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]+1.5+4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]+1.5);
			}
			else if(brd->b[i].quad==2)
			{
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]-1.5);
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]-1.5);
			}
			if(brd->b[i].quad==3)
			{
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]-1.5);
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]-1.5);
			}
			if(brd->b[i].quad==4)
			{
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]+1.5);
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]+1.5+4);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]+4+1.5);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]+1.5);
			}
			glEnd();
		glPopMatrix();
		}
		else if(brd->b[i].hno>0)
		{
			glPushMatrix();
			for(int m=1;m<=brd->b[i].hno;m++)
			{
				glPushMatrix();
				if(brd->b[i].quad==1)
				{
					glTranslatef(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]+1.5,0);
					
				}
				else if(brd->b[i].quad==2)
				{
					glTranslatef(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]-1.5,0);
					glRotatef(-90,0,0,1);
				}
				else if(brd->b[i].quad==3)
				{
					glTranslatef(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]-1.5,0);
					glRotatef(-180,0,0,1);
				}
				else if(brd->b[i].quad==4)
				{
					glTranslatef(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]+1.5,0);
					glRotatef(-180-90,0,0,1);
				}
				glScalef(.1,.07,0);
				d1(HOUSE,9);
				glPopMatrix();
				if(brd->b[i].quad==1)glTranslatef(8,0,0);
				else if(brd->b[i].quad==2)glTranslatef(0,-8,0);
				else if(brd->b[i].quad==3)glTranslatef(-8,0,0);
				else glTranslatef(0,8,0);
			}
			glPopMatrix();
		}
		glLineWidth(3);
		switch(i)
		{
			case 15:
			case 30:
			case 2 :
				glPushMatrix();
				if(brd->b[i].quad==1)
				glTranslatef(brd->b[i].posv[0][0]+3,brd->b[i].posv[0][1]+5,0);
				else if(brd->b[i].quad==2)
				{
					glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]-3,0);
					glRotatef(-90,0,0,1);
				}
				else if(brd->b[i].quad==4)
				{
					glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]+3,0);
					glRotatef(-180-90,0,0,1);
				}
				glScalef(.2,.3,0);
				glColor3fv(colr_brown);
				d1(CHEST1,9);
				glColor3fv(colr_yellow);
				d1(CHEST,9);
				glPopMatrix();
				break;
			case 11:
				glPushMatrix();
				glTranslatef(brd->b[i].posv[0][0]+10,brd->b[i].posv[0][1]-10,0);
				glRotatef(-90,0,0,1);
				glScalef(.18,.18,.1);
				glColor3fv(colr_yellow);
				d1(BOLT,9);
				glPopMatrix();
				break;
			case 9:
				glPushMatrix();
				glTranslatef(brd->b[i].posv[0][0]+20,brd->b[i].posv[0][1]+20,30);
				glScalef(.06,.06,.06);
				glRotatef(45,1,1,0);/*
				 glPushMatrix();
				for(int m=0;m<n[SPINNER];m++)
				{
					glBegin(9);
					glColor3fv(colr2[m-1]);
					for(int j=0;j<col[SPINNER][m];j++)
						glVertex2f(p[SPINNER][m][0][j],p[SPINNER][m][1][j]);
					glEnd();
				}
				glColor3f(1,1,1);
				glBegin(GL_POLYGON);
				for(int theta=0;theta<=360;theta++)
				{
					
					glVertex3f(150*cos(theta*val) ,150*sin(theta*val),3);
				}
									glEnd();

				glPopMatrix();*/
				 glCallList(SPIN);glPopMatrix();
				break;
		case 0:
		glColor3f(0,0,0);
			glPushMatrix();
			glTranslatef(brd->b[i].posv[0][0]+18,brd->b[i].posv[0][1]+5,100);
			glRotatef(45,0,0,1);
			glScalef(.35,.35,.35);
			myText(go,2);
			glPopMatrix();
			break;
		case 18:
		 glColor3f(0,0,0);
		 glPushMatrix();
			glTranslatef(brd->b[i].posv[1][0]-6,brd->b[i].posv[0][1]-4,100);
			glRotatef(-135,0,0,1);
			glScalef(.061,.061,.061);
			strokeText("PARKING",0,0);
			glPopMatrix();
			 glPushMatrix();
			glTranslatef(brd->b[i].posv[1][0]-6,brd->b[i].posv[0][1]-16,100);
			glRotatef(-135,0,0,1);
			glScalef(.061,.061,.061);
			
			strokeText("FREE",0,0);
			glPopMatrix();
			break;
		case 27:
		glColor3f(0,0,0);
		glPushMatrix();
		glTranslatef(brd->b[i].posv[1][0]-9,brd->b[i].posv[1][1]+13,100);
			glRotatef(-225,0,0,1);
			glScalef(.061,.061,.061);
			strokeText("JAIL",0,0);glPopMatrix();
     break;
     case 6:glPushMatrix();
     glColor3fv(colr_red);
     if(brd->b[i].quad==3){
     	glRotatef(-180,0,0,1);
     glTranslatef(brd->b[i].posv[0][0]-10,brd->b[i].posv[0][1]-5,0);
	 }
	 else
	 	 glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]+5+4,0);
	 	glScalef(.2,.2,.2);
	 	d1(QMARK,9);
     glPopMatrix();
     break;
     case 20:
     glPushMatrix();
     glColor3fv(colr_red);
     glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]-5-4,0);
     	glRotatef(-180,0,0,1);
	glScalef(.2,.2,.2);
	 	d1(QMARK,9);
     glPopMatrix();
     break;

     case 32:
     glPushMatrix();
     glColor3fv(colr_red);
     glTranslatef(brd->b[i].posv[0][0]-5-4,brd->b[i].posv[0][1]+5,0);
     	glRotatef(-180-90,0,0,1);
	glScalef(.2,.2,.2);
	 	d1(QMARK,9);
     glPopMatrix();
     break;
     case 25:
     glPushMatrix();
     glColor3fv(colr_blue);
     glTranslatef(brd->b[i].posv[0][0]-15,brd->b[i].posv[0][1]-17,0);
     glRotatef(-180,0,0,1);
     glScalef(.13,.14,.2);
     d1(WB,9);
     glPopMatrix();
     break;
		}
		
		glLineWidth(1);
	}glPushMatrix();

	glColor3f(.1,1,1);
	glTranslatef(200,300,1);
	
	glRotatef(90,1,0,0);
	glRotatef(0,0,1,0);
	
	glPopMatrix();
	static int z=1;
	if(z)
	{
	
	z=0;
}
glPopMatrix();glPushMatrix();
	glColor4f(1,1,1,.5);
	glBegin(GL_QUADS);
	glVertex2f(10,50);
	glVertex2f(291,50);
	glVertex2f(291,WH-50);
	glVertex2f(10,WH-50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,50,0);
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(79,475,0);
	glScalef(.7,.7,.7);
	myText(brd->p[0].name2,strlen(brd->p[0].name));
	glPopMatrix();

	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(60,420,0);
	glScalef(.6,.6,.6);
	myText(brd->p[0].tempamt,strlen(brd->p[0].amtcc)+1);
	glPopMatrix();char s1[20];int s2[20];
	glPushMatrix();
	glTranslatef(60,380,0);
	snprintf(s1,20,"SCORE:%d",(int)brd->p[0].totalGain/10);	
		for(int i=0;i<strlen(s1);i++)s2[i]=ccode[(int)s1[i]];
	glScalef(.4,.4,.6);
	myText(s2,strlen(s1));
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34,10,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(550,50,0);
	strokeText("Quit",5,5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,50,0);
	glPushMatrix();
	glTranslatef(34,60+50,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(.8,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.2,.2,0);
	glTranslatef(125,50,0);
	strokeText("Buy",5,5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(180,60+50,0);
	glScalef(.8,0.9,0);
	if(!brd->p[0].sellFlag)glColor4f(.5,.5,.5,.5);else glColor4f(TH_COLOR,.5);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.2,.2,0);
	glTranslatef(100,50,0);
	strokeText("Sell",5,5);
	glPopMatrix();
	
if(brd->me->prisoned && brd->me->pid==brd->p[0].pid)
	{
	glPushMatrix();
	glTranslatef(34,10+200,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(300,50,0);char temp131[10];
	char temp232[10]="Bail $";
	snprintf(temp131,10,"%d",brd->me->bail);
	strcat(temp232,temp131);
	if(brd->me->bailcrd==0)
	strokeText(temp232,5,5);
	else
	{
		glTranslatef(-250,0,0);
		strokeText("Use bail card",0,0);
	}
	glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(34,10+250,0);
	if(!brd->p[0].statusFlag)glColor4f(.5,.5,.5,.5);else glColor4f(TH_COLOR,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(450,50,0);
	strokeText("Status",5,5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34,10+50,0);
	if(!brd->p[0].houseFlag)glColor4f(.5,.5,.5,.5);else glColor4f(TH_COLOR,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(200,50,0);
	strokeText("Build House",5,5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34,10,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(340,50,0);
	strokeText("End Turn",5,5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34,10+150,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(200+100+50,50,0);
	strokeText("Spinner",5,5);
	glPopMatrix();
	 glPopMatrix();

	glColor3f(1,0,0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	if(brd->me->pid==brd->p[0].pid)
	{
		mat_ambient[0]=brd->p[0].c[0];
		mat_ambient[1]=brd->p[0].c[1];
				mat_ambient[2]=brd->p[0].c[2];	
				mat_diffuse[0]=brd->p[0].c[0];
				mat_diffuse[1]=brd->p[0].c[1];
				mat_diffuse[2]=brd->p[0].c[2];
				mat_specular[0]=brd->p[0].c[0];
				mat_specular[1]=brd->p[0].c[1];
				mat_specular[2]=brd->p[0].c[2];
}
else
{
		mat_ambient[0]=0.5;
		mat_ambient[1]=0.5;
				mat_ambient[2]=0.5;	
				mat_diffuse[0]=0.5;
				mat_diffuse[1]=0.5;
				mat_diffuse[2]=0.5;
				mat_specular[0]=.5;
				mat_specular[1]=0.5;
				mat_specular[2]=0.5;
}
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
GLfloat lightint[]={1.f,01.f,01.f,1.0f};
GLfloat lightpos[]={240.0f,520.0f,200.0f,1.0f};
glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);
	glPushMatrix();
	glTranslatef(50,470,100);
	
	glRotatef(-80,1,0,0);
	glTranslatef(0,-10,0);
	
	glColor3f(1,0,0);glutSolidCone(20,60,40,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(50,WH-160,100+10+10);
	if(brd->me->pid==brd->p[0].pid)
	glRotatef(temp_ang+=5,0,1,0);
	glutSolidCube(20);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();glPushMatrix();
	glTranslatef(1060,0,0);
	glColor4f(1,1,1,.5);
	
	glPushMatrix();
	glColor4f(1,1,1,.5);
	glBegin(GL_QUADS);
	glVertex2f(10,50);
	glVertex2f(291,50);
	glVertex2f(291,WH-50);
	glVertex2f(10,WH-50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,50,0);
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(79,475,0);
	glScalef(.7,.7,.7);
	myText(brd->p[1].name2,strlen(brd->p[1].name));
	glPopMatrix();

	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(60,420,0);
	glScalef(.6,.6,.6);
	myText(brd->p[1].tempamt,strlen(brd->p[1].amtcc)+1);
	glPopMatrix();glPushMatrix();
	glTranslatef(60,380,0);
	snprintf(s1,20,"SCORE:%d",(int)brd->p[1].totalGain/10);	
		for(int i=0;i<strlen(s1);i++)s2[i]=ccode[(int)s1[i]];
	glScalef(.4,.4,.6);
	myText(s2,strlen(s1));
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34,10,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(550,50,0);
	strokeText("Quit",5,5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,50,0);
	glPushMatrix();
	glTranslatef(34,60+50,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(.8,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.2,.2,0);
	glTranslatef(125,50,0);
	strokeText("Buy",5,5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(180,60+50,0);
	if(!brd->p[1].sellFlag)glColor4f(.5,.5,.5,.5);else glColor4f(TH_COLOR,.5);
	glScalef(.8,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.2,.2,0);
	glTranslatef(100,50,0);
	strokeText("Sell",5,5);
	glPopMatrix();glPushMatrix();
	glTranslatef(34,10+50,0);
	if(!brd->p[1].houseFlag)glColor4f(.5,.5,.5,.5);else glColor4f(TH_COLOR,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(200,50,0);
	strokeText("Build House",5,5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34,10+250,0);
	if(!brd->p[1].statusFlag)glColor4f(.5,.5,.5,.5);else glColor4f(TH_COLOR,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(450,50,0);
	strokeText("Status",5,5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34,10,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(340,50,0);
	strokeText("End Turn",5,5);
	glPopMatrix();

	if(brd->me->prisoned && brd->me->pid==brd->p[1].pid)
	{
	glPushMatrix();
	glTranslatef(34,10+200,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(300,50,0);char temp131[10];
	char temp232[10]="Bail $";
	snprintf(temp131,10,"%d",brd->me->bail);
	strcat(temp232,temp131);
	strokeText(temp232,5,5);
	glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(34,10+150,0);
	glColor4f(.5,.5,.5,.5);
	glScalef(2,0.9,0);
	d1(BUTTON,9);
	glColor3f(0,0,0);
	glScalef(.08,.2,0);
	glTranslatef(200+150,50,0);
	strokeText("Spinner",5,5);
	glPopMatrix();

	 glPopMatrix();

	glColor3f(1,0,0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	if(brd->me->pid==brd->p[1].pid)
	{
		mat_ambient[0]=brd->p[1].c[0];
		mat_ambient[1]=brd->p[1].c[1];
				mat_ambient[2]=brd->p[1].c[2];	
				mat_diffuse[0]=brd->p[1].c[0];
				mat_diffuse[1]=brd->p[1].c[1];
				mat_diffuse[2]=brd->p[1].c[2];
				mat_specular[0]=brd->p[1].c[0];
				mat_specular[1]=brd->p[1].c[1];
				mat_specular[2]=brd->p[1].c[2];
}
else
{
		mat_ambient[0]=0.5;
		mat_ambient[1]=0.5;
				mat_ambient[2]=0.5;	
				mat_diffuse[0]=0.5;
				mat_diffuse[1]=0.5;
				mat_diffuse[2]=0.5;
				mat_specular[0]=.5;
				mat_specular[1]=0.5;
				mat_specular[2]=0.5;
}
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);
	glPushMatrix();
	glTranslatef(50,470,100);
	
	glRotatef(-80,1,0,0);
	glTranslatef(0,-10,0);
	
	glColor3f(1,0,0);glutSolidCone(20,60,40,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(50,WH-160,100+10+10);
	if(brd->me->pid==brd->p[1].pid)
	glRotatef(temp_ang+=5,0,1,0);
	glutSolidCube(20);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void startkb(unsigned char key, int x,int y)
{
	if(!msgFlag)
	{

			if(key=='q'&& !brd->me->statusFlag){
				brd->winner=brd->opp;
			brd->loser=brd->me;
				swactive=1;
	glutPostRedisplay();
		swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;
		glutSetWindow(swid1);

		init();
		glutWarpPointer(177,143);
		glutDisplayFunc(leave);
		glutKeyboardFunc(leavekb);
		glutMouseFunc(leavem);
		glutPostRedisplay();
			}
			if(key=='b'&& !brd->me->statusFlag)
			{
				
				brd->buy();
			}
			else if(key=='s'&& !brd->me->statusFlag)
			{
				
				if(!brd->me->sellFlag )brd->me->sellFlag=1;else brd->me->sellFlag=0;
			}
			else if(key=='h' && !brd->me->statusFlag)
			{
				
				if(!brd->me->houseFlag)brd->me->houseFlag=1;else brd->me->houseFlag=0;
			}
			else if(key=='e' && !brd->me->statusFlag)
			{
				
				if(!brd->spinFlag || brd->me->prisoned){
				player* temp=brd->me;
				brd->me=brd->opp;
				brd->opp=temp;
				brd->spinFlag=1;
				brd->me->houseFlag=0;
				brd->me->sellFlag=0;
				strcpy(brd->headline,brd->me->name);
				strcat(brd->headline,"'s turn.");
				
				}
				else
					message("      Spin the spinner first.",sizeof("Spinner the spinner first."));}
			else if(key==' ' && !brd->me->statusFlag)
			{
				
				glutWarpPointer(resx/2,resy/2);
				if(brd->spinFlag)brd->play();

			}
			else if(key=='l' && brd->me->prisoned && !brd->me->statusFlag)
			{
				
				if(brd->me->prisoned==true)
				{
				if(brd->me->bailcrd==1)
					brd->me->bailcrd--;
				else if(brd->me->spend(brd->me->bail))
				brd->me->unjailed();
				else message("		Insufficient funds.",sizeof("		Insufficient funds."));
				}
			} 
			else if(key=='t')
			{
				
				if(brd->me->statusFlag)
				{
					glutSetWindow(wid);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutDestroyWindow(swid3);
	swactive=0;

		glutPostRedisplay();
		brd->me->statusFlag=0;
				}
				else
				{
					brd->me->statusFlag=1;
						swactive=1;
	glutPostRedisplay();
				swid3=glutCreateSubWindow(wid,(300+4)*sx,(0)*sy,(WH+80)*sx,(WH)*sy);
	swactive=1;

				glClearColor(1,1,1,0);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glMatrixMode(GL_PROJECTION);
				gluOrtho2D(0,resy-100,0,resy-100);
				glMatrixMode(GL_MODELVIEW);
				glutDisplayFunc(status);
				
				}
			}
			
	}

}

void startm(int b,int s,int x,int y)
{if(!msgFlag)
	{
	if(s==GLUT_DOWN && glutGetWindow()==wid && !back_lock)
	{
		if(containsPoint(37,600,271,632,x,y)&& brd->me->pid==brd->p[0].pid && !brd->me->statusFlag){
			brd->winner=brd->opp;
			brd->loser=brd->me;
	swactive=1;
	glutPostRedisplay();
		swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
		glutSetWindow(swid1);

		init();
		glutWarpPointer(177,143);
		glutDisplayFunc(leave);
		glutKeyboardFunc(leavekb);
		glutMouseFunc(leavem);
		glutPostRedisplay();
			}
			if(containsPoint(36,467,130,497,x,y)&&brd->me->pid==brd->p[0].pid && !brd->me->statusFlag)
			{
				
				brd->buy();
			}
			else if(containsPoint(181,468,276,498,x,y)&&brd->me->pid==brd->p[0].pid && !brd->me->statusFlag)
			{
				
				if(!brd->me->sellFlag )brd->me->sellFlag=1;else brd->me->sellFlag=0;
			}
			else if(containsPoint(34,513,273,543,x,y)&&brd->me->pid==brd->p[0].pid && !brd->me->statusFlag)
			{
				
				if(!brd->me->houseFlag)brd->me->houseFlag=1;else brd->me->houseFlag=0;
			}
			else if(containsPoint(35,556,274,587,x,y)&&brd->me->pid==brd->p[0].pid && !brd->me->statusFlag)
			{
				
				if(!brd->spinFlag |brd->me->prisoned){
				player* temp=brd->me;
				brd->me=brd->opp;
				brd->opp=temp;
				brd->spinFlag=1;
				brd->me->sellFlag=0;
				strcpy(brd->headline,brd->me->name);
				strcat(brd->headline,"'s turn.");
				
				}
				else
					message("      Spin the spinner first.",sizeof("Spinner the spinner first."));

			}
			else if(containsPoint(35,377,274,407,x,y) && brd->me->pid==brd->p[0].pid && brd->me->prisoned && !brd->me->statusFlag)
			{
				
				if(brd->me->prisoned==true)
				{
				if(brd->me->bailcrd==1)
					brd->me->bailcrd--;
				else if(brd->me->spend(brd->me->bail))
				brd->me->unjailed();
				else message("		Insufficient funds.",sizeof("		Insufficient funds."));
				}
			}
			else if(containsPoint(34,421,275,452,x,y) && !brd->me->statusFlag)
			{
				
				glutWarpPointer(resx/2,resy/2);
				if(brd->spinFlag)brd->play();

			}
			else if(containsPoint(35,334,274,361,x,y) )
			{    
				if(brd->me->statusFlag)
				{
					glutSetWindow(wid);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutDestroyWindow(swid3);
	swactive=0;

		glutPostRedisplay();
		brd->me->statusFlag=0;
				}
				else
				{
					brd->me->statusFlag=1;
						swactive=1;
	glutPostRedisplay();
				swid3=glutCreateSubWindow(wid,(300+4)*sx,(0)*sy,(WH+80)*sx,(WH)*sy);
				swactive=1;

				glClearColor(1,1,1,0);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glMatrixMode(GL_PROJECTION);
				gluOrtho2D(0,resy-100,0,resy-100);
				glMatrixMode(GL_MODELVIEW);
				glutDisplayFunc(status);
				
				}
			}

			if(containsPoint(37+1058,600,271+1058,632,x,y)&& brd->me->pid==brd->p[1].pid && !brd->me->statusFlag){
				brd->winner=brd->opp;
			brd->loser=brd->me;
				swactive=1;
	glutPostRedisplay();
		swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;

		init();
		glutWarpPointer(177,143);
		glutDisplayFunc(leave);
		glutKeyboardFunc(leavekb);
		glutMouseFunc(leavem);
		glutPostRedisplay();
			}
			if(containsPoint(36+1058,467,130+1058,497,x,y)&&brd->me->pid==brd->p[1].pid && !brd->me->statusFlag)
			{
				
				brd->buy();
			}
			else if(containsPoint(181+1058,468,276+1058,498,x,y)&&brd->me->pid==brd->p[1].pid && !brd->me->statusFlag)
			{
				
				if(!brd->me->sellFlag )brd->me->sellFlag=1;else brd->me->sellFlag=0;
			}
			else if(containsPoint(34+1058,513,273+1058,543,x,y)&&brd->me->pid==brd->p[1].pid && !brd->me->statusFlag)
			{
				
				if(!brd->me->houseFlag)brd->me->houseFlag=1;else brd->me->houseFlag=0;
			}
			else if(containsPoint(35+1058,556,274+1058,587,x,y)&&brd->me->pid==brd->p[1].pid && !brd->me->statusFlag)
			{
				
				if(!brd->spinFlag || brd->me->prisoned){
				player* temp=brd->me;
				brd->me=brd->opp;
				brd->opp=temp;
				brd->spinFlag=1;
				brd->me->houseFlag=0;
				brd->me->sellFlag=0;
				strcpy(brd->headline,brd->me->name);
				strcat(brd->headline,"'s turn.");
				
				}
				else
					message("      Spin the spinner first.",sizeof("Spinner the spinner first."));}
			else if(containsPoint(34+1058,421,275+1058,452,x,y) && !brd->me->statusFlag)
			{
				
				if(brd->spinFlag)brd->play();

			}
			else if(containsPoint(35+1058,377,274+1058,407,x,y) && brd->me->pid==brd->p[1].pid && brd->me->prisoned && !brd->me->statusFlag)
			{
				
				if(brd->me->prisoned==true)
				{
				if(brd->me->bailcrd==1)
					brd->me->bailcrd--;
				else if(brd->me->spend(brd->me->bail))
				brd->me->unjailed();
				else message("		Insufficient funds.",sizeof("		Insufficient funds."));
				}
			} 
			else if(containsPoint(35+1058,334,274+1058,361,x,y))
			{
				
				if(brd->me->statusFlag)
				{
					glutSetWindow(wid);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutDestroyWindow(swid3);
	swactive=0;

		glutPostRedisplay();
		brd->me->statusFlag=0;
				}
				else
				{
					brd->me->statusFlag=1;
						swactive=1;
	glutPostRedisplay();
				swid3=glutCreateSubWindow(wid,(300+4)*sx,(0)*sy,(WH+80)*sx,(WH)*sy);
	swactive=1;

				glClearColor(1,1,1,0);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glMatrixMode(GL_PROJECTION);
				gluOrtho2D(0,resy-100,0,resy-100);
				glMatrixMode(GL_MODELVIEW);
				glutDisplayFunc(status);
				
				}
			}
			
	}

	 if(s==GLUT_DOWN && containsPoint(305,5,1057,676,x,y))
	{
		tempbid=-1;
		for(int i=0;i<36;i++)
		{
			if(brd->b[i].quad==1)
			{
				if(containsPoint(305+2.35*brd->b[i].posv[1][0],10+WH-2.35*brd->b[i].posv[1][1],305+2.35*brd->b[i].posv[2][0],10+WH-2.35*brd->b[i].posv[2][1],x,y))
				{
					
					tempbid=i;
					 if(!brd->me->sellFlag && !brd->me->houseFlag) 
						message2();
					break;
				}
			}
			else if(brd->b[i].quad==2)
			 {
				int f=1;
				for(int j=0;j>=-8;j--)
				{
					if(containsPoint(306,530+j*62,398,530+(j+1)*62,x,y))
					{
						tempbid=10-j;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					f=0;
					break;
					}
				}
				if(!f)break;
			
			}
			 if(brd->b[i].quad==3)
			{
				if(containsPoint(309,5,399,88,x,y))
				{
					tempbid=18;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(399,5,470,87,x,y))
				{
					tempbid=19;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(470,5,540,88,x,y))
				{
					tempbid=20;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(540,4,609,87,x,y))
				{
					tempbid=21;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(611,6,681,87,x,y))
				{
					tempbid=22;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(681,5,753,87,x,y))
				{
					tempbid=23;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(753,4,822,87,x,y))
				{
					tempbid=24;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(821,5,892,88,x,y))
				{
					tempbid=25;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				if(containsPoint(892,5,963,87,x,y))
				{
					tempbid=26;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
			}
			else if(brd->b[i].quad==4)
			{if(containsPoint(964,4,1056,89,x,y))
				{
					tempbid=27;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					break;
				}
				else
				{
				int f=1;
				for(int j=0;j<=8;j++)
				{
					if(containsPoint(961,88+j*62,1056,88+(j+1)*62,x,y))
					{
						tempbid=28+j;
					if(!brd->me->sellFlag && !brd->me->houseFlag)message2();
					f=0;
					break;
					}
				}
				if(!f)break;
				}
			}
		}if(brd->me->sellFlag)brd->sell(tempbid);
		if(brd->me->houseFlag)brd->buyHouse(tempbid);
	}
}
}

void spinner()
{	int i;
	back_lock=true;
	glClearColor(TH_COLOR,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glPushMatrix();
	glScalef(.95,1,1);
	glColor3f(1,1,1);
	glScalef(.9,.9,.9);
	glPushMatrix();
	glScalef(1.05,1.05,1.5);
	d1(CIRCLE,9);
	glPopMatrix();
	glPushMatrix();
	glRotatef(ang,0,0,1);
	for(i=0;i<n[SPINNER];i++)
	{
		glBegin(9);
		glColor3fv(colr2[i-1]);
		for(int j=0;j<col[SPINNER][i];j++)
			glVertex2f(p[SPINNER][i][0][j],p[SPINNER][i][1][j]);
		glEnd();
	}
	glColor3f(1,1,1);
	int k;
	for(i=-10,k=ONE;k<=NINE;k++,i-=30)
	{
	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(210,0,0);
	glScalef(.65,.65,.65);
	d1(k,9);
	glPopMatrix();	
	}
	for(k=ZERO;k<=TWO;k++,i-=30)
	{

	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(175,0,0);
	glScalef(.65,.65,.65);
	d1(ONE,9);
	glPopMatrix();	
	
	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(225,0,0);
	glScalef(.65,.65,.65);
	d1(k,9);
	glPopMatrix();	
	}
	glPopMatrix();
	glLineWidth(12);
	d1(PIE,2);
	glLineWidth(1);
	glPushMatrix();
	glScalef(.45,.45,.45);
	d1(CIRCLE,9);
	glPopMatrix();
	glColor3f(RGB(80,80,80));
	glPushMatrix();
	glTranslatef(20,0,0);
	glScalef(.2,.15,.2);
	glBegin(GL_POLYGON);
	glVertex2f(350,200);
	glVertex2f(350,-200);
	glVertex2f(500,0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();}

void spinTimer(int step)
{	
	if(ang!=(360*3+30*step))
	{
	ang+=5;
	glutSetWindow(swid2);
	glutPostRedisplay();
	glutTimerFunc(5,spinTimer,step);
	}
	else
	{
		sleep(2);
		ang=0;
		brd->spinFlag=0;
		spin_lock=false;
		back_lock=false;
		glutSetWindow(wid);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutDestroyWindow(swid2);
	swactive=0;

		glutTimerFunc(1000,moveTimer,step+1);
		glutPostRedisplay();
		brd->spinover=1;
	}

}

void spinnerm(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN && b==GLUT_LEFT_BUTTON && !spin_lock)
	{
		spin_lock=true;
		
		glutTimerFunc(5,spinTimer,brd->step);
	}
}

void spinnerkb(unsigned char k,int x,int y)
{
	
	if(k==' ' && !spin_lock)
	{
	spin_lock=true;glutTimerFunc(5,spinTimer,brd->step);	
	}
}
void overview()
{

	overviewFlag=1;
	glRasterPos2f(370,0);GLfloat mat_ambient[4];
	GLfloat mat_diffuse[4];
	GLfloat mat_specular[4];
	GLfloat mat_shininess[]={50.0f};
	mat_ambient[3]=1;
	mat_diffuse[3]=1;
	mat_specular[3]=1;static int temp_ang=0,temp_ang2=0;brd->p[0].amtc();brd->p[1].amtc();float p0x,p0y,p1x,p1y;
	glClearColor (TH_COLOR,0);
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
	
	glLoadIdentity();
	glScalef(1,.89,1);
	glScalef(sx,sy,sy);

	glCallList(BACK);

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(610,-500,0);
    glRotatef(45,0,0,1);
    if(!swactive) glCallList(MONOPOLY);
    glPopMatrix();glPushMatrix();
	glTranslatef(305,10,0);
	glScalef(2.35,2.35,1);
	for(int i=0;i<36;i++)
	{
		glColor4f(1,1,1,.9);
		glBegin(GL_POLYGON);
		glVertex2f(brd->b[i].posv[0][0],brd->b[i].posv[0][1]);
		glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
		glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
		glVertex2f(brd->b[i].posv[2][0],brd->b[i].posv[2][1]);
		glEnd();

		if(brd->b[i].t==t_prop)
		{if(brd->b[i].c==gray || brd->b[i].c==brown)
			{
				if(brd->b[i].c==gray)glColor3fv(colr_gray);
				if(brd->b[i].c==brown)glColor3fv(colr_brown);
			glBegin(GL_POLYGON);
			glVertex2f(brd->b[i].posv[0][0],(brd->b[i].posv[0][1]+brd->b[i].posv[1][1])/1.45);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f(brd->b[i].posv[2][0],(brd->b[i].posv[2][1]+brd->b[i].posv[3][1])/1.45);
			glEnd();
			}
			 if(brd->b[i].c==yellow || brd->b[i].c==pink)
			{
				if(brd->b[i].c==pink)glColor3fv(colr_pink);
			if(brd->b[i].c==yellow)glColor3fv(colr_yellow);
			glBegin(GL_POLYGON);
			glVertex2f((brd->b[i].posv[0][0]+brd->b[i].posv[1][0])/1.45,brd->b[i].posv[0][1]);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f((brd->b[i].posv[2][0]+brd->b[i].posv[3][0])/1.45,brd->b[i].posv[2][1]);
			glEnd();
			}
			if(brd->b[i].c==red || brd->b[i].c==orange )
			{
			if(brd->b[i].c==red)glColor3fv(colr_red);
			if(brd->b[i].c==orange)glColor3fv(colr_orange);
			glBegin(GL_POLYGON);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f(brd->b[i].posv[2][0],brd->b[i].posv[3][1]+abs(brd->b[i].posv[3][1]-brd->b[i].posv[2][1])*.3);
			glVertex2f(brd->b[i].posv[0][0],brd->b[i].posv[1][1]+abs(brd->b[i].posv[0][1]-brd->b[i].posv[1][1])*.3);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);glEnd();
			}
			if(brd->b[i].c==green || brd->b[i].c==blue)
			{
			if(brd->b[i].c==blue)glColor3fv(colr_blue);
			
			if(brd->b[i].c==green)glColor3fv(colr_green);
			glBegin(GL_POLYGON);
			glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
			glVertex2f(brd->b[i].posv[3][0]+abs(brd->b[i].posv[3][0]-brd->b[i].posv[2][0])*.3,brd->b[i].posv[2][1]);
			glVertex2f(brd->b[i].posv[1][0]+abs(brd->b[i].posv[0][0]-brd->b[i].posv[1][0])*.3,brd->b[i].posv[0][1]);
			glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);glEnd();
			}
			char tempscost[10]="$";
			char tttt[10];
			snprintf(tttt,10,"%d",(int)brd->b[i].bcost);
			strcat(tempscost,tttt);

			if(brd->b[i].quad==1)
			{
					glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]+20,0);
	glRotatef(0,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]+20-10,0);
	glRotatef(0,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();
			}	
			else if (brd->b[i].quad==2)
			{
					glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+20,brd->b[i].posv[0][1]-5,0);
	glRotatef(-90,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]+20-10,brd->b[i].posv[0][1]-5,0);
	glRotatef(-90,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();
	
			}
			else if(brd->b[i].quad==3)
			{
					glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]-20,0);
	glRotatef(-180,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	glTranslatef(0,10,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]-20+10,0);
	glRotatef(-180,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();

						}
			else
			{
						glPushMatrix();
						if(i!=33)
	glTranslatef(brd->b[i].posv[0][0]-20,brd->b[i].posv[0][1]+5,0);
	else glTranslatef(brd->b[i].posv[0][0]-20,brd->b[i].posv[0][1],0);
	glRotatef(-270,0,0,1);
	glScalef(.035,.035,.035);
	glColor3f(0,0,0);strokeText(brd->b[i].name,0,0);
	glTranslatef(10,0,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(brd->b[i].posv[0][0]-20+10,brd->b[i].posv[0][1]+5,0);
	glRotatef(-270,0,0,1);
	glScalef(.035,.035,.035);
	strokeText(tempscost,0,0);
	glPopMatrix();
			}
		
		}
		glColor3f(0,0,0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(brd->b[i].posv[0][0],brd->b[i].posv[0][1]);
		glVertex2f(brd->b[i].posv[1][0],brd->b[i].posv[1][1]);
		glVertex2f(brd->b[i].posv[3][0],brd->b[i].posv[3][1]);
		glVertex2f(brd->b[i].posv[2][0],brd->b[i].posv[2][1]);
		glEnd();
		if(brd->b[i].t==t_it)
			{
				if(brd->b[i].quad==1)
				{
				
					glColor3f(0,0,0);
					glPushMatrix();
					glTranslatef(brd->b[i].posv[0][0]+3,brd->b[i].posv[1][1]-10,0);
					glScalef(.035,.035,0);
					strokeText("INCOME",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[0][0]+7,brd->b[i].posv[1][1]-17,0);
					glScalef(.035,.035,0);
					strokeText("TAX",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[0][0]+2,brd->b[i].posv[1][1]-30,0);
					glScalef(.026,.026,0);
					strokeText("Pay 1,000",0,0);
					glPopMatrix();
				}
				else if(brd->b[i].quad==4)
				{
					glPushMatrix();glColor3f(0,0,0);
					glPushMatrix();
					glTranslatef(brd->b[i].posv[1][0]+10,brd->b[i].posv[1][1]+3,0);
					glRotatef(90,0,0,1);
					glScalef(.035,.035,0);
					strokeText("INCOME",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[1][0]+17,brd->b[i].posv[1][1]+7,0);
					glRotatef(90,0,0,1);
					glScalef(.035,.035,0);
					strokeText("TAX",0,0);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(brd->b[i].posv[1][0]+30,brd->b[i].posv[1][1]+2,0);
					glRotatef(90,0,0,1);
					glScalef(.026,.026,0);
					strokeText("Pay 2,000",0,0);
					glPopMatrix();
					glPopMatrix();
				}
			}
		if(i==brd->p[0].pos)
		{
			int soms=brd->p[0].pos;
			if(brd->b[i].quad==1)
			{
				p0x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p0y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.25;
			}
			else if(brd->b[i].quad==2)
			{
				p0x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.25;
				p0y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			else if(brd->b[i].quad==3)
			{
				p0x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p0y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.25;
			}
			else if(brd->b[i].quad==4)
			{
				p0x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.25;
				p0y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			glPushMatrix();
			glTranslatef(p0x,p0y,100);
			glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
			mat_ambient[3]=1;
	mat_diffuse[3]=1;
	mat_specular[3]=1;mat_ambient[0]=brd->p[0].c[0];
		mat_ambient[1]=brd->p[0].c[1];
				mat_ambient[2]=brd->p[0].c[2];	
				mat_diffuse[0]=brd->p[0].c[0];
				mat_diffuse[1]=brd->p[0].c[1];
				mat_diffuse[2]=brd->p[0].c[2];
				mat_specular[0]=brd->p[0].c[0];
				mat_specular[1]=brd->p[0].c[1];
				mat_specular[2]=brd->p[0].c[2];

glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
GLfloat lightint[]={1.f,01.f,01.f,1.0f};

GLfloat lightpos[]={0,0,0,1.0f,1};glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);

	glPushMatrix();glTranslatef(0,0,+100+21);glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	
			glPopMatrix();
		}

		if(i==brd->p[1].pos)
		{
			int soms=brd->p[0].pos;
			if(brd->b[i].quad==1)
			{
				p1x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p1y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.75;
			}
			else if(brd->b[i].quad==2)
			{
				p1x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.75;
				p1y=brd->b[i].posv[1][1]-abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			else if(brd->b[i].quad==3)
			{
				p1x=brd->b[i].posv[1][0]-abs(brd->b[i].posv[1][0]-brd->b[i].posv[3][0])*.5;
				p1y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[0][1])*.75;
			}
			else if(brd->b[i].quad==4)
			{
				p1x=brd->b[i].posv[1][0]+abs(brd->b[i].posv[1][0]-brd->b[i].posv[0][0])*.75;
				p1y=brd->b[i].posv[1][1]+abs(brd->b[i].posv[1][1]-brd->b[i].posv[3][1])*.5;
			}
			glPushMatrix();
			glTranslatef(p1x,p1y,100);
			glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
			mat_ambient[3]=1;
	mat_diffuse[3]=1;
	mat_specular[3]=1;mat_ambient[0]=brd->p[1].c[0];
		mat_ambient[1]=brd->p[1].c[1];
				mat_ambient[2]=brd->p[1].c[2];	
				mat_diffuse[0]=brd->p[1].c[0];
				mat_diffuse[1]=brd->p[1].c[1];
				mat_diffuse[2]=brd->p[1].c[2];
				mat_specular[0]=brd->p[1].c[0];
				mat_specular[1]=brd->p[1].c[1];
				mat_specular[2]=brd->p[1].c[2];

glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
GLfloat lightint[]={1.f,01.f,01.f,1.0f};
GLfloat lightpos[]={p1x,p1y,40.0f,1.0f};

glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);

	glPushMatrix();glPopMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	
			glPopMatrix();
		
		}
		
		if(brd->b[i].owner==brd->p[0].pid)
			glColor3fv(brd->p[0].c);
		else if(brd->b[i].owner==brd->p[1].pid)
			glColor3fv(brd->p[1].c);
		else
			glColor4f(1,1,1,0);
		
		if(brd->b[i].hno==0)
		{
		glPushMatrix();
		glBegin(GL_QUADS);
		
			if(brd->b[i].quad==1)
			{
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]+1.5);
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]+1.5+4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]+1.5+4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]+1.5);
			}
			else if(brd->b[i].quad==2)
			{
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]-1.5);
			glVertex2f(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]+1.5+4,brd->b[i].posv[0][1]-1.5);
			}
			if(brd->b[i].quad==3)
			{
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]-1.5);
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]-1.5-4);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]-1.5);
			}
			if(brd->b[i].quad==4)
			{
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]+1.5);
			glVertex2f(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]+1.5+4);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]+4+1.5);
			glVertex2f(brd->b[i].posv[0][0]-1.5-4,brd->b[i].posv[0][1]+1.5);
			}
			glEnd();
		glPopMatrix();
		}
		else
		{
			glPushMatrix();
			for(int m=1;m<=brd->b[i].hno;m++)
			{
				glPushMatrix();
				if(brd->b[i].quad==1)
				{
					glTranslatef(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]+1.5,0);
					
				}
				else if(brd->b[i].quad==2)
				{
					glTranslatef(brd->b[i].posv[0][0]+1.5,brd->b[i].posv[0][1]-1.5,0);
					glRotatef(-90,0,0,1);
				}
				else if(brd->b[i].quad==3)
				{
					glTranslatef(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]-1.5,0);
					glRotatef(-180,0,0,1);
				}
				else if(brd->b[i].quad==4)
				{
					glTranslatef(brd->b[i].posv[0][0]-1.5,brd->b[i].posv[0][1]+1.5,0);
					glRotatef(-180-90,0,0,1);
				}
				glScalef(.1,.07,0);
				d1(HOUSE,9);
				glPopMatrix();
				if(brd->b[i].quad==1)glTranslatef(8,0,0);
				else if(brd->b[i].quad==2)glTranslatef(0,-8,0);
				else if(brd->b[i].quad==3)glTranslatef(-8,0,0);
				else glTranslatef(0,8,0);
			}
			glPopMatrix();
		}
		glLineWidth(3);
		switch(i)
		{
			 case 32:
     glPushMatrix();
     glColor3fv(colr_red);
     glTranslatef(brd->b[i].posv[0][0]-5-4,brd->b[i].posv[0][1]+5,0);
     	glRotatef(-180-90,0,0,1);
	glScalef(.2,.2,.2);
	 	d1(QMARK,9);
     glPopMatrix();
     break;
     case 25:
     glPushMatrix();
     glColor3fv(colr_blue);
     glTranslatef(brd->b[i].posv[0][0]-15,brd->b[i].posv[0][1]-17,0);
     glRotatef(-180,0,0,1);
     glScalef(.13,.14,.2);
     d1(WB,9);
     glPopMatrix();
     break;
			case 6:glPushMatrix();
     glColor3fv(colr_red);
     if(brd->b[i].quad==3){
     	glRotatef(-180,0,0,1);
     glTranslatef(brd->b[i].posv[0][0]-10,brd->b[i].posv[0][1]-5,0);
	 }
	 else
	 	 glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]+5+4,0);
	 	glScalef(.2,.2,.2);
	 	d1(QMARK,9);
     glPopMatrix();
     break;
     case 20:
     glPushMatrix();
     glColor3fv(colr_red);
     glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]-5-4,0);
     	glRotatef(-180,0,0,1);
	glScalef(.2,.2,.2);
	 	d1(QMARK,9);
     glPopMatrix();
     break;

			case 15:
			case 30:
			case 2 :
				glPushMatrix();
				if(brd->b[i].quad==1)
				glTranslatef(brd->b[i].posv[0][0]+3,brd->b[i].posv[0][1]+5,0);
				else if(brd->b[i].quad==2)
				{
					glTranslatef(brd->b[i].posv[0][0]+5,brd->b[i].posv[0][1]-3,0);
					glRotatef(-90,0,0,1);
				}
				else if(brd->b[i].quad==4)
				{
					glTranslatef(brd->b[i].posv[0][0]-5,brd->b[i].posv[0][1]+3,0);
					glRotatef(-180-90,0,0,1);
				}
				glScalef(.2,.3,0);
				glColor3fv(colr_brown);
				d1(CHEST1,9);
				glColor3fv(colr_yellow);
				d1(CHEST,9);
				glPopMatrix();
				break;
			case 11:
				glPushMatrix();
				glTranslatef(brd->b[i].posv[0][0]+10,brd->b[i].posv[0][1]-10,0);
				glRotatef(-90,0,0,1);
				glScalef(.18,.18,.1);
				glColor3fv(colr_yellow);
				d1(BOLT,9);
				glPopMatrix();
				break;
			case 9:
				glPushMatrix();
				glTranslatef(brd->b[i].posv[0][0]+20,brd->b[i].posv[0][1]+20,100);
				glScalef(.06,.06,.06);
				glRotatef(45,1,1,0);
				 glCallList(SPIN);glPopMatrix();
				break;
		case 0:
		glColor3f(0,0,0);
			glPushMatrix();
			glTranslatef(brd->b[i].posv[0][0]+18,brd->b[i].posv[0][1]+5,100);
			glRotatef(45,0,0,1);
			glScalef(.35,.35,.35);
			myText(go,2);
			glPopMatrix();
			break;
		case 18:
		 glColor3f(0,0,0);
		 glPushMatrix();
			glTranslatef(brd->b[i].posv[1][0]-6,brd->b[i].posv[0][1]-4,100);
			glRotatef(-135,0,0,1);
			glScalef(.061,.061,.061);
			strokeText("PARKING",0,0);
			glPopMatrix();
			 glPushMatrix();
			glTranslatef(brd->b[i].posv[1][0]-6,brd->b[i].posv[0][1]-16,100);
			glRotatef(-135,0,0,1);
			glScalef(.061,.061,.061);
			
			strokeText("FREE",0,0);
			glPopMatrix();
			break;
		case 27:
		glColor3f(0,0,0);
		glPushMatrix();
		glTranslatef(brd->b[i].posv[1][0]-9,brd->b[i].posv[1][1]+13,100);
			glRotatef(-225,0,0,1);
			glScalef(.061,.061,.061);
			strokeText("JAIL",0,0);glPopMatrix();
     break;
		}

		glLineWidth(1);
	}glPushMatrix();

	glColor3f(.1,1,1);
	glTranslatef(200,300,1);
	
	glRotatef(90,1,0,0);
	glRotatef(0,0,1,0);
	
	glPopMatrix();
	static int z=1;
	if(z)
	{
	
	z=0;
}
glPopMatrix();glutSwapBuffers();
}

void overviewkb(unsigned char k, int x,int y)
{

}

void overviewm(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN)
	{
		if(containsPoint(5,60,137,144,x,y)){
			overviewFlag=0;
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}
	if(s==GLUT_DOWN)
	{

		for(int i=0;i<36;i++)
		{
			if(brd->b[i].quad==1)
			{
				if(containsPoint(305+2.35*brd->b[i].posv[1][0],10+WH-2.35*brd->b[i].posv[1][1],305+2.35*brd->b[i].posv[2][0],10+WH-2.35*brd->b[i].posv[2][1],x,y))
				{
					
					tempbid=i;
					message2();
					break;
				}
			}
			else if(brd->b[i].quad==2)
			 {int f=1;
				for(int j=0;j>=-8;j--)
				{
					if(containsPoint(306,530+j*62,398,530+(j+1)*62,x,y))
					{
						tempbid=10-j;
					message2();
					f=0;
					break;
					}
				}
				if(!f)break;}
			 if(brd->b[i].quad==3)
			{
				if(containsPoint(309,5,399,88,x,y))
				{
					tempbid=18;
					message2();
					break;
				}
				if(containsPoint(399,5,470,87,x,y))
				{
					tempbid=19;
					message2();
					break;
				}
				if(containsPoint(470,5,540,88,x,y))
				{
					tempbid=20;
					message2();
					break;
				}
				if(containsPoint(540,4,609,87,x,y))
				{
					tempbid=21;
					message2();
					break;
				}
				if(containsPoint(611,6,681,87,x,y))
				{
					tempbid=22;
					message2();
					break;
				}
				if(containsPoint(681,5,753,87,x,y))
				{
					tempbid=23;
					message2();
					break;
				}
				if(containsPoint(753,4,822,87,x,y))
				{
					tempbid=24;
					message2();
					break;
				}
				if(containsPoint(821,5,892,88,x,y))
				{
					tempbid=25;
					message2();
					break;
				}
				if(containsPoint(892,5,963,87,x,y))
				{
					tempbid=26;
					message2();
					break;
				}
			}
			else if(brd->b[i].quad==4)
			{if(containsPoint(964,4,1056,89,x,y))
				{
					tempbid=27;
					message2();
					break;
				}
				else
				{
				int f=1;
				for(int j=0;j<=8;j++)
				{
					if(containsPoint(961,88+j*62,1056,88+(j+1)*62,x,y))
					{
						tempbid=28+j;
					message2();
					f=0;
					break;
					}
				}
				if(!f)break;
				}
			}
		}}

}

void leaderboardkb(unsigned char k, int x,int y)
{

}

void leaderboardm(int b,int s,int x,int y)
{	
	
	if(s==GLUT_DOWN)
	{
		if(containsPoint(5,60,137,144,x,y)){
				glutSetWindow(wid);
				glutDestroyWindow(swid3);
	swactive=0;

				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
		
	}
}

void creditsTimer(int x)
{
	x--;
	glutPostRedisplay();
}

void credits()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glPushMatrix();
	glCallList(BG);
	glPopMatrix();
	glScalef(sx,sy,sy);

	glScalef(1,.88,1);

	glCallList(BACK);

	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(550,615,0);
	myText(creditst,7);
	glPopMatrix();
		glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,550);
	glVertex2f(resx,550);
	glVertex2f(resx,200);
	glVertex2f(0,200);
	glEnd();
	if(t1!=10)
	{
	glColor4f(1,1,1,t1/50);
	glPushMatrix();
	glTranslatef(50,460,0);
	myText(team,4);
	glPopMatrix();
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(0,450);
	glVertex2f(resx,450);
	glEnd();
	glLineWidth(1);
	glPushMatrix();
	glTranslatef(50,330,0);
	myText(karthik,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(50,260,0);
	myText(chandan,9);
	glPopMatrix();
	if(t1==50)
	glutTimerFunc(3000,creditsTimer,t1--);
	else
	glutTimerFunc(1000,creditsTimer,t1--);
	}
	else if(t2!=10)
	{
	glColor4f(1,1,1,t2/50);
	glPushMatrix();
	glTranslatef(50,460,0);
	myText(support,7);
	glPopMatrix();
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(0,450);
	glVertex2f(resx,450);
	glEnd();
	glLineWidth(1);
	glPushMatrix();
	glTranslatef(50,330,0);
	myText(rashmi,10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(50,260,0);
	myText(sharan,10);
	glPopMatrix();
	if(t2==50)
	{
	sleep(2);
	glutTimerFunc(1000,creditsTimer,t2--);
	}
	else
	glutTimerFunc(1000,creditsTimer,t2--);
	}
	else
	{
		glColor3f(1,1,1);
		glPushMatrix();
		glTranslatef(50,330,0);
		myText(thanks,sizeof(thanks)/sizeof(int));
		glPopMatrix();
	}
	glutSwapBuffers();
}

void creditskb(unsigned char k, int x,int y)
{

}

void creditsm(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN)
	{
		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}

}

void exit1()
{	
	glClearColor(.9,.9,.9,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,400);
	glVertex2f(resx,400);
	glVertex2f(resx,700);
	glVertex2f(0,700);
	glEnd();
	glTranslatef(500,500,0);
	glScalef(2.5,2.5,2.5);
	glLineWidth(2);
	glColor3f(1,1,1);
	myText(exitt,4);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(TH_COLOR,.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((7+2)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.4,.5,2.5);
	glColor3f(1,1,1);
	strokeText("Yes",0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(TH_COLOR,.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((20+2.35)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.4,.5,2.5);
	glColor3f(1,1,1);
	strokeText("No",0,0);
	glPopMatrix();

	glutSwapBuffers();
}

void exitkb(unsigned char key, int x, int y)
{
	if(key=='y'||key=='Y' || key==13)
	{
		glutDestroyWindow(wid);
	swactive=0;

		exit(0);
	}
	if(key=='n' || key=='N' || key==27)
	{
			glutDestroyWindow(glutGetWindow());
	swactive=0;

			glutSetWindow(wid);
			glutDisplayFunc(mainScreen);
			glutKeyboardFunc(mainScreenkb);
			glutMouseFunc(mainScreenm);
			glutPostRedisplay();
	}
}
int containsPoint(int x1,int y1,int x2,int y2,int x,int y)
{
	
	
	
	
	

	x1*=sx,x2*=sx,y1*=sy,y2*=sy;
	
	
	if(x>=x1 && x<=(x2) && y>=y1 && y<=(y2)) return 1;
	else return 0;
}



	







void exitm(int b,int s ,int x, int y)
{
	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)
	{
		
		float ww=9.5*CM2PIX,wh=5*CM2PIX;
	if(containsPoint(84,131,166 ,156,x,y))
	{	

		glutDestroyWindow(wid);
	swactive=0;

		exit(0);
	}
	if(containsPoint(236,130,322,157,x,y))	
	{
			glutDestroyWindow(glutGetWindow());
	swactive=0;

			glutSetWindow(wid);
			glutDisplayFunc(mainScreen);
			glutKeyboardFunc(mainScreenkb);
			glutPostRedisplay();
	}
	}
}

void startupTimer(int x)
{
	glutPostRedisplay();
	if(x!=0)
	glutTimerFunc(500,startupTimer,1);
}

void leave()
{	
	glClearColor(.9,.9,.9,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,400);
	glVertex2f(resx,400);
	glVertex2f(resx,700);
	glVertex2f(0,700);
	glEnd();
	glColor3f(1,1,1);
	glTranslatef(480,500,0);
	glScalef(2.5,2.5,2.5);
	myText(exitt,4);
	glLineWidth(1);
	glScalef(.2,.2,.2);
	glTranslatef(-650,-120,0);
	strokeText2("Your progress will not be saved",0,0);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(TH_COLOR,.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((7+2)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.4,.5,2.5);
	glColor3f(1,1,1);
	strokeText("Yes",0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(TH_COLOR,.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((20+2.35)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.4,.5,2.5);
	glColor3f(1,1,1);
	strokeText("No",0,0);
	glPopMatrix();

	glutSwapBuffers();
}

void leavekb(unsigned char key, int x, int y)
{
	if(key=='y'||key=='Y' || key==13)
	{		
		startFlag=0;
		glutDestroyWindow(glutGetWindow());
	swactive=0;

		glutSetWindow(wid);
		glutDisplayFunc(result);
		
		glutMouseFunc(resultm);
		glutPostRedisplay();
	}
	if(key=='n' || key=='N' || key==27)
	{
			glutDestroyWindow(glutGetWindow());
	swactive=0;

			glutSetWindow(wid);
			glutDisplayFunc(start);
			glutKeyboardFunc(startkb);
			glutMouseFunc(startm);
			glutPostRedisplay();
	}
}

void leavem(int b,int s ,int x, int y)
{

	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)
	{
		printf("%d %d\n",x,y);
	if(containsPoint(84,131,166 ,156,x,y))
	{	
		startFlag=0;
		glutDestroyWindow(glutGetWindow());
	swactive=0;

		glutSetWindow(wid);
		glutDisplayFunc(result);
		
		glutMouseFunc(resultm);
		glutPostRedisplay();
	
	}
	if(containsPoint(236,130,322,157,x,y))	
	{
			glutDestroyWindow(glutGetWindow());
	swactive=0;

			glutSetWindow(wid);
			glutDisplayFunc(start);
			glutKeyboardFunc(startkb);
			glutMouseFunc(startm);
			glutPostRedisplay();	
	}
	}
	
}

void result()
{
glClearColor (TH_COLOR,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(sx,sy,sy);

	glScalef(1,.88,1);

	glPushMatrix();
	glCallList(BG);
	glPopMatrix();
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,550-160);
	glVertex2f(resx,550-160);
	glVertex2f(resx,200-100);
	glVertex2f(0,200-100);
	glEnd();

	GLfloat mat_ambient[4]={.24725,.1995,.0745,1};
	GLfloat mat_diffuse[4]={.75164,.60648,.22648,1};
	GLfloat mat_specular[4]={.628281,.555802,.366065,1};
	GLfloat mat_shininess[]={51.2f};glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);GLfloat em[]={RGB(255,215,0),0};
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);

GLfloat lightint[]={1.5f,01.5f,0.f,1.0f};
GLfloat lightpos[]={600-100+10+10,resy/2+50+60,400.0f,1.0f};

glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(resx/2,470,100);
	glScalef(2,2,2);
	
	glRotatef(-80,1,0,0);
	glRotatef(25,0,0,1);
	glTranslatef(0,-10,0);
	
	glColor3f(1,0,0);
	
	glPushMatrix();
	 glRotatef(80,0,0,01);
	 glRotatef(180,1,0,0);
	 glTranslatef(0,0,-60);
	 glutSolidCone(12,70,40,40);
	glPopMatrix();glPushMatrix();
	glScalef(1.9,1.9,.2);
	 glutSolidCube(10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,-1.2);
	glScalef(2.1,2.1,.2);
	glutSolidCube(10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,-2.4);
	glScalef(2.5,2.5,1);
	 glutSolidCube(10);
	glPopMatrix();
	glTranslatef(0,0,70);
	
	glutSolidSphere(15,20,20);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(300,400,60);
	glRotatef(180,0,1,0);
	
	glPopMatrix();
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	 glPushMatrix();
	 glColor3f(1,1,1);
	 glTranslatef(400,300-100,0);
	 myText(brd->winner->name2,strlen(brd->winner->name));
	 glTranslatef(0,65,0);
	 glScalef(.5,.5,.5);
	int winner[6]={W,I,N,N,E,R};
	myText(winner,6);
	 glPopMatrix();

	 int s2[20];char s1[20];
	 glPushMatrix();
	glTranslatef(400,150,0);
	snprintf(s1,20,"SCORE:%d",(int)brd->winner->totalGain/10);	
		for(int i=0;i<strlen(s1);i++)s2[i]=ccode[(int)s1[i]];
	glScalef(.6,.6,.6);
	myText(s2,strlen(s1));
	glPopMatrix();

	 glPushMatrix();
	 glTranslatef(830,WH-548-10,0);
	
	glScalef(.7,.7,1);
	glColor3f(1,1,1);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	
	 glTranslatef(830+10+10+5,WH-546-10+3,0);
	
	glColor4f(TH_COLOR,.75);
	rasterText("Ok",0,0);
	glPopMatrix();

	glutSwapBuffers();
}

void resultkb(unsigned char k,int x,int y)
{
	if(k=='\n')
		{
		delete brd;
		glutDisplayFunc(mainScreen);
		glutKeyboardFunc(mainScreenkb);
		glutMouseFunc(mainScreenm);
		glutPostRedisplay();
		}
}

void resultm(int b,int s,int x, int y)
{
	printf("%d %d\n",x,y);
	if(containsPoint(830,551,914,572,x,y))
	{
		lbentry temp;
		for(int i=0;i<strlen(brd->winner->name);i++)temp.name[i]=brd->winner->name2[i];
		char t[20];
		snprintf(t,20,"%d",(int)brd->winner->totalGain/10);
		for(int i=0;i<strlen(t);i++)temp.score[i]=ccode[t[i]];
		temp.scorei=brd->winner->totalGain/10;
	temp.nn=strlen(brd->winner->name);
		temp.ns=strlen(t);
		rankList.push_back(temp);
		sort(rankList.begin(),rankList.end(),compByScore);
		delete brd;
		glutDisplayFunc(mainScreen);
		glutKeyboardFunc(mainScreenkb);
		glutMouseFunc(mainScreenm);
		glutPostRedisplay();
		FILE* f=fopen("LB.txt","w");
		int j=0;
		for(vector<lbentry>::iterator i=rankList.begin(); j<3 && i!=rankList.end(); i++,j++)
		{
			fprintf(f,"%d\n",i->scorei*5467+343);
			fprintf(f,"%d\n",i->nn);
			for(int k=0;k<i->nn;k++)
			fprintf(f, "%d\t",i->name[k] );
			fprintf(f, "%d\n", i->ns);
			for(int k=0;k<i->ns;k++)
			fprintf(f, "%d\t",i->score[k] );

		}
		fclose(f);
	}
}
void helpText()
{
	glClearColor (TH_COLOR,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(100,800,0);
	glScalef(.15,.15,.15);glPopMatrix();
	glutSwapBuffers();
}

void leaderboard()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glCallList(BG);
	glLoadIdentity();
	glScalef(sx,sy,sy);

	glScalef(1,.88,1);

	glCallList(BACK);
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(470,615,0);
	myText(lb,sizeof(lb)/sizeof(int));
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,460,0);glColor4f(TH_COLOR,.75);
	glBegin(GL_POLYGON);
	glVertex3f(0,100,0);
	glVertex3f(resx,100,0);
	glVertex3f(resx,0,0);
	glVertex3f(0,0,0);
	glEnd();
	
	glTranslatef(0,-135,0);
	glColor4f(TH_COLOR,.75);
	glBegin(GL_POLYGON);
	glVertex3f(0,100,0);
	glVertex3f(resx,100,0);
	glVertex3f(resx,0,0);
	glVertex3f(0,0,0);
	glEnd();
	glTranslatef(0,-135,0);
	glColor4f(TH_COLOR,.75);
	glBegin(GL_POLYGON);
	glVertex3f(0,100,0);
	glVertex3f(resx,100,0);
	glVertex3f(resx,0,0);
	glVertex3f(0,0,0);
	glEnd();
	glPopMatrix();

		glTranslatef(50,470,0);
		int j=0;
		glColor3f(1,1,1);
	for(vector<lbentry>::iterator i=rankList.begin(); i!=rankList.end() && j<3;i++,j++)
	{	glPushMatrix();
		
		myText(i->name,i->nn);
		glTranslatef(1000,0,0);
		myText(i->score,i->ns);
		glPopMatrix();
		glTranslatef(0,-135,0);
	}
	glutSwapBuffers();
}

void rasterText(const char *txt,int x,int y)
{	int i;
	glPushMatrix();
	glTranslatef(x,y,1);
	glPushMatrix();
	glScalef(.1,.15,1);
	for(i=0;i<strlen(txt);i++){
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,txt[i]);
		 
		
	}
		glPopMatrix();
		glPopMatrix();

}

void rasterText2(const char *txt,int x,int y)
{/*	int i;
	glRasterPos2f(x,y);
	for(i=0;i<strlen(txt);i++){
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,txt[i]);

		 
		
	}
*/int i;
	glPushMatrix();
	glTranslatef(x,y,1);
	glPushMatrix();
	glScalef(.7,1,1);
	for(i=0;i<strlen(txt);i++){
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,txt[i]);
		 
		
	}
		glPopMatrix();
		glPopMatrix();
		
}
void startupdisp()
{ 	
	
	int i;
	static int x=0;
	GLfloat pat[11][2]={
		{0,0},
		 {2000.000000, 0.000000},
 		{1969.000000, 347.000000},
 		{1879.000000, 684.000000},
 		{1732.000000 ,1000.000000},
 		{1532.000000, 1285.000000},
 		{1285.000000, 1532.000000},
 		{1000.000000, 1732.000000},
 		{684.000000, 1879.000000},
		{347.000000, 1969.000000},
 		{0.000000 ,2000.000000}
	};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glScalef(sx,sy,sy);

	for(i=1;i<=9;i++)
	{
		glColor3fv(colr[i-1]);
		glBegin(GL_POLYGON);
		glVertex2fv(pat[0]);
		glVertex2fv(pat[i]);
		glVertex2fv(pat[i+1]);
		glEnd();
	}
	glColor3f(1,1,1);
	glPushMatrix();
	glScalef(1.5,1.5,1);
	rasterText("You gotta play to earn!",410,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500,383,0);
	glColor3f(1,1,1);
	d1(MONO,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(500,0,0);
	glColor3f(1,1,1);
	d1(POLY,9);
	glPopMatrix();

	if(x++%2){
		glPushMatrix();
		glTranslatef(500,10,0);
		glScalef(.15,.15,.15);
		strokeText("Press any key to continue",600,10);
		glPopMatrix();

	}
	glPushMatrix();
	glTranslatef(100,100,100);
	glScalef(10,10,10);
	glRotatef(45,0,1,1);glPopMatrix();
	GLfloat mat_ambient[4]={.24725,.1995,.0745,1};
	GLfloat mat_diffuse[4]={.75164,.60648,.22648,1};
	GLfloat mat_specular[4]={.628281,.555802,.366065,1};
	GLfloat mat_shininess[]={51.2f};glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);GLfloat em[]={RGB(255,215,0),0};
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);

GLfloat lightint[]={1.5f,01.5f,0.f,1.0f};
GLfloat lightpos[]={600-100+10+10,resy/2+50+60,400.0f,1.0f};

glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(resx/2,470,100);
	glScalef(2,2,2);
	
	glRotatef(-80,1,0,0);
	glRotatef(25,0,0,1);
	glTranslatef(0,-10,0);
	
	glColor3f(1,0,0);glPushMatrix();
	glRotatef(90,1,0,0);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,-60);
	
	glPopMatrix();glPushMatrix();
	glScalef(1.9,1.9,.2);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,-1.2);
	glScalef(2.1,2.1,.2);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,-2.4);
	glScalef(2.5,2.5,1);
	
	glPopMatrix();
	glTranslatef(0,0,70);glPushMatrix();
	glRotatef(90,1.0f,0.0f,.0f);
	glRotatef(45,0,0,1);
	glTranslatef(0,0,-.6);
	
	glPushMatrix();
	
	glScaled(2.9,.4,0.4);
	glTranslatef(0.0,0.0,16.0);
	
	glPopMatrix();glPushMatrix();
	glScaled(.4,2.9,0.4);
	glTranslatef(0.0,0.0,16.0);
	
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(300,400,60);
	glRotatef(180,0,1,0);
	
	glPopMatrix();
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	glutSwapBuffers();
}

void mainScreen()
{
	int k=0;
	int i,d=0,j;
	int factor=-resx/10;
	
	glClearColor (1,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glLoadIdentity();glCallList(BG);
	glScalef(sx,sy,sy);

	glScalef(1,.9,1);
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(479,450);
	glVertex2f(867,450);
	glVertex2f(867,700);
	glVertex2f(479,700);
	glEnd();
	glNewList(MONOPOLY,GL_COMPILE_AND_EXECUTE);
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(480,600,0);
	glScalef(.5,.5,.5);
	d1(MONO,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(480,400,0);
	glScalef(.5,.5,.5);
	d1(POLY,9);
	glPopMatrix();
	glEndList();
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(479,0);
	glVertex2f(867,0);
	glVertex2f(867,420);
	glVertex2f(479,420);
	glEnd();
    
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(500,0,0);
    glPushMatrix();
    glTranslatef(0,350,0);
    myText(startt,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,265,0);
    myText(overviewt,8);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,179,0);
    glScalef(.9,1,1);
    myText(lb,sizeof(lb)/sizeof(int));
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,95,0);
    myText(creditst,7);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,10,0);
    myText(exitt,4);
    glPopMatrix();
    glPopMatrix();
	
	
	glutSwapBuffers();
}

void mainScreenm(int b,int s,int x,int y)
{	
	printf("%d %d\n",x,y);
	if(s==GLUT_DOWN &&1)
	{

	if(containsPoint(500 ,327,691 ,375,x,y))
	{	
		
		glClearColor(TH_COLOR,0);
		glutKeyboardFunc(getNameskb);
		glutDisplayFunc(getNames);
		glutMouseFunc(getNamesm);
		glutPostRedisplay();
		
	}
	if(containsPoint(499, 403,839 ,452,x,y))
	{board *bd=new board();
		brd=bd;
		glutDisplayFunc(overview);
		glutKeyboardFunc(overviewkb);
		glutMouseFunc(overviewm);
		glutPostRedisplay();
	}
	if(containsPoint(497, 473,852, 530,x,y))
	{glutDisplayFunc(leaderboard);
		glutKeyboardFunc(leaderboardkb);
		glutMouseFunc(leaderboardm);
		
		glutPostRedisplay();
	}
	if(containsPoint(499, 552,770 ,606,x,y))
	{t1=t2=t3=50;
		glutDisplayFunc(credits);
		glutKeyboardFunc(creditskb);
		glutMouseFunc(creditsm);
		glutPostRedisplay();
	}
	if(containsPoint(499, 626,651, 685,x,y))
	{	
			swactive=1;
	glutPostRedisplay();
		swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;

		init();
		glutWarpPointer(177,143);
		glutDisplayFunc(exit1);
		glutKeyboardFunc(exitkb);
		glutMouseFunc(exitm);
		glutPostRedisplay();
	}
	}
}

void mainScreenkb(unsigned char key, int x, int y)
{	if(1)
	{
	if(tolower( key)=='s')
	{	
		
		glClearColor(TH_COLOR,0);
		glutKeyboardFunc(getNameskb);
		glutDisplayFunc(getNames);
		glutMouseFunc(getNamesm);
		glutPostRedisplay();
		
	}
	if(tolower( key)=='o')
	{board *bd=new board();
		brd=bd;
		glutDisplayFunc(overview);
		glutKeyboardFunc(overviewkb);
		glutMouseFunc(overviewm);
		glutPostRedisplay();
	}
	if(tolower( key)=='l')
	{glutDisplayFunc(leaderboard);
		glutKeyboardFunc(leaderboardkb);
		glutMouseFunc(leaderboardm);
		
		glutPostRedisplay();
	}
	if(tolower( key)=='c')
	{t1=t2=t3=50;
		glutDisplayFunc(credits);
		glutKeyboardFunc(creditskb);
		glutMouseFunc(creditsm);
		glutPostRedisplay();
	}
	if(tolower( key)=='e')
	{	
			swactive=1;
	glutPostRedisplay();
		swid1=glutCreateSubWindow(wid,((resx/2)-(10*CM2PIX/2))*sx,((resy/2)-(5*CM2PIX/2))*sy,(9.5*CM2PIX)*sx,(5*CM2PIX)*sy);
	swactive=1;

		init();
		glutWarpPointer(177,143);
		glutDisplayFunc(exit1);
		glutKeyboardFunc(exitkb);
		glutMouseFunc(exitm);
		glutPostRedisplay();
	}
	}
}
void setup()
{
	FILE* f;FILE* ft; char fn[60]; GLfloat x,y;int i=0,j,flag,k,temp;
	ccode[(int)'A']=A;
ccode[(int)'B']=B;
ccode[int('C')]=C;
ccode[int('D')]=D;
ccode[int('E')]=E;
ccode[int('F')]=F;
ccode[int('G')]=G;
ccode[int('H')]=H;
ccode[int('I')]=I;
ccode[int('J')]=J;
ccode[int('K')]=K;
ccode[int('L')]=L;
ccode[int('M')]=M;
ccode[int('N')]=N;
ccode[int('O')]=O;
ccode[int('P')]=P;
ccode[int('Q')]=Q;
ccode[int('R')]=R;
ccode[int('S')]=S2;
ccode[int('T')]=T;
ccode[int('U')]=U;
ccode[int('V')]=V;
ccode[int('W')]=W;
ccode[int('X')]=X;
ccode[int('Y')]=Y;
ccode[int('Z')]=Z;
ccode[(int)'$']=S;
ccode[(int)'-']=MINUS;
ccode[(int)'1']=ONE;
ccode[(int)'2']=TWO;
ccode[(int)'3']=THREE;
ccode[(int)'4']=FOUR;
ccode[(int)'5']=FIVE;
ccode[(int)'6']=SIX;
ccode[(int)'7']=SEVEN;
ccode[(int)'8']=EIGHT;
ccode[(int)'9']=NINE;
ccode[(int)'0']=ZERO;
ccode[(int)':']=COLON;
	char pointfiles[][20]={"MONO.txt","POLY.txt","PESO.txt","DOLLAR.txt","CENT.txt","RUPEE.txt","BUTTON.txt","BUILD1.txt","BUILD2.txt","BUILD3.txt","A.txt","B.txt","E.txt","H.txt","I.txt","L.txt","O.txt","P.txt","R.txt","T.txt","U.txt","V.txt","W.txt","S.txt","X.txt","C.txt","D.txt","ARROW.txt","SPINNER.txt","0.txt","1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt","9.txt","PIE.txt","K.txt","M.txt","N.txt","G.txt","S2.txt","CIRCLE.txt","J.txt","F.txt","HOUSE.txt","Z.txt","Y.txt","Q.txt","MINUS.txt","WB.txt","QMARK.txt","BOLT.txt","CHEST.txt","CHEST1.txt","COLON.txt","XYZ.txt"};
	int numf=60;
	trans t={{CM2PIX,0,0},
	   {0,CM2PIX,0},
	   {0,0,CM2PIX}};
	time_t sec;
	time(&sec);
	srand((unsigned int)sec);	
	
	bg.data=read_img(TH_IMG,&bg.w,&bg.h,FIF_TIFF);
	
	glShadeModel(GL_SMOOTH);
	f=fopen("LB.txt","r");

			lbentry templb;
	for(int i=0; i<3 ; i++)
		{

			if(fscanf(f,"%d\n",&(templb.scorei))!=EOF)
			{
				templb.scorei=(templb.scorei-343)/5467;
			fscanf(f,"%d\n",&(templb.nn));
			for(int k=0;k<templb.nn;k++)
			fscanf(f, "%d\t",&(templb.name[k] ));
			fscanf(f, "%d\n", &(templb.ns));
			for(int k=0;k<templb.ns;k++)
			fscanf(f, "%d\t",&(templb.score[k]) );
			rankList.push_back(templb);
			}
		}
		sort(rankList.begin(),rankList.end(),compByScore);
		fclose(f);
	for(k=0;k<numf;k++)
	{
		f=fopen(pointfiles[k],"r");
		if(f==NULL)
		{
			
			exit(1);
		}
		flag=1;
		for(i=0;i<5000;i++)
		{
			j=0;
			if(flag==0)break;
			while(1)
			{
				if(fscanf(f,"%f %f",&x,&y)==EOF){
					flag=0;
					break;
				}
				if(x==-111111.0 && y==-111111.0)
					break;
				else
				{
				p[k][i][0][j]=x;
				p[k][i][1][j]=y;
				//p[k][i][2][j]=1;
				j++;
				}
			}
			col[k][i]=j;
		}
		n[k]=i;
		fclose(f);
	}t[0][0]=2/3.f;
	t[1][1]=2/3.f;
	t[2][2]=2/3.f;

	glNewList(BG,GL_COMPILE);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	 
	 for(int i=0;i<=glutGet(GLUT_WINDOW_HEIGHT);i+=bg.h)

     {
     	for(int j=0;j<=glutGet(GLUT_WINDOW_WIDTH);j+=bg.w)
     	{
     	glRasterPos2f(j,i);
		glDrawPixels(bg.w, bg.h, GL_RGB, GL_UNSIGNED_BYTE, (GLubyte*)bg.data);
		}
	}
	
	
	glEndList();

	glNewList(BACK,GL_COMPILE);
	glColor4f(TH_COLOR,.75);
	glBegin(GL_QUADS);
	glVertex2f(0,600);
	glVertex2f(resx,600);
	glVertex2f(resx,700);
	glVertex2f(0,700);
	glEnd();
	
	glColor3f(1,1,1);
	
	glPushMatrix();
	glTranslatef(10,610,0);
	d1(ARROW,9);
	glPopMatrix();
	glEndList();

	glNewList(SPIN,GL_COMPILE);
	
	glColor3f(1,1,1);
	glPushMatrix();
	glScalef(.9,.9,.9);
	glPushMatrix();
	glScalef(1.05,1.05,1.5);
	d1(CIRCLE,9);
	glPopMatrix();
	glPushMatrix();
	glRotatef(ang,0,0,1);
	for(i=0;i<n[SPINNER];i++)
	{
		glBegin(9);
		glColor3fv(colr2[i-1]);
		for(int j=0;j<col[SPINNER][i];j++)
			glVertex3f(p[SPINNER][i][0][j],p[SPINNER][i][1][j],3);
		glEnd();
	}
	glColor3f(1,1,1);
	
	for(i=-10,k=ONE;k<=NINE;k++,i-=30)
	{
	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(210,0,4);
	glScalef(.65,.65,.65);
	d1(k,9);
	glPopMatrix();	
	}
	for(k=ZERO;k<=TWO;k++,i-=30)
	{

	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(175,0,4);
	glScalef(.65,.65,.65);
	d1(ONE,9);
	glPopMatrix();	
	
	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(225,0,4);
	glScalef(.65,.65,.65);
	d1(k,9);
	glPopMatrix();	
	}
	glPopMatrix();
	glLineWidth(12);
	
	glLineWidth(1);
	glPushMatrix();
	glScalef(.45,.45,.45);
	glTranslatef(0,0,10);
	d1(CIRCLE,9);
	glPopMatrix();
	glColor3f(RGB(80,80,80));
	glPushMatrix();
	glTranslatef(20,0,11);
	glScalef(.2,.15,.2);
	glBegin(GL_POLYGON);
	glVertex3f(350,200,6);
	glVertex3f(350,-200,4);
	glVertex3f(500,0,4);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glEndList();
}

void startupkb(unsigned char key, int x, int y)
{

	if(key)
	{
		init();
		glutDisplayFunc(mainScreen);
		glutKeyboardFunc(mainScreenkb);
		glutMouseFunc(mainScreenm);
		glutPostRedisplay();
	}
}
void startupm(int b, int s,int x, int y)
{
	if(s==GLUT_DOWN)
	{
		glutDisplayFunc(mainScreen);
		glutKeyboardFunc(mainScreenkb);
		glutMouseFunc(mainScreenm);
		glutPostRedisplay();
	}
}


int wwid;

void welcomekb(unsigned char k, int x, int y)
{
	if(k)
	{
		glutSetWindow(wid);	
		glutDestroyWindow(wwid);
	}
}
void welcome()
{

	static int dist=0,ang=0;
   int i;
   glClearColor(RGB(220,20,60),1);  
 glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glScalef(sx,sy,sy);
glTranslatef(0,-100,0);
glBegin(GL_POLYGON);  //sky
// glColor3f(RGB(244,67,54));  
glColor3f(RGB(220,20,60));
 glVertex2f (0,0); 
 // glColor3f(RGB(244+30,67+30,54+30)); 
glColor3f(RGB(220,20,60));

   glVertex2f (0,1000);
// glColor3f(RGB(244+30,67+100,54+100));
   // glColor3f(RGB(220,30,90));
   glVertex2f (1700,1000); 
   // glColor3f(RGB(244,67,54)); 
   // glColor3f(RGB(220,30,90));

   glVertex2f (1700,0); 
   // glColor3f(RGB(0,100,0)); 
   // glVertex2f (1700,50);
   // glColor3f(RGB(0,100,0)); 
   // glVertex2f (1600,0);  
    glEnd();

// glCallList(BG);
// glBegin(GL_POLYGON);
// glColor3f(0,0,0);
// glVertex2f(5,5);
// glVertex2f(1595,5);
// glVertex2f(1595,895);
// glVertex2f(5,995);
// glEnd();
int cg[]={C,O,M,P,U,T,E,R,-1,G,R,A,P,H,I,C,S2};

int temp[100];
char t[100];
int t1[100]={J,S2,S2,-1,M,A,H,A,V,I,D,Y,A,P,E,E,T,A};
// glColor3f(RGB(65,105,225));
glColor3f(1,1,1);
glPushMatrix();
glTranslatef(100,0,0);
glPushMatrix();//text
glTranslatef(350+50,670,0);
// glScalef(.2931,.231,0);
glScalef(.5,.5,.5);
glLineWidth(4.5);
myText(t1,sizeof("JSS MAHAVIDYAPEETA")-1);
glPopMatrix();

int t2[100]={J,S2,S2,-1,A,C,A,D,E,M,Y,-1,O,F,-1,T,E,C,H,N,I,C,A,L,-1,E,D,U,C,A,T,I,O,N};
 // glColor3f(RGB(65,105,225));

glPushMatrix();//text
glTranslatef(150,610,0);
glScalef(.75,.75,.5);
// glScalef(.2931,.31,0);
glLineWidth(5.5);
myText(t2,sizeof("JSS ACADEMY OF TECHICAL EDUCATION"));
glPopMatrix();

int t3[100]={D,E,P,A,R,T,M,E,N,T,-1,O,F,-1,C,O,M,P,U,T,E,R,-1,S2,C,I,E,N,C,E};
 // glColor3f(RGB(65,105,225));

glPushMatrix();//text
glTranslatef(270+50,560,0);
glScalef(.5,.5,.5);
// glScalef(.231,.21,0);
glLineWidth(1.5);
myText(t3,sizeof("DEPARTMENT OF COMPUTER SCIENCE")-1);
glPopMatrix();

 // glColor3f(RGB(65,105,225));
glPushMatrix();//text
glTranslatef(360,500,0);
glScalef(.7,.7,.5);
// glScalef(.321,.31,0);
glLineWidth(2.5);
myText(cg,sizeof("COMPUTER GRAPHICS")-1);
glPopMatrix();

 // glColor3f(RGB(65,105,225));
glPushMatrix();//text
glTranslatef(500,460,0);
glScalef(.191231,.1932931,0);
glLineWidth(2.5);
// strokeText("MINI PROJECT",0,0);
glPopMatrix();

 //glColor3f(RGB(65,105,225));
int t4[10]={M,O,N,O,P,O,L,Y};
// glColor3f(RGB(255,127,0));
glPushMatrix();//text
glTranslatef(250+50+125,400,0);
// glScalef(.31,.31,0);
// glLineWidth(3.5);
myText(t4,8);
glPopMatrix();
glPopMatrix();
/*
glColor3f(RGB(248,248,255));
glPushMatrix();//text
glTranslatef(470,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("BH",0,0);
glPopMatrix();

glColor3f(RGB(0,0,139));
glPushMatrix();//text
glTranslatef(535,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("ARA",0,0);
glPopMatrix();

glColor3f(RGB(248,248,255));
glPushMatrix();//text
glTranslatef(620,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("TH",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(710,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("ABHIYAAN",0,0);
glPopMatrix();*/

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(10,300,0);
glScalef(.1921,.21,0);
glLineWidth(1);
strokeText("Under the guidance of:",0,0);
glPopMatrix();

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,250,0);
glScalef(.1921,.191,0);
glLineWidth(1);
strokeText("Ms.RASHMI B N",0,0);
glPopMatrix();

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,228,0);
glScalef(.13,.1,0);
// glLineWidth(1.2);
strokeText("FACULTY INCHARGE",0,0);
glPopMatrix();

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,190,0);
glScalef(.1921,.191,0);
glLineWidth(1);
strokeText("MR.SHARANA BASAVANA GOWDA",0,0);
glPopMatrix();

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,175,0);
glScalef(.13,.1,0);
// glLineWidth(1.3);
strokeText("ASST. PROF,",0,0);
glPopMatrix();

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,160,0);
glScalef(.13,.1,0);
// glLineWidth(1.3);
strokeText("DEPARTMENT OF CSE",0,0);
glPopMatrix();
glTranslatef(30,10,0);
// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(900,300,0);
glScalef(.1921,.21,0);
// glLineWidth(1.5);
strokeText("Team:",0,0);
glPopMatrix();

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(950,250,0);
glScalef(.1821,.191,0);
// glLineWidth(1.5);
strokeText("Karthik S",0,0);
glPopMatrix();

// glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(950,190,0);
glScalef(.1921,.191,0);
// glLineWidth(1.5);
strokeText("Chandan M N",0,0);
glPopMatrix();

// printf("%d %d \n",bg.w,bg.h);
// glRasterPos2f(0,0);

    // glDrawPixels(bg.w, bg.h, GL_RGB, GL_UNSIGNED_BYTE, (GLubyte*)bg.data);

glutSwapBuffers();

}


void init()
{
	glClearColor(1,1,1,1);
	glViewport(0,0,resx,resy);
	gluLookAt(resx/2,resy/2,25,resx/2,resy/2,0,0,1,0);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_NORMALIZE);glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,resx,0,resy,-resy,resy);
	
	glMatrixMode(GL_MODELVIEW);
}
void init2()
{
	
	glClearColor(1,1,1,1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-resy/2+50,resy/2-50,-resy/2+50,resy/2-50);
	glMatrixMode(GL_MODELVIEW);
}
void myReshape1(int w,int h)
{

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<h)
	gluOrtho2D(0.0,resx,0.0,resy*h/w);
	else
		gluOrtho2D(0.0,resx*w/h,0.0,resy);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void myReshape(int w,int h){
	printf("entering reshape h:%d w:%d\n",h,w);
	
	printf("%d %d --)\n", glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	sx=(float)glutGet(GLUT_WINDOW_WIDTH)/1366;
	sy=(float)glutGet(GLUT_WINDOW_HEIGHT)/685;
	glOrtho(0,w,0,h,-resy,resy);

		glMatrixMode(GL_MODELVIEW);
		glutPostRedisplay();
}
int main(int argc,char** argv)
{
	int nil=open("/dev/null",O_WRONLY);
	if(dup2(nil,2)) printf("%s\n","redirecting warnings to /dev/null\n" );
	if(dup2(nil,1)) printf("%s\n","redirecting output to /dev/null\n" );
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(resx,resy);
	wid=glutCreateWindow("Monopoly");
	init();
	setup();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(startupdisp);glutTimerFunc(500,startupTimer,1);
	glutKeyboardFunc(startupkb);
	glutMouseFunc(startupm);
	wwid=glutCreateWindow("");
	init();
	glutReshapeFunc(myReshape);
glutKeyboardFunc(welcomekb);
glutDisplayFunc(welcome);
	glutMainLoop();
	return 0;
}
