#if !defined(CRAPS_H)
#define CRAPS_H
#include <iostream>
enum class Estado {GANA,PIERDE,REPITE};
enum class Mensajes {INICIAL, GANADOR, PERDEDOR, CONTINUAR};
class Craps
{
private:
    //Variables privadas

    Estado estado; //Estado actual de la partida
    unsigned conteoTiros; //cantidad de tiros realizados por el usuario
    unsigned tiro; //resultado del ultimo tiro realizado por el usuario
    unsigned puntoJugador; //punto que el usuario debe intentar acertar, establecido después del primer tiro
    
    //Funciones privadas
    void establecerPuntoJugador();
    unsigned obtenerPuntoJugador() const;
    unsigned obtenerTiro() const;
    void establecerEstado(Estado nuevoEstado);
    unsigned obtenerConteoTiros() const;
    void incrementarTiros();
    void comprobarTiradaInicial();
    void comprobarRestoDeTiros();

public:
    Estado obtenerEstado() const;
    Craps(/* args */); //Constructor de la clase
    ~Craps(); //Destructor de la clase
    void establecerTiro(unsigned nuevoTiro);
    bool comprobarEstado();
    void mostrarMensaje(Mensajes tipoMensaje) const;
    void reestablecer();
    static void mostrarReglas()
    {
        std::cout << "Bienvenido al juego de Craps."
            		 "\nReglas:" << std::endl;
    	std::cout << "=============================================================================================" << std::endl;
        std::cout << "Se lanzan dos dados de 6 caras y se calcula la suma de las dos caras superiores"
                  << "\n    Si la suma es 7 o es 11 en el primer tiro, el jugador gana."
                  << "\n    Si la suma es 2, 3 o 12 en el primer tiro, el jugador pierde."
                  << "\n    Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, la suma será el punto del jugador."
                  << "\nPara ganar el jugador debe seguir tirando los dados hasta que salga su punto otra vez."
                  << "\nEl jugador pierde si saca un 7 antes de llegar a su punto." << std::endl;
    	std::cout << "=============================================================================================" << std::endl;
    }
};

#endif // CRAPS_H
