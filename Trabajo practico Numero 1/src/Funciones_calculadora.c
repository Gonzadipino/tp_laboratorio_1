/*
 ============================================================================
 Name        : Calculadora
 Author      : Di Pino Gonzalo
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico N°1
 ============================================================================*/
#include "Prototipo_calculadora.h"
/// @param caracterUno
/// @param numeroUno
/// @param caracterDos
/// @param numeroDos
/// @param mensaje
/// @param opcion
void PrintMenu(char caracterUno[], float numeroUno, char caracterDos[], float numeroDos, char mensaje[], char opcion[])

{

	fflush(stdin);
	system("cls");
	printf(" 1. Ingresar 1er operando (A=%s %.2f)\n",caracterUno,numeroUno);
	printf(" 2. Ingresar 2do operando (B=%s %.2f)\n",caracterDos,numeroDos);
	printf("\n");
	printf(" 3. Calcular todas las operaciones\n");
	printf("    a) Calcular la suma (A+B)\n");
	printf("    b) Calcular la resta (A-B)\n");
	printf("    c) Calcular la division (A/B)\n");
	printf("    d) Calcular la multiplicacion (A*B)\n");
	printf("    e) Calcular el factorial (A!)\n");
	printf("\n");
	printf(" 4. Informar resultados\n");
    printf("\n");
	printf(" 5. Salir\n");
	printf("%s\n", mensaje);
	printf("%s",  opcion);

}
/// @param flag1
/// @param operandoUno
/// @param operandoDos
/// @param flag2
/// @return
int  ElegirOpcion(int flag1, float operandoUno, float operandoDos, int flag2)
{
	int opcionFuncion;
	int flagFuncion1;
	int flagFuncion2;
	flagFuncion1=flag1;
	flagFuncion2=flag2;

	scanf("%d", &opcionFuncion);
	while (((flagFuncion1==1 || flagFuncion2==1) && (opcionFuncion==3 || opcionFuncion==4)) || opcionFuncion <1 || opcionFuncion >5)
	{
	    if(opcionFuncion==3|| opcionFuncion==4)
	    {
	    PrintMenu("x",operandoUno,"y", operandoDos, "Error. Primero ingrese operandos", "Opcion: ");
	    }
	    else
	    {
	    PrintMenu("x",operandoUno,"y", operandoDos, "Error. Primero ingrese operandos", "Opcion: ");
	    }
	    scanf("%d", &opcionFuncion);
	    fflush(stdin);
	}
	return opcionFuncion;
}
/// @return
float TomarNumero(void)
{
    float numero;
    fflush(stdin);
    scanf("%f", &numero);
    fflush(stdin);
    return numero;
}

/// @param operandoUno
/// @param operandoDos
/// @param suma
/// @param resta
/// @param multiplicacion
/// @param division
/// @param factorialA
/// @param factorialB
void CalcularOperaciones (float operandoUno, float operandoDos, float *suma, float *resta, float *multiplicacion, float *division, int *factorialA, int *factorialB)
    {
      float sumar, restar, dividir, multiplicar;
      int factorialUno, factorialDos;
      float primerNumero;
      float segundoNumero;
      primerNumero = operandoUno;
      segundoNumero = operandoDos;

      sumar =FuncionSumar (primerNumero, segundoNumero);
      restar = FuncionRestar (primerNumero, segundoNumero);
      multiplicar = FuncionMultiplicar (primerNumero, segundoNumero);
      dividir = FuncionDividir (primerNumero, segundoNumero);

      if(primerNumero==0)
      {
      factorialUno=1;
      }
      else
      {
      factorialUno=FuncionFactorial (primerNumero);
      }
      if(segundoNumero==0)
      {
      factorialDos=1;
      }
      else
      {
      factorialDos=FuncionFactorial (segundoNumero);
      }
    *suma=sumar;
    *resta=restar;
    *division=dividir;
    *multiplicacion=multiplicar;
    *factorialA=factorialUno;
    *factorialB=factorialDos;
    }



/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionSumar (float primerNumero, float segundoNumero)
{
  float resultado;
  resultado = primerNumero + segundoNumero;
  return resultado;
}
/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionRestar(float primerNumero, float segundoNumero)
{
  float resultado;
  resultado = primerNumero - segundoNumero;
  return resultado;
}
/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionMultiplicar(float primerNumero, float segundoNumero)
{
  float resultado;
  resultado = primerNumero * segundoNumero;
  return resultado;
}
/// @param primerNumero
/// @param segundoNumero
/// @return
float FuncionDividir(float primerNumero, float segundoNumero)
{
  float resultado;

  resultado = primerNumero / segundoNumero;

  return resultado;
}

/// @param numero
/// @return
int FuncionFactorial(float numero)
{
 float numeroFloat=numero;
 float numeroInt;
 int factorial= numero;

 if (numero>=1)
 {
    numeroInt = numeroFloat -(int)numero;
 }
 else if (numero<=-1)
 {
 numeroInt = (-1 * numeroFloat) + (int)numero;
 }

 if(numeroInt!=0)
 {
    factorial=0;
 }
 else
 {
     if( factorial!=15)
    {
       if (numero>0 )
       {
            while(numero>1)
            {
                numero--;
                factorial=factorial*numero;
            }
        }
        else
        {
            while(numero<-1)
            {
                numero++;
                factorial=factorial*numero;
                factorial = factorial*-1;
            }

        }
    }
 }
 return factorial;
}
/// @param primerNumero
/// @param segundoNumero
void CargarResultados(float primerNumero, float segundoNumero)
{
    printf(" 3. Calcular todas las operaciones:\n");
	printf("    a) Calcular la suma (%.2f + %.2f)\n",primerNumero, segundoNumero);
	printf("    b) Calcular la resta (%.2f - %.2f)\n",primerNumero,segundoNumero);
	if(segundoNumero==0)
	{
	printf("    c) Calcular la division: No se puede dividir por 0.\n");
	}
	else
	{
	printf("    c) Calcular la division (%.2f / %.2f)\n",primerNumero,segundoNumero);
	}
	printf("    d) Calcular la multiplicacion (%.2f * %.2f)\n",primerNumero,segundoNumero);
	printf("    e) Calcular el factorial (%f!)\n",primerNumero);
	printf("       Calcular el factorial (%f!)\n",segundoNumero);
}
/// @param operandoUno
/// @param operandoDos
/// @param suma
/// @param resta
/// @param multiplicacion
/// @param division
/// @param factorialA
/// @param factorialB
void MostrarResultados(float operandoUno,float operandoDos,float  suma, float resta, float multiplicacion,float division, int  factorialA, int factorialB)
{
    printf("a) El resultado de %.2f + %.2f es: %.2f\n",operandoUno,operandoDos,suma);
    printf("b) El resultado de %.2f - %.2f es: %.2f\n",operandoUno,operandoDos,resta);
    if(operandoDos==0)
    {
    printf("c) No es posible dividir por 0.\n");
    }else
    {
    printf("c) El resultado de %.2f / %.2f es: %.2f\n",operandoUno,operandoDos,division);
    }
    printf("d) El resultado de %.2f * %.2f es: %.2f\n",operandoUno,operandoDos,multiplicacion);
    if(factorialA==0)
    {
    printf("e) No es posible hacer el factorial de un numero con decimales.\n");
    }
    else if (operandoUno>12|| operandoUno<-12)
    {
        printf("e) No es posible realizar el factorial de un numero mayor a 12.\n");
    }else
    {
    printf("e) El factorial de %.0f es: %d\n",operandoUno,factorialA);
    }
     if(factorialB==0)
    {
    printf("   No es posible hacer el factorial de un numero con decimales.\n");
    }
    else if (operandoDos>12|| operandoDos<-12)
    {
        printf("e) No es posible realizar el factorial de un numero mayor a 12.\n");
    }
    else
    {
    printf("   El factorial de %.0f es: %d\n",operandoDos,factorialB);
    }

}

