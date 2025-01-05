#pragma once
float get_average(int x, int y, int z);

typedef struct ThingA thing_a;
typedef struct ThingB thing_b;

struct ThingA {
	struct ThingB* name;
};

struct ThingB {
	thing_a* name;
};

typedef enum {
	MON = 1,
	TUES,
	WED,
	THURS,
	FRI,
	SAT,
	SUN
} days_of_week_t;

typedef union EnOrChar {
	days_of_week_t dayzzz;
	char* name;
} en_or_char_t;

void printMessageOne();
void printMessageTwo();
void printMessageThree();
void printStackPointerDiff();
