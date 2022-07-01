#include <iostream>
#include <vector>
#include <array>
#include <locale.h>
using namespace std;
enum class Torres {A = 1, B, C};
void mostrarTorres();
void moverPila(unsigned discos, unsigned comienzo, unsigned destino, unsigned temporal);
int main()
{
    setlocale(LC_ALL,"");
    //mostrarTorres();
    cout << endl;
    moverPila(3, (unsigned)Torres::A,(unsigned)Torres::C, (unsigned)Torres::B);

}

void mostrarTorres()
{
    cout << "*"
            "\n* *"
            "\n* * *"
            "\n* * * * *"
            "\n* * * * * *";
            
}


void moverPila(unsigned discos, unsigned comienzo, unsigned destino, unsigned temporal)
{
    //static array<int, 4> pilas{0, discos};
    
    if (discos == 1)
    {
        //Mueve el disco superior a la aguja destino.
        cout << "El disco " << discos << " no tiene m�s discos por encima. Se mover� a su destino." << endl;
        cout << comienzo << " > " << destino << endl;
    }
    else
    { 
        //Mueve la pila m�s chica a la aguja temporal
        cout << "El disco " << discos << " tiene una pila de " << discos-1 << " que impide el movimiento." << endl;
        cout << "Se mover� esta pila m�s chica a una aguja temporal" << endl;
            moverPila(discos-1, comienzo, temporal, destino);
        cout << "El disco " << discos << " ahora est� libre. Se mover� a la aguja destino." << endl;
        //Mueve el �ltimo disco a la aguja destino
            cout << comienzo << " > " << destino << endl;
        cout << "Se vuelve a situar la pila de " << discos -1 << " encima del disco " << discos << " en la aguja destino." << endl;
        //Mueve la pila m�s chica de la aguja temporal a la destino
            moverPila(discos - 1, temporal, destino, comienzo);
    }
}


void moverPilaIterativa(unsigned discos, unsigned comienzo, unsigned destino, unsigned temporal)
{
    for (size_t i = 1; i <= discos; i++)
    {
        if (discos % 2 == 0)
        {
            cout << comienzo << " > " << temporal << endl;
            cout << comienzo << " > " << destino << endl;
            for (size_t j = 0; j <= i; j++)
            {
                cout << temporal << " > " << destino << endl;
            }
            
        }
        
    }
    
}
