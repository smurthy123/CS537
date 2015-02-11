#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"

int
main(int argc, char *argv[])
{
  printf(1, "usertests starting\n");
  int pid = getpid();
  printf(1, "The process id is %d\n", pid);
  
  printf(1, "Number of  processes running in the system: %d\n", getprocs());
  printf(1, "successful!!\n");
  
  exit();
}
