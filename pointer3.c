#include <stdio.h>
#include <stdlib.h>

//pass by value
void swap1(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//pass by reference
void swap2(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int c3 = 689;
	int c4 = 777;
	int v = 0;
	printf("Initial values:\n");
	printf("\tc3 = %d\n", c3);
	printf("\tc4 = %d\n", c4);

	printf("No function call swap:\n");
	//printf("v = c3; \n");
	//printf("c3 = c4;\n");
	//printf("c4 = v; \n");
	v = c3;
	c3 = c4;
	c4 = v;
	printf("\tc3 = %d\n", c3);
	printf("\tc4 = %d\n", c4);

	printf("swap1(c3, c4);\n");
	swap1(c3, c4);
	printf("\tc3 = %d\n", c3);
	printf("\tc4 = %d\n", c4);

	printf("swap2(&c3, &c4);\n");
	swap2(&c3, &c4);
	printf("\tc3 = %d\n", c3);
	printf("\tc4 = %d\n", c4);

	return 0;
}
