#include "types.h"
#include "user.h"

int main() {

  printf(1, "testmpfork start\n");

  int pid = fork();
  int * addrC = (int *)1024;
  //run mprotect on 1 KB of code
  int rc = mprotect(addrC, 1024);
  printf(1, "mprotect returned %d\n", rc);

  // test if mprotect works in child
  if (pid == 0 ){
      printf(1, "try to change code at 1025\n");
      //try to change the code at address 1025
      addrC[1] = 2;
      //This line is executed if mprotect does not work as intended for child
      printf(1,"testmpfork failed\n");
  }

  wait();
  exit();
}