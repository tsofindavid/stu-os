#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

char buf[512];

void
cp(int fd_1, int fd_2)
{
  int n;

  while ((n = read(fd_1, buf, sizeof(buf))) > 0) {
    if (write(fd_2, buf, n) != n) {
      fprintf(2, "cp: write error\n");
      exit(1);
    }
  }

  if (n < 0) {
    fprintf(2, "cp: read error\n");
    exit(1);
  }
}

int
main(int argc, char *argv[])
{
  int fd_1, fd_2;

  if (argc != 3) {
    printf("cp: Invalid arguments count.\n");
    exit(1);
  }

  if ((fd_1 = open(argv[1], O_RDONLY)) < 0) {
    fprintf(2, "cp: cannot open %s\n", argv[1]);
    exit(1);
  }

  if ((fd_2 = open(argv[2], O_CREATE | O_WRONLY | O_TRUNC)) < 0) {
    fprintf(2, "cp: cannot open %s\n", argv[2]);
    exit(1);
  }

  cp(fd_1, fd_2);

  close(fd_1);
  close(fd_2);

  exit(0);
}
