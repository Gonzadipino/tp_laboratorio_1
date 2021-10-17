/*
 ============================================================================
 Name        : TrabajoPracticoN2.c
 Author      : Di Pino, Gonzalo
 Version     :
 Copyright   :
 Description : Trabajo practico numero 2, alta baja y modificacion. Muestreo de listas, manejo de direcciones de memoria, estructuras
 ============================================================================
 */

#include "biblioteca.h"
#include "ArrayEmployees.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <stdio_ext.h>

#define LOGISTICA 1
#define PRODUCCION 2
#define MANTENIMIENTO 3
#define DEPOSITO 4
#define SECTORS 4

#define LOADED 1
#define EMPTY 0

#define LEN_EMPLOYEE 1000 // tamaño de eEmployee
#define LEN_TYPE 4 //tamaño de eEmployeeType
#define OPTIONS 5// cantidad de opciones



int main(){

    setbuf(stdout,NULL);


    int opcion;
    int defined_Id=1;
    int state;
    int modifyThisId;
    int subOpcion;
    int deleteThisId;

    sEmployee employeeList[LEN_EMPLOYEE];/*={{1,"Gonzalo","Di Pino",23000,1,LOADED},
                                           {2,"Matias","Di Pino",24000,3,LOADED},
                                           {3,"Martin","Giorgi",26000,2,LOADED},
                                           {4,"Gabriel","Castro",1200,0,LOADED},
                                           {5,"Franco","Gaona",12.23,1,LOADED},
                                           {6,"Quimey","Espinosa",21000,2,LOADED},
                                           {7,"Lucas","Ramirez",23000,1,LOADED},
                                           {8,"German","Molinari",24000,3,LOADED},
                                           {9,"Miguel","Di Pino",26000,2,LOADED},
                                           {10,"Cristiano","Ronaldo",1200,0,LOADED},
                                           {11,"Franco", "Giorgi",12.23,1,LOADED},
                                           {12,"Paula", "Rodriguez",21000,2,LOADED},
                                           {13,"Rodrigo","Perez",23000,1,LOADED},
                                           {14,"Felipe","Martinez",24000,3,LOADED},
                                           {15,"Oscar", "Martinez",26000,2,LOADED},
                                           {16,"Carlos","Perez",1200,0,LOADED},
                                           {17,"Juan", "Rodriguez",12.23,1,LOADED},
                                           {18,"Lionel", "Messi",21000,0,LOADED}};*/

    sEmployeeType sectorList[LEN_TYPE]= {{1,"LOGISTICA"},{2,"PRODUCCION"},{3,"MANTENIMIENTO"},{4,"DEPOSITO"}};

    state = initEmployees(employeeList,LEN_EMPLOYEE);

    do{
        system("cls");
        printf("///////////TRABAJO PRACTICO N°2 ALUMNO DI PINO GONZALO DIV. F///////////\n\n");
        printf("    1. ALTA de empleado\n");
        printf("    2. MODIFICACION empleado\n");
        printf("    3. BAJA empleado\n");
        printf("    4. INFORMAR\n");
        //printf("    5. LISTADO\n");
        printf("    0. SALIR\n\n");

        opcion = LoadInt(" OPCION:",0,4); //cantidad de opciones del menu.
        state=ValidateLoadedList(employeeList,LEN_EMPLOYEE);
        if (state!=0&& opcion!=1 && opcion !=0){
        AlertMessage(state,"","Ingrese al menos un empleado.\n");
            } else{
            switch(opcion)
            {
                case 1:
                state= AddEmployee(employeeList, sectorList, LEN_EMPLOYEE, LEN_TYPE, &defined_Id);
                AlertMessage(state, "Empleado cargado correctamente.","No hay espacio en memoria. Elimine un empleado para cargar otro.");
                break;

                case 2:
                modifyThisId= findEmployeeById("Ingrese el numero de ID del empleado que quiere modificar:",employeeList, sectorList, LEN_EMPLOYEE, LEN_TYPE);
                state= ModifyEmployee(modifyThisId, employeeList, sectorList,LEN_EMPLOYEE, LEN_TYPE);
                AlertMessage(state,"Empleado modificado correctamene.", "El id ingresado no existe.");

                break;

                case 3:
                deleteThisId= findEmployeeById("Ingrese el numero de ID del empleado que quiere borrar:",employeeList, sectorList, LEN_EMPLOYEE, LEN_TYPE);
                state = RemoveEmployee(employeeList,LEN_EMPLOYEE, deleteThisId);
                AlertMessage(state,"Empleado eliminado correctamene.", "El id ingresado no existe.");
                break;

                case 4:
                do{
                    subOpcion=LoadSubMenu(2);
                    switch(subOpcion){
                        case 1:
                        printf(" 1. Ordenar de manera ASCENDENTE(A-Z)\n 2. Ordenar de manera DESCENDENTE(Z-A)\n");
                        opcion=LoadInt(" OPCION:",0,2);
                            if(opcion!=0){
                            system("cls");
                            state = sortEmployeesByLastnameOrName(employeeList,LEN_EMPLOYEE, opcion);
                            state = PrintEmployeesByType(employeeList, LEN_EMPLOYEE, sectorList, LEN_TYPE);
                            AlertMessage(state,"Lista ordenanda correctamente.", "No se pudo ordenar la lista.");
                            }
                        break;

                        case 2:
                        state= AverageSalaryAndHigherSalary(employeeList, sectorList, LEN_EMPLOYEE, LEN_TYPE);
                        AlertMessage(state,"", "");
                        break;

                        case 0:
                        opcion=1;
                        break;
                    }
                }while(subOpcion!=0);
                break;
               /* case 5:
                state=PrintEmployees(employeeList, sectorList, LEN_EMPLOYEE, LEN_TYPE);
                AlertMessage(1,"","");
                break;*/
            }
        }
    }while (opcion!=0);
    return 0;
}

