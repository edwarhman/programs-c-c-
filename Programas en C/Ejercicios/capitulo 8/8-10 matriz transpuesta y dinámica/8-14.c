#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct vendedor
{
    int *modelo;
    int total;
}Vendedor;
struct autos
{
    Vendedor *vendedor;
    int *modelo;
    int modelos;
    int vendedores;
    int total;
    int ganador;
};
int* asig_modelos(int);
void asig_ven(struct autos *p);
void mostrar_d(struct autos *p);
void ingresar_d(struct autos *p);
void suma (int valor, int *total);
void calculos(struct autos *p);
void buscar_mayor(struct autos *p);
int main(int argc, char const *argv[])
{
    Vendedor *vendedores;
    struct autos Autos;
    asig_ven(&Autos);
    vendedores=Autos.vendedor;
    ingresar_d(&Autos);
    calculos(&Autos);
    buscar_mayor(&Autos);
    mostrar_d(&Autos);
    return 0;
}
int* asig_modelos(int cantidad)
{   int *p;
    p = (int*)malloc(sizeof(int)*cantidad);
    return p;
}
void asig_ven(struct autos *p)
{
    int cantidad;
    printf("Ingrese la cantidad de modelos que vende la empresa: ");
    scanf("%d",&p->modelos);
    printf("Ingrese la cantidad de vendedores de la empresa: ");
    scanf("%d",&cantidad);
    p->vendedores=cantidad;
    p->vendedor = (Vendedor*)malloc(sizeof(Vendedor)*cantidad);
    for(int i=0 ; i < cantidad; i++)
    {
        p->vendedor[i].modelo = asig_modelos(p->modelos);
    }
    p->modelo = asig_modelos(p->modelos);
}
void mostrar_d(struct autos *p)
{
    printf("\nvendedor");
    for (int i = 0; i < p->modelos; i++)
    {
        printf("\t    modelo %d",i+1);
    }
    printf("\t\ttotal");
    for (int i = 0; i < p->vendedores; i++)
    {
        printf("\nvendedor %d",i+1);
        for (int j = 0; j < p->modelos; j++)
        {
            printf("\t\t%d",p->vendedor[i].modelo[j]);
        }
        printf("\t\t%d",p->vendedor[i].total);
    }
    printf("\n\t");
    for (int i = 0; i < p->modelos; i++)
    {
        printf("\t\t%d",p->modelo[i]);
    }
    printf("\t\t%d",p->total);
    printf("\nEl ganador del premio al mayor vendedor es el vendedor %d.",p->ganador);
}
void ingresar_d(struct autos *p)
{
    for (int i = 0; i < p->vendedores; i++)
    {
        printf("\nModelos vendidos por vendedor %d: ",i+1);
        for (int j = 0; j < p->modelos; j++)
        {
            scanf("%d",&p->vendedor[i].modelo[j]);
            if (i==0) p->modelo[j]=0;
        }
        p->vendedor[i].total=0;
    }
    
}
void suma (int valor, int *total)
{
    *total+=valor;
}

void calculos(struct autos *p)
{
    for (int i = 0; i < p->vendedores ; i++)
    {
        for (int j = 0; j < p->modelos; j++)
        {
            suma(p->vendedor[i].modelo[j],&p->vendedor[i].total);
        }
        suma(p->vendedor[i].total,&p->total);
    }
    for (int i = 0; i < p->modelos; i++)
    {
        int cuenta=0;
        for (int j = 0; j < p->vendedores; j++)
        {
            suma(p->vendedor[j].modelo[i], &p->modelo[i]);
        }
        
    }
    
}

void buscar_mayor(struct autos *p)
{
    int mayor=0;
    for (int i = 0; i < p->vendedores; i++)
    {
        if(p->vendedor[i].total>mayor)
            p->ganador=i+1;
    }
    
}