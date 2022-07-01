#include <stdio.h>
#include <C:\Users\Emerson\Documents\Programas en C\Headers\misheaders.h>
#define MAX 255

struct coordenadas
{
    int x,
        y;
};
struct array
{
    int valor[MAX][MAX];
    struct coordenadas dimensiones,mayor,menor;
}matriz;
typedef struct array arreglo;

void encontrar_mm(arreglo* M);
void leer_m(arreglo* M);
void mostrar_m(const arreglo* M);
void mostrar_res(arreglo* M);

int main(int argc, char const *argv[])
{   
    setlocale(LC_CTYPE,"spanish");
    puts("Programa que muestra una matriz de dimensiones y valores dados por el usuario. Así como tambien cual es el valor mayor y el menor y sus respectivas posiciones.");
    matriz.dimensiones.y=LeerEntero("Ingrese el número de filas: ");
    matriz.dimensiones.x=LeerEntero("Ingrese el número de columnas: ");
    leer_m(&matriz);
    mostrar_m(&matriz);
    encontrar_mm(&matriz);
    mostrar_res(&matriz);
    return 0;
}
void leer_m(arreglo* M)
{
    int valor=0;
    for (int j = 0; j < M->dimensiones.y; j++)
    {
        printf("Ingrese los datos de la fila %d: ",j+1);
        for (int i = 0; i < M->dimensiones.x; i++)
        {
            scanf("%d",&valor);
            M->valor[i][j] = valor;
        }
        
    }
    
}
void mostrar_m(const arreglo *M)
{
    for (int j = 0; j < M->dimensiones.y; j++)
    {
        for (int i = 0; i < M->dimensiones.x; i++)
        {
            printf("%d\t", M->valor[i][j]);
        }
        printf("\n");
        
    }
}

void encontrar_mm(arreglo *M)
{
    int mayor = 0, menor = 32000, valor = 0;
    
    for (int j = 0; j < M->dimensiones.y; j++)
    {
        for (int i = 0; i < M->dimensiones.x; i++)
        {
            valor = M->valor[i][j];
            
            if ((valor > mayor) || (i < 1 && j < 1))
            {
                M->mayor.x = i;
                M->mayor.y = j;
                mayor=valor;
            }
            if ((valor < menor) || (i < 1 && j < 1))
            {
                M->menor.x = i;
                M->menor.y = j;
                menor=valor;
            }
        }
    }
}

void mostrar_res(arreglo* M)
{
    int mayor=0 , menor=0, i=0, j=0;
    i=M->mayor.x;
    j=M->mayor.y;
    printf("\nEl número mayor de la matriz se encuentra en la posición (%d,%d) y su valor es %d.",i+1,j+1,M->valor[i][j]);
    i=M->menor.x;
    j=M->menor.y;
    printf("\nEl número menor de la matriz se encuentra en la posición (%d,%d) y su valor es %d.",i+1,j+1,M->valor[i][j]);
    
}