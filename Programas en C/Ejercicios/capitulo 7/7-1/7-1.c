#include <stdio.h>
char moverCaracter(int* x, int* y);
int main(int argc, char const *argv[])
{
    int 
        x=205/2,
        y=56/2;
    char caracter='C',finaliza=' ';
    char matriz[56][205];
    for (int i = 0; i < 56; i++)
    {
        for (int j = 0; j < 205; j++)
        {
            matriz[i][j]=' ';
        }
    }
    matriz[y][x]=caracter;
    do
    {
        printf("\n");
        for (int i = 0; i < 56; i++)
        {
            if(i==y)
            {
                for (int j = 0; j < 205; j++)
                {
                    printf("%c", matriz[i][j]);
                }
            }else printf("\n");
        }
        matriz[y][x]=0;
        finaliza=moverCaracter(&x,&y);
        matriz[y][x]=caracter;
    } while (finaliza!='f');
    
    
    
    return 0;
}
char moverCaracter(int* x, int* y)
{
    printf("\nHacia donde se mueve? (a,b,i,d): ");
    char accion;
    scanf("%c",&accion);
    switch (accion)
    {
    case 'a':
        *y=*y-1;
        break;
    case 'b':
        *y=*y+1;
        break;
    case 'i':
        *x=*x-1;
        break;
    case 'd':
        *x=*x+1;
        break;
    
    default:
        break;
    }
    return accion;
}