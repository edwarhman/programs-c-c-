Algoritmo Main
	Escribir "Programa que muestra los años que son bisiestos en el siglo XXII";
	definir year como entero;
	year = 2101;
	Mientras year<2201 Hacer
		Si Calcular_bisiesto(year) Entonces
			Escribir year;
		FinSi
		year = year+1;
	FinMientras
FinAlgoritmo

Funcion es_bisiesto <- bisiesto (year)
	definir es_bisiesto como logico;
	Si year % 4==0 Entonces
		Si year %100==0 && year %400==0 Entonces
			es_bisiesto = verdadero;
		SiNo
			es_bisiesto = falso;
		FinSi
	SiNo
		es_bisiesto = falso;
	FinSi
FinFuncion
