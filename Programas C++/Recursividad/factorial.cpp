#include <iostream>
using namespace std;

unsigned long factorial(unsigned numero);
int main(int argc, char const *argv[])
{
    cout << 7 << "! = ";
    cout << factorial(7) << endl;
    return 0;
}


unsigned long factorial(unsigned numero)
{
    
    if (numero <= 1)
    {
        cout << "1 " << endl;
        //El numero es 1  o 0, devuelve 1
        return 1;
    }
    
    else
    {
        cout << numero << " * " << numero - 1 << "! " << endl; 
        cout << numero -1 << "! = ";
        //El numero es mayor a uno 
        return numero * factorial(numero-1);
    }
    
}