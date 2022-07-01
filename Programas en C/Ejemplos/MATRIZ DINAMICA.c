#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <C:\Users\Emerson\Documents\Programas en C\Headers\misheaders.h>
#define A_MAX 50
#define A_MIN 0
struct coordenadas
{
    int filas;
    int columnas;
};
typedef struct coordenadas coor;
struct arreglo
{
    int **Matriz;
    coor d;
};
typedef struct arreglo matriz;
enum m_matriz {MATRIZ,INVERSO};
//PROTOTIPOS
pedir_dim(matriz *m);
generar_array(matriz *m);
muestra_array(matriz m,int);
int main(int argc, char const *argv[])
{
    srand(time(0));
    rand();
    matriz M;
    pedir_dim(&M);
    //intercambiar(&M.d.filas,&M.d.columnas);
    printf("Matriz de dimensiones %dx%d\n",M.d.columnas,M.d.filas);
    
    generar_array(&M);
    muestra_array(M,MATRIZ);
    puts("");
    muestra_array(M,INVERSO);
    puts("");
    muestra_array(M,MATRIZ);
    return 0;
}
pedir_dim(matriz *m)
{
    m->d.filas=LeerEntero("Ingrese la cantidad de filas: ");
    m->d.columnas=LeerEntero("Ingrese la cantidad de columnas: ");
}

generar_array(matriz *m)
{
    int j;
    m->Matriz=(int**)malloc(m->d.filas*sizeof(int*));
    for(j=0;j<m->d.filas;j++)
    {
        m->Matriz[j]=(int*)malloc(m->d.columnas*sizeof(int));
        printf("ingrese valores de la fila %d : ",j+1);
        for (int i = 0; i < m->d.columnas; i++)
        {
            scanf("%d",&m->Matriz[j][i]);
        }
        
    }
}

muestra_array(matriz m,int inverso)
{
    
    if (inverso)
        intercambiar(&m.d.columnas, &m.d.filas);
    for (int j = 0; j < m.d.filas; j++)
    {
        for (int i = 0; i < m.d.columnas; i++)
        {
            if (inverso)
                printf("%d ", m.Matriz[i][j]);
            else
                printf("%d ", m.Matriz[j][i]);
        }
        printf("\n");
    }
    m.Matriz[0][0]=15;
}