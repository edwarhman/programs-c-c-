#include <iostream>
#include <time.h>
#include <iomanip>
enum class Movimientos {PASO_RAPIDO = 1, RESBALON = 1, PASO_LENTO = 8};
using namespace std;
int main(int argc, char const *argv[])
{
    Movimientos miMovimiento = Movimientos::PASO_RAPIDO;
    miMovimiento = (Movimientos)1;
    if (miMovimiento == Movimientos::PASO_RAPIDO)
    {
        cout << "Paso rapido" << endl;
    }
    
    float tiempo = (time(0) + 1000) / 1000 ;
    cout << setprecision(3) <<  tiempo << endl;
    return 0;
}
