#if !defined(EMPLEADOBASEMASCOMISION_H)
#define EMPLEADOBASEMASCOMISION_H
#include "EmpleadoPorComision.h"
#include <string>

class EmpleadoBaseMasComision : public EmpleadoPorComision
{
private:
    double salarioBase;

public:
    EmpleadoBaseMasComision(const std::string &, const std::string &, const std::string &, double, double, double);
    ~EmpleadoBaseMasComision();
    void establecerSalarioBase(double);
    double obtenerSalarioBase() const;
    double ingresos() const;
    void imprimir() const;
};




#endif // EMPLEADOBASEMASCOMISION_H
