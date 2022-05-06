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
#define REGISTER_SIZE 16

/*INSTRUCTION SET ARCHITECTURE
  * Available instructions - ADD,SUB,MUL,DIV,LOAD,STORE
  * Architecture
  (Instruction size) - 64bits
  (Instruction arch)
  (---4bits-- , --60bits-- )
  (--opcode-- , --arguments--)
    FOR BINARY INSTRUCTIONS
   (--4bits--,--4bits--,--4bits--,--4bits--,--rest--)
   ( opcode  ,  arg1   ,  arg2   ,  arg3   ,  not used      )
*/
enum OPCODE{
  ADD,SUB,MUL,DIV,LOAD,STORE
};

/* GLOBAL VARIABLES
*/
uint64_t INSTRUCTIONS[MAX_INST_LEN];
int64_t MEMORY[MEMORY_SIZE];
int64_t REGISTERS[REGISTER_SIZE];
  
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

uint64_t generateInst(OPCODE opcode
                     ,uint8_t arg1
                     ,uint8_t arg2
                     ,uint8_t arg3){
  uint64_t inst = ((uint64_t)opcode)<<60;
  inst = inst | ((uint64_t)arg1<<56);
  inst = inst | ((uint64_t)arg2<<52);
  inst = inst | ((uint64_t)arg3<<48);
  return inst;
}

int main(int argc,char **argv){

    for(int i=0; i<MAX_INST_LEN; i++){
    INSTRUCTIONS[i] = generateInst((OPCODE)(rand()%STORE),0,0,0);
  }
  
  for(int i=0; i<MAX_INST_LEN; i++){
    processInst(INSTRUCTIONS[i]);
    printf("\n");
  }

}
