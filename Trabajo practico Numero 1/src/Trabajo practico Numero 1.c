/*
 ============================================================================
 Name        : Calculadora
 Author      : Di Pino Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico N°1
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Prototipo_calculadora.h"

int main(void)

{
	setbuf(stdout,NULL);


	int opcionMain=0;
	int flagoperandoUno=1;
	int flagoperandoDos=1;
	float operandoUno=0;
	float operandoDos=0;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	int factorialA;
	int factorialB;
	char enter;
	PrintMenu("x", operandoUno, "y", operandoDos,"", "Opcion: ");
    do{


		opcionMain= ElegirOpcion(flagoperandoUno,operandoUno, operandoDos, flagoperandoDos);
		fflush(stdin);

	switch(opcionMain)
	{
	    case 1:
	    PrintMenu("", operandoUno, "", operandoDos,"1.Ingresar 1er operando(A=x):","");
	    operandoUno=TomarNumero();
	    flagoperandoUno=0;
	    break;

	    case 2:
	    PrintMenu("", operandoUno, "", operandoDos,"2.Ingresar 2do operando(B=y): ","");
	    operandoDos=TomarNumero();
	    flagoperandoDos=0;
	    break;

	    case 3:

	     PrintMenu("", operandoUno, "", operandoDos,"","");
	     CargarResultados(operandoUno,operandoDos);
	     printf("Resultados cargados correctamente. Presione una tecla para continuar.");
	      scanf("%c",&enter);
	       fflush(stdin);

	     CalcularOperaciones (operandoUno, operandoDos, &suma, &resta, &multiplicacion, &division, &factorialA, &factorialB);

	    break;
	    case 4:
	    PrintMenu("", operandoUno, "", operandoDos, "","");
	    MostrarResultados(operandoUno, operandoDos, suma, resta, multiplicacion, division, factorialA, factorialB);

	    printf("\nPresione cualquier tecla para volver al menú. \n");
	    scanf("%c", &enter);
	    fflush(stdin);
	    break;
	}
	 PrintMenu("", operandoUno, "", operandoDos,"","Opcion:");


    }while (opcionMain!=5);





	return EXIT_SUCCESS;
}
