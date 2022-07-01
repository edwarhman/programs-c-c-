#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define MEM 4
typedef struct mayusculas
{
    int posicion;
    int espacios;
}mayus;
struct texto 
{
    char *cadena;
    int mayusculas;
    mayus *mayuscula;
    float frecuencia;
};
char *asigcad ();
void asig_mem (mayus *p,int i);
void buscar_mayus (struct texto *p);
void cal_freq(struct texto *p);
void mostrar_r(struct texto *p);
int main(int argc, char const *argv[])
{
    struct texto linea;
    setlocale(LC_CTYPE,"spanish");
    linea.cadena = asigcad();
    printf("\n%s",linea.cadena);
    buscar_mayus(&linea);
    cal_freq(&linea);
    mostrar_r(&linea);
    return 0;
}

char *asigcad ()
{
    char cad[150];
    char *p;
    int tam = 0;
    printf("Ingrese una cadena:\n");
    gets(cad);
    tam=sizeof(char)*(strlen(cad)+1);
    p = (char*)malloc(tam);
    if (p == NULL)
    {
        printf("Error de asignación de cadena.\n");
        exit(-1);
    }
    printf("%d vs %d\t",p,tam);
    strcpy(p,cad);
    return p;
}

void asig_mem (mayus *p,int i)
{
    static int tam = 0;
    tam += sizeof(mayus)*MEM;
    p = (mayus*) realloc(p,tam);
}

void buscar_mayus (struct texto *p)
{
    p->mayuscula = (mayus*)malloc(sizeof(mayus));
    int N = 0, i = 0, j = 0;
    N = strlen(p->cadena)+1;
    for (i = 0 , j = 0; i < N; i++)
    {
        if (isupper(p->cadena[i]))
        {
            if (j+1==1 || (j+1)%MEM== 0)
            {
                asig_mem(p->mayuscula,j+1);
            }
            p->mayuscula[j].posicion = i;
            if (j+1==1)
            {
                p->mayuscula[j].espacios=i;
            } else
            {
                p->mayuscula[j].espacios = p->mayuscula[j].posicion - p->mayuscula[j-1].posicion;
            }
            j++;
        }
    }
    p->mayusculas = j;
}

void cal_freq(struct texto *p)
{
    int i = 0 , suma = 0;
    for ( i = 0; i < p->mayusculas; i++)
    {
        suma+= p->mayuscula[i].espacios;
    }
    p->frecuencia = (float)suma / p->mayusculas;
}

void mostrar_r(struct texto *p) // Claramente
{
    //printf("\n%d",p->mayusculas);
    printf("\n%s",p->cadena);
    printf("\n1:\t%c es la primera letra mayuscula, encontrada en la posición %d.",p->cadena[p->mayuscula[0].posicion],p->mayuscula[0].posicion+1);
    for (int i = 1; i < p->mayusculas; i++)
    {
        printf("\n%d:\t%c en la posición %d, %d espacios luego de la anterior letra mayúscula.", i+1, p->cadena[p->mayuscula[i].posicion], p->mayuscula[i].posicion + 1, p->mayuscula[i].espacios);
    }
    printf("\nEl promedio de frecuencia de aparición de las letras mayúsculas es %.2f",p->frecuencia);
    
}