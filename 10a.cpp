#include<iostream.h> 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
#include<math.h> 
#include<dos.h> 
class koch 
{ 
public: 
void koch2D(float x0,float y0,float x1,float y1,float xout, float yout, float level) 
{ 
float xa, xb, xd, ya, yb, yd; 
float xmid, ymid, outmag, displacemag; 
if(level==0) 
{ 
line(x0, y0,x1,y1); 
} 
else 
{ 
xa=x0+0.3333333*(x1-x0); ya=y0+0.3333333*(y1-y0); xb=x0+0.6666666*(x1-x0); yb=y0+0.6666666*(y1-y0); 
koch2D(x0,y0,xa,ya,xout,yout,level-1); 
//draw first third koch2D(xb,yb,x1,y1,xout,yout,level-1); 
//draw second third 
outmag=sqrt(xout*xout+yout*yout); 
displacemag=tan(3.14159/3.0)*sqrt((x1-x0)*(x1-x0)+(y1- y0)*(y1-y0))/6.0; 
xmid=xout*displacemag/outmag; 
ymid=yout*displacemag/outmag;
xd=x0+0.5*(x1-x0)+xmid; 
yd=y0+0.5*(y1-y0)+ymid; 
koch2D(xa,ya,xd,yd,xa+0.5*(xd-xa)-xb,ya+0.5*(yd-ya)- yb,level-1); 
koch2D(xd,yd,xb,yb,xd+0.5*(xb-xd)-xa,yd+0.5*(yb-yd)- ya,level-1); 
}
}
}; 
koch k; 
float x0,y0,x1,y1,xout,yout,level; 
cout<<"Enter the value of x0,y0,x1,y1,xout,yout,level"; cin>>x0>>y0>>x1>>y1>>xout>>yout>>level; 
k.koch2D(x0,y0,x1,y1,xout,yout,level); 
getch(); 
closegraph(); 
}
