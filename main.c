#include <stdbool.h>
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

int *allocate_scalar_list(int size, int multiplier) {
  int *res = calloc(size, sizeof(int));

  for (int i = 0; i < size; i++) {
    res[i] = i * multiplier;
  }

  return res;
}

char *get_full_greeting(bool zeroVal, char *greeting, char *name, int size) {
  char *new_arr;
  if (zeroVal) {
    // calloc initializes memory to all 0s
    new_arr = (char *)calloc(size, sizeof(char));
  } else {
    new_arr = (char *)malloc(size * sizeof(char));
  }
  if (new_arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  snprintf(new_arr, size, "%s %s", name, greeting);
  return new_arr;
}

int main() {
  char *thing = get_full_greeting(true, "hello world", "Danny", 100);
  int *res = allocate_scalar_list(10, 3);
  printf("%s\n", thing);
  for (int i = 0; i < 10; i++) {
    printf("%d\n", res[i]);
  }
  free(thing);
  free(res);

  const int num_lists = 500;
  for (int i = 0; i < num_lists; i++) {
    int *lst = allocate_scalar_list(50000, 2);
    if (lst == NULL) {
      printf("Failed to allocate list\n");
      return 1;
    } else {
      printf("Allocated list %d\n", i);
    }
    free(lst);
  }
}
