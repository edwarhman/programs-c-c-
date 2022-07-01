#include <array>
#include <iostream>
//#include <cstddef>
#define TAM_ARRAY 20
using namespace std;
int pedirDatos(array<int,TAM_ARRAY> &a);
void mostrarElementosArreglo(array<int,TAM_ARRAY> a, int elementos);
bool evaluarAnteriores(array<int,TAM_ARRAY> a, int elementos, int entrada);
int main()
{
    array<int, TAM_ARRAY> arreglo;
    int elementos;
    elementos = pedirDatos(arreglo);
    mostrarElementosArreglo(arreglo, elementos);

    return 0;
}

int pedirDatos(array<int,TAM_ARRAY> &a)
{
    int entrada = 0;
    int contador = 0;
    cout << "Por favor ingrese los datos del array: ";
    for (size_t i = 0; i < a.size(); i++)
    {
        cin >> entrada;
        if (( 0== i) || !evaluarAnteriores(a,contador,entrada))
        {
            a[contador] = entrada;
            contador++;
            //cout << a[i] << " " << contador << " ";
        }
    }
    return contador;
}

void mostrarElementosArreglo(array<int,TAM_ARRAY> a, int elementos)
{
    for (int i = 0; i < elementos; i++)
    {
        cout << a[i] << " ";
    }
    
}

bool evaluarAnteriores(array<int,TAM_ARRAY> a, int elementos, int entrada)
{
    bool seRepite = false;
    for (int i = 0; i < elementos; i++)
    {
        if (a[i] == entrada)
        {
            seRepite = true;
        }
        
    }
    return seRepite;
}