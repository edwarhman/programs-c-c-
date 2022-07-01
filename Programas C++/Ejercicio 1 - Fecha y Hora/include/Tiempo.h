#if !defined(TIEMPO_H)
#define TIEMPO_H
#include <ctime>
class Tiempo
{
private:
    int hora;
    int min;
    int seg;
public:
    Tiempo();
    Tiempo(int, int, int);
    ~Tiempo();
    // Funciones establecer

    void establecerTiempo(int, int, int);
    void establecerTiempo(time_t);
    void establecerHora(int entrada);
    void establecerMin(int entrada);
    void establecerSeg(int entrada);
    // Funciones obtener

    int obtenerHora() const;
    int obtenerMin() const;
    int obtenerSeg() const;
    // Funciones de impresión

    void imprimirUniversal() const;
    void imprimirEstandar() const;

    // Otras funciones

    void tictac();
    // Operadores Sobrecargados
    bool operator==(Tiempo arg2) const;
};

#endif // TIEMPO_H
