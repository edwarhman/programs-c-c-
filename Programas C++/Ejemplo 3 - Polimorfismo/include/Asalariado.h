#if !defined(ASALARIADO_H)
#define ASALARIADO_H
#include "Empleado.h"

class Asalariado : public Empleado
{
private:
    double salarioSemanal;
public:
    Asalariado(const std::string &, const std::string &, const std::string &, double = 0.0);
    virtual ~Asalariado(){}
    void establecerSalarioSemanal(double);
    double obtenerSalarioSemanal() const;

    virtual double ingresos() const override;
    virtual void imprimir() const override;

};


#endif // ASALARIADO_H
