#include <array>
#include <vector>
class Vendedor
{
private:
    int ventas;
    int salario;
public:
    explicit Vendedor(int, int);
    void establecerVentas(int cantidad);
    int obtenerVentas() const;
    void establecerSalario();
    int obtenerSalario();
};
struct RangoDeSalario
{
    int limiteInf;
    int limiteSup;
    int cantidad; //Cantidad de vendedores en ese rango
};

class Salarios
{
public:
    static const int cantidadDeRangos = 9;
    static const int sueldoFijo = 200; //dolares
    static constexpr double comision = 0.08; //comision por venta que reciben los empleados
    static const int separacionRangos = 100;
private:
    std::vector<Vendedor> vendedor;
    std::array<RangoDeSalario, cantidadDeRangos> clasificacionVendedores;

public:
    explicit Salarios();
    void clasificarVendedores();
    void mostrarClasificacionVendedores() const;
    Vendedor obtenerVentasVendedor();
    void agregarVendedor();
    void calcularSalarios();
};

