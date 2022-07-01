Algoritmo Main
	definir numero como entero;
	numero = 1900;
	Mientras numero <=2000 Hacer
		Factorial(numero);
		numero = numero+1;
	FinMientras
FinAlgoritmo

Funcion Factorial(numero)
	Definir i Como Entero;
	i <- 2;
	Mientras i<numero Hacer
		Si numero MOD i==0 Entonces
			Escribir i;
			numero <- numero/i;
		SiNo
			i <- i+1;
		FinSi
	FinMientras
FinFuncion
