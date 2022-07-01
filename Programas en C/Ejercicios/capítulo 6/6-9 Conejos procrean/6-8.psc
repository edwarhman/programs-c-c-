Algoritmo Main
	Definir conejos_d Como Entero;
	Escribir 'Programa que indica segun el problema de fibonacci Cuantos conejos habra despues de un año habiendo empezado con una pareja. Tambien Calcula cuantos meses son necesarios para conseguir la cantidad de conejos especificada por el usuario.';
	Escribir 'Conejos totales despues de un año';
	Conejos_porAño;
	conejos_d <- Pedir_dato('Ingrese la cantidad de conejos deseados');
	Meses_para_conejos(conejos_d);
FinAlgoritmo

Funcion Conejos_T <- Ciclo_Fertil
	Definir Conejos_T Como Entero;
	Definir Conejos_N Como Entero;
	Definir Conejos_V Como Entero;
	Conejos_T <- 2;
	Conejos_N <- 0;
	Conejos_N <- Conejos_T;
	Conejos_T <- Conejos_V+Conejos_N;
FinFuncion

Funcion Conejos_porAño
	Definir i Como Entero;
	Definir Total Como Entero;
	Mientras i<=12 Hacer
		Total <- Ciclo_Fertil;
		i <- i+1;
	FinMientras
	Escribir 'Hay un total de ';
	Escribir Total;
FinFuncion

Funcion Meses_para_conejos(conejos_d)
	Definir meses Como Entero;
	Definir Total Como Entero;
	meses <- 1;
	Mientras Total<conejos_d Hacer
		Total <- Ciclo_Fertil;
		meses <- meses+1;
	FinMientras
	Escribir 'Para tener los conejos deseados son necesarios';
	Escribir meses;
FinFuncion

Funcion dato <- Pedir_dato(mensaje)
	Definir dato Como Entero;
	Definir entrada Como Caracter;
	Escribir mensaje;
	Mientras dato<1 Hacer
		Leer dato;
		Si dato<1 Entonces
			Leer entrada;
			Escribir "Dato invalido";
		FinSi
	FinMientras
FinFuncion
