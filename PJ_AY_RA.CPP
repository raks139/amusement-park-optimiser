#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include"arbox.CPP"
#include<string.h>
#include<dos.h>
int e=0;
struct person
  {char name[20];
  int age;
  };
struct ride
 {char rname[30];
  int capacity;
  int duration;
  int min;
  int agelimit;
  char queue[100][20];
  int status;
  };
void add(char nam[],ride &r);
void move(ride &r);
void showp();
void line();
void botl();
int nor,choice;
ride R1={"Touring Tram",4,60,3,5,{"a","b","c","d","e" },4};
ride R2={"Roller Coaster",4,40,3,18,{"f","g","h","i","j" },4};
ride R3={"Loop-a-Loop",4,30,2,16,{"k","l","m","n"},3};
ride R4={"Water Splash",5,25,3,8,{"p","q","r","s","t"},4};
person p[3];
 void main()
 {
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   cleardevice();
cout<<"                 |ZZzzz              "<<endl;
cout<<"                 |                   "<<endl;
cout<<"                 |                   "<<endl;
cout<<"    |ZZzzz      /^\            |ZZzzz"<<endl;
cout<<"    |          |~~~|           |     "<<endl;
cout<<"    |        |^^^^^^^|        / \    "<<endl;
cout<<"   /^\       |[]+    |       |~~~|   "<<endl;
cout<<"|^^^^^^^|    |    +[]|       |   |   "<<endl;
cout<<"|    +[]|/\/\/\/\^/\/\/\/\/|^^^^^^^| "<<endl;
cout<<"|+[]+   |~~~~~~~~~~~~~~~~~~|    +[]| "<<endl;
cout<<"|       |  []   /^\   []   |+[]+   | "<<endl;
cout<<"|   +[]+|  []  || ||  []   |   +[]+| "<<endl;
cout<<"|[]+    |      || ||       |[]+    | "<<endl;
cout<<"|_______|------------------|_______| "<<endl;
   outtextxy(250,300,"WELCOME TO");
   outtextxy(250,350,"JOY WORLD");
   for (int o=10;o<14;o++)
    {
     cout<<'\a';
     setbkcolor(o);
     delay(1000);
     }
   for(int i=0;i<3;i++)
    {
     int n,choice;
     initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
     setbkcolor(4);
     cleardevice();
     line();
     cout<<"PERSONAL DETAILS"<<endl;
     cout<<"Enter your name(initials)"<<endl;
     cin>>p[i].name;
     cout<<"Enter your age"<<endl;
     cin>>p[i].age;
     showp();
     rect();
     cout<<"How many rides?"<<endl;
     cin>>n;
     if (n>4)
       {
	cout<<"invalid enter again"<<endl;
	cin>>n;
	}
     for(int j=0;j<n;j++)
       {rep : cout<<"Enter your ride choice "<<j+1<<"(only 1 to 4)"<<endl;
	cin>>choice;
	switch(choice)
	 {
	   case 1:if ((p[i].age>=5)&&(p[i].age<=50))
		  add(p[i].name,R1);
		  else
		  cout<<"Person not eligible....sorry :( "<<endl;
		  delay(250);
		  break;
	   case 2:if ((p[i].age>=18)&&(p[i].age<=50))
		  add(p[i].name,R2);
		  else
		  cout<<"Person not eligible....sorry :( "<<endl;
		  delay(250);
		  break;
	   case 3:if ((p[i].age>=16)&&(p[i].age<=50))
		  add(p[i].name,R3);
		  else
		  cout<<"Person not eligible....sorry :( "<<endl;
		  delay(250);
		  break;
	   case 4:if ((p[i].age>=8)&&(p[i].age<=50))
		  add(p[i].name,R4);
		  else
		  cout<<"Person not eligible...sorry :( "<<endl;
		  delay(250);
		  break;
	   default:cout<<"Please enter valid choice."<<endl;
	 }
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
       }
    }
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   line();
   botl();
   setbkcolor(3);
   showp();
   rect();
   delay(3000);
   outtextxy(10,110,"Get ready to get splashin' with water splash XD");
   delay(2000);
   move(R4);
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   line();
   botl();
   setbkcolor(1);
   showp();
   rect();
   delay(3000);
   outtextxy(10,110,"Get ready to loose your mind with loop-a-loop XD");
   delay(2000);
   move(R3);
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   line();
   botl();
   setbkcolor(2);
   showp();
   rect();
   delay(4000);
   outtextxy(10,110,"Get ready to scream with roller coaster XD");
   delay(2000);
   move(R2);
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   line();
   botl();
   setbkcolor(5);
   showp();
   rect();
   delay(2000);
   outtextxy(10,110,"Get ready to get mindblown with touring tram XD");
   delay(2000);
   move(R1);
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   line();
   botl();
   setbkcolor(7);
   showp();
   rect();
   delay(2000);
   clrscr();
   cleardevice();
   outtextxy(200,200,"HOPE YOU ENJOYED RIDING WITH US");
   outtextxy(250,250,"VISIT US AGAIN");
   for (o=10;o<14;o++)
    {
      setbkcolor(o);
      delay(1000);
     }
   closegraph();
   getch();
  }
//functions
void add(char nam[],ride &r)                //adding ppl
{
 strcpy(r.queue[++(r.status)],nam);
 }
void move(ride &r)                          //deletion
{
 int t=(r.status)+1;
 if(t>=r.min && t<=r.capacity)
 {
  r.status=-1;
  cout<<"ride closed";
  delay(1000);
  }
 else if(t>r.capacity)
 {
  for (int i=0;i<t-(r.capacity);i++)
  strcpy(r.queue[i],r.queue[i+(r.capacity)]);
  r.status=(r.status)-(r.capacity);
  }
 else if(t<r.min)
 {
  cout<<"ride ";
  puts(r.rname);
  cout<<" is closed";
  delay(1000);
  }
 }
void showp()                                //displaying ppl
{
 e=0;
 for (int q= 25;q<=25+(20*(R1.status+1));q=q+20)
  outtextxy(406,q,R1.queue[e++]);
 e=0;
 for ( q= 25;q<=25+(20*(R2.status+1));q=q+20)
  outtextxy(456,q,R2.queue[e++]);
 e=0;
 for ( q= 25;q<=25+(20*(R3.status+1));q=q+20)
  outtextxy(506,q,R3.queue[e++]);
 e=0;
 for ( q= 25;q<=25+(20*(R4.status+1));q=q+20)
  outtextxy(556,q,R4.queue[e++]);
 }
void line()                                 //design
{cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
 }
void botl()
{gotoxy(1,20);
cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-**-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
cout<<endl;
 }