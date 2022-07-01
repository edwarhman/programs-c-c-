#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <C:\Users\Emerson\Documents\Programas en C\Headers\misheaders.h>
#define S 10
#define NUM 99

struct arreglo
{
    int *v;
    int n;
};
typedef struct arreglo Vector;

void gen_array(Vector* inic);
void escribe_array(Vector W);
void nuevo_array(Vector inic, Vector *nd);
int main(int argc, char const *argv[])
{
    Vector prim,dest;
    setlocale(LC_CTYPE,"spanish");
    prim.n=LeerEntero("Números de elementos del array: ");
    printf("%d",prim.n);
    gen_array(&prim);
    escribe_array(prim);
    nuevo_array(prim,&dest);
    escribe_array(dest);
    return 0;
}
void gen_array(Vector* inic)
{
    int k,valor;
    inic->v=(int*)calloc(inic->n,sizeof(int));
    printf("\nIngrese %d valores al arreglo: ",inic->n);
    for ( k = 0; k < inic->n; k++)
    {
        scanf("%d",&inic->v[k]);
    }
}

void escribe_array(Vector W)
{
    printf("\nValores que contiene el vector: ");
    for (int i = 0; i < W.n; i++)
    {
        printf("%d ",W.v[i]);
    }
    
}
void nuevo_array(Vector inic, Vector *nd)
{
    int k,tam;
    nd->v=NULL;
    tam=sizeof(int)*S;
    nd->v=(int*)realloc(nd->v,tam);
    nd->v[0]=inic.v[0];
    nd->n=1;
    for(k=1;k<inic.n;k++)
    {
        int j,dup;
        j=dup=0;
        while ((j<nd->n)&&!dup)
        {
            dup=inic.v[k]==nd->v[j++];
        }
        if(!dup)
        {
            if(nd->n%S==0)
            {
                tam+=sizeof(int)*S;
                nd->v=(int*)realloc(nd->v,tam);
            }
            nd->v[nd->n++]=inic.v[k];
        }
    }
}
