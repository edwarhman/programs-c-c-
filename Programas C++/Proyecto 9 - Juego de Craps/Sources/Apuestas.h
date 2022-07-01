#if !defined(APUESTAS_H)
#define APUESTAS_H

enum class Resultado {GANA, PIERDE};

class Apuestas
{
private:
    unsigned fondos;
    unsigned apuesta;
    unsigned enjuego;
public:
    Apuestas();
    ~Apuestas();
    void apostar();
    unsigned obtenerFondos() const;
    void establecerFondos(Resultado estado);
    unsigned obtenerApuesta() const;
    void establecerApuesta(int valor);
    void mostrarFondos() const;
    void incrementarApuesta();
    void reestablecerEnJuego();
    void establecerEnJuego();
    unsigned obtenerEnJuego() const;
};




#endif // APUESTAS_H
