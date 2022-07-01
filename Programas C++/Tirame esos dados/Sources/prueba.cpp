#include <random>
#include <ctime>
#include <iostream>
using namespace std;
void lanzarDado(unsigned int);
int main(int argc, char const *argv[])
{
    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> intAleartorio(1, 6);

    for (size_t i = 0; i < 11; i++)
    {
        lanzarDado(intAleartorio(motor));
        cout << motor << " ";
    }
    
    return 0;
}

void lanzarDado(unsigned int aleartorio)
{
    cout << aleartorio << " ";
}