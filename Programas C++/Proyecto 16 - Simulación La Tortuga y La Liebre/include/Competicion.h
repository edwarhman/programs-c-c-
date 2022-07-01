#if !defined(COMPETICION_H)
#define COMPETICION_H
#include <vector>
#include "Tortuga.h"
#include "Liebre.h"

enum class Ganador {EMPATE, TORTUGA, LIEBRE};
class Competicion
{
private:
    Tortuga tortuga;
    Liebre liebre;
    Competidor * competidor;
    Ganador ganador;
    
public:
    Competicion();
    ~Competicion();
    Tortuga * obtenerTortuga();
    Liebre * obtenerLiebre();
    void comenzar();
    void mostrar() const;
    bool comprobarEstado() const;
    void establecerGanador();
    Ganador obtenerGanador() const;
    void mostrarGanador() const;
};


#endif // COMPETICION_H
