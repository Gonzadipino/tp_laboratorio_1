#include "biblioteca.h"
#include "ArraySector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <stdio_ext.h>


#define LOGISTICA 1
#define PRODUCCION 2
#define MANTENIMIENTO 3
#define DEPOSITO 4
#define SECTORS 4 //cantidad de sectores.

#define LOADED 1
#define EMPTY 0

#define LEN_EMPLOYEE 1000 // tamaño de eEmployee
#define LEN_TYPE 4 //tamaño de eEmployeeType
#define OPTIONS 5// cantidad de opciones

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

/// @param employeeList
/// @param len
/// @return devuelve 0 o -1 en caso de validar o no si la lista esta cargada.
int ValidateLoadedList(sEmployee* employeeList, int len);

/// @param employeeList
/// @param sectorList
/// @param employee_Len
/// @param sector_Len
/// @param id
/// @return devuelve 0 o -1 si: 0, el usuario se cargo correctamente, -1 si la lista esta completamente cargada.
int AddEmployee(sEmployee* employeeList, sEmployeeType* sectorList,int employee_Len,int sector_Len, int *id);

/// @param sectorList
/// @param sector_Len
/// muestra la lista dividida en sectores.
void DisplayEmployeeSector(sEmployeeType* sectorList,int sector_Len);

/// @param employeeList
/// @param employee_len
/// @return
int initEmployees(sEmployee*employeeList, int employee_len);

/// @param employeelist
/// @param sEmployeeType
/// @param employee_len
/// @param sector_Len
/// @return muestra la lista completa de los usuarios, en caso de no tener nada para mostrar devuelve -1.
int PrintEmployees(sEmployee* employeelist, sEmployeeType* sEmployeeType, int employee_len, int sector_Len);

/// @param employeeList
/// @param EmployeeType
/// @param len
/// muestra de a un solo empleado.
void DisplayEmployee(sEmployee employeeList, sEmployeeType* EmployeeType, int len);

/// @param employeeList
/// @param len
/// @param id
/// @return devuelve 0 o -1 si 0, elimino correctamente al usuario, -1 si no pudo encontro el usuario que queria eliminar.
int RemoveEmployee(sEmployee* employeeList,int len, int id);

/// @param messaje
/// @param employeeList
/// @param employeeType
/// @param employee_len
/// @param sector_Len
/// @return devuelve 0 o -1 si 0, encontro el usuario, -1 no lo encontro.
int findEmployeeById(char messaje[],sEmployee* employeeList, sEmployeeType* employeeType, int employee_len, int sector_Len);

/// @param SelectedId
/// @param employeeList
/// @param employeeType
/// @param employee_len
/// @param sector_Len
/// @return devuelve 0 o -1 si 0,modifico el usuario correctamente, no hizo ninguna modificacion en el array.
int ModifyEmployee(int SelectedId, sEmployee* employeeList, sEmployeeType* employeeType, int employee_len, int sector_Len);


/// @param employee
/// @param employee_len
/// @param order
/// @return devuelve 0 o -1 si 0,si pudo ordenar la lista, -1 si no ordeno nada.
int sortEmployeesByLastnameOrName(sEmployee* employee, int employee_len, int order);

/// @param employee
/// @param employee_len
/// @param sector
/// @param sector_len
/// @return devuelve 0 o -1 si 0, pudo imprimir la lista con los usuarios.
int PrintEmployeesByType(sEmployee* employee, int employee_len,sEmployeeType* sector, int sector_len);

/// @param employee
/// @param sector
/// @param employee_len
/// @param sector_len
/// @return devuelve 0 o -1 si 0 si pudo calcular el promedio y mostrar la lista, -1 si no pudo.
int AverageSalaryAndHigherSalary(sEmployee* employee,sEmployeeType* sector, int employee_len, int sector_len);

/// @param employee
/// @param employee_len
/// @return
/// devuelve el valor del promedio.
float AverageSalary(sEmployee* employee,int employee_len);

/// @param employee
/// @param sector
/// @param employee_len
/// @param sector_len
/// @param averageSalary
/// muestra los usuarios con sueldo mayor o igual al promedio.
void HigerSalary(sEmployee* employee,sEmployeeType* sector,int employee_len,int sector_len,float averageSalary);


#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



#endif /* ARRAYEMPLOYEES_H_ */
