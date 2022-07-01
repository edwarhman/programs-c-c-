#include <iostream>
#include <locale.h>
using namespace std;
//Prototipos de funciones
unsigned mcd(unsigned x, unsigned y);
void intercambiar(unsigned &x, unsigned &y);

//funcion main
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"");
    cout << mcd(594, 324);
    return 0;
}

unsigned mcd(unsigned x, unsigned y)
{
    //Si y es mayor a x los intercambia entre ellos
    if (y > x)
    {
        cout << "Cómo x tiene que ser mayor a y, se intercambian " << x << " y " << y << endl;
        intercambiar(x, y);
    }

    //Si y  es 0 devuelve x como el maximo comun divisor
    if (y == 0)
    {
        cout << "Cómo el segundo argumento es 0. entonces el primero (" << x <<") es el mcd." << endl;
        cout << "===================================================================" << endl;
        return x;
    }
    //Si y no es cero entonces calcula el mcd entre 
    else
    {
        cout << "Cómo el segundo argumento (" << y << ") es distinto de 0\n"
             << y << " pasa a ser el primer argumento.\n"
             << "El residuo entre " << x << " y " << y << " (" << x % y << ") pasa a ser el segundo argumento." << endl;
        cout << "===================================================================" << endl;
        return mcd(y, x % y);
    }
    
    
}

void intercambiar(unsigned &x, unsigned &y)
{
    unsigned aux;
    aux = x;
    x = y;
    y = aux;
}