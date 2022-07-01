#include "Ventas.h"
#include <iostream>
using namespace std;
//Contructor de la clase
Ventas::Ventas(const std::vector<Notas> &notasMes)
:notas(notasMes)
{
    ventas = {0};
}//Fin de constructor

//Funcion que lee las notas y almacena las ventas del producto y vendedor correspondiente
void Ventas::leerNotas()
{
    long suma = 0;
    for (auto &i : notas)
    {
        ventas[i.obtenerNumVendedor()][i.obtenerNumProducto()] = i.obtenerValorTotal();
        suma += i.obtenerValorTotal();
    }//Fin ciclo for
    establecerVentasTotales(suma);
}//fin funcion leerNotas

//Funcion que muestra las ventas en pantalla en formato tabular
void Ventas::mostrarVentas() const
{
    cout << "productos";
    for (size_t i = 0; i < vendedores; i++)
    {
        cout << "\tVendedor " << i+1;
    }//Fin primer ciclo for
    cout << "\tTotal producto" << endl;
    for (size_t i = 0; i < productos; i++)
    {
        cout << "producto " << i+1;
        for (size_t j = 0; j < vendedores; j++)
        {
            cout << "\t" << ventas[j][i] << "\t";
        }//fin ciclo for interno
        cout <<"\t" << calcularTotalProducto(i) << endl;
    }//Fin segundo ciclo for
    cout << "Total vendedor";
    for (size_t i = 0; i < vendedores; i++)
    {
        cout << "\t" << calcularTotalVendedor(i) << "\t";
    }//fin tercer ciclo for
    cout << "\t" << obtenerVentasTotales() << endl;
}//Fin funcion mostrarVentas

void Ventas::establecerVentasTotales(const long total)
{
    ventasTotales = total;
}

//Funcion que calcula el total de las ventas de un vendedor y devuelve el resultado
long Ventas::calcularTotalVendedor(const int vendedor) const
{
    long suma = 0;
    for (auto &i : ventas[vendedor])
    {
        //cout << "i = " << i;
        suma += i;
        //cout << " suma = " << suma <<endl;
    } //Fin ciclo for 
    return suma;
} //Fin funcion calcularTotalVendedor

//Funcion que calcula el total de las ventas de un producto y devuelve el resultado
long Ventas::calcularTotalProducto(const int producto) const
{
    long suma = 0;
    for (auto &&i : ventas)
    {
        suma = i[producto];
    }//fin ciclo for
    return suma;
} //fin funcion calcularTotalProducto

long Ventas::obtenerVentasTotales() const
{
    return ventasTotales;
}