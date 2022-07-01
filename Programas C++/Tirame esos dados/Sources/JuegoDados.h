#if !defined(JUEGODADOS_H)
#define JUEGODADOS_H


#include <vector>
#include <random>
#include <ctime>
#include "PosiblesSumas.h"
class JuegoDados
{
public:
    static const int caras = 6;  //caras del dado
    explicit JuegoDados();  //constructor de la clase
    void establecerApariciones(int); // incrementa la cantidad de apariciones del argumento suministrado
    void mostrarResultados() const;  //Muestra las apariciones totales de cada resultado posible
    bool evaluarVector(int) const; //evalua si el argumento suminstrado ya se encuentra en el vector
    void lanzarDados();  //tira los dados 
private:
    std::vector<PosiblesSumas> listaResultados;
};




#endif // JUEGODADOS_H


