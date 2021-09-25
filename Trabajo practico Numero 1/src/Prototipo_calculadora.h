/*
 ============================================================================
 Name        : Calculadora
 Author      : Di Pino Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico N°1
 ============================================================================*/

#ifndef PROTOTIPO_CALCULADORA_H_
#define PROTOTIPO_CALCULADORA_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/// @param caracterUno
/// @param numeroUno
/// @param caracterDos
/// @param numeroDos
/// @param mensaje
/// @param opcion
void PrintMenu(char caracterUno[], float numeroUno, char caracterDos[], float numeroDos, char mensaje[], char opcion[]);
/// @param flag1
/// @param operandoUno
/// @param operandoDos
/// @param flag2
/// @return
int  ElegirOpcion(int flag1, float operandoUno, float operandoDos, int flag2);
/// @return
float TomarNumero(void);
/// @param operandoUno
/// @param operandoDos
/// @param suma
/// @param resta
/// @param multiplicacion
/// @param division
/// @param factorialA
/// @param factorialB
void CalcularOperaciones (float operandoUno, float operandoDos,
			 float *suma, float *resta, float *multiplicacion,
			 float *division, int *factorialA, int *factorialB);
/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionSumar (float primerNumero, float segundoNumero);
/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionRestar(float primerNumero, float segundoNumero);
/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionMultiplicar(float primerNumero, float segundoNumero);
/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionDividir(float primerNumero, float segundoNumero);
/// @param numero
/// @return
int FuncionFactorial(float numero);
/// @param primerNumero
/// @param segundoNumero
void CargarResultados(float primerNumero, float segundoNumero);
/// @param operandoUno
/// @param operandoDos
/// @param suma
/// @param resta
/// @param multiplicacion
/// @param division
/// @param factorialA
/// @param factorialB
void MostrarResultados(float operandoUno,float operandoDos,float  suma, float resta, float multiplicacion,float division, int  factorialA, int factorialB);



#endif /* PROTOTIPO_CALCULADORA_H_ */
