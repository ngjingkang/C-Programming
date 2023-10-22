#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

#define PI 3.142857

void diameterAreaCircum(float radius,float*diameter,float*area,float*circumference) {
	*diameter = 2 * radius;
	*area = PI * radius * radius;
	*circumference = 2 * PI * radius;
}

void main(){
	float radius,d,a,c;
	printf("Enter radius:");
	scanf("%f", &radius);
	diameterAreaCircum(radius, &d, &a, &c);
	printf("Diameter = %.2f\n", d);
	printf("Area = %.2f\n", a);
	printf("Circumference = %.2f\n", c);
}