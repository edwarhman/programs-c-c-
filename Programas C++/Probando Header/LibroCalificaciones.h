#include <string>

class LibroCalificaciones
{
private:
    std::string nombreCurso;

public:
    explicit LibroCalificaciones(std::string nombre);
    void establecerNombreCurso(std::string nombre);
    std::string obtenerNombreCurso() const;
    void mostrarMensaje() const;
};