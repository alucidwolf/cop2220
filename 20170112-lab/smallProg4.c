// Brandon Franklin
// COP2220
// Small Program 4 - Source

//PART 1:
//Create a program that asks the user to enter a number from 1 to 9
//Get the number from the user(For example if the user enters a 5, each loop below will repeat 5
//	times)
//	Print the statement “FAU Owls - Hoot Hoot” the number of times entered by the user using a for loop.
//	Print the statement “Programming is awesome” the same number of times using a do / while loop.
//	Print the statement “Florida beaches are beautiful” the same number of times using a while loop.
//	Note: You will be graded on whether or not you used the correct loop as described above,
//	not just on output
//	PART 2 : calculates the remainder and the product of two integers with one user - defined
//	functions :
//takes two integer arguments and two integer pointer arguments
//1. calculate the product and stores the result in prodPtr
//2. calculate the remainder of num1 % num2 and store the result in remPtr
//if num2 is 0 do not calculate the remainder and the value at remPtr will be 0
//void CalculateBoth(int num1, int num2, int*prodPtr, int *remPtr);
//Call the CalculateBoth function from main.
//Print the results(value at remPtr and value at prodPtr) inside the CalculateBoth function
//Also, print the results again in the main function after the function has been called

// IN CLASS WORK
//
	//void Calculate(double num, double num2, double *qPtr, double *dPtr);

	//int main() {

	//	double x, y, quo, diff;
	//	Calculate(x, y, &quo, &diff);
	//	printf("difference is: %f", diff);

	//	return 0;
	//}

	//void Calculate(double num, double num2, double *qPtr, double *dPtr) {
	//	*dPtr = num - num2; // value at @@@@@ dPtr
	//	if (num2 != 0) {
	//		*qPtr = num / num2;
	//	}
	//	else {
	//		*qPtr = 0.0;
	//		printf("%.2f", *qPtr);
	//	}
	//};
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

void PrintStatements(int arg1);
void Calculations(int arg1, int arg2, int *prodPtr, int *remPtr);
int main() {

	int userCount, num1, num2, prod, rem;

	printf("please enter a number 1 - 9 => ");
	scanf("%d", &userCount);
	PrintStatements(userCount);

	printf("now i need 2 numbers, first one => ");
	scanf("%d", &num1);
	printf("second one => ");
	scanf("%d", &num2);
	Calculations(num1, num2, &prod, &rem);

	printf("This is the prod from the main function: %d\n", prod);
	printf("This is the rem from the main function: %d\n", rem);

	return 0;
};

void PrintStatements(int arg1) {
	int i;
	for (i = 1; i <= arg1; i++) {
		printf("FAU Owls - Hoot Hoot\n");
		printf("Programming is awesome\n");
		printf("Florida beaches are beautiful\n");
		printf("end print run #%d\n\n", i);
	}
};

void Calculations(int arg1, int arg2, int *prodPtr, int *remPtr) {
	*prodPtr = arg1 * arg2; // value @ prodtPtr
	printf("The product is: %d\n", *prodPtr);
	if (arg2 != 0) {
		*remPtr = arg1 % arg2;
		printf("The remainder is: %d\n", *remPtr);
	}
	else {
		*remPtr = 0.0;
		printf("Cannot divide by zero!\n");
	}
};
