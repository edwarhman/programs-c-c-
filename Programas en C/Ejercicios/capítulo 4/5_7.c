#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    int dia_n,mes_n,year_n,dia_a,mes_a,year_a,dif_d,dif_m,dif_y;
    dia_a=dia_n=mes_a=mes_n=year_a=year_n=dif_d=dif_m=dif_y=0;

    setlocale(LC_CTYPE,"spanish");
    printf("Programa que calcula la edad de un individuo según su fecha de nacimento y la fecha actual.\n");
    printf("Por favor ingrese su fecha de nacimiento: ");
    scanf("%d %d %d",&dia_n,&mes_n,&year_n);
    printf("Ahora ingrese la fecha actual: ");
    scanf("%d %d %d",&dia_a,&mes_a,&year_a);
    dif_d=dia_a-dia_n;
    dif_m=mes_a-mes_n;
    dif_y=year_a-year_n;
    if (dif_m<0) printf("Su edad es %d",dif_y-1);
        else if (dif_m!=0) printf("Su edad es %d",dif_y);
            else if (dif_d<0)printf("Su edad es %d",dif_y-1);
                else printf("Su edad es %d",dif_y);
    
    
    return 0;
}
