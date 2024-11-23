#include <stdbool.h>  // wtf? this is needed?
#include <stdint.h>
#include <stdio.h>

#include "src/exercise.h"
#include "src/thing.h"

int main() {
  printf("sizeof(char)   = %zu\n", sizeof(char));
  printf("sizeof(int)   = %zu\n", sizeof(int));
  printf("sizeof(float)   = %zu\n", sizeof(float));
  printf("sizeof(double)   = %zu\n", sizeof(double));
  printf("sizeof(size_t)   = %zu\n", sizeof(size_t));
  printf("sizeof(bool)   = %zu\n", sizeof(bool));
}
