#include "rectangle.h"

void print_description(struct Rectangle *rect)
{
	switch (rect_describe(rect)) {
		case wide:
			printf("Wide.\n"); break;
		case tall:
			printf("Tall.\n"); break;
		case square:
			printf("Square.\n"); break;
		default:
			printf("Unknown.\n"); break;
	}
}


int main()
{
	struct Rectangle *my_rect = rect_create(10, 5);
	rect_print(my_rect);
	rect_print2(*my_rect);
	if (rect_valid(my_rect)) {
		printf("Rectangle is valid.\n");
	}
	printf("Rectangle is ");
	print_description(my_rect);

	rect_turn(my_rect, tall);
	printf("Now rectangle is ");
	print_description(my_rect);

	rect_print(my_rect);

	rect_free(my_rect);
	return 0;
}
