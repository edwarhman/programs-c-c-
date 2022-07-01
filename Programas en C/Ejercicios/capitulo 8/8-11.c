#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C:\Users\Emerson\Documents\Programas en C\Headers\misheaders.h"
#define R_MAX 10
struct array
{
    int *v;
    int r;
};
typedef struct array vector;
enum liberar {no,si};
mostrar_vector(vector L);
llenar_vector(vector L);
int nuevo_vector (vector ae, vector *nv);
int main(int argc, char const *argv[])
{
    srand(time(0));
    rand();
    vector A, B;
    int e_mod;
    A.r=B.r=R_MAX;
    A.v=(int*)malloc(R_MAX*sizeof(int));
    //B.v=(int*)malloc(R_MAX*sizeof(int));
    llenar_vector(A);
    mostrar_vector(A);
    e_mod=nuevo_vector(A,&B);
    printf("\n");
    mostrar_vector(B);
    printf("\nElementos modificados %d",e_mod);
    return 0;
}

llenar_vector(vector L)
{
    for (int i = 0; i < L.r; i++)
    {
        L.v[i]=random(0,R_MAX);
    }
    
}
mostrar_vector(vector L)
{
    for (int i = 0; i < L.r; i++)
    {
        printf("%d\t",L.v[i]);
    }
    
}

int nuevo_vector (vector ae, vector *nv)
{
    int liberar=si, em=0, tam=0;
    tam=sizeof(int)*nv->r;
    nv->v=(int*)malloc(tam);
    nv->v[0]=ae.v[0];
    
    for (int i = 1, j=0; i < ae.r; i++)
    {
        nv->v[i] = ae.v[i];
        for (j = 0; i > j; j++)
        {
            if (ae.v[i] == ae.v[j])
            {
                nv->v[i] = -5;
                em++;
                liberar = no;
                break;
            }
        }
    }
    if(liberar) free(nv->v);
    return em;
}
