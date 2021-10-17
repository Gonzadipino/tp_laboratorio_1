

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @param message
/// @param min
/// @param max
/// @return
int LoadInt(char message[],int min, int max);

/// @param message
/// @param min
/// @return
float LoadFloat(char message[], int min);

/// @param message
/// @param loadedString
void LoadString(char message[], char loadedString[]);

/// @param num
/// @param messageA
/// @param messageB
void AlertMessage(int num, char messageA[],char messageB[]);

/// @param number
/// @return
int ValidateIntNumber(char number[]);

/// @param string
/// @return
int ValidateString(char string[]);

/// @param number
/// @return
int ValidateFloatNumber(char number[]);

/// @param string
/// @param len
void StandardChar(char string[],int len);

/// @param options
/// @return
int LoadSubMenu(int options);

#endif /* BIBLIOTECA_H_ */
