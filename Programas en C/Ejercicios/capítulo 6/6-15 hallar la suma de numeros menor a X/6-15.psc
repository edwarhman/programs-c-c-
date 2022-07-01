Algoritmo Main
	definir number como entero;
	Escribir "Programa que encuentra el primer numero natural cuya suma con los numeros que le preceden es mayor a un numero ingresado por el usuario.";
	number = pedir_Dato("Por favor ingrese un numero entero: ");
	EvaluarSuma(number);
FinAlgoritmo

Funcion suma <- sumadeN(number)
	Definir suma Como Entero;
	Definir i Como Entero;
	suma <- 0;
	i <- 0;
	Repetir
		suma <- suma+(number-i);
	Mientras Que i<number
FinFuncion

Funcion EvaluarSuma(number)
	Definir i Como Entero;
	i <- 2;
	Mientras sumadeN(i)<=number Hacer
		i <- i+1;
	FinMientras
	Escribir i;
FinFuncion

Funcion dato <- pedir_Dato(mensaje)
	Definir dato Como Entero;
	Definir entrada Como Caracter;
	Repetir
		Escribir mensaje;
		Leer dato;
		Si dato<=0 Entonces
			Leer entrada;
			Escribir dato,invalido;
		FinSi
	Mientras Que dato<=0
FinFuncion
