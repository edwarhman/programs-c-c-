Algoritmo Calculadora
	definir numero_a Como Real;
	definir numero_b Como Real;
	definir operador Como Caracter;
	definir resultado Como Real;
	Escribir "Calculadora que realiza las operaciones algebraicas básicas(suma, resta, multiplicación, división y cálculo del resto).";
	Escribir "Para realizar el cálculo se debe ingresar una expresión como la siguiente: 5+19" ;
	Escribir "Utilizar (+) para sumar";
	Escribir "Utilizar (-) para restar";
	Escribir "Utilizara (*) para multiplicar.";
	Escribir "Utilizar (/) para dividir.";
	Escribir "Utilizar (%) para calcular el resto.";
	Escribir "Por favor ingrese la expresión a calcular(Ej. 12 + 9):" ;
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
