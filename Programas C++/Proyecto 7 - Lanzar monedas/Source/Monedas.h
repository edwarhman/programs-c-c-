#if !defined(MONEDAS_H)
#define MONEDAS_H

class Monedas
{
private:
    int ultimoLanzamiento;
    void mostrarResultado() const;
public:
    Monedas(/* args */);
    ~Monedas();
    bool tirarMoneda();
};




#endif // MONEDAS_H


