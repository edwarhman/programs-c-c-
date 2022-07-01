#include <stdio.h>
#include "C:/Users/Emerson/Documents/Programas en C/Headers/misHeaders.h"

struct fecha 
{
    int dia,
        mes,
        anyo,
        dias,
        bisiesto;
};
const int dias_meses[]={31,28,31,30,31,30,31,31,30,31,30,31};
const char meses[12][20]={
                            "enero","febrero","marzo",
                            "abril","mayo","junio",
                            "julio","agosto","septiembre",
                            "octubre","noviembre","diciembre"
                        };
//prototipos funciones
void pedir_f(struct fecha* pf);
void calcula_m_d (struct fecha* pf);
void suma_dias (struct fecha* pf);
struct fecha nueva_f(struct fecha* pf,const int dias_s);
void muestra_f(struct fecha* pf);


int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    struct fecha fecha_u, fecha_n;
    puts("Programa que pide una fecha al usuario y luego muestra en pantalla la fecha correspondiente, el número de días del año y si este es bisiesto.");
    puts("Luego se muestra los mismos datos para una fecha 100 días despues.");
    pedir_f(&fecha_u);
    suma_dias(&fecha_u);
    muestra_f(&fecha_u);
    fecha_n=nueva_f(&fecha_u,100);
    muestra_f(&fecha_n);
    return 0;
}

void pedir_f(struct fecha* pf)
{
    puts("Ingrese una fecha (DD/MM/AAAA): ");
    pf->dia=LeerEntero("");
    pf->mes=LeerEntero("");
    pf->anyo=LeerEntero("");
}

void calcula_m_d (struct fecha* pf)
{
    int dias=0,i=0;
    dias=pf->dias;
    for (i = 0;(pf->bisiesto&&i==1)?dias>dias_meses[i]+1: dias>dias_meses[i]; i++)
    {
        dias-=dias_meses[i];
        if(pf->bisiesto&&i==1) dias--;
    }
    
    pf->mes=i+1;
    pf->dia=dias;
}
void suma_dias (struct fecha* pf)
{
    int dias=pf->dia;
    pf->bisiesto=esBisiesto(pf->anyo);
    for (int i = 0; i < pf->mes-1; i++)
        dias+=dias_meses[i];
    if (pf->bisiesto && dias > 31 + 29)
        pf->dias = dias + 1;
    else
        pf->dias = dias;
}


struct fecha nueva_f(struct fecha* pf,const int dias_s)
{
    struct fecha nf;
    nf.dias=pf->dias + dias_s;
    if (nf.dias>366&&pf->bisiesto)
    {
        nf.dias-=366;
        nf.anyo=pf->anyo+1;
    }
    else if(nf.dias>365&&!pf->bisiesto) 
    {
        nf.dias-=365;
        nf.anyo=pf->anyo+1;
    }
    else
        nf.anyo=pf->anyo;
    nf.bisiesto=esBisiesto(nf.anyo);
    calcula_m_d(&nf);
    return nf;
}

void muestra_f(struct fecha* pf)
{
    printf("%d de %s de %d.\n",pf->dia,meses[pf->mes-1],pf->anyo);
    printf("Día %d del año.\n",pf->dias);
    if(pf->bisiesto) printf("Año bisiesto.\n");
        else printf("Año no bisiesto.\n");
}