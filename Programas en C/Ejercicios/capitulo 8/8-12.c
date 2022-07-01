#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DISTRITOS 5
#define CANDIDATOS 4

struct candidatos
{
    char nombre;
    int votos;
    float porcentaje;
    int ganador;

};
struct elecciones
{
    int resultados[DISTRITOS][CANDIDATOS];
    int votos;
    struct candidatos candidato[CANDIDATOS];
    int ganador;
} e_alcalde;
void mostrar_t(int T[DISTRITOS][CANDIDATOS]);
void copiar_m (int [DISTRITOS][CANDIDATOS], int [DISTRITOS][CANDIDATOS]);
void votos_c (struct elecciones *e);
int cal_vt (struct elecciones *e);
void ordenar(struct elecciones *e);
void mostrar_vC(struct elecciones *e);
int main(int argc, char const *argv[])
{
    int res_e[DISTRITOS][CANDIDATOS]={
        194, 48, 206, 45,
        180, 20, 320, 16,
        221, 90, 140, 20,
        432, 50 ,821, 14,
        820, 61, 946, 18,
    };
    copiar_m(e_alcalde.resultados,res_e);
    mostrar_t(e_alcalde.resultados);
    votos_c(&e_alcalde);
    e_alcalde.votos= cal_vt(&e_alcalde);
    mostrar_vC(&e_alcalde);
    if (e_alcalde.ganador > 0)
    {
        printf("El ganador es el candidato %c.\n",e_alcalde.candidato[e_alcalde.ganador]);
    }
    else
    {
        ordenar(&e_alcalde);
        printf("Los dos candidatos que pasan a la segunda ronda son:\n\t%s\n\t%s\n",e_alcalde.candidato[0],e_alcalde.candidato[CANDIDATOS-1]);
    }
    
    
    return 0;
}

void mostrar_t(int T[DISTRITOS][CANDIDATOS])
{
    printf("Distrito");
    for (int k = 0; k < CANDIDATOS; k++)
        printf("\tCandidato %c", 'A' + k);
    for (int j = 0; j < DISTRITOS; j++)
    {
        printf("\n%d", j + 1);
        for (int i = 0; i < CANDIDATOS; i++)
            printf("\t\t%d", T[j][i]);
    }
}
void copiar_m (int mc[DISTRITOS][CANDIDATOS], int mo[DISTRITOS][CANDIDATOS])
{
    for (int i = 0; i < CANDIDATOS; i++)
    {
        for (int j = 0; j < DISTRITOS; j++)
        {
            mc[j][i]=mo[j][i];
        }
    }
}
void votos_c (struct elecciones *e)
{
    int suma = 0;
    for (int i = 0; i < CANDIDATOS; i++)
    {
        
        suma = 0;
        for (int j = 0; j < DISTRITOS; j++)
        {
            suma += e->resultados[j][i];
        }
        e->candidato[i].votos=suma;
    }
}
int cal_vt (struct elecciones *e)
{
    int total = 0;
    for (int i = 0; i < CANDIDATOS; i++)
    {
        total += e->candidato[i].votos;
    }
    for (int i = 0; i < CANDIDATOS; i++)
    {
        e->candidato[i].porcentaje = (float)e->candidato[i].votos*100/total;
        if (e->candidato[i].porcentaje>50)
        {
            e->candidato[i].ganador=1;
            e->ganador=i;
        }
    }
    return total;
}

void ordenar(struct elecciones *e)
{
    for (int i = CANDIDATOS-1; i >0; i--)
    {
        for (int j = 0; i > j; j++)
        {
            if (e->candidato[j].votos>e->candidato[j+1].votos)
                e->candidato[j] = e->candidato[j + 1];
        }
        
    }
    
}
void mostrar_vC(struct elecciones *e)
{
    char j;
    printf("\nResultados de cada candidato:\n");
    for (int i = 0, j='A'; i < CANDIDATOS; i++, j++)
    {
        e->candidato[i].nombre=j;
        printf("Candidato %c: %d votos, %.2f\n",e->candidato[i].nombre,e->candidato[i].votos,e->candidato[i].porcentaje);
    }
    
}

