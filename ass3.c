//-----------------------------------------------------------------------------
// ass1.c
//
// Template program for ESP Assignment 1 WS18
//
// Group: Group 02, study assistant <Name of Study assistant>
//
// Authors: Philipp Bardakji 11701628
//-----------------------------------------------------------------------------
//
#include <stdio.h>
#include <stdlib.h>

//Struct defines values which are read from the config file
typedef struct _InitValues_
{
  int a;
  int b;
  int c;
  int d;
} InitValues;

//Return values of the program
typedef enum _ReturnValue_
{
  EVERYTHING_OK = 0,
  INVALID_ARG_COUNT_2 = -1,
  INVALID_ARG_COUNT_3 = -2,
  FILE_NOT_FOUND = -3,
  INVALID_FILE = -4,
  INVALID_MATRIKEL_NUMBER = -5
} ReturnValue;


//forward declarations
void function(int, int, int, int);
ReturnValue printErrorMessage(ReturnValue return_value);
ReturnValue readSingleValue(FILE* file, int* value);
ReturnValue readInitValuesFromFile(FILE* file, InitValues* init_values);
ReturnValue readInitValuesFromPath(const char* path, InitValues* init_values);

//------------------------------------------------------------------------------
///
/// Entry function of the program for ass1
///
/// @param argc number of arguments
/// @param argv program arguments
///
/// @return value of ReturnValue which defines type of error
//
int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    return printErrorMessage(INVALID_ARG_COUNT_2);
  }

  InitValues init_values = {0, 0, 0, 0};
  ReturnValue return_value = readInitValuesFromPath(argv[1], &init_values);
  if(return_value != EVERYTHING_OK)
  {
    return printErrorMessage(return_value);
  }

  function(init_values.a, init_values.b, init_values.c, init_values.d);

  return 0;
}

//------------------------------------------------------------------------------
///
/// Print message which describes the return value.
///
/// @param return_value type of main return value
///
/// @return parameter return_value
//
ReturnValue printErrorMessage(ReturnValue return_value)
{
  switch(return_value)
  {
    case INVALID_ARG_COUNT_2:
      printf("[ERR] Wrong number of parameters. Usage ./ass1 <config-file>\n");
      break;
    case INVALID_ARG_COUNT_3:
      printf(
        "[ERR] Wrong number of parameters. Usage ./ass1 <config-file> <matrikel-number>\n");
      break;
    case INVALID_FILE:
      printf("[ERR] Config-File is invalid.\n");
      break;
    case FILE_NOT_FOUND:
      printf("[ERR] Config-File does not exist or is not readable.\n");
      break;
    case INVALID_MATRIKEL_NUMBER:
      printf("[ERR] Matrikel-Number is invalid.\n");
      break;
    case EVERYTHING_OK:
      //left blank intentionally
      break;
  }
  return return_value;
}

//------------------------------------------------------------------------------
///
/// read int as string followed by \n from file
///
/// @param file pointer to file to read from
/// @param value pointer to store read value
///
/// @return type of error. 0 if success
//
ReturnValue readSingleValue(FILE* file, int* value)
{
  char str[10];
  int read = fscanf(file, "%s\n", str);
  if(read != 1)
  {
    return INVALID_FILE;
  }

  *value = (int)strtol(str, NULL, 10);
  return EVERYTHING_OK;
}

//------------------------------------------------------------------------------
///
/// Read Initial values from file
///
/// @param file file to read from
/// @param init_values struct to save read variables to
///
/// @return error type. 0 if success
//
ReturnValue readInitValuesFromFile(FILE* file, InitValues* init_values)
{
  int* variables[4] =
    {&init_values->a, &init_values->b, &init_values->c, &init_values->d};

  for(int variable_iterator = 0; variable_iterator < 4; variable_iterator++)
  {
    ReturnValue
      return_value = readSingleValue(file, variables[variable_iterator]);
    if(return_value != EVERYTHING_OK)
    {
      return return_value;
    }
  }

  return EVERYTHING_OK;
}

//------------------------------------------------------------------------------
///
/// Read config values from path into struct
///
/// @param path relative path to file
/// @param init_values struct to read values of file into
///
/// @return error type. 0 if success
//
ReturnValue readInitValuesFromPath(const char* path, InitValues* init_values)
{
  FILE* file = fopen(path, "r");
  if(file == NULL)
  {
    return FILE_NOT_FOUND;
  }
  ReturnValue read_return_value = readInitValuesFromFile(file, init_values);

  fclose(file);
  return read_return_value;
}

//------------------------------------------------------------------------------
///
/// Function to be written by students. It calculates some values dependend on
/// their matrikular number
///
/// @param a initial value a
/// @param b initial value b
/// @param c initial value c
/// @param d initial value d
///
//
void function(int a, int b, int c, int d)
{
  int result = 0;
  // ----------------------------------------
  // Beginn der Abgabe
  // ----------------------------------------
  
  if(a < 26)
  {
	while(b <= c)
	{
	  a += 2;
	  b++;
	  int sum = (b+c+d);
	  sum = sum * 9;
	  result = sum - 17;
	  printf("%d %d %d %d\n", a, b, c, d);
	  printf("%d\n",result);
	  printf("--\n");
	}
  }
  else
  {
	while(a <= c)
    {
	  a += 2;
	  b++;
	  int sum = (b+c+d);
	  sum = sum * 9;
	  int result = sum - 17;
	  printf("%d %d %d %d\n", a, b, c, d);
	  printf("%d\n",result);
	  printf("--\n");	
	}
  }
  result = result * (a%2);
  printf("%d %d %d %d\n", a, b, c, d);
  printf("%d\n",result);
  
  // ----------------------------------------
  // Ende der Abgabe
  // ----------------------------------------
}

 for(i = 1; i < 26; i++)
  {
    struct _DrawStack_*temp2 = malloc(sizeof(struct _DrawStack_));
    temp -> next= temp2;
    temp2 -> card = array[i];
    temp2 -> next = NULL;
    temp = temp2;
  }
  

void copyToStack1(char array[][4], int i)                        //copying array elements and create linked list
{
  
  struct _Stack1_*head_1 = malloc(sizeof(struct _Stack1_));
  
  if(head_1 -> next != NULL)
  {
    head_1 -> card = array[i];
    head_1 -> next = NULL;
  }
  else
  {
    struct _Stack1_*node = malloc(sizeof(struct _Stack1_));
    head_1 -> next= node;
    node -> card = array[i];
    node -> next = NULL;
    head_1 = node;
  }
  
}