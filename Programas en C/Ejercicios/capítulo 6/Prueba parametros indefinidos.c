#include <locale.h>
#include <stdio.h>
#include <stdarg.h>

void maximo(int n, ...);
int main()
{
    setlocale(LC_CTYPE,"spanish");
    puts("Primera busqueda del máximo");
    maximo(6,3.0,4.0,-12.5,1.2,4.5,6.4);
    puts("Nueva busqueda del máximo");
    maximo(4,5.4,17.8,5.9,-17.99);
    return 0;
}

void maximo(int n, ...)
{
    double mx, actual;
    va_list puntero;
    va_start(puntero,n);
    mx=actual=va_arg(puntero,double);
    printf("\tArgumento actual: %.2f\n",actual);
    for (int i = 2; i <=n; i++)
    {
        actual=va_arg(puntero,double);
        printf("\tArgumento actual: %.2f\n",actual);
        if (actual>mx)
        {
            mx=actual;
        }  
    }
    printf("\tEl máximo de la lista de %d números es: %.2f\n",n,mx);
    va_end(puntero);
}