#include <stdlib.h>
int main(void) {
  int *p;
  p = 0x1234
  *p = 1
  int i = 2;
  if (i == 2) {
    free(p);
  }
}
