#pragma once

typedef struct Coordinate {
	int x;
	int y;
	int z;
} coordinate_t ;

typedef struct {
	char Data1;
	short Data2;
	int Data3;
	char Data4;
} another_struct_t;


typedef struct {
	char Data4;
	char Data1;
	short Data2;
	int Data3;
} another_struct_t_aligned ;

coordinate_t new_coord(int x, int y, int z);

coordinate_t scale_coordinate(struct Coordinate coord, int factor);
