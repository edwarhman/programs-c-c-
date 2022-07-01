#include <locale.h>
#include <stdio.h>
#define tam_list 10
void mostrarEntero(int* lista[60],int elementos);
int main(int argc, char const *argv[])
{
    int lista[tam_list];
    int numero=55;
    mostrarEntero(lista,tam_list);
    mostrarEntero(&numero,0);
    printf("\n%d",numero);
    return 0;
}

void mostrarEntero(int* lista[60],int elementos)
{
    if (elementos>0)
    {
        for (int i = 0; i < elementos; i++)
        {
            lista[i] = i;
            printf("\t%d",lista[i]);
        }
    }else
    {
        printf("\n%d",*lista[0]);
        *lista[0]=99;
        printf("\n%d",*lista[0]);
    }
    
    
    
}
