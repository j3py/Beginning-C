#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		for (char* c = argv[i]; *c; c++) {
			printf("%c", *c);
		}
		printf("\n");
	}

	int* dyno_mem = (int*) malloc(argc * sizeof(int)); /* sizeof could be an 
	assigned value instead - int is 4 bytes*/

	int a = 7;
	int b = a;
	int* c = &a;
	char* hello = "Hello!";
	for (char* i = hello; *i; i++) {
		printf("The value at %p is %c\n", (void*) i, *i);
	}

	int d[] = {1, 31, 432, 12, 543, 3};
	int size = 6;
	for (int* i = d; (i - d) < size; i++) {
		printf("The value at %p is %d\n", (void*) i, *i);
	}  /* Here we are incrementing the memory address by four bytes (int is 32 bits) */

	printf("a is %d, c is %p, and c points to the value %d\n",a, (void*) c, *c);
	*c = 27;
	/* long b = c;  must convert b to long to match pointer c's type. */
	printf("a points to %d, b points to %d, and c points to %d\n", a, b, *c);

	free(dyno_mem); /* Free-up the dynamic memory! */
	
	return 0;
}