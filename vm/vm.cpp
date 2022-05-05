#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 


/* HEADER DEFINITIONS
 * MAX_INST_LEN - the virtual machine's capacity of program size it can run
 * MEMORY_SIZE  - the allocated memory size for the virtual machine
 * REGISTER_SIZE - the maximum number of registers
 */
#define MAX_INST_LEN 100
#define MEMORY_SIZE 2048
#define REGISTER_SIZE 8

/*INSTRUCTION SET ARCHITECTURE
  * Available instructions - ADD,SUB,MUL,DIV,LOAD,STORE
  * Architecture
  (Instruction size) - 64bits
  (Instruction arch)
  (---4bits-- , --60bits-- )
  (--opcode-- , --arguments--)
*/
enum OPCODE{
  ADD,SUB,MUL,DIV,LOAD,STORE
};

void processInst(uint64_t inst){
  uint8_t op_code = (inst>>60); // to get the first four bits
  switch(op_code){
    case ADD:
      printf("ADD");
      break;
    case SUB:
      printf("SUB");
      break;
    case MUL:
      printf("MUL");
      break;
    case DIV:
      printf("DIV");
      break;
    case LOAD:
      printf("LOAD");
      break;
    case STORE:
      printf("STORE");
      break;
    default:
      printf("Default");
      break;
  }
}

uint64_t generateInst(OPCODE opcode){
  return ((uint64_t)opcode<<60);
}

int main(int argc,char **argv){

  uint64_t INSTRUCTIONS[MAX_INST_LEN];
  int64_t MEMORY[MEMORY_SIZE];
  int64_t REGISTERS[REGISTER_SIZE];
  
  for(int i=0; i<MAX_INST_LEN; i++){
    INSTRUCTIONS[i] = generateInst((OPCODE)(rand()%STORE));
  }
  
  for(int i=0; i<MAX_INST_LEN; i++){
    processInst(INSTRUCTIONS[i]);
    printf("\n");
  }

}
