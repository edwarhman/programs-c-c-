#include <iostream>
#include <locale.h>
using namespace std;
//Prototipos de funciones

unsigned long long Exponente(unsigned int b, unsigned int n);
void LeerEntrada(unsigned int &entrada);
//Funcion main
int main()
{
    unsigned int resultado = 0;
    unsigned int base = 0;
    unsigned int exponente = 0;
    setlocale(LC_ALL,"");
    cout << "\nPor favor ingrese la base: ";
    LeerEntrada(base);
    cout << "\nPor favor ingrese el exponente: ";
    LeerEntrada(exponente);
    cout << "\nEl resultado es " << Exponente(base, exponente);


    return 0;

}


//Funciones 

//Funcion que calcula el exponente de los dos numeros suministrados
unsigned long long Exponente(unsigned int b, unsigned int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return b;
    if(b == 0)
        return 0;
    else
        return b * Exponente(b, n-1);
} //Fin de la función exponente

//Funcion que solicita un número al usuario
void LeerEntrada(unsigned int &entrada)
{
    int prueba;

    do
    {
        cin >> prueba;
        if (0 < prueba)
            entrada = prueba;
        else
            cout << "dato inválido. intente otra vez: ";
    } while (prueba < 0);
    
}