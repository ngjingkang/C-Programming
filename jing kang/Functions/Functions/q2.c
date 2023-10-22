#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

void rootFx(int a, int b, int c, float* x1, float* x2) {
	*x1 = (-b + sqrt(b * b - (4 * a * c))) / (2 * a);
	*x2 = (-b - sqrt(b * b - (4 * a * c))) / (2 * a);
}

void main() {
	int a, b, c;
	float x1, x2;
	printf("Enter a,b and c :");
	scanf("%d %d %d", &a, &b, &c);
	rootFx(a, b, c, &x1, &x2);

	printf("Roots = %.2f  and  %.2f", x1, x2);
}