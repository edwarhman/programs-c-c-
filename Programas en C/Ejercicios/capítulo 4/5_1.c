#include <stdio.h>
#include <locale.h>
#define COUNT 4
int main(int argc, char const *argv[])
{
    float nota,total,media;
    setlocale(LC_CTYPE,"spanish");
    printf("Programa que muestra la calificación final de un estudiante según las notas suministradas.\n");
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
        printf("La calificación es F.\n");
        break;
    case 6:
        printf("La calificación es D.\n");
        break;
    case 7:
        printf("La calificación es C.\n");
        break;
    case 8:
        printf("La calificación es B.\n");
        break;
    case 9:
        printf("La calificación es A.\n");
        break;
    default:
        break;
    }
    return 0;
}
