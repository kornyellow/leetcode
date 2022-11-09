#include "function.c"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: ./main \"(){}[]\"\n");
		return 1;
	}

	if (isValid(argv[1]))
		printf("True\n");
	else
		printf("False\n");

	return 0;
}
