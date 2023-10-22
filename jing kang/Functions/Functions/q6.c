#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

#define CY 2019
#define CM 11

void age(int yearBorn, int monthBorn, int* ageYrs, int* ageMths) {
	*ageYrs = ((CY * 12 + CM) - (yearBorn * 12 + monthBorn)) / 12;
	*ageMths = ((CY * 12 + CM) - (yearBorn * 12 + monthBorn)) % 12;
}

void main() {
	int monthborn, yearborn, ageYears, ageMonths;
	printf("Enter your year of birth :");
	scanf("%d", &yearborn);

	printf("Enter your month of birth :");
	scanf("%d", &monthborn);

	age(yearborn, monthborn, &ageYears, &ageMonths);

	printf("Your age = %d year and %d month\n ", ageYears, ageMonths);

}
