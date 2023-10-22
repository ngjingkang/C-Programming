#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)
void profit(int sell[],int cost[],int prof[],int size){
	for (int a = 0; a < size; a++) {
		prof[a] = sell[a] - cost[a];
	}
}

void main() {
	int s[5] = { 20,17,24,26,18 };
	int c[5] = { 16,10,20,22,15 };
	int p[5];
	int size = 5;
	profit(s[5], c[5],p[5],size);
	
}