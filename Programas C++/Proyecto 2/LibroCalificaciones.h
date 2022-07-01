#include <string>
#include <array>
#define CAN_ESTUDIANTES 10 //Estudiantes totales para cada curso
#define CAN_PRUEBAS 3 //El total de pruebas que puede llegar a tener un estudiante
class LibroCalificaciones
{
private:
    std::string nombreCurso;
    std::string nombreInstructor;
    unsigned int aCuenta;
    unsigned int bCuenta;
    unsigned int cCuenta;
    unsigned int dCuenta;
    unsigned int fCuenta;
    std::array <std::array <int,CAN_PRUEBAS> , CAN_ESTUDIANTES> calificaciones;
public:
    static const size_t estudiantes = 10;
    explicit LibroCalificaciones(std::string nombreC, std::string nombreI, std::array<std::array<int,CAN_PRUEBAS>,CAN_ESTUDIANTES> &);
    void establecerNombreCurso(std::string nombre);
    std::string obtenerNombreCurso() const;
    void establecerNombreInstructor(std::string nombre);
    std::string obtenerNombreInstructor() const;
    void mostrarMensaje() const;
    void recibirCalificaciones(); //recibe un número aleartorio de calificaciones
    void mostrarReporteCalificaciones() const;
    void procesarCalificaciones() const;
    int obtenerMinimo() const;
    int obtenerMaximo() const;
    double obtenerPromedio(const array<int, CAN_PRUEBAS> &) const;
    void imprimirGraficoBarras() const;
    void imprimirCalificaciones() const;
};
