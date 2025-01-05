#include <stdbool.h>  // wtf? this is needed?
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/_types/_u_int8_t.h>

#include "limits.h"
#include "src/coord.h"
#include "src/exercise.h"

const int max_buffer_size = 64;
typedef struct {
  size_t length;
  char buffer[64];
} TextBuffer;
int smart_append(TextBuffer* dest, const char* src) {
  if (!src || !dest) {
    return 1;
  }

  int lenSrc = strlen(src);
  int usable_buffer_size =
      max_buffer_size - 1;  // minus one for the null terminator
  int remaining_length =
      usable_buffer_size -
      dest->length;  // not sure why this implicit minus is working

  bool fullAppendPossible = remaining_length >= lenSrc;

  strncat(dest->buffer, src, remaining_length);

  if (fullAppendPossible) {
    dest->length = dest->length + lenSrc;
  } else {
    dest->length = usable_buffer_size;
  }

  /*for (int i = remaining_length, j = 0;*/
  /*     i > 0 && dest->length < max_buffer_size - 1 && j < lenSrc;*/
  /*     i--, dest->length++, j++) {*/
  /*  dest->buffer[dest->length] = src[j];*/
  /*}*/
  /**/
  /*dest->buffer[dest->length + 1] = '\0';*/

  return !fullAppendPossible;  // implicit conversion?, also need to flip cuz 0
                               // is success
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

void thingamajig(int* stuff) {
  printf("thingamajig = %d", *(stuff + 17));
  printf("\n");
}

typedef union {
  int value;
  unsigned int err;
} val_or_err_t;

typedef union {
  days_of_week_t value;
  int err;
} dayzOrError;

typedef union PacketHeader {
  struct {
    uint16_t src_port;
    uint16_t dest_port;
    uint32_t seq_num;
  } tcp_header;
  uint8_t raw[8];
} packet_header_t;

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

  int* intArrPtr = intArray;
  printf("Size of pointer of int array: %zu bytes\n", sizeof(intArrPtr));
  thingamajig(points_start);

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

  char src2[] =
      " that will fill the whole buffer and leave no space for some of the "
      "chars.";
  TextBuffer thingBuffer = {0};
  strcpy(thingBuffer.buffer, "This is a long string");
  thingBuffer.length = 21;
  int a = smart_append(&thingBuffer, src2);
  printf("%s\n", thingBuffer.buffer);
  printf("%zu\n", thingBuffer.length);
  printf("%d\n", a);

  days_of_week_t dayz;
  switch (dayz) {
    case MON:
    case TUES:
    case WED:
    case THURS:
    case FRI:
    case SAT:
    case SUN:
      break;
  }

  val_or_err_t lanes_score = {.value = -420};
  printf("value (set): %d\n", lanes_score.value);
  printf("err (unset): %u\n", lanes_score.err);

  val_or_err_t teejs_score = {.err = UINT_MAX};
  printf("value (unset): %d\n", teejs_score.value);
  printf("err (set): %u\n", teejs_score.err);

  dayzOrError nanann = {.value = MON};
  printf("value (set): %u\n", nanann.value);
  printf("err (unset): %u\n", nanann.err);

  packet_header_t header;
  header.tcp_header.src_port = 0x1234;
  header.tcp_header.dest_port = 0x5678;
  header.tcp_header.seq_num = 0x9ABCDEF0;

  printf("%#080x\n", header.tcp_header.src_port);
  printf("%#080x\n", header.tcp_header.dest_port);
  printf("%#080x\n", header.tcp_header.seq_num);
  printf("\n");

  for (uint8_t i = 0; i < sizeof(header.raw) / sizeof(header.raw[0]); i++) {
    /*munit_assert_uint8(header.raw[0], ==, 0x34, "[0] should be 0x34");*/
    /*munit_assert_uint8(header.raw[1], ==, 0x12, "[1] should be 0x12");*/
    /*munit_assert_uint8(header.raw[2], ==, 0x78, "[2] should be 0x78");*/
    /*munit_assert_uint8(header.raw[3], ==, 0x56, "[3] should be 0x56");*/
    /*munit_assert_uint8(header.raw[4], ==, 0xF0, "[4] should be 0xF0");*/
    /*munit_assert_uint8(header.raw[5], ==, 0xDE, "[5] should be 0xDE");*/
    /*munit_assert_uint8(header.raw[6], ==, 0xBC, "[6] should be 0xBC");*/
    /*munit_assert_uint8(header.raw[7], ==, 0x9A, "[7] should be 0x9A");*/
    printf("%#080x\n", header.raw[i]);
  }

  return 0;
}
