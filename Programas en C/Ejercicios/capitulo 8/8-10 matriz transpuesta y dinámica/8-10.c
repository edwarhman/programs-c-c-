#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//DECLARACIONES GLOBALES
int m=0, n=0;

enum tipo_matriz {normal,transpuesta};
//PROTOTIPOS DE FUNCIONES
void pedir_dim(int**);
void llenar_m(int**);
void mostrar_m(int** ,int);
void intercambiar();
//FUNCIÓN PRINCIPAL
int main(int argc, char const *argv[])
{
    int** matriz_a;
    pedir_dim(matriz_a);
    llenar_m(matriz_a);
    mostrar_m(matriz_a,normal);
    intercambiar();
    mostrar_m(matriz_a,transpuesta);
    return 0;
}
//FUNCIONES SECUNDARIAS
void pedir_dim(int** matriz)
{
    do
    {
        printf("Ingrese la cantidad de filas: ");
        scanf("%d",&n);
    } while (n<=0);
    
    matriz=(int**)malloc(n*sizeof(int*));
    do
    {
        printf("Ingrese la cantidad de columnas: ");
        scanf("%d",&m);
    } while (m<=0);

    for (int i = 0; i < n; i++)
    {
        matriz[i]=(int*)malloc(m*sizeof(int));
    }
    

}
void llenar_m(int** matriz)
{
    for (int j = 0; j < n; j++)
    {
        printf("Ingrese los valores de la fila %d: ",j+1);
        for (int i = 0; i < m; i++)
        {
            //scanf("%d",&matriz[j][i]);
            matriz[j][i]=j;
            printf("%d ",matriz[j][i]);
        }
        
    }
}

void mostrar_m(int** matriz,int tipo)
{
    printf("\n");
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if(tipo==normal)
                printf("%d\t", matriz[j][i]);
            else if (tipo==transpuesta)
                printf("%d\t", matriz[i][j]);

        }
        printf("\n");
    }
}

void intercambiar()
{
    int aux=0;
    aux=m;
    m=n;
    n=aux;
    
}