#include "Ventas.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int salir;
    vector<Notas> notasJunio = {Notas(3,4,90),Notas(1,3,154),Notas(3,2,73)};
    vector<Notas> notasMayo{Notas(1,1,153),Notas(2,3,500),Notas(3,2,764)};
    cout << notasJunio[0].obtenerNumVendedor() << endl;
    cout << notasJunio[0].obtenerNumProducto() << endl;
    cout << notasJunio[0].obtenerValorTotal() << endl;

    Ventas ventasJunio(notasJunio);
    ventasJunio.leerNotas();
    ventasJunio.mostrarVentas();
    cout << "Pulse enter para salir.";
    cin >> salir;
    return 0;
}
