#include <iostream>
using namespace std;

//Prototipos
template<typename T>
void leerEntrada(T &valor);

// Función main
int main(int argc, char const *argv[])
{
    unsigned numero;
    cout << numero << endl;
    leerEntrada(numero);

    cout << numero;
    return 0;
}

template<typename T>
void leerEntrada(T &valor)
{
    T entrada;
    try
    {
        cout << "Ingrese la entrada: ";
        cin.;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cerr << "Intente de nuevo." << endl;
        leerEntrada(valor);
        return;
    }
    
    valor = entrada;

}
