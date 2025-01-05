#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} coord_t;

coord_t new_coords(int x, int y) {
  coord_t c;
  c.x = x;
  c.y = y;
  return c;
}

char *get_full_greeting(char *greeting, char *name, int size) {
  char *new_arr = (char *)malloc(size * sizeof(char));
  if (new_arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  snprintf(new_arr, size, "%s %s", name, greeting);
  return new_arr;
}

int main() {
  char *thing = get_full_greeting("hello world", "Danny", 100);
  printf("%s", thing);
  free(thing);
}
