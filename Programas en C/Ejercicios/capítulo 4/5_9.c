#include <locale.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int dia,mes,year;
    dia=mes=year=0;

    setlocale(LC_CTYPE,"spanish");
    printf("Programa que indica la cantidad de días de un mes de acuerdo al mes y al año suministrado por el usuario.\n");
    do
    {
        printf("Por favor ingrese el mes y el año (mm aaaa): ");
        scanf("%d %d",&mes,&year);
        if (mes>12||mes<1) printf("Mes inválido.\n");
        if (year<1) printf("Año inválido.\n");
    } while ((mes>12||mes<1)||year<1);
    switch (mes)
    {
    case 1:case 3: case 5: case 7: case 8: case 10: case 12:
        dia=31;
        break;
    case 4: case 6: case 9: case 11:
        dia=30;
        break;
    case 2:
        if (Bisiesto(year))
        {
            dia=29;
        }else dia=28;
        break;
    }
    printf("El mes %d del año %d tiene %d días.\n",mes,year,dia);
    return 0;
}

int Bisiesto(int year_)
{
    int es_bisiesto=0;
    if (year_%4==0)
    {
        if (year_%100==0)
        {
        	if (year_%400==0)
            	es_bisiesto=1;
         	else
			 	es_bisiesto = 0;   	
        } else es_bisiesto=1;
        
    } else es_bisiesto=0;
    return es_bisiesto;
}
