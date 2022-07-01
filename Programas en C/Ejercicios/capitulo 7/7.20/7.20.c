#include <stdio.h>
#include <C:\Users\Emerson\Documents\Programas en C\Headers\misheaders.h>
#define NUM_VERTICES 3
struct coordenadas
{
    float x;
    float y;
};

struct triangulo
{
    struct coordenadas vertices[NUM_VERTICES];
    struct coordenadas pinternos[100];
    float medianas[3];
    int c_puntos;
} T1;

void MuestraPuntos(struct triangulo* p);
void pidevertices(struct triangulo *p);
void intercambiar(float *a, float *b);
void ordenar(struct triangulo *p);
void calculaMediana(struct triangulo *p);
void encuentraPuntos(struct triangulo *p);

int main(int argc, char const *argv[])
{
    pidevertices(&T1);
    ordenar(&T1);
    calculaMediana(&T1);
    encuentraPuntos(&T1);
    MuestraPuntos(&T1);
}

void pidevertices(struct triangulo *p)
{
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        printf("%d: ingrese las coordenadas x e y del vertice: ", i+1);
        p->vertices[i].x = LeerEntero("");
        p->vertices[i].y = LeerEntero("");
    }
}

void intercambiar(float* a, float* b)
{
    float aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenar(struct triangulo *p)
{
    for (int i = NUM_VERTICES - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (p->vertices[j].x > p->vertices[j + 1].x)
            {

                intercambiar(&p->vertices[j].x, &p->vertices[j + 1].x);
                intercambiar(&p->vertices[j].y, &p->vertices[j + 1].y);
            }
        }
    }
}

void calculaMediana(struct triangulo *p)
{
    p->medianas[0] = (p->vertices[0].y - p->vertices[2].y) / (p->vertices[0].x - p->vertices[2].x);
    p->medianas[1] = (p->vertices[0].y - p->vertices[1].y) / (p->vertices[0].x - p->vertices[1].x);
    p->medianas[2] = (p->vertices[1].y - p->vertices[2].y) / (p->vertices[1].x - p->vertices[2].x);
}

void encuentraPuntos(struct triangulo *p)
{
    float y, y0;
    int k;
    y = y0 = k = 0;
    for (int i = p->vertices[0].x; i <= p->vertices[2].x; i++)
    {
        y0 = p->medianas[0] * (i - p->vertices[0].x) + p->vertices[0].y;
        if (i < p->vertices[1].x)
        {
            y = p->medianas[1] * (i - p->vertices[1].x) + p->vertices[1].y;
        }
        else
            y = p->medianas[2] * (i - p->vertices[2].x) + p->vertices[2].y;
        if (y0 > y) intercambiar(&y0 , &y);

        for (int j = (y0 - (int)y0 > 0) ? y0 + 1 : y0; (j <= y); j++)
        {
            p->pinternos[k].x = i;
            p->pinternos[k].y = j;
            k++;
        }
    }
    p->c_puntos=k;
}

void MuestraPuntos(struct triangulo* p)
{
    for (int i = 0; i < p->c_puntos; i++)
    {
        printf("(%.2f,%.2f) ",p->pinternos[i].x,p->pinternos[i].y);
    }
    
}