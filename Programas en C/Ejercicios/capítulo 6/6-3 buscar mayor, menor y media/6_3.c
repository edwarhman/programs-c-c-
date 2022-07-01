#include <stdio.h>
#include <locale.h>

int Pedir_dato(char mensaje[64]);
int Buscar_mayor(int dato,int ciclo);
int Buscar_menor(int dato,int ciclo);

int main(int argc, char const *argv[])
{
    int suma, mayor_n, menor_n, N, numero;
    float media = 0.0f;
    setlocale(LC_CTYPE,"spanish");
    suma=mayor_n=menor_n=N=numero=0;
    puts("Programa que indica el número mayor, el número menor y la media entre una serie de números suministrados por el usuario.");
    N=Pedir_dato("Por favor ingrese la cantidad de datos que desea evaluar: ");
    printf("Ingrese los %d números: ",N);
    for (int i = 1; i <= N; i++)
    {
        //numero=Pedir_dato("Ingrese el número: ");
        scanf("%d",&numero);
        mayor_n=Buscar_mayor(numero,i);
        menor_n=Buscar_menor(numero,i);
        suma+=numero;
    }
    media=(float)suma/N;
    printf("El número mayor es: %d\n",mayor_n);
    printf("El número menor es: %d\n",menor_n);
    printf("La media entre los números es: %.2f\n",media);
    

    return 0;
}
int Pedir_dato(char mensaje[64])
{
    int numero = 0;
    char cadena[64];
    for(;;)
    {
        printf(mensaje);
        scanf("%d",&numero);
        if (numero >= 0)
            break;
        scanf("%s",cadena);
        puts("Dato inválido.");
        return numero;
    }
}
int Buscar_mayor(int numero,int ciclo)
{
    static int mayor;
    if (mayor < numero||ciclo==1)
        mayor = numero;
    return mayor;
}
int Buscar_menor(int numero,int ciclo)
{
    static int menor;
    if ((menor > numero)||ciclo==1)
        menor = numero;
    return menor;
}
