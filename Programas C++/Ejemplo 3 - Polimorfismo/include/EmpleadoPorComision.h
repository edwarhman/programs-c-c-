#if !defined(POR_COMISION_H)
#define POR_COMISION_H
#include "Empleado.h"

class EmpleadoPorComision : public Empleado
{
private:
    double ventasBrutas;
    double tarifaComision;
public:
    EmpleadoPorComision(const std::string &, const std::string &, const std::string &, double = 0.0, double = 0.0 );
    virtual ~EmpleadoPorComision(){}
    void establecerVentasBrutas(double);
    double obtenerVentasBrutas() const;
    void establecerTarifaComision(double);
    double obtenerTarifaComision() const;

    virtual double ingresos() const override;
    virtual void imprimir() const override;
};





#endif // POR_COMISION_H
