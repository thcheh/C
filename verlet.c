#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main()
{
    double alfa = 45.0;
    double alfarad = (alfa*M_PI)/180;
    double dt = 0.1;
    double v = 20.0;
    double xp = 0.0;
    double xf = 0.0;
    double x = 0.0;
    double ax = 0.0;
    double ay = -9.81;
    double y = 0.0;
    double yp = 5.0; //poczatkowe
    double yf = 0.0;
    double t = 0.0;
    double vy = v*sin(alfarad); // vy = v*sin(alfarad)
    double vx = v*cos(alfarad); // vx = v*cos a - podac w radianach 45 stopni - pi/4 =


    FILE *data=NULL;
    data=fopen("data.txt", "w");

    fprintf(data,"t[s]\tx[]\ty[]\t  vx[]\t    vy[]\n");
    printf("t[s]\tx[]\ty[]\t  vx[]\t    vy[]\n");

    y=yp+vy*dt;
    x=xp+vx*dt;
    vy=vy+ay*dt;
    vx=vx+ax*dt;
    t=t+dt;
    fprintf(data,"%lf %lf %lf %lf %lf\n", t,x,y,vx,vy);
    printf("%lf %lf %lf %lf %lf\n", t,x,y,vx,vy);

    while(y>0)
    {
        yf=2*y-yp+ay*dt*dt;
        xf=2*x-xp+ax*dt*dt;
        vy=(yf-yp)/(2*dt);
        vx=(xf-xp)/(2*dt);
        t=t+dt;
        fprintf(data,"%lf %lf %lf %lf %lf\n", t,xf,yf,vx,vy);
        printf("%lf %lf %lf %lf %lf\n", t,xf,yf,vx,vy);
        yp=y;
        xp=x;
        y=yf;
        x=xf;
    };

    fclose(data);
    return 0;
}
