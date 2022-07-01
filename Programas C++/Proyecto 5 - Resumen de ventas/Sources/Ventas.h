#include "Notas.h"
#include <vector>
#include <array>

class Ventas
{
public:
    static const int vendedores = 4;
    static const int productos = 5;
    explicit Ventas(const std::vector<Notas> &notasMes);
    void mostrarVentas() const;
    long calcularTotalVendedor(const int vendedor) const;
    long calcularTotalProducto(const int producto) const;
    void leerNotas();
    void establecerVentasTotales(const long);
    long obtenerVentasTotales() const;
private:
    const std::vector<Notas> &notas;
    std::array<std::array<long , productos> , vendedores> ventas;
    long ventasTotales;
};

