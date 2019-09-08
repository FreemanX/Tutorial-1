#include <stdio.h>
#include <stdlib.h>

int main() { 
	printf("void pointer:\n");
	void *a;
	float b = 7.21;
	printf("\tBefore assignment, size of a %ld, size of *a %ld\n", 
			sizeof(a), sizeof(*a)); 
	printf("\tBefore assignment, size of &b %ld, size of b %ld\n", 
			sizeof(&b), sizeof(b)); 
	a = &b;
	printf("\ta = %p, *a = %f\n", a, *(float *)a);
	printf("\t&b = %p, b = %f\n", &b, b);
	printf("\tAfter assignment size of a %ld, size of *a %ld\n", 
			sizeof(a), sizeof(*a)); 
	printf("\tAfter assignment size of &b %ld, size of b %ld\n", 
			sizeof(&b), sizeof(b)); 

	printf("float pointer:\n");
	float *c;
	float d = 8.31;
	printf("\tBefore assignment, size of c %ld, size of *c %ld\n", 
			sizeof(c), sizeof(*c)); 
	printf("\tBefore assignment, size of &d %ld, size of d %ld\n", 
			sizeof(&d), sizeof(d)); 
	c = &d;
	printf("\tc = %p, *c = %f\n", c, *(float *)c);
	printf("\t&d = %p, d = %f\n", &d, d);
	printf("\tAfter assignment size of c %ld, size of *c %ld\n", 
			sizeof(c), sizeof(*c)); 
	printf("\tAfter assignment size of &d %ld, size of d %ld\n", 
			sizeof(&d), sizeof(d)); 

	void *dummy = NULL; 
	printf("dummy is a null pointer: \n\tprint as ptr %p \
			\n\tprint as int %d\n"
			, dummy, dummy);
	if(dummy) printf("if(dummy), dummy is assigned with value\n");
	else printf("if(!dummy), dummy is NULL\n");
	dummy = c;
	printf("dummy = c\n");
	if(dummy) printf("if(dummy), dummy is assigned with value\n");
	else printf("if(!dummy), dummy is NULL\n");

	return 0;
}
