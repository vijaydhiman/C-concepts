#include <stdio.h>
#include <string.h>
int i = 0;
typedef struct Params_struct
{
    char aString[20];
    void (*functionPointer)(char * data);
} Params;

void CalledWithFunctionPointer(char * data)
{
    printf("%s\n", data);
}

int foo(Params *params)
{
  int x = 1;
  for (int i = 0; i < 10; i++)
  {
    x += i * x;
  };
  params->functionPointer(params->aString);
  sprintf(params->aString,"string changed\n");
  params->functionPointer(params->aString);
  x++;
  return x;
}

void app_main(void)
{
  Params params;
  sprintf(params.aString, "hello world!");
  params.functionPointer = CalledWithFunctionPointer;
  int result = foo(&params);
  printf("%d\n", result);
}
