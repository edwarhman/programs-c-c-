#include <stdio.h>
#include <locale.h>
#define N 8
#define n (N+1)
int tablero[n][n];
int d[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
void escribeTablero();
void saltocaballo(int i, int x, int y, int *exito);
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"spanish");
    int x,y;
    int solucion;
    int i,j;
    //pedir coordenadas iniciales
    do
    {
        printf("Coordenadas iniciales del caballo: ");
        scanf("%d %d",&x, &y);
    } while (x < 1 || x > N || y < 0 || y > N);
    //Valores iniciales del tablero
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            tablero[i][j]=0;
    // Posicion inicial
    tablero[x][y]=1;
    solucion=0;
    saltocaballo(2,x,y,&solucion);
    if (solucion)
    {
        puts("\n\tEl problema tiene solución.\n");
        escribeTablero();
    }
    else
        puts("no se ha encontrado solución al problema");
    return 0;
}
void saltocaballo(int i, int x, int y, int *exito)
{
    int nx, ny;
    int k;
    *exito = 0;
    k = 0;
    do
    {
        k++;
        nx = x + d[k - 1][0];
        ny = y + d[k - 1][1];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && tablero[nx][ny] == 0)
        {
            tablero[nx][ny] = i;
            if (i < N * N)
            {
                saltocaballo(i + 1, nx, ny, exito);
                if (!*exito)
                    tablero[nx][ny]=0;
                escribeTablero();
                printf("\n");
            }
            else
                *exito = 1;
        }
    } while ((k < 8) && !*exito);
}
void escribeTablero()
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            printf("%d %c", tablero[i][j], (j < N ? ' ' : '\n'));
}
