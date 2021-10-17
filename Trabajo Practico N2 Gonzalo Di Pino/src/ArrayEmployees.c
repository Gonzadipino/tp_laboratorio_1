#include "ArrayEmployees.h"

/// @param employeeList
/// @param len
/// @return
int ValidateLoadedList(sEmployee employeeList[], int len){

    int ret=-1;
        for(int i =0; i<len; i++){
            if(employeeList[i].isEmpty == LOADED){
                ret =0;
            break;
            }
        }

    return ret;
}

/// @param employeeList
/// @param sectorList
/// @param employee_Len
/// @param sector_Len
/// @param id
/// @return
int AddEmployee(sEmployee* employeeList, sEmployeeType* sectorList,int employee_Len,int sector_Len, int* id){
    int functionId;
    int flagReturn=-1;
    functionId = *id;
    for(int i=0; i<employee_Len; i++){
        if(employeeList[i].isEmpty==EMPTY){
           flagReturn=0;
           employeeList[i].id = functionId;
           LoadString("Ingresar nombre: ", employeeList[i].name);
           LoadString("Ingresar apellido: ", employeeList[i].lastName);
           employeeList[i].salary = LoadFloat("Ingresar salario: $",1);
           DisplayEmployeeSector(sectorList, sector_Len);
           employeeList[i].sector = LoadInt("Ingrese sector:",1,SECTORS);
           employeeList[i].isEmpty = LOADED;
           functionId++;
           break;
        }
    }
    *id= functionId;
    return flagReturn;
}

/// @param sectorList
/// @param sector_Len
void DisplayEmployeeSector(sEmployeeType* sectorList,int sector_Len){
    for(int i =0; i<sector_Len; i++){
        printf("// %d. %s ",sectorList[i].sector, sectorList[i].description);
    }
    printf("//\n");
}

/// @param employeeList
/// @param employee_len
/// @return
int initEmployees(sEmployee* employeeList, int employee_len){
    int Return=-1;
    for(int i =0; i<employee_len;i++){
        employeeList[i].isEmpty=EMPTY;
        Return=0;
    }
    return Return;
}

/// @param employeeList
/// @param employeeType
/// @param employee_len
/// @param sector_Len
/// @return
int PrintEmployees(sEmployee* employeeList, sEmployeeType* employeeType, int employee_len, int sector_Len){
    int ret=-1;
    printf("  ID               NOMBRE             APELLIDO       $ SALARIO               SECTOR\n\n");
    for(int i=0; i<employee_len; i++){
        if(employeeList[i].isEmpty==LOADED){
            DisplayEmployee(employeeList[i],employeeType,sector_Len);
            ret=0;
        }
    }
    return ret;
}

/// @param employee
/// @param employeeType
/// @param sector_Len
void DisplayEmployee(sEmployee employee, sEmployeeType* employeeType, int sector_Len){

    for(int i=0; i<sector_Len; i++){
    if(employee.sector==employeeType[i].sector){
        printf("%4d %20s %20s   $%12.2f %20s\n",employee.id, employee.name,
        employee.lastName,employee.salary,employeeType[i].description);
        }
    }
}

/// @param employeeList
/// @param len
/// @param id
/// @return
int RemoveEmployee(sEmployee* employeeList,int len, int id){
    int flagDelete=-1;
    for(int i=0; i<len;i++){
        if(employeeList[i].id == id){
            flagDelete=0;
            employeeList[i].isEmpty=EMPTY;
        }
    }
    return flagDelete;

}

/// @param message
/// @param employeeList
/// @param employeeType
/// @param employee_len
/// @param sector_Len
/// @return
int findEmployeeById(char message[],sEmployee* employeeList, sEmployeeType* employeeType, int employee_len, int sector_Len){
    int flagDisplay;
    int deleteThisId;
    flagDisplay  = PrintEmployees(employeeList, employeeType, LEN_EMPLOYEE, LEN_TYPE);
    deleteThisId = LoadInt(message,1,LEN_EMPLOYEE);// revisar esta linea
    return deleteThisId;
}

/// @param SelectedId
/// @param employeeList
/// @param employeeType
/// @param employee_len
/// @param sector_Len
/// @return
int ModifyEmployee(int SelectedId, sEmployee* employeeList, sEmployeeType* employeeType, int employee_len, int sector_Len){
    int ret = -1;
    int option;
    for(int i=0; i<employee_len; i++){
       if(employeeList[i].id==SelectedId && employeeList[i].isEmpty==LOADED){
        ret=0;
        do{
            printf("//1. Nombre //2. Apellido //3. Salario //4. Sector //0. Volver al menu\n");
            option= LoadInt("Elija el campo que desea cambiar:",0,4);
            switch(option){
                case 1:
                LoadString("Ingresar nombre: ", employeeList[i].name);
                break;
                case 2:
                LoadString("Ingresar apellido: ", employeeList[i].lastName);
                break;
                case 3:
                employeeList[i].salary = LoadFloat("Ingresar salario: $",1);
                break;
                case 4:
                DisplayEmployeeSector(employeeType, sector_Len);
                employeeList[i].sector = LoadInt("Ingrese sector:",1,SECTORS);
                break;
            }
        }while(option!=0);
        break;
       }
    }

    return ret;
}

/// @param employee
/// @param employee_len
/// @param order
/// @return
int sortEmployeesByLastnameOrName(sEmployee* employee, int employee_len, int order){
    int ret=-1;
    sEmployee aux;
    if(order==1){
        for(int i=0; i<employee_len; i++){
            for(int j=i+1; j<employee_len; j++){
                if(employee[i].isEmpty!=EMPTY){
                    if(strcmp(employee[i].lastName,employee[j].lastName)>0){
                    ret=0;
                    aux = employee[i];
	                employee[i] = employee[j];
	                employee[j] = aux;
                }
                if(strcmp(employee[i].lastName,employee[j].lastName)==0){
                    if(strcmp(employee[i].name,employee[j].name)>0){
                    ret=0;
                    aux = employee[i];
	                employee[i] = employee[j];
	                employee[j] = aux;
                        }
                    }
                }
            }
         }

    }
    if(order==2){
                for(int i=0; i<employee_len; i++){
            for(int j=i+1; j<employee_len; j++){
                if(employee[i].isEmpty!=EMPTY){
                    if(strcmp(employee[i].lastName,employee[j].lastName)<0){
                    ret=0;
                    aux = employee[i];
	                employee[i] = employee[j];
	                employee[j] = aux;
                }
                if(strcmp(employee[i].lastName,employee[j].lastName)==0){
                    if(strcmp(employee[i].name,employee[j].name)<0){
                    ret=0;
                    aux = employee[i];
	                employee[i] = employee[j];
	                employee[j] = aux;
                        }
                    }
                }
            }
         }
    }

    return ret;
}

/// @param employee
/// @param employee_len
/// @param sector
/// @param sector_len
/// @return
int PrintEmployeesByType(sEmployee* employee, int employee_len,sEmployeeType* sector, int sector_len){
    int ret=-1;
    printf("         ID               NOMBRE             APELLIDO       $ SALARIO\n\n");
    for(int i=0; i<sector_len;i++){
        printf("%s:\n",sector[i].description);

        for(int j=0;j<employee_len;j++){
        if(employee[j].isEmpty!=EMPTY && sector[i].sector==employee[j].sector){
            printf("        %4d %20s %20s   $%12.2f\n",employee[j].id, employee[j].name,
            employee[j].lastName,employee[j].salary);
            ret=0;
            }
        }
    }
    return ret;
}

/// @param employee
/// @param sector
/// @param employee_len
/// @param sector_len
/// @return
int AverageSalaryAndHigherSalary(sEmployee* employee,sEmployeeType* sector, int employee_len, int sector_len){
    int ret =-1;
    float averageSalary;
    averageSalary= AverageSalary(employee, employee_len);
    if(averageSalary!=0){
        ret=0;
        HigerSalary(employee, sector, employee_len,sector_len, averageSalary);
    }
    return ret;
}

/// @param employee
/// @param employee_len
/// @return
float AverageSalary(sEmployee* employee,int employee_len){
    int SalaryCount=0;
    float SalaryAcum;
    float averageSalary;
    for(int i=0; i<employee_len; i++){
        if(employee[i].isEmpty!=EMPTY){
            SalaryAcum= SalaryAcum+ employee[i].salary;
            SalaryCount++;
        }
    }
    printf(" GASTO EN SALARIOS: $%.2f\n",SalaryAcum);
 averageSalary=SalaryAcum/SalaryCount;
 return averageSalary;
}

/// @param employee
/// @param sector
/// @param employee_len
/// @param sector_len
/// @param averageSalary
void HigerSalary(sEmployee* employee,sEmployeeType* sector,int employee_len,int sector_len,float averageSalary){
    printf(" USUARIOS CON SALARIO MAYOR AL PROMEDIO %.2f:\n", averageSalary);
    printf("  ID               NOMBRE             APELLIDO         SALARIO               SECTOR\n\n");
    for(int i=0; i<employee_len; i++){
        if(employee[i].isEmpty!=EMPTY && employee[i].salary>= averageSalary){
            DisplayEmployee(employee[i],sector,sector_len);
        }
    }
}

