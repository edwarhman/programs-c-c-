#include <stdio.h>
#include <locale.h>
#define COUNT 4
int main(int argc, char const *argv[])
{
    float nota,total,media;
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que muestra la calificaci�n final de un estudiante seg�n las notas suministradas.\n");
    for (size_t i = 1; i <= COUNT; i++)
    {
        printf("Ingrese la nota: ");
        scanf("%f",&nota);
        total=total+nota;
    }
    media=total/COUNT;
    switch ((int)(media/10))
    {
    case 0: case 1: case 2: case 3: case 4: case 5:
        printf("La calificaci�n es F.\n");
        break;
    case 6:
        printf("La calificaci�n es D.\n");
        break;
    case 7:
        printf("La calificaci�n es C.\n");
        break;
    case 8:
        printf("La calificaci�n es B.\n");
        break;
    case 9:
        printf("La calificaci�n es A.\n");
        break;
    default:
        break;
    }
    return 0;
}
