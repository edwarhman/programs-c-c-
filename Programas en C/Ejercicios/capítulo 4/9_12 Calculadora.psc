Algoritmo Calculadora
	definir numero_a Como Real;
	definir numero_b Como Real;
	definir operador Como Caracter;
	definir resultado Como Real;
	Escribir "Calculadora que realiza las operaciones algebraicas b�sicas(suma, resta, multiplicaci�n, divisi�n y c�lculo del resto).";
	Escribir "Para realizar el c�lculo se debe ingresar una expresi�n como la siguiente: 5+19" ;
	Escribir "Utilizar (+) para sumar";
	Escribir "Utilizar (-) para restar";
	Escribir "Utilizara (*) para multiplicar.";
	Escribir "Utilizar (/) para dividir.";
	Escribir "Utilizar (%) para calcular el resto.";
	Escribir "Por favor ingrese la expresi�n a calcular(Ej. 12 + 9):" ;
	Leer numero_a;
	Leer caracter;
	Leer numero b;
	Segun caracter Hacer
		'+':
			resultado = numero_a+numero_b;
		'-':
			resultado = numero_a-numero_b;
		'*':
			resultado = numero_b*numero_a;
		'/':
			resultado = numero_a/numero_b;
		De Otro Modo:
			resultado = numero_a%numero_b;
	FinSegun
	Escribir "A+B=C";
FinAlgoritmo
