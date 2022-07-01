#if !defined(BASE_MAS_COMISION_H)
#define BASE_MAS_COMISION_H
#include "EmpleadoPorComision.h"

class EmpleadoBaseMasComision : public EmpleadoPorComision
{
private:
    double salarioBase;
public:
    EmpleadoBaseMasComision(const std::string &, const std::string &, const std::string & nss, double ventas = 0.0, double tarifa = 0.0, double salario = 0.0);
    virtual ~EmpleadoBaseMasComision(){}
    void establecerSalarioBase(double salario);
    double obtenerSalarioBase() const;
    virtual double ingresos() const override;
    virtual void imprimir() const override;
};



#endif // BASE_MAS_COMISION_H
