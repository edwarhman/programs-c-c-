#if !defined(ENTERO_ENORME_H)
#define ENTERO_ENORME_H
#include <array>
#include <string>
#define DIGITOS 40 
class EnteroEnorme
{
private:
    std::array<int, DIGITOS> digitos;

    // Funciones Privadas
    void convertir(const std::string *);

    // Funciones Públicas
public:
    EnteroEnorme();
    EnteroEnorme(std::string cadena);
    ~EnteroEnorme();
    void imprimir() const;
    void recibir();
    void establecerDigito(int indice, int valor);
    int obtenerDigito(int indice) const;
    const EnteroEnorme operator+(const EnteroEnorme arg2) const;
    EnteroEnorme operator=(const EnteroEnorme arg2);
    
private: void leerEntrada(std::string *entrada);
};

#endif // ENTERO_ENORME_H
