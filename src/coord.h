#pragma once

typedef struct Coordinate {
	int x;
	int y;
	int z;
} coordinate_t ;

typedef struct {
	char a;
	double b;
	char c;
	char d;
	long e;
	char f;
} another_struct_t;


// As a rule of thumb, ordering your fields from largest to smallest will help the compiler minimize padding:
typedef struct {
	double b;
	long e;
	char a;
	char c;
	char d;
	char f;
} another_struct_t_aligned ;

coordinate_t new_coord(int x, int y, int z);

coordinate_t scale_coordinate(struct Coordinate coord, int factor);
