#include <stdio.h>
#include <locale.h>


int main(int argc, char const *argv[])
{
    //DECLARACIÓN DE VARIABLES
    int hora,minuto;
    char nada;
    //ENCABEZADO
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que transforma una hora en formato de 24 horas al formato de 12 horas.\n");
    //Entrada de datos
    for(;;)
    {
        printf("Por favor ingrese la hora (hh:mm): ");
        scanf("%d %c %d",&hora,&nada,&minuto);
        if ((hora>=0||hora<24)&&(minuto>=0||minuto<60)) break;
            else printf("Hora inválida, por favor verifíquela.\n");
    }
    //printf("hora: %d minuto: %d",hora,minuto);
    
    if (hora>=12)
    {
        if (hora==12)
        {
            printf("La hora es %d:%d P.M\n",hora,minuto);
        }else printf("La hora es %d:%d P.M\n",hora-12,minuto);
        
    }else printf("La hora es %d:%d A.M\n",hora,minuto);
    
    return 0;
}
