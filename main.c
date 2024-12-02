#include <stdbool.h>  // wtf? this is needed?
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "src/coord.h"
#include "src/exercise.h"

typedef struct {
  size_t length;
  char buffer[64];
} TextBuffer;
int smart_append(TextBuffer* dest, const char* src) {
  if (!src || !dest) {
    return 1;
  }
  return 0;
}

void concat_strings(char* str1, const char* str2) {
  while (*str1 != '\0') {
    str1 = str1 + 1;
  }

  while (*str2 != '\0') {
    *str1 = *str2;
    str2 = str2 + 1;
    str1 = str1 + 1;
  }

  *str1 = '\0';
}

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

  int numbers[5] = {10, 11, 12, 13, 14};
  for (int i = 0; i < 5; ++i) {
    printf("%d", numbers[i]);
  }
  printf("\n");

  int* numbers_prt = numbers;
  int value = *(numbers + 2);
  value = *(numbers_prt + 2);
  value = 2 [numbers_prt];  // because why not
  value = 2 [numbers];      // because why not
  int* p = numbers + 2;
  p = &numbers[2];
  value = *p;
  printf("%d", value);

  coordinate_t points[3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  int* points_start = (int*)points;  // because why fuckin not
  for (int i = 0; i < 9; i++) {
    printf("%d: %d\n", i, points_start[i]);
  }

  int* intPtr;
  printf("Size of int pointer: %zu bytes\n", sizeof(intPtr));

  int intArray[10];
  printf("Size of int array: %zu bytes\n", sizeof(intArray));

  int* intArray2[5];
  intArray2[0] = &value;

  char str1[] = "Hi";  // because why not
  char* str2 = "snek";

  char first[50] = "Snek";
  char* second = "lang!";
  strcat(first, second);
  printf("Hello, %s\n", first);

  char one[50] = "Hi, ";
  char* two = "MY";
  concat_strings(one, two);
  printf("%s", one);

  char src[] = "Hello";
  char dest[6];
  strncpy(dest, src, 3);
  dest[3] = '\0';
  printf("%s\n", src);
  printf("%s\n", dest);

  TextBuffer thingBuffer = {0};
  int a = smart_append(NULL, src);
  printf("%d", a);

  return 0;
}
