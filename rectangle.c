#include "rectangle.h"

struct Rectangle *rect_create(double width, double height)
{
	struct Rectangle *rect = calloc(1, sizeof(struct Rectangle));
	rect->width = width;
	rect->height = height;
	return rect;
}

void rect_free(struct Rectangle *rect)
{
	free(rect);
}

double rect_area(struct Rectangle *rect)
{
	return rect->width * rect->height;
}

void rect_grow(struct Rectangle *rect)
{
	rect->width++;
	rect->height++;
}

/* Prints rectangle given as pointer to a struct */
void rect_print(struct Rectangle *rect)
{
	printf("Height: %f\nWidth: %f\nArea: %f\n",
		rect->height, rect->width, rect_area(rect));
}

/* Prints rectangle given as a struct */
void rect_print2(struct Rectangle rect)
{
	rect_print(&rect);
}

bool rect_valid(struct Rectangle *rect)
{
	return (rect->height > 0) && (rect->width > 0);
}

/* Returns result of doing some function on width and height of rectangle.*/
double rect_calculate(struct Rectangle *rect, double (*f)(double, double))
{
	return f(rect->width, rect->height);
}

/* Describes rectangle (wide, tall, etc.) */
enum rect_description rect_describe(struct Rectangle *rect)
{
	if (rect->height > rect->width) {
		return tall;
	} else if (rect->height < rect->width) {
		return wide;
	} else {
		return square;
	}
}

/* Turns the rectangle so that it matches the given description (wide, tall, etc.) */
void rect_turn(struct Rectangle *rect, enum rect_description descr)
{
	enum rect_description original = rect_describe(rect);

	// Make rectangle into a square
	if (descr == square) {
		double side = (rect->height + rect->width) / 2;
		rect->width = side;
		rect->height = side;
		return;
	}

	// Swap height and width
	if (descr != original) {
		double temp = rect->width;
		rect->width = rect->height;
		rect->height = temp;
	}
}

