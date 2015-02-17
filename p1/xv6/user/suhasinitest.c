#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"


#define assert(x) if (x) {} else { \
  printf(1, "%s: %d ", __FILE__, __LINE__); \
  printf(1, "assert failed (%s)\n", # x); \
  printf(1, "TEST FAILED\n"); \
  exit(); \
}

int
main(int argc, char *argv[])
{
  int pid, i;
  for (i = 0; i < 20; ++i)
  {  
    pid = fork();
    if (pid == 0)
    {
     while(1);
    }
  }  
  assert((int) getprocs() == 23);
  printf(1, "TEST PASSED\n");
  exit();
}

//int
//main(int argc, char *argv[])
//{
//  printf(1, "usertests starting\n");
//  int pid = getpid();
//  printf(1, "The process id is %d\n", pid);
//  
//  printf(1, "Number of  processes running in the system: %d\n", getprocs());
//  printf(1, "successful!!\n");
//  
//  exit();
//}
//
//~bdavis/public/cs537/tests/
