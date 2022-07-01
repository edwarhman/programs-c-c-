//PROGRAMA QUE SEPARA LOS DIGITOS DE UN ENTERO Y LOS ALMACENA EN UN ARREGLO. LUEGO, A PARTIR DE LOS DIGITOS, CONSTRUYE EL NUMERO INVERTIDO.
//MUESTRA EL NUMERO ORIGINAL, LOS DIGITOS DEL NUMERO POR SEPARADO, EL NUMERO INVERTIDO Y SI EL NUMERO ES CAPICUA O NO.

#include <iostream>
#include <locale.h>
using namespace std;
// Prototipos funciones 
unsigned int cociente(unsigned int, unsigned int );
unsigned int resto(unsigned int, unsigned int);
//definicion de la clase entero
class Entero
{
private:
    unsigned int entero; //El valor entero a evaluar
    unsigned int invertido; //El valor entero invertido
    unsigned int digito[5]; //Arreglo que contendrá a cada uno de los digitos del arreglo
    unsigned int candidadDigitos; //Variable que almacena la cantidad de digitos del entero
public:
    //Constructor de la clase Entero
    explicit Entero()
    :entero(0), candidadDigitos(0), invertido(0)
    {
        for (int i = 0; i < 5; i++)
        {
            digito[i] = 0;
        }
        
    }; //Fin del constructor

    void establecerEntero(unsigned int valor)
    {
        entero = valor;
    } //Fin de la funcion establecer entero

    unsigned int obtenerEntero() const
    {
        return entero;        
    }//Fin de funcion obtenerEntero

    void establecerDigito(unsigned int posicion, unsigned int valor)
    {
        digito[posicion] = valor;
    } //Fin de funcion establecerDigito

    //Funcion que obtiene el digito especificado por el parametro
    //El argumento no puede ser 0
    unsigned int obtenerDigito(unsigned int posicion) const
    {
        if (posicion <= 0)
        {
            cerr << "\nError. Argumento invalido en la función obtenerDigito. \nargumento obtenido: " << posicion;
            exit(0);
        }
        return digito[posicion-1];
    }   //Fin de funcion obtenerDigito

    void incrementarCantidadDigitos()
    {
        candidadDigitos++;
    }

    unsigned int obtenerCantidadDigitos() const
    {
        return candidadDigitos;
    }

    //Funcion que separa en entero en sus digitos y los almacena en el array digito de la clase
    unsigned int separar(unsigned int numero)
    {
        if (cociente(10, numero) < 1)  //Condicion de finalización de la funcion recursiva
        {
            establecerDigito(0, numero);
            incrementarCantidadDigitos();
        } //Fin de if
        else
        {
            separar(cociente(10, numero));
            establecerDigito(obtenerCantidadDigitos(), resto(10, numero));
            incrementarCantidadDigitos();
            //cout << resto(10,numero) << " ";
        } //fin de else
    } //fin de funcion separar

    void mostrarDigitos() const
    {
        cout << "\nEl número entero " << obtenerEntero() << " tiene los siguientes dígitos: ";
        for (int i = 1; i <= obtenerCantidadDigitos(); i++)
        {
            cout << obtenerDigito(i) << " ";
        } //fin ciclo for
        
        cout << endl;
    } //Fin funcion mostrar digitos

    //Funcion que establece el inverso del numero entero inicial
    void establecerInvertido()
    {
        for (int i = 1, j = 1; i <= obtenerCantidadDigitos(); i++)
        {
            invertido +=  (obtenerDigito(i)*j);
            j*=10;
        }
    }//Fin funcion establecerInvertido

    unsigned int obtenerInvertido() const
    {
        return invertido;
    }

    //Funcion que muestra el número entero invertido
    void mostrarInverso() const
    {
        cout << "\nEl número invertido es: " << obtenerInvertido() << endl;
    } //Fin funcion mostrarInverso

    //Funcion que muestra si el número entero es capicúa (se leé igual de izquierda a derecha que de izquierda a derecha)
    void mostrarCapicua() const
    {
        if (entero == invertido)
        {
            cout << "\nEl número es capicúa." << endl;
        }
        else
        {
            cout << "\nEl número no es capicúa." << endl;
        } //Fin de if - else
    } //Fin funcion mostrarCapicua

}; //Fin de declaracion de clase Entero

//Funcion Main
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    Entero entero1;
    unsigned int numero;
    cout << "Por favor ingrese un valor entero positivo no mayor a 32767: ";
    cin >> numero;
    entero1.establecerEntero(numero);
    entero1.separar(entero1.obtenerEntero());
    entero1.mostrarDigitos();
    entero1.establecerInvertido();
    entero1.mostrarInverso();
    entero1.mostrarCapicua();
    return 0;
} // Fin funcion main

//Funcion que calcula el cociente entre dos numeros positivos
unsigned int cociente(unsigned int divisor = 10, unsigned int dividendo = 1)
{
    return dividendo / divisor;
} //Fin funcion cociente

//Funcion que calcula el residuo entre dos numeros positivos
unsigned int resto(unsigned int divisor = 10, unsigned int dividendo = 1)
{
    return dividendo % divisor;
} //Fin funcion resto
