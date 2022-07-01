#if !defined(EMPLEADO_H)
#define EMPLEADO_H
#include <string>

class Empleado
{
private:
    std::string primerNombre;
    std::string apellidoPaterno;
    std::string numeroSeguroSocial;
public:
    Empleado(const std::string &, const std::string &, const std::string &);
    virtual ~Empleado(){}
    void establecerPrimerNombre(const std::string &);
    std::string obtenerPrimerNombre() const;
    void establecerApellidoPaterno(const std::string &);
    std::string obtenerApellidoPaterno() const;
    void establecerNumeroSeguroSocial(const std::string &);
    std::string obtenerNumeroSeguroSocial() const;

    virtual double ingresos() const = 0;
    virtual void imprimir() const;
};




#endif // EMPLEADO_H

