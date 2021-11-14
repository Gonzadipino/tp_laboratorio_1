#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "Biblioteca.h"

int main() {

	setbuf(stdout,NULL);

    int option      = 0 ;
    int estado         ;
    int flagCarga   = 0;
    int flagBinario = 0;
    int flagTexto   = 0;
    int flagGuardado= 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do {
    	flagCarga = ll_isEmpty(listaEmpleados); // verifico que la lista este cargada con almenos un dato

    	system("cls");
    	printf("***************************************** T R A B A J O   P R A C T I C O   N ° 3 *****************************************\n");
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    	printf("3. Alta de empleado\n");
    	printf("4. Modificar datos de empleado\n");
    	printf("5. Baja de empleado\n");
    	printf("6. Listar empleados\n");
    	printf("7. Ordenar empleados\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    	printf("10. Salir\n");

    	if(flagCarga == 1 && (option !=1 && option != 10 && option != 0)) {

    		printf("Primero cargue la lista.\n");
    	}

    	option = LoadInt("Ingrese una opcion: ", 1,10);

        switch(option)

        {
            case 1:

            	if(flagBinario == 0 && flagTexto == 0) { //CARGAR LISTA LISTO

            		estado = controller_loadFromText("data.csv",listaEmpleados);

            		if(estado == 0) {

            			flagTexto = 1;
            		}

            	} else {
            		AlertMessage(0,"La lista ya fue cargada previamente.\n" ,"");
            	}

            	break;

            case 2:

            	if(flagBinario == 0 && flagTexto == 0) {

            		estado = controller_loadFromBinary("data.bin", listaEmpleados);

            		if(estado == 0) {

            		    flagBinario = 1;
            		}

            	} else {
            		AlertMessage(0,"La lista ya fue cargada previamente.\n" ,"");
            	}

            	break;

            case 3:
            		//Crear empleado LISTO
            	estado = controller_addEmployee(listaEmpleados);
            	AlertMessage(estado, "Usuario cargado correctamente", "No se pudo cargar el usuario.");

            	break;

            case 4:
            	if(flagCarga != 1) { // Modificar empleado //podria modificar los flags por is_empty

            		estado = controller_editEmployee(listaEmpleados);
            		AlertMessage(estado, "", "No se encontro el usuario.");

            	}
            	break;

            case 5:
            	if(flagCarga != 1) { //Baja empleado LISTO

            		estado = controller_removeEmployee(listaEmpleados);
            		AlertMessage(estado, "Usuario borrado correctamente", "No se borro el usuario.");

            	}
            	break;

            case 6:
            	if(flagCarga != 1) { //LISTAR LISTO

            		estado = controller_ListEmployee(listaEmpleados);
            		AlertMessage(estado, "Lista cargada.", "No hay nada para mostrar.");

            	}
            	break;

            case 7:
            	if(flagCarga != 1) { // ORDENAR LISTO

            		estado = controller_sortEmployee(listaEmpleados);
            		AlertMessage(estado,"Lista ordenada correctamente.", "No se ordeno la lista.");

            	}
            	break;

            case 8:
            	if(flagCarga != 1) {
            		// guardar datos listo
            		estado = controller_saveAsText("data.csv", listaEmpleados);
            		AlertMessage(estado, "Lista guardada en archivo '.csv' ", "No se guardaron los datos.");

            		if(estado == 0) {

            			flagGuardado = 1;
            		}
            	}
            	break;

            case 9:
            	if(flagCarga != 1) {

            		estado = controller_saveAsBinary("data.bin", listaEmpleados);
            		AlertMessage(estado, "Lista guardada en archivo '.bin' ", "No se guardaron los datos.");

            		if(estado == 0) {

            			flagGuardado = 1;
            		}
            	}
            	break;

            case 10: // corroborar lista guardada listo
            	if(flagGuardado != 1 && flagCarga != 1) {

            		printf("ATENCION: No se guardaron los datos. Desea salir sin guardar?\n");

            		estado = LoadInt(" 1. SALIR\n 0. VOLVER", 0, 1);

            		if(estado == 0) {

            			option = 0;

            		} else {

            			ll_deleteLinkedList(listaEmpleados); // al salir definitivamente borro la linked list
            		}
            	}

            	break;

        }
    } while(option != 10);
    system("cls");
    printf(" PROGRAMACION/LABORATORIO I\n TRABAJO PRACTICO N°3\n ALUMNO: DI PINO, GONZALO\n TURNO: NOCHE  DIV.: F\n 2do CUATRIMESTRE 2021\n");
    system("pause");
    return EXIT_SUCCESS;
}

