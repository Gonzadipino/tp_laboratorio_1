#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Biblioteca.h"
#include "parser.h"

Employee* employee_new() {

	return(Employee*)malloc(sizeof(Employee));

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* SueldoStr) {

	 Employee* EmpleadoNuevo = NULL;
	 EmpleadoNuevo = employee_new();

	 if(EmpleadoNuevo != NULL) {

		 employee_setId(EmpleadoNuevo, atoi(idStr));
    	 employee_setNombre(EmpleadoNuevo, nombreStr);
		 employee_setHorasTrabajadas(EmpleadoNuevo,atoi(horasTrabajadasStr));
		 employee_setSueldo(EmpleadoNuevo, atoi(SueldoStr)); // hacer validacion con los setters

	 } else {
			employee_delete(EmpleadoNuevo);
			EmpleadoNuevo = NULL;
		 }

	 return EmpleadoNuevo;
}


void employee_delete(Employee* this) {

	if(this!= NULL) {//veriico que sea distinto de null, de ser asi no hago nada

		free(this);
		this = NULL;
	}
}

int employee_setId(Employee* this,int id) {

	int retorno = -1;

	if(this !=NULL && id >= 0) {//verifico que la dir de memoria sea distnta de null y en caso de ser asi, me fijo que el valor sea mayor o igual a cero

		this-> id = id;
		retorno = 0;
	}

return retorno;
}

int employee_getId(Employee* this,int* id) {

	int retorno = -1;

	if(this != NULL && id != NULL) {

		*id= this ->id;
		retorno = 0;

	}

	return retorno;
}



int employee_setNombre(Employee* this,char* nombre) {

	int retorno =-1;

	if(this!= NULL) {

		strcpy(this->nombre, nombre);
		retorno = 0;

	}

	return retorno;

}

int employee_getNombre(Employee* this,char* nombre) {

	int retorno = -1;

	if(this != NULL && nombre != NULL) {

		strcpy(nombre, this->nombre);
		retorno =0;

	}

	return retorno;

}




int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) {

	int retorno = -1;

	if(this != NULL && horasTrabajadas >= 0) {

		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;

	}

return retorno;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas) {

	int retorno = -1;

	if( this != NULL && horasTrabajadas != NULL) {

		*horasTrabajadas = this  ->horasTrabajadas;
		retorno = 0;

	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo) {

	int retorno = -1;

	if(this !=NULL && sueldo >=0) {

		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo) {

	int retorno =-1;

	if(this != NULL && sueldo != NULL) {

	*sueldo = this -> sueldo;
	retorno  = 0;

	}

	return retorno;
}


int employee_Print(Employee* this, int auxId, char* auxNombre, int auxHoras, int auxSueldo) {

	int retorno=-1;

	if(this!= NULL) {

		printf("%5d %30s %10d %8d\n", auxId, auxNombre, auxHoras, auxSueldo);
		retorno = 0;

	}

	return retorno;
}

void employee_Cabecera() {

	printf("   ID                         NOMBRE      HORAS   SUELDO\n");

}


int EmployeeId(FILE* pFile) {

	char idChar[100];
	char nombre[20];
	char horas[20];
	char sueldo[20];
	int validation;
	int id;
	int maxId = -1;
	int flag = 1;

	if(pFile!= NULL) {

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idChar,nombre,horas,sueldo);// consultar como evitar tomar datos innecesarios

		do {
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idChar,nombre,horas,sueldo);
			validation = ValidateIntNumber(idChar);

			if(validation != -1) {

				id = atoi(idChar);

				if(flag == 1 || id > maxId) {

					maxId= id;
					flag=0;
				}

			}

		} while(!feof(pFile));
	}

	return maxId;  //esta funcion trabaja con enteros.
}

//----------------------------------------------------------------------
//funciones de ordenamiento de empleados


int employee_SortBy_Id(LinkedList* this) {

	int opcion;
	int retorno = -1;

	printf("ORDENAMIENTO POR ID:\n0.MAYOR A MENOR\n1.MENOR A MAYOR\n");
	opcion = LoadInt("CRITERIO DE ORDENAMIENTO:", 0, 1);

	system("cls");
	printf("\nPuede que esto demore unos segundos...\n");

	if(ll_sort(this, compareById, opcion) == 0) {

		retorno = 0;
	}

	return retorno;
}

int employee_SortBy_Name(LinkedList* this) {

	int opcion;
	int retorno =-1;

	printf("CRITERO DE ORDENAMIENTO POR NOMBRE:\n0.ASCENDENTE (A-Z)\n1.DESCENDENTE(Z-A)\n");
	opcion = LoadInt("CRITERIO DE ORDENAMIENTO:", 0, 1);
	system("cls");
	printf("\nPuede que esto demore unos segundos...\n");

	if(ll_sort(this, compareByName, opcion) == 0) {

		retorno = 0;
	}

	return retorno;
}

int employee_SortBy_Salary(LinkedList* this) {

	int opcion;
	int retorno =-1;

	printf("ORDENAMIENTO POR SALARIO:\n0.MAYOR A MENOR\n1.MENOR A MAYOR\n");
	opcion = LoadInt("CRITERIO DE ORDENAMIENTO:", 0, 1);
	system("cls");
	printf("\nPuede que esto demore unos segundos...\n");

	if(ll_sort(this, compareBySalary, opcion) ==0) {

		retorno = 0;
	}

	return retorno;

}

int employee_SortBy_Hs(LinkedList* this) {

	int opcion;
	int retorno =-1;

	printf("ORDENAMIENTO DE HORAS TRABAJADAS:\n0.MAYOR A MENOR\n1.MENOR A MAYOR\n");
	opcion = LoadInt("CRITERIO DE ORDENAMIENTO:", 0, 1);
	system("cls");
	printf("\nPuede que esto demore unos segundos...\n");

	if(ll_sort(this, compareByHs, opcion) == 0) {

		retorno = 0;

	}

	return retorno;
}


int compareByName(void* firstEmployee,void* SecondEmployee) {

	int ret;
	char first[50];
	char second[50];

	employee_getNombre(firstEmployee, first);
	employee_getNombre(SecondEmployee, second);
	ret = strcmp(first, second);

	return ret;

}

int compareById(void* firstEmployee,void* SecondEmployee) {

	int ret = 0;
	int firstId;
	int secondId;

	employee_getId(firstEmployee, &firstId);
	employee_getId(SecondEmployee,&secondId);

	if(firstId > secondId) {

		ret = 1;

	} else {

		if(firstId < secondId) {

			ret = -1;
		}
	}

	return ret;

}

int compareByHs(void* firstEmployee,void* SecondEmployee) {

	int ret = 0;
	int firstHs;
	int secondHs;

	employee_getHorasTrabajadas(firstEmployee , &firstHs);
	employee_getHorasTrabajadas(SecondEmployee, &secondHs);

	if(firstHs > secondHs) {

		ret = 1;

	} else {

		if(firstHs < secondHs) {

			ret = -1;
		}
	}

	return ret;
}
int compareBySalary(void* firstEmployee,void* SecondEmployee) {

	int ret = 0;
	int firstSalary;
	int secondSalary;

	employee_getSueldo(firstEmployee,  &firstSalary);
	employee_getSueldo(SecondEmployee, &secondSalary);


	if(firstSalary > secondSalary) {

		ret = 1;

	} else {

		if(firstSalary < secondSalary) {

			ret = -1;

		}
	}

	return ret;
}
