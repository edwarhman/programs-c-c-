#if !defined(SINDUPLICADOS_H)
#define SINDUPLICADOS_H
#include <vector>
#define ELEMENTOS 20
#define VAL_MIN 10
#define VAL_MAX 100
class SinDuplicados
{
private:
    std::vector<int> arreglo;
    bool buscarElemento(unsigned dato) const;
    void establecerElemento(unsigned dato);
public:
    SinDuplicados(/* args */);
    ~SinDuplicados();
    void leerEntrada();
    void mostrarElementos() const;
};

#endif // SINDUPLICADOS_H
