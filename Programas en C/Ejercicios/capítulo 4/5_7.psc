Algoritmo calcular_edad
	Definir dia_n,dia_a,mes_n,mes_a,year_n,year_a,dif_d,dif_m,dif_y Como Entero;
	Definir char Como Caracter;
	Escribir 'Programa que calcula la edad de un individuo según su fecha de nacimiento y la fecha actual.';
	Escribir 'Por favor ingrese su fecha de nacimiento: ';
	Leer dia_n,char,mes_n,char,year_n;
	Escribir 'Por favor ingrese la fecha actual: ';
	Leer dia_a,char,mes_a,char,year_a;
	dif_d <- dia_a-dia_n;
	dif_m <- mes_a-mes_n;
	dif_y <- year_a-year_n;
	Si dif_m>=0 Entonces
		Si dif_m==0 Entonces
			Si dif_d<0 Entonces
				Escribir dif_y-1;
			SiNo
				Escribir dif_y;
			FinSi
		SiNo
			Escribir dif_y;
		FinSi
	SiNo
		Escribir dif_y-1;
	FinSi
FinAlgoritmo
