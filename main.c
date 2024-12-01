#include <stdbool.h>  // wtf? this is needed?
#include <stdint.h>
#include <stdio.h>

#include "src/coord.h"
#include "src/exercise.h"

int main() {
  struct Coordinate c = {0};

  struct Coordinate thing = {1, 34, -22};

  struct Coordinate preferred = {
      .x = 2,
      .y = 2,
      .z = 2,
  };

  preferred = new_coord(1, 2, 3);
  printf("size = %zu\n", sizeof(preferred));

  another_struct_t another_thing = {0};
  printf("size another = %zu\n", sizeof(another_thing));

  another_struct_t_aligned another_thing_aligned = {0};
  printf("size another = %zu\n", sizeof(another_thing_aligned));
  printf("address = %p\n", &another_thing_aligned);
  long long thingy = 2;
  printf("size address another = %zu\n", size_of_addr(thingy));

  int i = preferred.y;
  do {
    printf("i = %d\n", scale_coordinate(preferred, i).y);
    i++;
  } while (i < 5);

  return 0;
}
