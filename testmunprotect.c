#include "types.h"
#include "user.h"

int main() {
  printf(1, "testmunprotect start\n");
  int * addrC = (int *)1024;
  //run mprotect on 1 KB of code
  int rc = mprotect(addrC, 1024);
  printf(1, "mprotect returned %d\n", rc);
  //run munprotect on 1 KB of code
  rc = munprotect(addrC, 1024);
  printf(1, "munprotect returned %d\n", rc);
  //try to change the code at address 1025
  printf(1, "try to change code at 1025\n");
  addrC[1] = 2;
  //This line is executed if munprotect does not work as intended
  printf(1,"testmunprotect failed\n");
  exit();
}