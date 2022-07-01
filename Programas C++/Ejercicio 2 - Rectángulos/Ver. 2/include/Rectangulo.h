#if !defined(RECTANGULO_H)
#include <array>
#define RECTANGULO_H
#define COORDENADAS 2
#define VERTICES 4
class Rectangulo
{
private:
    std::array<std::array<float, COORDENADAS>, VERTICES> vertices;
    float longitud;
    float anchura;
    char caracter;
public:
    Rectangulo();
    Rectangulo(float l, float a);
    ~Rectangulo();
// Funciones establecer
   
    void establecerRectangulo(float l, float a);
    void establecerRectangulo();
    void establecerRectangulo(std::array<std::array<float, COORDENADAS>, VERTICES> entrada);
    void establecerLongitud(float valor);
    void establecerAnchura(float valor);
    void establecerAyA();
// Funciones obtener

    float obtenerLongitud() const;
    float obtenerAnchura() const;

// Cálculos

    float perimetro() const;
    float area() const;
    bool cuadrado() const;

// Impresión

    void imprimir() const;

// Otras funciones

    static void leerEntrada(std::array<std::array<float, COORDENADAS>, VERTICES> *entrada);
    void dibujar() const;
    void establecerCaracterRelleno();
    char caracterRelleno() const;
};

#endif // RECTANGULO_H
