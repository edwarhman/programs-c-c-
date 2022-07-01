#include "coordenadas.h"


//Constructor predeterminado
Coordenadas::Coordenadas(int coor_x = 0, int coor_y = 0)
:x(coor_x), y(coor_y)
{
}//Fin constructor predeterminado

Coordenadas::Coordenadas(const Coordenadas &copia)
{
    x = copia.obtenerX();
    y = copia.obtenerY();
}

Coordenadas::Coordenadas()
:x(0), y(0)
{

}

//Destructor de la clase
Coordenadas::~Coordenadas()
{
}//fin destructor

//Funcion que establece el argumento como la coordenada x del objeto
void Coordenadas::establecerX(int x)
{
    Coordenadas::x = x;
} //Fin funcion establecerX

//Funcion que establece el argumento como la coordenada y del objeto
void Coordenadas::establecerY(int y)
{
    Coordenadas::y = y;
} //Fin funcion establecerY

//Funcion que obtiene la coordenada x del objeto
int Coordenadas::obtenerX() const
{
    return x;
}//Fin funcion obtenerX

//Funcion que obtiene la coordenada y del objeto
int Coordenadas::obtenerY() const
{
    return y;
}//Fin funcion obtenerX

//Operadores

//operador "+" de la clase Coordenadas
const Coordenadas Coordenadas::operator+(const Coordenadas &a_derecho) const
{
    Coordenadas suma(0, 0);
    suma.x = this->obtenerX() + a_derecho.obtenerX();
    suma.y = this->obtenerY() + a_derecho.obtenerY();
    return suma;
}//Fin de operador "+"

//Operador "=" de la clase Coordenadas
const Coordenadas &Coordenadas::operator=(const Coordenadas &a_derecho)
{
    this->x = a_derecho.obtenerX();
    this->y = a_derecho.obtenerY();
    return *this;
}//Fin de operador "="

//operador "+=" de la clase coordenadas
const Coordenadas &Coordenadas::operator+=(const Coordenadas &a_derecho)
{
    x += a_derecho.obtenerX();
    y += a_derecho.obtenerY();

    return *this;
}//Fin de operador+=

//Operador lógico ">" de la clase coordenadas
bool Coordenadas::operator>(const Coordenadas &a_derecho)
{
    if (x < a_derecho.obtenerX() && y < a_derecho.obtenerY())
    {
        return false;
    }
    else 
        return true;
}//fin de operador lógico >

//Operador lógico ">=" de la clase Coordenadas
bool Coordenadas::operator>=(const Coordenadas &a_derecho) 
{
    if (x >= a_derecho.obtenerX() && y >= a_derecho.obtenerY())
    {
        return true;
    }
    else 
        return false;
}//Fin de operador>=