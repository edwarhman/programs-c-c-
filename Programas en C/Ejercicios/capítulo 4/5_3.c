#include <locale.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int dia,mes=2,year;
    char mes_S[61];
    char c;
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que lee una fecha de la forma: 15, Febrero 1989.\n");
    printf("Luego la muestra como: 15 2 1989.\n");
    printf("Por favor introduzca la fecha (DD, MES AAAA): ");
    scanf("%d %c %s %d",&dia,&c,mes_S,&year);
    if        (!strncmp(mes_S,"Ene",3)||!strncmp(mes_S,"ENE",3)||!strncmp(mes_S,"ene",3)) mes=1;//comparar cadena mes
        else if (!strncmp(mes_S,"Feb",3)||!strncmp(mes_S,"FEB",3)||!strncmp(mes_S,"feb",3)) mes=2;
            else if (!strncmp(mes_S,"Mar",3)||!strncmp(mes_S,"MAR",3)||!strncmp(mes_S,"mar",3)) mes=3;
                else if (!strncmp(mes_S,"Abr",3)||!strncmp(mes_S,"ABR",3)||!strncmp(mes_S,"abr",3)) mes=4;
                    else if (!strncmp(mes_S,"May",3)||!strncmp(mes_S,"MAY",3)||!strncmp(mes_S,"may",3)) mes=5;
                        else if (!strncmp(mes_S,"Jun",3)||!strncmp(mes_S,"JUN",3)||!strncmp(mes_S,"jun",3)) mes=6;
                            else if (!strncmp(mes_S,"Jul",3)||!strncmp(mes_S,"JUL",3)||!strncmp(mes_S,"jul",3)) mes=7;
                                else if (!strncmp(mes_S,"Ago",3)||!strncmp(mes_S,"AGO",3)||!strncmp(mes_S,"ago",3)) mes=8;
                                    else if (!strncmp(mes_S,"Sep",3)||!strncmp(mes_S,"SEP",3)||!strncmp(mes_S,"sep",3)) mes=9;
                                        else if (!strncmp(mes_S,"Oct",3)||!strncmp(mes_S,"OCT",3)||!strncmp(mes_S,"oct",3)) mes=10;
                                            else if (!strncmp(mes_S,"Nov",3)||!strncmp(mes_S,"NOV",3)||!strncmp(mes_S,"nov",3)) mes=11;
                                                else if (!strncmp(mes_S,"Dic",3)||!strncmp(mes_S,"dic",3)||!strncmp(mes_S,"DIC",3)) mes=12;
    printf("%d %d %d.\n",dia,mes,year);   
    return 0;
}
