#include <stdio.h>
#include <stdlib.h>

void printPtr(int* p) {
	printf("\tp   = %p, ", p);
	printf("*p   = %d\n", *p);
}

int main() {
	int dataLength = 10;
	int *a = malloc(dataLength * sizeof(*a)); 
	int i;
	for(i = 0; i < dataLength; i++){ // Fill data
		a[i] = i + 1;
		printf("a[%d]=%d ", i, a[i]);
	}
	printf("\n");

	printf("Shift 4:\n");
	printPtr(&a[4]); 
	printPtr(a + 4);

	printf("Shift dataLength:\n");
	int *end_a = a + dataLength;
	printPtr(&a[9]); 
	printPtr(end_a);

	printf("Shift dataLength - 1:\n");
	end_a = a + dataLength - 1;
	printPtr(&a[9]); 
	printPtr(end_a); 

	printf("Shift with void ptr:\n");
	void *end_a_void = a + dataLength - 1;
	printPtr(&a[9]); 
	printPtr(end_a); 

	printf("Loop with end_a:\n\t");
	for(i = 0; i < dataLength; i++){
		printf("%d ", *(end_a-i));
	} 
	printf("\n");

	printf("Loop with end_a_void:\n\t");
	for(i = 0; i < dataLength; i++){
		printf("%d ", *(int*)(end_a_void-i));
	} 
	printf("\n");
	printf("Loop with end_a_void, print addr:\n"); 
	for(i = 0; i < dataLength; i++){
		printPtr(end_a_void-i);
	} 
	free(a);
	return 0;
}
