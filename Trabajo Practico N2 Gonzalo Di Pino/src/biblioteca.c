#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <stdio_ext.h>
#include "biblioteca.h"

#define OPTIONS 5// cantidad de opciones


/// @param message
/// @param min
/// @param max
/// @return Valida el ingreso de un entero.
int LoadInt(char message[],int min, int max){
    char option[50];
    int state=0;
    int validOption;
    int flag=0;
    do{
    if (flag==1){
        printf("ERROR.");
    }
    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", option);
    state = ValidateIntNumber(option);

    while(state!=0){
        printf("ERROR. '%s' no es una opcion,%s",option, message);
          fflush(stdin);
        scanf("%[^\n]", option);
        state=ValidateIntNumber(option);
    }
    validOption= atoi(option);
    flag=1;
    }while(validOption <min || validOption > max);

    return validOption;

}

/// @param message
/// @param min
/// @return Valida el ingreso de un numero flotante.
float LoadFloat(char message[], int min){
    char option[50];
    int state=0;
    float validOption;
    int flag=0;
    do{
    if (flag){
        printf("ERROR.");
    }
    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", option);

    state = ValidateFloatNumber(option);

    while(state!=0){
        printf("ERROR. '%s' no es un numero decimal,%s",option, message);
         fflush(stdin);
        scanf("%[^\n]", option);
        state=ValidateFloatNumber(option);
    }
    validOption= atof(option);
    flag=1;
    }while(validOption <min);

    return validOption;

}

/// @param message
/// @param loadedString
/// Carga un string en un vector, valida.
void LoadString(char message[], char loadedString[]){
    int state=0;
    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", loadedString);
   state=ValidateString(loadedString);
    while(state!=0){
        printf(" '%s' no es valido,%s",loadedString, message);
        fflush(stdin);
        scanf("%[^\n]", loadedString);
        state=ValidateString(loadedString);
    }
    StandardChar(loadedString,51);

}

/// @param num
/// @param messageA
/// @param messageB
/// muestra un mensaje: en caso de recibir 0 da un alerta positivo, en caso de retornar -1 da un mensaje negativo.
void AlertMessage(int num, char messageA[], char messageB[]){
    char enter;
    if(num==0){
        printf("%s\n",messageA);
    } else{
        printf("%s\n",messageB);
    }
    printf("Presione cualquier tecla para continuar.");
    fflush(stdin);
    scanf("%c", &enter);

    printf("\n\n");

}

/// @param number
/// @return
int ValidateIntNumber(char number[]){
    int i=0;
    int j;
    int ret=0;

    j=strlen(number);
    while(i<j && ret==0){
        if(isdigit(number[i])!=0){
            i++;
        }
        else{
            ret=-1;
        }
    }
    return ret;
}

/// @param string
/// @return
int ValidateString(char string[]){
    int i=0;
    int ret=0;
    int j;
    j=strlen(string);
    while(i<j && ret==0){

         if(string[0]==' ' && j==1){
        	ret=-1;
        	printf("No se admiten solo espacios.");
        	break;
        }else if(string[i]==' ' && string[i+1]==' '){
            ret=-1;
            printf("No se puede ingresar dos espacios seguidos.");
            break;
        } else if(isalpha(string[i])!=0 || string[i]== ' '){
        	            i++;
        }
    }
    return ret;
}

/// @param number
/// @return
int ValidateFloatNumber(char number[]){
    int i=0;
    int ret=0;
    int j;
    int flag=1;
    j=strlen(number);
    while(i<j && ret==0){
        if(isdigit(number[i])!=0){
            i++;
        }else if(flag && (number[i])=='.'){
            i++;
            flag=0;
            }else{
                 ret=-1;
            }

        }
        return ret;
    }

/// @param string
/// @param len
void StandardChar(char string[],int len){
    int flag=1;

    for(int i=0; i<len; i++){
        if(string[i]==' '){
        flag=1;
        }else if(flag && string[i]!=' '){
            string[i]= toupper(string[i]);
            flag=0;
        }else if(flag==0){
            string[i]= tolower(string[i]);
            }
        }

}

/// @param options
/// @return
int LoadSubMenu(int options){
    int subOption;
    system("cls");
    printf("//////////////////INFORMAR//////////////////\n\n");
    printf("1. LISTADO DE EMPLEADOS (ordenados alfabeticamente por Apellido y Sector).\n");
    printf("2. TOTAL/PROMEDIO DE SALARIOS ( empleados que superan el salario promedio).\n");
    printf("0. VOLVER AL MENU.\n");
    subOption=LoadInt("OPCION:",0,2);
    return subOption;

}
