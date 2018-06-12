#include <stdio.h>
#include "csapp.h"

void test(char* filename) {
  int fd;
  char buf[20];
  fd = Open(filename, O_RDONLY, 0);
  Read(fd, buf, 20);
  buf[strlen(buf)]=0;
  printf("%s",buf);
}


int main(int argc, char* argv[]) {

  struct stat stat;
  int fd;
  char* bufp;
  size_t size;

  fd = Open("hello.txt", O_RDWR, 0);
  fstat(fd, &stat);
  size = stat.st_size;

  bufp = Mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd, 0);
  *bufp = 'J';
  Munmap(bufp, size);

  test("hello.txt");

  return 0;
}