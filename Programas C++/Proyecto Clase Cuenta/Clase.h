class Cuenta
{
private:
    int saldoCuenta;
public:
    explicit Cuenta(int saldo);
    void establecerSaldo(int saldo);
    int obtenerSaldo();
    void abonar(int monto);
    void retirar(int monto);
};