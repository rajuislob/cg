
#include<iostream>

#include<graphics.h>

#include<math.h>



using namespace std;

#define ROUND(a) ((int) (a+0.5))



void ellipsePlotPoints(int, int, int, int);



//Function plotting points of Ellipse

void ellipseMidpoint (int xCenter, int yCenter, int Rx, int Ry)
 
{

int Rx2 = Rx*Rx;

int Ry2 = Ry*Ry;

int twoRx2 = 2*Rx2;

int twoRy2 = 2*Ry2;

int p;

int x = 0;

int y = Ry;

int px = 0;

int py = twoRx2 *y;






ellipsePlotPoints(xCenter, yCenter, x, y);



p = ROUND(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));



while (px < py)

{

x++;

px += twoRy2;



if (p < 0)

{

p += Ry2 + px;
 
}



else

{

y--;

py -= twoRx2;

p += Ry2 + px - py;

}

ellipsePlotPoints(xCenter, yCenter, x,y);

}

/* Region 2 */

p	= ROUND (Ry2*(x+0.5)*(x+0.5) + Rx2*(y-1)*(y-1) - Rx2*Ry2); while (y > 0)

{

y--;

py -= twoRx2;



if (p > 0)

{

p += Rx2 - py;

}



else

{
 
x++;

px += twoRy2;

p += Rx2 - py + px;

}




ellipsePlotPoints(xCenter, yCenter, x, y); }

}




void ellipsePlotPoints (int xCenter, int yCenter, int x, int y) {

putpixel (xCenter + x, yCenter + y, YELLOW); putpixel (xCenter- x, yCenter + y, YELLOW); putpixel (xCenter+ x, yCenter - y, YELLOW); putpixel (xCenter - x, yCenter - y, YELLOW);



}



int main()

{

int x , y,xmid,ymid;

float r,r2;

int gd = DETECT , gm; initgraph(&gd, &gm, (char*)"");
 


cout<<" Ellipse Mid-point Algorithm \n\n";




cout<<" Enter the x co-ordinate of centre : "; cin>>x;



cout<<"\n Enter the y co-ordinate of centre : "; cin>>y;



cout<<"\n Enter the radius1 : ";

cin>>r;



cout<<"\n Enter the radius2 : ";

cin>>r2;



xmid = getmaxx()/2;

ymid = getmaxy()/2;

line(xmid , 0 , xmid , getmaxy());

line(0 , ymid , getmaxx() , ymid);

ellipseMidpoint(x + xmid , ymid - y , r,r2);

getch();

closegraph();

return 0;
 
}
