#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
    double dt=0.01;
    double y=100;
    double g=-9.81;
    double czas=sqrt(2*y/g);
    double vy=g*dt;
    double t=0.0;
    FILE *data=NULL;
    data=fopen("data.txt", "w");
    if(data != NULL )
    {
        fprintf(data, "t[s]\t\ty(t)\t\tvy(t)\n");

    }
    else
    {
        printf("Blad otwarcia pliku %s\n", "data.txt");
    }
    while (y>0)
    {
        vy=vy+g*dt;
        y=y+vy*dt;
        t=t+dt;
        printf("%lf\t%lf\t%lf\n", t,y,vy);
        fprintf(data, "%lf\t%lf\t%lf\n",t,y,vy);
    }
    fclose(data);
}
