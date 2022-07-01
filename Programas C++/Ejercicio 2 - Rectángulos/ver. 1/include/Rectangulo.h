#if !defined(RECTANGULO_H)
#define RECTANGULO_H

class Rectangulo
{
private:
    float longitud;
    float altura;
public:
    Rectangulo();
    Rectangulo(float l, float a);
    ~Rectangulo();
// Funciones establecer
   
    void establecerRectangulo(float l, float a);
    void establecerRectangulo();
    void establecerLongitud(float valor);
    void establecerAltura(float valor);
// Funciones obtener

    float obtenerLongitud() const;
    float obtenerAltura() const;

// C�lculos

    float perimetro() const;
    float area() const;

// Impresi�n

    void imprimir() const;

};


#endif // RECTANGULO_H
