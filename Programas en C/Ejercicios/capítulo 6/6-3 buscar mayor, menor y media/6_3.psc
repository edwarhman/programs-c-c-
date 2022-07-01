Algoritmo Main
	Definir N Como Entero;
	Definir suma Como Entero;
	Definir media Como Real;
	Definir mayor_ Como Entero;
	Definir menor_ Como Entero;
	Definir dato Como Entero;
	Escribir 'Programa que evalua una serie de números e indica cual de ellos mayor y cual es el menor.';
	Escribir 'tambien calcula cual es la media de los números dados.';
	N <- Pedir_dato('Por favor ingrese la cantidad de números que desea evaluar: ');
	Definir i Como Entero;
	i <- 1;
	Mientras i<=N Hacer
		dato <- Pedir_dato('Ingrese el valor: ');
		mayor_ <- Buscar_mayor(dato);
		menor_ <- Buscar_menor(dato);
		suma <- suma+dato;
	FinMientras
	media <- suma/N;
	Escribir 'El mayor numero es: ',mayor_;
	Escribir 'El menor numero es: ',menor_;
	Escribir 'La media es: ',media;
FinAlgoritmo

Funcion dato <- Pedir_dato(mensaje)
	Definir dato Como Entero;
	Definir char Como Caracter;
	Repetir
		Escribir mensaje;
		Leer dato;
		Leer string;
		Si dato<0 Entonces
			Escribir 'error';
		FinSi
	Mientras Que dato<0
FinFuncion

Funcion mayor_n <- Buscar_mayor(dato)
	Definir mayor_n Como Entero;
	mayor_n <- 0;
	Si dato_>mayor_n Entonces
		mayor_n <- dato;
	FinSi
FinFuncion

Funcion menor_n <- Buscar_menor(numero_)
	Definir menor_n Como Entero;
	menor_n <- 32000;
	Si numero_<menor_n Entonces
		menor_n <- numero_;
	FinSi
FinFuncion
