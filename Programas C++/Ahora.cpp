#include <iostream>
#include <locale>
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"ALL");
    std::cout << "No me jodas. Am�n.\n";
    return 0;
}
