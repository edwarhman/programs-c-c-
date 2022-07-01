#include <stdio.h>
#include <locale.h>
int Ciclo_apareamiento(int condicion, int evaluador);
void Meses_paraConejos();
void Conejos_poryear();
int Pedir_dato(char mensaje[30]);
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    int conejos_d=0;
    puts("Programa que indica, según el problema de Fibonacci, cuantos conejos habrá despues de un año de apareamientos habiendo empezado con dos conejos.");
    puts("También calcula cuantos meses son necesarios para obtener una cantidad de conejos especificada por el usuario.");
    Conejos_poryear();
    Meses_paraConejos();
    return 0;
}

int Ciclo_apareamiento(int condicion, int evaluador)
{
    static int  conejos_T,
                conejos_N,
                conejos_V;
    //printf("condicion %d\tevaluador %d\t",condicion,evaluador);
    if (evaluador<=condicion)
    {
        conejos_T = 2,
        conejos_N = 0,
        conejos_V = 2;
    }
    
    conejos_N=conejos_V;
    conejos_V=conejos_T;
    conejos_T=conejos_N+conejos_V;
    //("%d\t%d\t%d\n",conejos_N,conejos_V,conejos_T);
    return conejos_T;
}

void Conejos_poryear()
{
    int Total=0;
    for (int i = 1; i <= 12; i++)
    {
        //printf("%d\t",i);
        Total=Ciclo_apareamiento(1,i);
    }
    printf("Al cabo de un año hay un total de %d conejos.\n",Total);
}
void Meses_paraConejos()
{
    int conejos_d=0;
    conejos_d=Pedir_dato("Ingrese la cantidad de conejos deseados: ");
    int meses=1,
        total=0;
    while (total < conejos_d)
    {
        total = Ciclo_apareamiento(1,meses);
        meses++;
    }
    printf("Para tener %d conejos son necesarios %d meses.\n",conejos_d,meses-1);
}
int Pedir_dato(char mensaje[30])
{
    int dato=0;
    char entrada;
    for (;;)
    {
        printf(mensaje);
        scanf("%d",&dato);
        //printf("%d",dato);
        if(dato<1)
        {
            scanf("%c",&entrada);
            puts("Dato inválido.");
        } else
        {
            break;
        }
        
    }
}