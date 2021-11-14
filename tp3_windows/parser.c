#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Biblioteca.h"
#include "controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {

	int retorno = -1;
	char id[100];
	char nombre[100];
	char horas[100];
	char sueldo[100];
	int splits;
	Employee* pEmployeeText;

	if(pFile!=NULL && pArrayListEmployee != NULL) {

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);//hago una lectura previa para evitar la cabecera del archivo
		while(!feof(pFile)) {

			splits = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);//validar splits

			if(splits == 4) {

				 if(ValidateIntNumber(id) != -1 && ValidateString(nombre) != -1 && ValidateIntNumber(horas)!= -1 && ValidateIntNumber(sueldo) != -1) {

					 pEmployeeText = employee_newParametros(id, nombre, horas, sueldo);

					if(pEmployeeText == NULL) {
						printf("hasta aca llego");
						break;

					} else {

						if(ll_add(pArrayListEmployee, pEmployeeText) != -1) {

							  retorno = 0; // usar lo que devuelve add, no permitir
						}

					}

				}
			}

		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) {

	int retorno = -1;
	Employee* pEmployeeBin = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL) {

		while(!feof(pFile)) {

			pEmployeeBin = employee_new();

			if(pEmployeeBin != NULL) {

				if(fread(pEmployeeBin,sizeof(Employee),1,pFile) == 1) {

					ll_add(pArrayListEmployee,pEmployeeBin);
					retorno = 0;

				}

			} else {

			break;

			}
		}
	}
	return retorno;
}

int parser_setIdFromBinary(char* pathId) {

		FILE * pArchivo = NULL;
		int auxId = -1;
		int flag = 1;
		pArchivo = fopen(pathId, "rb"); // leo el archivo binario y obtengo el ultimo id
		if(pArchivo != NULL) {
			fread(&auxId,sizeof(int),1, pArchivo);
			auxId++; // lo incremento
			flag = 0;
		}
		fclose(pArchivo); // cierro archvo

		if(flag == 0) { //solo lo sobreescribo si lo pude incrementar
			pArchivo= fopen(pathId, "wb");
			if(pArchivo != NULL) {
				fwrite(&auxId,sizeof(int),1,pArchivo);
			}

			fclose(pArchivo); //cierro el archivo
		}

		return auxId;


}

int parser_GetLastId(char* pathId) {

	FILE * pArchivo = NULL;
	int auxId = -1;

	pArchivo = fopen(pathId, "rb"); // leo el archivo binario y obtengo el ultimo id
	if(pArchivo != NULL) {

		fread(&auxId,sizeof(int),1, pArchivo);

	}

	fclose(pArchivo); // cierro archvo
	return auxId;

}

