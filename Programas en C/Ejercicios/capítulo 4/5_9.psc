Funcion es_bisiesto <- bisiesto (year)
	Definir es_bisiesto Como Logico;
	Si year MOD 4==0 Entonces
		Si year MOD 100==0 Y year MOD 400==0 Entonces
			es_bisiesto <- true;
		SiNo
			es_bisiesto <- false;
		FinSi
	SiNo
		es_bisiesto <- false;
	FinSi
	// return es_bisiesto;  
FinFuncion

Algoritmo dias_del_mes
	Definir year Como Entero;
	Definir mes Como Entero;
	Definir dias Como Entero;
	Escribir 'Pedir mes y año';
	// asigna la lectura a mes y a year. 
	Leer mes,year;
	Segun mes  Hacer
		1,3,5,7,8,10,12:
			dias <- 31;
		,4,6,9,11:
			dias <- 30;
		2:
			Si bisiesto(year) Entonces
				dias <- 29;
			SiNo
				dias <- 28;
			FinSi
		De Otro Modo:
			Escribir 'dato inválido';
	FinSegun
	Escribir 'El mes %d deñ año %d tiene %d dias.';
FinAlgoritmo
