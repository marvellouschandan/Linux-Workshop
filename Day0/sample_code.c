#include <stdio.h>  // Included Library

// Defining macros
#define num1 5
#define num2 10
#define sum(a, b) (a+b)

int main()
{
	printf("Sum of %d and %d is %d", num1, num2, sum(num1, num2));
	return 0;
}
