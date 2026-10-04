#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  for (int i = 0; i < 10; i++) {
    fprintf(2, "%d^2: %d\n", i, square(i));
  }

  exit(0);
}
