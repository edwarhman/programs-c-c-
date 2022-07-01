#include <string>
class FrecuenciaCardiaca
{
private:
    std::string nombrePersona;
    std::string apellidoPersona;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
    int edadPersona;
public:
    explicit FrecuenciaCardiaca(std::string, std::string, int, int, int);
    void establecerNombre(std::string);
    void establecerApellido(std::string);
    void establecerDiaNacimiento(int);
    void establecerMesNacimiento(int);
    void establecerAnioNacimiento(int);
    std::string obtenerNombre() const;
    std::string obtenerApellido() const;
    int obtenerDiaNacimiento() const;
    int obtenerMesNacimiento() const;
    int obtenerAnioNacimiento() const;
    int obtenerEdad() const;
    void establecerEdad();
    void establecerFrecuenciaCardiaca(int*, int*) const;
};