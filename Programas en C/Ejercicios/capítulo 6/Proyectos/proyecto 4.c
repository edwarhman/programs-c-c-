#include <stdio.h>
#include <locale.h>
#include "C:/Users/Emerson/Documents/Programas en C/Headers/misHeaders.h"

struct fecha
{
    int dia,
        mes,
        anio;
};
void pedirfecha(struct fecha* Fecha);
int calculaDias(struct fecha lfecha);
int main(int argc, char const *argv[])
{
    struct fecha lfecha;
    int dias;
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que solicita una fecha y luego indica el día del año correspondiente.");
    pedirfecha(&lfecha);
    dias=calculaDias(lfecha);
    printf("La fecha dada corresponde al día %d del año.",dias);
    return 0;
}

void pedirfecha(struct fecha* Fecha)
{
    printf("Ingrese la fecha (DD MM AAAA): ");
    Fecha->dia=LeerEntero("");
    Fecha->mes=LeerEntero("");
    Fecha->anio=LeerEntero("");
}

int calculaDias(struct fecha lfecha)
{
    const int bisiesto[12]={31,29,31,30,31,30,31,31,30,31,30,31}, nobisiesto[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int dias=lfecha.dia;

    for (int i = 0; i < lfecha.mes - 1; i++)
    {
        if (esBisiesto(lfecha.anio))
        {
            dias += bisiesto[i];
        }
        else
        {
            dias += nobisiesto[i];
        }
    }
    return dias;
}


