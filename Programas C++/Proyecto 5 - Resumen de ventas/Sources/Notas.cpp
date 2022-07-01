#include "Notas.h"


Notas::Notas(int nVen, int nProd, long vTotal)
: numVendedor(nVen), numProducto(nProd), valorTotal(vTotal)
{
    
}
//Funcion que obtiene el numero del producto del objeto
int Notas::obtenerNumProducto() const
{
    return numProducto;
} //fin funcion obtenerNumProducto

//Funcion que obtiene el numero del vendedor del objeto
int Notas::obtenerNumVendedor() const
{
    return numVendedor;
} //Fin funcion obtenerNumVendedor

//Funcion que obtiene el valor total de las ventas (en $) del objeto
long Notas::obtenerValorTotal() const
{
    return valorTotal;
}//Fin funcion obtenerValorTotal