Algoritmo main
	Definir terminos Como Entero;
	Escribir 'Programa que calcula el valor de PI.';
	terminos <- Pedir_dato('Por favor ingrese el número de terminos:');
	Calcular_PI(terminos);
FinAlgoritmo

Funcion N_terminos <- Pedir_dato(mensaje)
	Definir N_terminos Como Entero;
	Repetir
		Escribir mensaje;
		Leer N_terminos;
		Si n<1 Entonces
			Escribir 'Entrada inválida';
		FinSi
	Mientras Que n<1
FinFuncion

Funcion Calcular_PI(terminos)
	Definir pi_ Como Real;
	Definir i Como Entero;
	pi_ = 3;
	i <- 1;
	Repetir
		pi_ <- -pi_-(4/i*i+1*i+2);
		i <- i+2;
	Mientras Que i<=n*2
	Escribir 'El valor de PI es ',PI;
FinFuncion
