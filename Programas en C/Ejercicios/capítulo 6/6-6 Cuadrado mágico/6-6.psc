Algoritmo CUADRADO_MAGICO
	Definir rango Como Entero;
	Dimension cuadrado[10,10];
	Escribir 'programa que visualiza un cuadrado mágico de orden impar comprendico entre 3 y 11.';
	Escribir 'Por favor ingrese un valor para N que sea inpar y que este comprendido entre 3 y 11:';
	Leer rango;
	Definir i Como Entero;
	Definir m Como Entero;
	Definir n Como Entero;
	i <- 1;
	m <- 0;
	n <- 1;
	Mientras i<=rango*rango Hacer
		Si m>=rango Entonces
			m <- 0;
		FinSi
		Si n<0 Entonces
			n <- rango-1;
		FinSi
		Si cuadrado[m,n]!=0 Entonces
			m <- m-1;
			n <- n+2;
		FinSi
		Si m<0 Entonces
			m = rango-1;
		FinSi
		Si n>rango Entonces
			n = n- rango;
		FinSi
		cuadrado[m,n]<-i;
	FinMientras
	m = 0;
	n = 0;
	Mientras n<rango Hacer
		Escribir cuadrado[m,n];
		Si m>=rango-1 Entonces
			Escribir "Salto de línea";
			m = 0;
			n = n+1;
		SiNo
			m = m+1;
		FinSi
	FinMientras
FinAlgoritmo
