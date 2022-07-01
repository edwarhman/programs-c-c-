#ifndef ARREGLOS_H
#define ARREGLOS_H
#include <iostream>
class Arreglos
{
    friend std::ostream &operator<<(std::ostream &, const Arreglos &);
    friend std::istream &operator>>(std::istream &, Arreglos &);
private:
    size_t tamanio;
    int *ptr;
public:
    //Constructores y destructor
    explicit Arreglos(int elementos);
    ~Arreglos();
    Arreglos(const Arreglos &copiaArray);

    //Funciones
    size_t obtenerTamanio() const;
    
    //Operadores
    const Arreglos &operator=(const Arreglos &array2);
    bool operator==(const Arreglos &array2) const;
    bool operator!=(const Arreglos &array2) const
    {
        return !(*this==array2);
    }
    int &operator[](int subindice);
    int operator[](int subIndice) const;    
};

#endif