Algoritmo Aumento_salario
	Definir salario Como Real;
	Definir salario_nuevo Como Real;
	Escribir 'Programa que cálcula el salario de un trabajador según la siguiente tabla:';
	Escribir 'Salario en dólares				Aumento %';
	Escribir '0 a 9000		20';
	Escribir '9001 a 15000			10';
	Escribir '15001 a 20000			5';
	Escribir 'más de 20000			0';
	salario <- Pedir_entrada;
	Si salario>9000 Entonces
		Si salario>15000 Entonces
			Si salario>20000 Entonces
				salario_nuevo <- salario;
			SiNo
				salario_nuevo <- salario+(salario*0.05);
			FinSi
		SiNo
			salario_nuevo <- salario+(salario*0.1);
		FinSi
	SiNo
		salario_nuevo <- salario+(salario*0.2);
	FinSi
	Escribir 'El nuevo salario es',salario,nuevo;
FinAlgoritmo

Funcion entrada <- dir_entrada
	Definir entrada Como Entero;
	Escribir 'Por favor ingrese el salario: ';
	Leer salario;
FinFuncion
