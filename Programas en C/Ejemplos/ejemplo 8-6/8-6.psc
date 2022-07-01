Algoritmo Main
	Escribir "programa que calcula la suma de una lista de numeros y tambien indica cual es el mayor entre ellos.";
	definir tam_lista como entero;
	definir suma como entero;
	definir MAX como entero;
	Dimension  lista(tam_lista);
	suma = 0;
	MAX = 0;
	tam_lista = 10;
	suma = calculaSuma(lista,tam_lista);
	MAX = encontrarMAX(lista,tam_lista);
	Escribir suma;
	Escribir MAX;
FinAlgoritmo

Funcion dato <- PedirEntero(mensaje)
	definir dato como entero;
FinFuncion

Funcion suma <- CalculaSuma(lista,elementos)
	definir suma como entero;
	suma = 0;
	definir i como entero;
	i = 0;
	Repetir
		suma = suma+lista[i];
		i=i+1;
	Mientras Que i<elementos
FinFuncion

Funcion MAX <- EncontrarMAX(lista,elementos)
	definir MAX como entero;
	definir i como entero;
	MAX = 0;
	i = 0;
	Repetir
		Si lista[i]>MAX Entonces
			MAX = lista[i] ;
		SiNo
			i = i+1;
		FinSi
	Mientras Que i<elementos
FinFuncion

Funcion llenarLista(Lista)
	
FinFuncion
