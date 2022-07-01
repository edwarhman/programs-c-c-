#if !defined(COORDENADAS_H)
#define COORDENADAS_H
#include <iostream>

class Coordenadas   ///Clase que almacena y manipula coordenadas (x, y).
{
private:
    int x;  ///Posicion x
    int y;  ///Posicion y
public:
    //Funciones de la clase

    Coordenadas(int, int);  ///Constructor predeterminado de clase.
    Coordenadas();
    Coordenadas(const Coordenadas &);
    ~Coordenadas();  ///Desctructor de clase
    void establecerX(int);  ///establece el argumento introducido como la coordenada x del objeto.
    void establecerY(int);  ///establece el argumento introducido como la coordenada y del objeto
    int obtenerX() const;  ///Obtiene la coordenada x
    int obtenerY() const;  ///obtiene la coordenada y

    //Operadores de clase
    const Coordenadas &operator=(const Coordenadas &a_derecho);
    const Coordenadas operator+(const Coordenadas &a_derecho) const; 
    const Coordenadas &operator+=(const Coordenadas &a_derecho);
    bool operator>(const Coordenadas &a_derecho);
    ///Operador lógico "<" de la clase coordenadas
    bool operator<(const Coordenadas &a_derecho)
    {
        return !(*this> a_derecho) ? true : false; 
    }   
    bool operator>=(const Coordenadas &a_derecho) ;
};

#endif // COORDENADAS_H
