#include <stdio.h>
#include "C:/Users/Emerson/Documents/Programas en C/Headers/misHeaders.h"
#define ACE 9.8f
int main(int argc, char const *argv[])
{
    float H, h, Vo,Vf;
    h=H=Vf=Vo=0;
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que lee la altura desde la que cae un objeto y muestra el valor de la velocidad y la altura a cada segundo.");
    H=LeerEntero("Ingrese la altura inicial del objeto: ");
    for (int t = 0; h>0; t++)
    {
        Vf=Vo+ACE*t;
        h=H-Vf*t;
        printf("%d\t%.2f\t%.2f\n",t,h,Vf);
    }
    
    
    return 0;
}
