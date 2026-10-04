#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  fprintf(2, "ncpus: %d\n", ncpus());
  exit(0);
}
