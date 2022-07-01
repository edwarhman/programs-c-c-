#include <iostream>
#include "miLibreria.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a = 15;
	int b = 16;
	cout << "a + b = " << Matematicas::sumar(a, b) << endl;
	
	return 0;
}
