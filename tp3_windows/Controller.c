#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX_SUELDO 1000001
#define  MAX_HORAS  744

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Biblioteca.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {

	FILE* pArchivo;
	int state = -1;

	system("cls");

	pArchivo = fopen(path,"r"); //cargo el path y la lectura en modo texto

	if(pArchivo != NULL) { // si el archivo se abrio y no es null, llamo la parser para manejar los datos

		state = parser_EmployeeFromText(pArchivo, pArrayListEmployee); // parsser devuelve el estado 0 o -1, si pudo cargar aunque sea un dato o no se pudo cargar ninguno
		AlertMessage(state, "Lista cargada correctamente", "No se pudo cargar la lista.");

	} else {

		printf("ERROR. EL ARCHIVO.CSV NO EXISTE.\n");

	}

	fclose(pArchivo);
	return state;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {

	int state = -1;
	FILE* pArchivo;
	pArchivo = fopen(path, "rb");

	system("cls");

	if(pArchivo != NULL) {

		state = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		AlertMessage(state, "Lista cargada correctamente", "No se pudo cargar la lista.");

	} else {

		printf("ERROR. EL ARCHIVO .BIN NO EXISTE.\n");
	}

	fclose(pArchivo);
    return state;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee) {

	Employee* pEmployee = NULL;
	int auxId;
	char auxIdChar[50];
	char auxNombre[50];
	char auxHorasTrabajadas[50];
	char auxSueldo[50];
	int retorno = -1;

	system("cls");

	if(pArrayListEmployee != NULL) {

		printf("*************************** A L T A   D E   E M P L E A D O ***************************\n");
		auxId = parser_setIdFromBinary("Max_ID.bin");
		sprintf(auxIdChar,"%d",auxId);
		LoadString("Ingrese un nombre: ", auxNombre);
		LoadIntReturnChar("Ingrese las horas trabajadas: ", 0 , MAX_HORAS, auxHorasTrabajadas);
		LoadIntReturnChar("Ingrese el sueldo: $", 1, MAX_SUELDO, auxSueldo);

		pEmployee = employee_newParametros(auxIdChar, auxNombre, auxHorasTrabajadas, auxSueldo);

		if(pEmployee != NULL) {

			ll_add(pArrayListEmployee, pEmployee);
			retorno=0;

		} else {

			printf("No hay espacio.\n");

		}

	}

	return retorno;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee) {

	Employee* auxEmployee = NULL;
	int retorno = -1;
	int idSeleccionado;
	int opcionConfirmacion;
	int opcionCampo;
	int flagModificacion = -1;
	char auxNombre[50];
	int auxHorasTrabjadas;
	int auxSueldo;
	int idMasAlto;

	system("cls");

	printf("*************************** M O D I F I C A C I O N   D E   E M P L E A D O ***************************\n");
	controller_ListEmployee(pArrayListEmployee);
	idMasAlto = parser_GetLastId("Max_ID.bin");
	idSeleccionado = LoadInt("Ingrese el id que desea modificar: ", 1, idMasAlto);

	for(int i = 0; i<ll_len(pArrayListEmployee); i++) {

			auxEmployee = ll_get(pArrayListEmployee, i);
			if(auxEmployee != NULL) {

				if(idSeleccionado == auxEmployee->id) {

					employee_Print(auxEmployee, auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
					opcionConfirmacion = LoadInt("Es este el usuario que desea modificar?\n 1.CONFIRMAR\n 2. CANCELAR\n", 1, 2);

					if(opcionConfirmacion == 1) {

						retorno = 0;
						do {
							system("cls");
							printf("*************************** M O D I F I C A C I O N   D E   E M P L E A D O ***************************\n");

							if(flagModificacion == 0) {

							printf("Campo modificado correctamente.\n");

							}

							printf("Que campo desea modificar? \n 1. NOMBRE\n 2. HORAS TRABAJADAS\n 3.SUELDO\n\n 0.VOLVER\n");
							opcionCampo = LoadInt(" Opcion: ", 0, 3);

							switch (opcionCampo) {

								case 1:

									LoadString("Ingrese nuevo nombre: ", auxNombre);
									employee_setNombre(auxEmployee, auxNombre);
									flagModificacion = 0;
								break;

								case 2:

									auxHorasTrabjadas = LoadInt("Ingrese nuevas horas trabajadas: ", 0, MAX_HORAS);
									employee_setHorasTrabajadas(auxEmployee, auxHorasTrabjadas);
									flagModificacion = 0;
								break;

								case 3:

									auxSueldo = LoadInt("Ingrese nuevo sueldo: $", 1, MAX_SUELDO);
									employee_setSueldo(auxEmployee, auxSueldo);
									flagModificacion = 0;
								break;

							}

						} while(opcionCampo!=0);

						if(flagModificacion != 0) {

							printf("No se modifico ningun campo.");

						}
					}
				break;
				}
			}
		}

    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {

	Employee* auxEmployee = NULL;
	int retorno = -1;
	int idSeleccionado;
	int opcion;
	int idMasAlto;
	int flag;

	system("cls");

	printf("*************************** B A J A   D E   E M P L E A D O ***************************\n");
	controller_ListEmployee(pArrayListEmployee);
	idMasAlto = parser_GetLastId("Max_ID.bin");
	idSeleccionado = LoadInt("Ingrese el id que desea borrar: ", 1, idMasAlto);

	for(int i = 0; i<ll_len(pArrayListEmployee); i++) {

		auxEmployee = ll_get(pArrayListEmployee, i);

		if(auxEmployee != NULL) {

			if(idSeleccionado == auxEmployee->id) {

				employee_Print(auxEmployee, auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
				opcion = LoadInt("Es este el usuario que desea borrar?\n 1.CONFIRMAR\n 2. CANCELAR\n", 1, 2);

				if(opcion == 1) {

					retorno = 0;
					ll_remove(pArrayListEmployee, i);
					employee_delete(auxEmployee);

				} else {

					printf("operacion cancelada.\n");
					retorno = -1;
					flag = 0;

				}
				break;
			}
		}
	}

	if(retorno == -1 && flag != 0) {

		printf("No se encontro el empleado.\n");

	}

    return retorno;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {

	int retorno = -1;
	char auxNombre[120];
	int auxId;
	int auxHoras;
	int auxSueldo;

	Employee* pEmpleadoAux = NULL;

	system("cls");

	employee_Cabecera();

		if(pArrayListEmployee != NULL) {

			for(int i = 0; i< ll_len(pArrayListEmployee); i++) {

				pEmpleadoAux = ll_get(pArrayListEmployee, i);
				if(employee_getNombre(pEmpleadoAux, auxNombre) == 0 && employee_getId(pEmpleadoAux, &auxId) == 0 &&
					employee_getHorasTrabajadas(pEmpleadoAux, &auxHoras) == 0 && employee_getSueldo(pEmpleadoAux, &auxSueldo) ==0) {

					retorno = 0;
					employee_Print(pEmpleadoAux, auxId, auxNombre, auxHoras, auxSueldo);

				}
			}
		}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee) {

	int retorno= -1;
	int opcion;

	system("cls");

	if(pArrayListEmployee != NULL) {


		printf("*************************** O R D E N A R   E M P L E A D O S ***************************\n");
		printf("1. ORDENAR POR ID\n2. ORDENAR POR NOMBRE\n3. ORDENAR POR SUELDO\n4. ORDENAR POR HORAS TRABAJADAS\n\n0.VOLVER\n");
		opcion = LoadInt("OPCION:", 0,4);
		system("cls");

		switch (opcion) {
			case 1:
				if(employee_SortBy_Id(pArrayListEmployee)== 0) {

					retorno = 0;
				}
				break;

			case 2:
				if(employee_SortBy_Name(pArrayListEmployee)== 0) {

					retorno= 0;
				}
				break;

			case 3:
				if(employee_SortBy_Salary(pArrayListEmployee)== 0) {

					retorno = 0;
				}
				break;

			case 4:
				if(employee_SortBy_Hs(pArrayListEmployee)== 0) {

					retorno = 0;
				}
				break;

			case 0:
				break;
		}
	}

    return retorno;

}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {

	FILE* pArchivo = NULL;
	Employee* pEmployee = NULL;
	int retorno = -1;
	int auxId;
	char auxNombre[50];
	int auxHoras;
	int auxSueldo;

	system("cls");

	if(path != NULL && pArrayListEmployee != NULL) {

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL) {
			fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

			for(int i = 0; i<ll_len(pArrayListEmployee); i++) {

				pEmployee = ll_get(pArrayListEmployee, i);

				if(pEmployee != NULL) {

					if(employee_getId(pEmployee, &auxId) == 0 && employee_getNombre(pEmployee, auxNombre) == 0 &&
					employee_getHorasTrabajadas(pEmployee, &auxHoras) == 0 && employee_getSueldo(pEmployee, &auxSueldo) == 0) {

						fprintf(pArchivo,"%d,%s,%d,%d\n", auxId,auxNombre,auxHoras,auxSueldo);
						retorno = 0;

					}
				}
			}

			fclose(pArchivo);
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee) {

	FILE* pArchivo = NULL;
	Employee* pEmployee = NULL;
	int retorno = -1;

	system("cls");

	pArchivo = fopen(path, "wb");

	if(pArchivo != NULL) {

		for(int i = 0; i<ll_len(pArrayListEmployee); i++) {

			pEmployee = ll_get(pArrayListEmployee, i);

			if(pEmployee != NULL) {

					fwrite(pEmployee,sizeof(Employee),1,pArchivo);
					retorno = 0;

			}
		}
	}

    return retorno;
}

/*int controller_getIdFromText(char* pathLista ,char* pathId) {

	FILE* pArchivo = NULL;
	FILE* pArchivoID = NULL;
		int maxId = 0;
		int retorno =-1;

		pArchivo = fopen(pathLista,"r");
		if(pArchivo!= NULL) {
		maxId = EmployeeId(pArchivo);
		}
		fclose(pArchivo);

		pArchivoID = fopen(pathId,"wb");
		if(pArchivoID!=NULL){
			fwrite(&maxId,sizeof(int),1, pArchivoID);
			fclose(pArchivoID);
			retorno  = 0;
			}

		return retorno; // funcion que hice y no use ( borrada en correccion)
}
*/


