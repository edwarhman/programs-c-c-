#include <stdio.h>
//#include <locale.h>
#include "C:/Users/Emerson/Documents/Programas en C/Headers/misHeaders.h"  
int main()
{
    int N=0;
    setlocale(LC_CTYPE,"spanish");
    N=LeerEntero("Ingrese un entero: ");
    //printf("%d",N);
    puts("");
    for (int i = 1,j=1; i >= 1; (j++<N)?i++:i--)
    {
        for (int k = 1; k <= i; k++)
        {
            printf("%d\t",k);
        }
        puts("");
    }
    
    return 0;
}
