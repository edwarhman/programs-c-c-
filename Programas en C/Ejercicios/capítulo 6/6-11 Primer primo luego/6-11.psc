Algoritmo Main
	definir number como entero;
	Escribir "Programa que solicita un numero y halla el primer numero primo superior al numero suministrado.";
	number = pedir_Dato("Por favor ingrese un numero");
	definir i como entero;
	i = number+1;
	Repetir
		Si es_Primo(i) Entonces
			Escribir "i es primo";
			Escribir "detener";
		FinSi
	Mientras Que i>0
FinAlgoritmo

Funcion lo_es <- es_Primo(number)
	definir lo_es como logico;
	definir i como entero;
	definir resto como entero;
	i = 2;
	lo_es = verdadero;
	Mientras i<number Hacer
		resto = numero%i;
		Si resto==0 Entonces
			lo_es = falso;
			Escribir "Detener";
		FinSi
	FinMientras
FinFuncion

Funcion dato <- pedir_Dato(mensaje)
	definir dato como entero;
	definir entrada como caracter;
	Repetir
		Escribir mensaje;
		Leer dato;
		Si dato<=0 Entonces
			Leer entrada;
			Escribir dato invalido;
		FinSi
	Mientras Que dato<=0
FinFuncion

Funcion SinTitulo
	
FinFuncion
