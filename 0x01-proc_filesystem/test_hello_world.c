#include "elf.h"

#define Buff[100];

/**
 *
 *
 *
 *
 **/
int main()
{
  char buffer[100] = {1, };
  if(!buffer || buffer == NULL )
  {
    free(buffer);
  }
  printf("Hello World!");
  printf("Hello World123!");
  return (0);  
}
