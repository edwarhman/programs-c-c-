#include <iostream>
#include <locale>
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"ALL");
    std::cout << "No me jodas. Amén.\n";
    return 0;
}
