Algoritmo Salario
	Definir horas_s Como Entero;
	Definir tasa Como Entero;
	Definir salario_bruto Como Real;
	Definir salario_neto Como Real;
	Escribir 'programa que calcula el salario neto.';
	Escribir 'Por favor ingrese la tasa a la que se pagan las horas de trabajo: ';
	Leer tasa;
	Escribir 'Por favor ingrese las horas semanales trabajadas: ';
	Leer horas_s;
	Si horas_s<38 Entonces
		salario_bruto <- horas_s*4*tasa;
	SiNo
		salario_bruto <- horas_s*4*tasa*1.5;
	FinSi
	Si salario_bruto<50000 Entonces
		salario_neto <- salario_bruto;
	SiNo
		salario_neto <- salario_bruto-(salario_bruto*0.1);
	FinSi
	Escribir 'El salario neto es %d',salario_neto;
FinAlgoritmo
