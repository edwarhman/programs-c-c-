Algoritmo Redondearcentenas
	Definir A,B,C,N,M Como Entero;
	Escribir 'Encabezado del programa.';
	Escribir 'Pedir N';
	Leer N;
	Si N MOD 100!=0 Entonces
		Si N>100 Entonces
			A <- (N-(N MOD 1000))/1000;
			B <- (N MOD 1000-(N MOD 1000 MOD 100))/100;
			C <- (N MOD 1000 MOD 100-(N MOD 1000 MOD 100 MOD 10))/10;
			Si C>=5 Entonces
				M <- A*1000+(B+1)*100;
			SiNo
				M <- A*1000+B*100;
			FinSi
		SiNo
			Si N>=50 Entonces
				M <- 100;
			SiNo
				M <- 0;
			FinSi
		FinSi
		Escribir "El resultado es: ",M;
	SiNo
		M <- N;
	FinSi
FinAlgoritmo
