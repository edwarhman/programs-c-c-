#include "Arreglos.h"
#include <stdexcept>
#include <iomanip>
using namespace std;

//Constructor predeterminado de la clase Array
Arreglos::Arreglos(int elementos)
:tamanio(elementos>0?elementos:throw invalid_argument("El tama�o del arreglo debe ser mayor a 0.")),
 ptr(new int[tamanio])
{
    for (size_t i = 0; i < tamanio; i++)
    {
        ptr[i] = 0;
    }
    
    
} //Fin constructor predeterminado

//Constructor por copia de la clase array
Arreglos::Arreglos(const Arreglos &copiaArreglo)
:tamanio(copiaArreglo.tamanio),
 ptr(new int[tamanio])
{
    for (size_t i = 0; i < tamanio; i++)
    {
        ptr[i] = copiaArreglo[i];
    }
    
}//Fin constructor por copia de la clase Arreglos

//destructor de la classe Arreglo
Arreglos::~Arreglos()
{
    delete [] ptr;
} //Fin del destructor

//Funcion que obtiene el tama�o del arreglo
size_t Arreglos::obtenerTamanio() const
{
    return tamanio;
}

//Operador de igualdad =
const Arreglos &Arreglos::operator=(const Arreglos &array2)
{
    //Comprueba que ambos arreglos sean distintos para evitar la autoasignaci�n
    if (this != &array2)
    {
        //Comprueba que el tama�o de los arreglos sea el mismo
        if (this->obtenerTamanio() != array2.obtenerTamanio())
        {
            delete[] ptr;
            tamanio = array2.obtenerTamanio();
            ptr = new int[tamanio];
        }//fin de if que evalua si los tama�os son iguales
        for (size_t i = 0; i < tamanio; i++)
        {
            ptr[i] = array2[i];
        }//fin de for que copia los elementos
    }//fin de if que evita la autoasignaci�n
    return *this;
}//Fin de operador de igualdad

bool Arreglos::operator==(const Arreglos &derecha) const
{
    if (tamanio != derecha.obtenerTamanio())
    {
        return false;
    }
    for (size_t i = 0; i < tamanio; i++)
        if (ptr[i] != derecha[i])
            return false;

    return true;
}

//Operador sub�ndice [] 
int &Arreglos::operator[](int subIndice) 
{
    //evalua si el sub�ndice es adecuado para el arreglo
    if (subIndice < 0 || subIndice >= obtenerTamanio() )
    {
        throw invalid_argument("El sub�ndice no puede ser mayor al tama�o del arreglo ni menor a 0.");
    }//fin de la evaluacion del subindice

    return ptr[subIndice];
}//Fin de operador sub�ndice []

//Operador sub�ndice [] constante
int Arreglos::operator[](int subIndice) const
{
    if (subIndice < 0 || subIndice >= obtenerTamanio() )
    {
        throw invalid_argument("El sub�ndice no puede ser mayor al tama�o del arreglo ni menor a 0.");
    }
    return ptr[subIndice];
} //Fin de operador subindice [] constante

//Operador de salida para la clase Arreglos
ostream &operator<<(ostream &salida, const Arreglos &a)
{
    for (size_t i = 0; i < a.obtenerTamanio(); i++)
    {
        salida << setw(12) << a[i];
        if ((i+1)%4 == 0)
        {
            salida << endl;
        }
        
    }

    if (a.obtenerTamanio()%4 != 0)
    {
        salida << endl;
    }
    
    
    return salida;
}//Fin de operador de salida


//Operador de entrada para la clase Arreglos 
istream &operator>>(istream &entrada, Arreglos &a)
{
    for (size_t i = 0; i < a.obtenerTamanio(); i++)
    {
        entrada >> a[i];
    }
    
    return entrada;
} //Fin de operador de entrada


