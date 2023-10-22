#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)
void display(int num[],int size) {
	for (int a = 0; a < size; a++){
		printf("%d\t", num[a]);
	}
}

void displayRec(int num[],int size){
	for ( int a = size-1; a >= 0; a--){
		printf("%d\t", num[a]);
	}
}

void main() {
	int num[4],size=4;
	
	for (int i = 0; i < size; i++){
		printf("Enter a number :");
		scanf("%d", &num[i]);
	}

	display(num,4);
	displayRec(num, 4);
}