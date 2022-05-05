#include <stdio.h>
#include <stdint.h> 

/* HEADER DEFINITIONS
*/
#define MAX_INST_LEN 100
#define MEMORY_SIZE 2048
#define REGISTER_SIZE 8


int main(int argc,char **argv){

  uint64_t INSTRUCTIONS[MAX_INST_LEN];
  int64_t MEMORY[MEMORY_SIZE];
  int64_t REGISTERS[REGISTER_SIZE];

  int i=0;
  while(i<MAX_INST_LEN){
    printf("The current value is : %d\n",INSTRUCTIONS[i]);
    i++;
  }
}
