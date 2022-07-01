#if !defined(COMPETIDOR_H)
#define COMPETIDOR_H
#define META 70
class Competidor
{
private:
    int posicion;
    char identificador;
public:
    Competidor(char NuevoIdentificador);
    ~Competidor();
    virtual ~Competidor();
    void mover(int nuevaPosicion);
    virtual void mover();
    int obtenerPosicion() const;
    char obtenerIdentificador() const;
};




#endif // COMPETIDOR_H
