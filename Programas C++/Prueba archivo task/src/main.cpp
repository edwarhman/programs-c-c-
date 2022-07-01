#include "HelloWorld.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int numero = 9;
    HelloWorld myWorld;
    myWorld.say();
    numero = numero * 0;
    cout << "Pulse enter para salir.";
    cin.ignore();
    return 0;
}
