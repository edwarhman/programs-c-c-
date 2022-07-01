class Notas
{
private:
    int numVendedor;
    int numProducto;
    long valorTotal;
public:
    Notas(int nVen, int nProd, long vTotal);
    void establecerNumVendedor(int);
    void establecerNumProducto(int);
    void establecerValorTotal(long);
    int obtenerNumVendedor() const;
    int obtenerNumProducto() const;
    long obtenerValorTotal() const;
};


