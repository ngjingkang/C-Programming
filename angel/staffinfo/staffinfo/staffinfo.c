#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#pragma warning (disable:4996)

typedef struct {
	char name[41];
	char gender;
}staffInfo;

typedef struct {
	char ID[21];
	staffInfo SI;
	int phoneNo;
	char password[100];
	char position[51];
}staffDetails;

typedef struct {
	char ID[21];
	staffInfo MI;
	int phoneNo;
	char password[100];
	char position[51];
}staffModify;

void addStaffInformation();
void searchStaffInformation();
void modifyStaffInformation();
void displayStaffInformation();
void deleteStaffInformation();
void countStaffPosition();

void main() {

	int select;

	printf(" --------------------------------- \n");
	printf("|         Staff Information       |\n");
	printf("|---------------------------------|\n");
	printf("|1  | Add staff information       |\n");
	printf("|2  | Search staff information    |\n");
	printf("|3  | Modify staff information    |\n");
	printf("|4  | Display staff information   |\n");
	printf("|5  | Delete staff information    |\n");
	printf("|6  | Count staff position        |\n");
	printf("|7  | Exit staff information      |\n");
	printf(" --------------------------------- \n");

	printf("\n");
	printf("Please select one :");
	scanf("%d", &select);

		if (select == 1) {
			addStaffInformation();
			printf("\n");
			system("cls");
			main();
		}

		if (select == 2) {
			searchStaffInformation();
			printf("\n");
			system("cls");
			main();
		}

		if (select == 3) {
			modifyStaffInformation();
			printf("\n");
			system("cls");
			main();
		}

		if (select == 4) {
			displayStaffInformation();
			printf("\n");
			system("cls");
			main();
		}

		if (select == 5) {
			deleteStaffInformation();
			printf("\n");
			system("cls");
			main();
		}

		if (select == 6) {
			countStaffPosition();
			printf("\n");
			system("cls");
			main();
		}

		if (select == 7) {

		}
}

//done
void addStaffInformation() {
	char option;

	staffDetails SD;

	FILE* fpStaff;
	fpStaff = fopen("staffinformation.bin", "ab");

	if (fpStaff == NULL) {
		printf("Error\n");
		exit(-1);
	}

	do {
		system("cls");
		printf("\n-------------------------------------\n");
		printf("\tAdd Staff Information\n");
		printf("---------------------------------------\n\n");

		printf("Enter Staff ID           : ");
		rewind(stdin);
		gets(SD.ID);

		printf("Enter Staff Name         : ");
		rewind(stdin);
		gets(SD.SI.name);

		printf("Enter Staff Gender (M/F) : ");
		rewind(stdin);
		scanf("%c", &SD.SI.gender);

		printf("Enter Staff Phone Number : ");
		scanf("%d", &SD.phoneNo);

		printf("Enter Staff Password     : ");
		rewind(stdin);
		gets(SD.password);

		printf("Enter Staff Position     : ");
		rewind(stdin);
		gets(SD.position);

		fwrite(&SD, sizeof(SD), 1, fpStaff);

		printf("\n-------------------------------------------------\n");
		printf("Continue to add another staff record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &option);
		printf("-------------------------------------------------\n\n");

	} while (toupper(option) == 'Y');

	fclose(fpStaff);
}

//done
void searchStaffInformation() {
	char search[20];
	char option;

	staffDetails SD;

	do {
		system("cls");
		printf("\n----------------------------------------\n");
		printf("\tSearch Staff Information\n");
		printf("----------------------------------------\n\n");

		FILE* fpStaff;
		fpStaff = fopen("staffinformation.bin", "rb");

		if (fpStaff == NULL) {
			printf("Error\n");
			exit(-1);
		}

		printf("Enter Staff ID to search : ");
		rewind(stdin);
		gets(search);

		int check = 0;

		while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
			if (strcmp(search, SD.ID) == 0) {
				printf(" ----------------------------------------------------------------------------------------------------------- \n");
				printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
				printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
				printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", SD.ID, SD.SI.name, SD.SI.gender, SD.phoneNo, SD.password, SD.position);
				printf(" ----------------------------------------------------------------------------------------------------------- \n");
				check++;
			}
		}

		if (check == 0) {
			printf("----------------\n");
			printf("Record Not Found\n");
			printf("----------------\n");
		}

		fclose(fpStaff);

		printf("\n----------------------------------------------------\n");
		printf("Continue to search another staff record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &option);
		printf("----------------------------------------------------\n\n");

	} while (toupper(option) == 'Y');
}

//done
void modifyStaffInformation(){
	staffDetails SD;
	staffModify MD;
	

	FILE* fpStaff;
	FILE* fpChange;

	char search[21];
	char select;
	char option;

	do {
		system("cls");
		printf("\n----------------------------------------\n");
		printf("\tModify Staff Information\n");
		printf("----------------------------------------\n\n");

		FILE* fpStaff;
		fpStaff = fopen("staffinformation.bin", "rb");

		if (fpStaff == NULL) {
			printf("Error\n");
			exit(-1);
		}

		printf(" ----------------------------------------------------------------------------------------------------------- \n");
		printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
		printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
		while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
			printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", SD.ID, SD.SI.name, SD.SI.gender, SD.phoneNo, SD.password, SD.position);
		}
		printf(" ----------------------------------------------------------------------------------------------------------- \n\n");
		fclose(fpStaff);

		printf("Enter staff id to modify record :");
		rewind(stdin);
		gets(search);

		fpStaff = fopen("staffinformation.bin", "rb");

		if (fpStaff == NULL) {
			printf("Error\n");
			exit(-1);
		}

		int check = 0;
		while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
			if (strcmp(search, SD.ID) == 0) {
				printf(" ----------------------------------------------------------------------------------------------------------- \n");
				printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
				printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
				printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", SD.ID, SD.SI.name, SD.SI.gender, SD.phoneNo, SD.password, SD.position);
				printf(" ----------------------------------------------------------------------------------------------------------- \n\n");
				check++;
			}
		}

		if (check == 0) {
			printf("------------------\n");
			printf("Record not found\n");
			printf("------------------\n\n");
		}

		printf("Are you sure to modify %s record ? (Y/N) :", search);
		rewind(stdin);
		scanf("%c", &select);

		if (toupper(select) == 'Y') {
			fpStaff = fopen("staffinformation.bin", "rb");

			if (fpStaff == NULL) {
				printf("Error\n");
				exit(-1);
			}

			int check = 0;
			while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
				fpChange = fopen("change.bin", "ab");

				if (fpChange == NULL) {
					printf("Error\n");
					exit(-1);
				}

				if (strcmp(search, SD.ID) == 0) {
					printf("\n"); 
					printf("Modify staff ID           : ");
					rewind(stdin);
					gets(MD.ID);

					printf("Modify staff name         : ");
					rewind(stdin);
					gets(MD.MI.name);

					printf("Modify staff gender       : ");
					rewind(stdin);
					scanf("%c", &MD.MI.gender);

					printf("Modify staff phone number : ");
					scanf("%d", &MD.phoneNo);

					printf("Modify staff password     : ");
					rewind(stdin);
					gets(MD.password);

					printf("Modify staff position     : ");
					rewind(stdin);
					gets(MD.position);

					fwrite(&MD, sizeof(MD), 1, fpChange);

					printf("\nModify Successfully\n");
					printf("%s record has been modified to \n",search);
					printf(" ----------------------------------------------------------------------------------------------------------- \n");
					printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
					printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
					printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", MD.ID, MD.MI.name, MD.MI.gender, MD.phoneNo, MD.password, MD.position);
					printf(" ----------------------------------------------------------------------------------------------------------- \n\n");
					check++;

				}

				else {
					fwrite(&SD, sizeof(SD), 1, fpChange);
				}
				fclose(fpChange);
			}

			if (check == 0) {
				printf("---------------------\n");
				printf("No record\n");
				printf("Modify Unsuccessfully\n");
				printf("---------------------\n\n");
			}
			fclose(fpStaff);

			fpStaff = fopen("staffinformation.bin", "wb");
			fclose(fpStaff);

			fpStaff = fopen("staffinformation.bin", "ab");
			fpChange = fopen("change.bin", "rb");

			while (fread(&SD, sizeof(SD), 1, fpChange) != 0) {
				fwrite(&SD, sizeof(SD), 1, fpStaff);
			}

			fclose(fpStaff);
			fclose(fpChange);

			fpChange = fopen("change.bin", "wb");
			fclose(fpChange);

		}

		if (toupper(select) == 'N') {
			printf("-------------\n");
			printf("Modify Cancel\n");
			printf("-------------\n\n");
		}

		printf("----------------------------------------------------\n");
		printf("Continue to modify another staff record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &option);
		printf("----------------------------------------------------\n\n");

	} while (toupper(option) == 'Y');

}

//done
void displayStaffInformation(){
	system("cls");

	int option;

	staffDetails SD;
	
	do {
		printf("\n-----------------------------------------\n");
		printf("\tDisplay Staff Information\n");
		printf("-----------------------------------------\n\n");

		FILE* fpStaff;
		fpStaff = fopen("staffinformation.bin", "rb");

		if (fpStaff == NULL) {
			printf("Error\n");
			exit(-1);
		}

		
		printf(" ----------------------------------------------------------------------------------------------------------- \n");
		printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
		printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
		
		while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
			printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", SD.ID, SD.SI.name, SD.SI.gender, SD.phoneNo, SD.password, SD.position);
		}

		printf(" ----------------------------------------------------------------------------------------------------------- \n");
		fclose(fpStaff);

		printf("Press 1 to continue :");
		scanf("%d", &option);

		while (option!=1){
			printf("Invalid Choice\n");
			printf("Press 1 to continue :");
			scanf("%d", &option);
		}

	} while (option != 1);
}

//done
void deleteStaffInformation(){
	
	staffDetails SD;

	FILE* fpStaff;
	FILE* fpChange;

	char search[20];
	char option;
	char select;
	
	do{
	system("cls");
	printf("\n----------------------------------------\n");
	printf("\tDelete Staff Information\n");
	printf("----------------------------------------\n\n");

		fpStaff = fopen("staffinformation.bin", "rb");

		if (fpStaff == NULL) {
			printf("Error\n");
			exit(-1);
		}

		printf(" ----------------------------------------------------------------------------------------------------------- \n");
		printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
		printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");

		while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
			printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", SD.ID, SD.SI.name, SD.SI.gender, SD.phoneNo, SD.password, SD.position);
		}

		printf(" ----------------------------------------------------------------------------------------------------------- \n\n");
		fclose(fpStaff);

		printf("Enter staff id to delete :");
		rewind(stdin);
		gets(search);

		fpStaff = fopen("staffinformation.bin", "rb");

		if (fpStaff == NULL) {
			printf("Error\n");
			exit(-1);
		}

		int check = 0;
		while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
			if (strcmp(search, SD.ID) == 0) {
				printf(" ----------------------------------------------------------------------------------------------------------- \n");
				printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
				printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
				printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", SD.ID, SD.SI.name, SD.SI.gender, SD.phoneNo, SD.password, SD.position);
				printf(" ----------------------------------------------------------------------------------------------------------- \n\n");
				check++;
			}
		}

		if (check == 0) {
			printf("------------------\n");
			printf("Record not found\n");
			printf("------------------\n\n");
		}

		printf("Are you sure to delete %s record ? (Y/N) :",search);
		rewind(stdin);
		scanf("%c", &select);

		if (toupper(select) == 'Y') {
			fpStaff = fopen("staffinformation.bin", "rb");

			if (fpStaff == NULL) {
				printf("Error\n");
				exit(-1);
			}

			int check = 0;

			while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
				if (strcmp(search, SD.ID) == 0) {
					check++;
					printf("-------------------\n");
					printf("Delete successfully\n");
					printf("-------------------\n");
				}

				else {
					fpChange = fopen("change.bin", "ab");

					if (fpChange == NULL) {
						printf("Error\n");
						exit(-1);
					}

					fwrite(&SD, sizeof(SD), 1, fpChange);
					fclose(fpChange);
				}
			}

			if (check == 0) {
				printf("----------------------\n");
				printf("There is no record\n");
				printf("Delete Unsuccesfully\n");
				printf("----------------------\n");
			}

			fclose(fpStaff);

			fpStaff = fopen("staffinformation.bin", "wb");
			fclose(fpStaff);

			fpStaff = fopen("staffinformation.bin", "ab");
			fpChange = fopen("change.bin", "rb");

			while (fread(&SD, sizeof(SD), 1, fpChange) != 0) {
				fwrite(&SD, sizeof(SD), 1, fpStaff);
			}

			fclose(fpStaff);
			fclose(fpChange);

			fpChange = fopen("change.bin", "wb");
			fclose(fpChange);

		}

		if (toupper(select) == 'N') {
			printf("-------------\n");
			printf("Delete cancel\n");
			printf("-------------\n");
		}

		printf("\n----------------------------------------------------\n");
		printf("Continue to delete another staff record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &option);
		printf("----------------------------------------------------\n\n");
	} while (toupper(option) == 'Y');

}

//done
void countStaffPosition(){
	char search[20];
	char option;

	staffDetails SD;

	do {
		system("cls");
		printf("\n------------------------------------\n");
		printf("\tCount Staff Position\n");
		printf("------------------------------------\n\n");

		FILE* fpStaff;
		fpStaff = fopen("staffinformation.bin", "rb");

		if (fpStaff == NULL) {
			printf("Error\n");
			exit(-1);
		}

		printf("Enter staff position to count: ");
		rewind(stdin);
		gets(search);

		int count = 0;
		int check = 0;

		
		printf(" ----------------------------------------------------------------------------------------------------------- \n");
		printf("|   Staff ID   |  Staff Name  |  Staff Gender  |  Staff Phone Number  |  Staff Password  |  Staff Position  |\n");
		printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
		while (fread(&SD, sizeof(SD), 1, fpStaff) != 0) {
			if (strcmp(search, SD.position) == 0) {
				printf("|  %s  |  %-10s  |       %-7c  |      0%-10d     |  %-14s  |  %-14s  |\n", SD.ID, SD.SI.name, SD.SI.gender, SD.phoneNo, SD.password, SD.position);
				count++;
				check++;
			}
		}
		printf(" ----------------------------------------------------------------------------------------------------------- \n");
		printf("There is %d %s position\n", count, search);

		if (check == 0) {
			printf("No record\n");
		}

		fclose(fpStaff);

		printf("\n-----------------------------------------------------\n");
		printf("Continue to count another staff position ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &option);
		printf("-----------------------------------------------------\n\n");

	} while (toupper(option) == 'Y');
}

