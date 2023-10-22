#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct DATE {
	int day, mont, year;
};

typedef struct {
	char model[10];
	struct DATE purchaseDate;
	double power;
	double price;
}CAR;

void main() {
	FILE* carFile;
	FILE* carSelect;

	carFile = fopen("car.txt", "r");

	if (carFile==NULL)
	{
		printf("Error!! Please try again");
		exit(-1);
	}

	carSelect = fopen("CarSelection.bin", "wb");

	CAR carRec;
	while (!feof(carFile)){
		fscanf(carFile,"%[^|]|%d|%d|%d|%lf|%ld\n", &carFile.model, &carFile.purchaseDate, &carFile.power, &carFile.price != EOF);

		fprintf(carRec,"%[^|]|%d|%d|%d|%lf|%ld\n", &carRec.model, &carRec.purchaseDate, &carRec.power, &carRec.price != EOF);

	}
}