/*
 * Intentionally creating bugs to demo gdb
 * */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

//Function with unknow number of args
void charScanf(const char *format, ...);

//Pass by reference
int calculator(const float *a, const float *b, float *result, const char *op);

int main(int argc, char **argv) {
	char name[1024];
	printf("What's your name?\n");
	scanf("%s", name);
	printf("Welcome %s!\n", name);

	float a, b;
	float *result; 
	char op;

	do {
		printf("Enter a number:\n");
		scanf("%f", &a);

		printf("Enter operator(+, -, *, /):\n");
		//charScanf("%c", &op);
		scanf("%c", &op);

		printf("Enter second number:\n");
		scanf("%f", &b);
		if(calculator(&a, &b, result, &op))
			printf("Output: %f %c %f = %f\n", a, op, b, *result);
		else
			printf("wrong input\n");

		printf("Do you want to continue ? (y/n)\n");
		//charScanf("%c", &op);
		scanf("%c", &op);

	} while (op == 'y');

	return 0;

} 

//solution for getting char
void charScanf(const char *format, ...) { 
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	va_list args;
	va_start(args, format);
	vscanf(format, args);
	va_end(args);
}


int calculator(const float *a, const float *b, float *result, const char *op) {
	// example of how to use switch
	switch (*op) {
		case '+' :
			*result = *a + *b;
			break;
		case '-' :
			*result = *a - *b;
			break;
		case '*' :
			*result = *a * *b;
			break;
		case '/' :
			*result = *a / *b;
			break;
		default:
			result = NULL;
			return 0;
	}
	return 1;
}
