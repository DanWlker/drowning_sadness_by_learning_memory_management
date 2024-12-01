#include "coord.h"

struct Coordinate new_coord(int x, int y, int z) {
  struct Coordinate res = {
      .x = x,
      .y = y,
      .z = z,
  };
  return res;
}

struct Coordinate scale_coordinate(struct Coordinate coord, int factor) {
  struct Coordinate res = {
      .x = coord.x * factor,
      .y = coord.y * factor,
      .z = coord.z * factor,
  };
  return res;
}
unsigned long size_of_addr(long long i) {
  unsigned long sizeof_snek_version = sizeof(i);
  return sizeof_snek_version;
}
