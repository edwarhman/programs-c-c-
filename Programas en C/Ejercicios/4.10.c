#include <stdio.h>

float entrada=0,min=0,seg=0;
const valor_segundos=60;

int main(int argc, char const *argv[])
{
    printf("%d",valor_segundos);
    printf("Programa que pide un tiempo en segundos y lo transforma a minutos y segundos\nIngrese los segundos:");
    scanf("%f",&entrada);
    min=entrada/valor_segundos;
    seg=valor_segundos*(min-(int)min);
    printf("%f segundos equivale a %d:%d ",entrada,(int)min,(int)seg);
    return 0;
}
