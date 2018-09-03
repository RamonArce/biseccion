#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);

int main()

{
    int imax,iter;

    double xl,xu,ea,em,test,xr,xrold;

       printf("\nMETODO DE BISECCION\n\n");
       printf("Introduce el extremo del intervalo por la izquierda\n");
       scanf("%lf",&xl);
       printf("Introduce el extremo del intervalo por la derecha\n");
       scanf("%lf",&xu);
       printf("Introduce el numero de iteraciones maximas\n");
       scanf("%d",&imax);
        printf("Introduce el error minimo del calculo\n");
    scanf("%lf",&em);

iter=0;
xr=0;
if(f(xl)*f(xu)>0)
    printf("No hay raiz en ese intervalo\n");
else{
  printf("\nIter    Raiz     Error aprox\n");
  do{
    iter++;
    xrold=xr;
     xr=(xl+xu)/2;
    ea=fabs((xr-xrold)/xr)*100;
    test=f(xl)*f(xr);
    if(test<0)
        xu=xr;
    else if(test >0)
        xl=xr;
    else
        ea=0;
    printf("\n%d    %lf    %lf",iter,xr,ea);

  } while(ea>em && iter<imax);

}
    return 0;

}
double f(double x)
{
    return x*x -2;

}
