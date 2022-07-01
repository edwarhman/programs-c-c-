//PRIMERA CREACION DE UNA CLASE
#include <iostream>
using namespace std;
class LibroCalificaciones
{
public:
    void mostrarMensaje(string autor) const
    {
        cout << "Mi primera clase. -" << autor << endl;
    }
};

int main(int argc, char const *argv[])
{
    string autor;
    cout << "Ingrese el nombre del autor: ";
    getline(cin,autor);
    LibroCalificaciones miLibro;
    miLibro.mostrarMensaje(autor);
    return 0;
}
