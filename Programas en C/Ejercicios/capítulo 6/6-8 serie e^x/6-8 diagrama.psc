Algoritmo Main
	definir x como entero;
	Escribir Programa que bla bla bla;
	x = pedirdato("Ingrese el valor de X: ");
	Serie_Ex(x);
FinAlgoritmo

Funcion resultado <- factorial (n)
	definir resultado como entero;
	resultado = resultado*n;
FinFuncion

Funcion Serie_Ex(x)
	definir suma como entero;
	suma = 1;
	definir i como entero;
	Mientras i<101 Hacer
		suma = suma+(x^i/factorial(i));
		Escribir suma;
	FinMientras
FinFuncion

Funcion numero <- Pedirdato(mensaje)
	definir numero como entero;
	Repetir
		Escribir mensaje;
		Leer numero;
		Si numero<0 Entonces
			Escribir "error";
		FinSi
	Mientras Que numero<0
FinFuncion
