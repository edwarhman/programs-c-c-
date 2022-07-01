#if !defined(CASILLA_H)
#define CASILLA_H

class Casilla
{
private:
    unsigned estado; // Contiene el posible estado que puede tener la casilla.
    unsigned eliminaciones; // Contiene la cantidad de casillas eliminadas al colocar una reina en dicha casilla.
public:
    Casilla(/* args */); // Constructor de la clase.
    ~Casilla(); // Destructor de la clase.
    void establecerEstado(unsigned nuevoEstado); //establece el estado de la casilla.
    unsigned obtenerEstado() const; // obtiene el estado de la casilla.
    void establecerEliminaciones(unsigned bloqueos); // establece las eliminaciones de la casilla.
    unsigned obtenerEliminaciones() const; // obtiene las eliminaciones de la casilla.
};




#endif // CASILLA_H
