//SUMA DE ENTEROS
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, suma;
    a = b = suma = 0;
    cout << "Ingrese el primer valor: ";
    cin >> a;

    cout << "Ingrese el segundo valor: ";
    cin >> b;

    suma = a + b;
    cout << "La suma entre " << a << " y " << b << " es " << suma << std::endl;
    return 0;
}
