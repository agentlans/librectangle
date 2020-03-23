#ifndef _RECT
#define _RECT

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Rectangle
{
	double width;
	double height;
};

enum rect_description
{
	tall,
	wide,
	square
};

struct Rectangle *rect_create(double width, double height);
void rect_free(struct Rectangle *rect);
double rect_area(struct Rectangle *rect);
void rect_grow(struct Rectangle *rect);
void rect_print(struct Rectangle *rect);
void rect_print2(struct Rectangle rect);
bool rect_valid(struct Rectangle *rect);
double rect_calculate(struct Rectangle *rect, double (*f)(double, double));
enum rect_description rect_describe(struct Rectangle *rect);
void rect_turn(struct Rectangle *rect, enum rect_description descr);

#endif

