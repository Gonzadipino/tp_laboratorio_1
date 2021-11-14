#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* SueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_Print(Employee* this, int auxId, char *auxNombre, int auxHoras, int auxSueldo);
void employee_Cabecera();

int EmployeeId(FILE* pFile);
//---------------------------------------------------------------
//funciones de ordenamiento de datos

int employee_SortBy_Id(LinkedList* this);
int employee_SortBy_Name(LinkedList* this);
int employee_SortBy_Salary(LinkedList* this);
int employee_SortBy_Hs(LinkedList* this);
#endif // employee_H_INCLUDED

int compareByName(void* firstEmployee,void* SecondEmployee);
int compareById(void* firstEmployee,void* SecondEmployee);
int compareByHs(void* firstEmployee,void* SecondEmployee);
int compareBySalary(void* firstEmployee,void* SecondEmployee);
