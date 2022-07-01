Algoritmo Main
	definir numero como entero;
	Dimension Perfecto[3];
	definir i como entero;
	i = 0;
	numero = 1;
	Mientras numero<32000&&perfecto[2]==0 Hacer
		Si numero%2==0 Entonces
			Si EsPerfecto(numero) Entonces
				Perfecto[i] = numero;
				i = i+1;
			FinSi
		FinSi
	FinMientras
	Escribir "Los tres primeros números perfectos son ";
	i = 0;
	Mientras i<3 Hacer
		Escribir Perfecto[i];
		i = i+1;
	FinMientras
FinAlgoritmo

Funcion Respuesta <- EsPerfecto(numero)
	definir Respuesta como logico;
	definir i como entero;
	definir suma como entero;
	suma = 0;
	i = 1;
	Mientras i<numero Hacer
		definir resto como entero;
		resto = numero%i;
		Si resto=0 Entonces
			suma = suma+i;
		FinSi
		i = i+1;
	FinMientras
	Si suma=numero Entonces
		Respuesta = verdadero;
	SiNo
		Respuesta = falso;
	FinSi
FinFuncion
