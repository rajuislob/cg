#include<iostream>

#include<graphics.h>

#include<windows.h>



using namespace std;

int xmid,ymid;



//Function to implement DDA line drawing algorithm void dda(int x1,int y1,int x2,int y2) {


int dx,dy,steps,xinc,yinc;



dx=x2-x1;

dy=y2-y1;



xmid=getmaxx()/2;

ymid=getmaxy()/2;



if(abs (dx) > abs(dy) )

{

steps =abs(dx);

}
 


else

{

steps=abs(dy);

}



xinc = dx/(float) steps;

yinc = dy/(float)steps;



for(int k=0;k<steps; k++)

{

putpixel(x1,y1,YELLOW);

x1+= xinc;

y1+= yinc;

}

}



int main()

{

int gd = DETECT , gm;

initgraph(&gd, &gm,"C:\\Dev-Cpp\\lib");



int x1,y1,x2,y2;

cout<<" Digital Differential Analyzer Line Drawing Algorithm \n\n"; cout<<" Enter the x co-ordinate of point 1: "; cin>>x1;
 


cout<<"\n Enter the y co-ordinate of point 1: "; cin>>y1;



cout<<"\n Enter the x co-ordinate of point 2: "; cin>>x2;



cout<<"\nEnter the y co-ordinate of point 2: "; cin>>y2;


xmid=getmaxx()/2;

ymid=getmaxy()/2;

line(xmid , 0 , xmid , getmaxy());

line(0 , ymid , getmaxx() , ymid);



dda(x1+xmid ,ymid-y1,x2+xmid,ymid-y2);



getch();

closegraph();

return 0;

}
