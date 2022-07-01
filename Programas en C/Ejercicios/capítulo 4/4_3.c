#include <stdio.h>
#include <locale.h>

float x,y,a,b,c,d,e,f;

int main()
{
    setlocale(LC_CTYPE,"spanish");
    //Cabezera y entrada de datos
    printf("Programa que calcula las variables x e y de un sistema de ecuaciones de dos incognitas tal como:\n\n {Ax+By=C\n {Dx+Ey=F\n");
    printf("\nPor favor ingrese los valores de los coeficientes A, B, C, D, E y F respectivamente: ");
    scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&f);

    //Cálculos
    x=(c*e-b*f)/(a*e-b*d);
    y=(a*f-c*d)/(a*e-b*d);

    //Salida de datos
    printf("\nPara el sistema dado los resultados son:\nx=%.2f\ny=%.2f\n",x,y);
    return 0;
}
