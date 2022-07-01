#include <iostream>
#include "Salarios.h"
using namespace std;
//Constructor clase vendedor
Vendedor::Vendedor(int nVentas, int salarioS) 
:ventas(nVentas),
 salario(salarioS)
{

}
//Funcion que establece las ventas de un vendedor
void Vendedor::establecerVentas(int cantidadVentas)
{
    ventas = cantidadVentas;
}// fin funcion establecerVentas

//Funcion que obtiene las ventas de un vendedor
int Vendedor::obtenerVentas() const
{
    return ventas;
}// fin funcion obtenerVentas

// Funcion que establece el salario de un vendedor
void Vendedor::establecerSalario()
{
    salario = (ventas* Salarios::comision) + Salarios::sueldoFijo;
} //Fin de funcion establecerSalario

//Funcion que obtiene el salario de un vendedor
int Vendedor::obtenerSalario()
{
    return salario;
} //fin funcion obtenerSalario

//Constructor clase Salarios

Salarios::Salarios()
{
    for (size_t i = 0; i < clasificacionVendedores.size(); i++)
    {
        clasificacionVendedores[i].limiteInf = (i+2)*separacionRangos;
        clasificacionVendedores[i].limiteSup = clasificacionVendedores[i].limiteInf +(separacionRangos-1);
        clasificacionVendedores[i].cantidad = 0;
    }//Fin del ciclo for
    
}//Fin constructor salario

//Funcion que clasifica a los vendedores según su salario semanal
void Salarios::clasificarVendedores()
{
    for (auto &j : vendedor)
    {
        for (size_t i = 0; i < clasificacionVendedores.size(); i++)
        {
            if (j.obtenerSalario() <= clasificacionVendedores[i].limiteSup
                && j.obtenerSalario() >= clasificacionVendedores[i].limiteInf)
            {
                ++clasificacionVendedores[i].cantidad;
            } //Fin de sentencia if
            
        } //Fin de for interno (clasificación)
        
    }//Fin de for externo (vendedores)
    
} //Fin funcion clasificarVendedores

//Función que muestra los vendedores según su rango
void Salarios::mostrarClasificacionVendedores() const
{
    cout << "Rangos\t     Cantidad\tGráfico" << endl;
    for (auto &i : clasificacionVendedores)
    {
        cout << i.limiteInf << "-" << i.limiteSup << " :";
        cout << "\t" << i.cantidad << "\t";
        for (size_t j = 0; j < i.cantidad; j++)
        {
            cout << '*';
        }// Fin for interno (muestra estrellas)
        cout << endl;
    }//fin for externo (muestra los rangos de salarios)
} //fin funcion mostrarClasificacionVendedores

//Funcion que agrega uno o mas vendedores al objeto
void Salarios::agregarVendedor()
{
    char entrada = 'N';
    
    do
    {
        vendedor.push_back(obtenerVentasVendedor());
        cout << "¿Desea agregar otro vendedor? (S/N): ";
        cin >> entrada;

    } while (entrada == 'S');
    
}
//Obtiene las ventas del vendedor de los datos suministrados por el usuario
Vendedor Salarios::obtenerVentasVendedor()
{
    int entrada = 0;
    cout << "Ingrese las ventas del vendedor: ";
    cin >> entrada;
    Vendedor vendedor(entrada,0);
    return vendedor;
}

//Funcion que calcula el salario de todos los vendedores
void Salarios::calcularSalarios()
{
    for (auto &i : vendedor)
    {
        i.establecerSalario();
    }
    
}