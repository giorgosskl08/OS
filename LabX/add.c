#include <stdio.h>

int add(int *a, int *b, int *c){
	return *a + *b + *c;
}

int main() {

	int number1, number2, number3, result;	

	printf("Enter the first number: ");
	scanf("%d", &number1);
	printf("Enter the second number: ");
	scanf("%d", &number2);
	printf("Enter the third number: ");
	scanf("%d", &number3);

	result = add(&number1, &number2, &number3);

	printf("The sum of %d, %d and %d is %d. \n", number1, number2, number3, result);
	
	return 0;
} 
