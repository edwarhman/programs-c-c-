#if !defined(EMPLEADOPORCOMISION_H)
#define EMPLEADOPORCOMISION_H
#include <string>

class EmpleadoPorComision
{
private:
    std::string primerNombre;
    std::string apellidoPaterno;
    std::string numeroSeguroSocial;
    double ventasBrutas;
    double tarifaComision;
    
public:
    EmpleadoPorComision(const std::string &, const std::string &, const std::string &, double = 0.0, double = 0.0);
    ~EmpleadoPorComision();
    void establecerPrimerNombre(const std::string &); 
    std::string obtenerPrimerNombre() const;
    void establecerApellidoPaterno(const std::string &); 
    std::string obtenerApellidoPaterno() const;
    void establecerNumeroSeguroSocial(const std::string &); 
    std::string obtenerNumeroSeguroSocial() const;
    void establecerVentasBrutas(double);
    double obtenerVentasBrutas() const;
    void establecerTarifaComision(double);
    double obtenertarifaComision() const;
    double ingresos() const;
    void imprimir() const;
};




#endif // EMPLEADOPORCOMISION_H
