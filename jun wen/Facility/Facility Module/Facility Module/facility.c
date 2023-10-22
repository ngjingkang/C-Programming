#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning (disable:4996)

typedef struct {
	char type[21];
	char desc[51];
}facilityType;

typedef struct {
	char facilityID[5];
	facilityType FT;
	facilityType MT;
	char venue[51];
	int maxUser;
	int phone;
}facilityInfo;

void addFacilityRecord();
void searchFacilityRecord();
void countFacilityType();
void modifyFacilityRecord();
void displayFacilityRecord();
void deleteFacilityRecord();

void main() {
	
	int choice;
	char opt;
	
	printf(" --------------------------------------- \n");
	printf("|               Facility                |\n");
	printf("|---------------------------------------|\n");
	printf("| 1  | Add Facility Record              |\n");
	printf("| 2  | Search Facility Record           |\n");
	printf("| 3  | Count Facility Types             |\n");
	printf("| 4  | Modify Facility Record           |\n");
	printf("| 5  | Display Facility Record          |\n");
	printf("| 6  | Delete Facility Record           |\n");
	printf("| 7  | Exit Facility Module             |\n");
	printf(" --------------------------------------- \n");

	printf("\n");
	printf("Enter Your Choice :");
	scanf("%d", &choice);

		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7) {
			printf("\nInvalid Choice !\n");
			printf("Please Enter Your Choice :");
			scanf("%d", &choice);
		}

		if (choice == 1) {
			addFacilityRecord();
			printf("\n");
			system("cls");
			main();
		}

		if (choice == 2) {
			searchFacilityRecord();
			printf("\n");
			system("cls");
			main();
		}


		if (choice == 3) {
			countFacilityType();
			printf("\n");
			system("cls");
			main();
		}

		if (choice == 4) {
			modifyFacilityRecord();
			printf("\n");
			system("cls");
			main();
		}

		if (choice == 5) {
			displayFacilityRecord();
			printf("\n");
			system("cls");
			main();
		}

		if (choice == 6) {
			deleteFacilityRecord();
			printf("\n");
			system("cls");
			main();
		}

		if (choice == 7) {

		}
}

//done
void addFacilityRecord() {
	facilityInfo FI;

	FILE* fpFacility;
	fpFacility = fopen("facility.txt", "a");

	if (fpFacility == NULL) {
		printf("Error!\n");
		exit(-1);
	}

	char opt;
	
	do {
		system("cls");
		printf("\n");
		printf("-------------------------------\n");
		printf("\tAdd New Record\n");
		printf("-------------------------------\n\n");

		printf("Enter Facility ID             : ");
		rewind(stdin);
		gets(FI.facilityID);

		printf("Enter Facility Types          : ");
		rewind(stdin);
		gets(FI.FT.type);

		printf("Enter Facility Description    : ");
		rewind(stdin);
		gets(FI.FT.desc);

		printf("Enter Facility Venue          : ");
		rewind(stdin);
		gets(FI.venue);

		printf("Enter Maximum Allowable Users : ");
		scanf("%d", &FI.maxUser);

		printf("Enter The Contact Number      : ");
		scanf("%d", &FI.phone);

		fprintf(fpFacility, "%s|%s|%s|%s|%d|0%d\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser,FI.phone);

		printf("\n-------------------------------\n");
		printf("Add Another Record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &opt);

		printf("-------------------------------\n\n");
		
		while (toupper(opt) != 'Y' && toupper(opt) != 'N') {
			printf("-------------------------------\n");
			printf("Invalid Choice !\n");
			printf("Add Another Record ? (Y/N) :");
			rewind(stdin);
			scanf("%c", &opt);
			printf("-------------------------------\n\n");
		} 
	} while (toupper(opt) != 'N');

	fclose(fpFacility);
}

//done
void searchFacilityRecord(){
	facilityInfo FI;

	FILE* fpFacility;

	char search[50];
	char opt;

	do {
		system("cls");
		printf("\n");
		printf("-------------------------------\n");
		printf("\tSearch A Record\n");
		printf("-------------------------------\n\n");

		printf("Enter Facility ID to search :");
		rewind(stdin);
		gets(search);

		fpFacility = fopen("facility.txt", "r");

		if (fpFacility == NULL) {
			printf("Error!\n");
			exit(-1);
		}

		int record = 0;

		while (!feof(fpFacility)) {
			fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);

			if (strcmp(search, FI.facilityID) == 0) {
				printf(" --------------------------------------------------------------------------------------------------------------- \n");
				printf("| Facility ID |  Facility Types    |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
				printf("|-------------|--------------------|------------------------|------------------|---------------|----------------|\n");
				printf("|     %-7s |  %-16s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
				printf(" --------------------------------------------------------------------------------------------------------------- \n");
				record++;
			}
		}

		if(record == 0) {
			printf("----------\n");
			printf("No records\n");
			printf("----------\n");
		}

		printf("\n----------------------------------\n");
		printf("Search Another Record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &opt);
		printf("----------------------------------\n\n");

		while (toupper(opt) != 'Y' && toupper(opt) != 'N') {
			printf("----------------------------------\n");
			printf("Invalid Choice !\n");
			printf("Search Another Record ? (Y/N) :");
			rewind(stdin);
			scanf("%c", &opt);
			printf("----------------------------------\n\n");
		}

		fclose(fpFacility);

	}while (toupper(opt) != 'N');
}

//done
void countFacilityType() {
	facilityInfo FI;

	FILE* fpFacility;

	char search[50];
	char opt;

	do {
		system("cls");
		printf("\n");
		printf("-------------------------------\n");
		printf("\tCount Facility\n");
		printf("-------------------------------\n\n");


		printf("Enter Facility Type to Count :");
		rewind(stdin);
		gets(search);

		fpFacility = fopen("facility.txt", "r");

		if (fpFacility == NULL) {
			printf("Error!\n");
			exit(-1);
		}

		int record = 0;
		int count = 0;

		printf(" --------------------------------------------------------------------------------------------------------------- \n");
		printf("| Facility ID |  Facility Types    |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
		printf("|-------------|--------------------|------------------------|------------------|---------------|----------------|\n");

		while (!feof(fpFacility)) {
			fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);

			if (strcmp(search, FI.FT.type) == 0) {
				printf("|     %-7s |  %-16s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
				record++;
				count++;
			}

		}
		printf(" --------------------------------------------------------------------------------------------------------------- \n");
		
		printf("There are %d %s Facility \n", count, search);

		printf("\n-------------------------------------------\n");
		printf("Count Another Type Of Facility ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &opt);
		printf("-------------------------------------------\n\n");

		while (toupper(opt) != 'Y' && toupper(opt) != 'N') {
			printf("-------------------------------------------\n");
			printf("Invalid Choice !\n");
			printf("Count Another Type Of Facility ? (Y/N) :");
			rewind(stdin);
			scanf("%c", &opt);
			printf("-------------------------------------------\n\n");
		}

		fclose(fpFacility);

	} while (toupper(opt) != 'N');
	
}

//done
void modifyFacilityRecord() {
	facilityInfo FI;
	facilityInfo MI;

	FILE* fpFacility;
	FILE* fpTemp;

	char search[5];
	char choice;
	char opt;

	do {
		system("cls");
		printf("\n");
		printf("-------------------------------\n");
		printf("\tModify A Record\n");
		printf("-------------------------------\n\n");

		fpFacility = fopen("facility.txt", "r");

		if (fpFacility == NULL) {
			printf("Error!\n");
			exit(-1);
		}
		
		printf(" -------------------------------------------------------------------------------------------------------------- \n");
		printf("| Facility ID |  Facility Types  |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
		printf("|-------------|------------------|------------------------|------------------|---------------|----------------|\n");
		while (!feof(fpFacility)) {
			fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);
			printf("|     %-7s |  %-14s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
		}
		printf(" --------------------------------------------------------------------------------------------------------------- \n\n");
		fclose(fpFacility);

		printf("Enter Facility ID To Modify :");
		rewind(stdin);
		gets(search);

		fpFacility = fopen("facility.txt", "r");

		if (fpFacility == NULL) {
			printf("Error\n");
			exit(-1);
		}

		int record = 0;

		while (!feof(fpFacility)) {
			fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);
			if (strcmp(search, FI.facilityID) == 0) {
				printf(" --------------------------------------------------------------------------------------------------------------- \n");
				printf("| Facility ID |  Facility Types    |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
				printf("|-------------|--------------------|------------------------|------------------|---------------|----------------|\n");
				printf("|     %-7s |  %-16s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
				printf(" --------------------------------------------------------------------------------------------------------------- \n\n");
				record++;
			}
		}

		if (record == 0) {
			printf("----------------\n");
			printf("Record Not Found\n");
			printf("----------------\n\n");
		}

		printf("Are You Sure To Modify %s ? (Y/N) :",search);
		rewind(stdin);
		scanf("%c", &choice);


		if (toupper(choice) == 'Y') {
			fpFacility = fopen("facility.txt", "r");

			if (fpFacility == NULL) {
				printf("Error\n");
				exit(-1);
			}

			int record = 0;
			
			while (!feof(fpFacility)) {
				fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);

				fpTemp = fopen("temp.txt", "a");

				if (fpTemp == NULL) {
					printf("Error\n");
					exit(-1);
				}

				if (strcmp(search, FI.facilityID) == 0) {
					printf("\n");
					printf("Modify Facility ID             : ");
					rewind(stdin);
					gets(MI.facilityID);

					printf("Modify Facility Types          : ");
					rewind(stdin);
					gets(MI.MT.type);

					printf("Modify Facility Description    : ");
					rewind(stdin);
					gets(MI.MT.desc);

					printf("Modify Facility Venue          : ");
					rewind(stdin);
					gets(MI.venue);

					printf("Modify Maximum Allowable Users : ");
					scanf("%d", &MI.maxUser);

					printf("Modify The Contact Number      : ");
					scanf("%d", &MI.phone);

					fprintf(fpTemp, "%s|%s|%s|%s|%d|0%d\n", MI.facilityID, MI.MT.type, MI.MT.desc, MI.venue, MI.maxUser, MI.phone);

					printf("\nSuccessfully Modify\n");
					printf("%s Has Modified To \n", search);
					printf(" --------------------------------------------------------------------------------------------------------------- \n");
					printf("| Facility ID |  Facility Types    |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
					printf("|-------------|--------------------|------------------------|------------------|---------------|----------------|\n");
					printf("|     %-7s |  %-16s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", MI.facilityID, MI.MT.type, MI.MT.desc, MI.venue, MI.maxUser, MI.phone);
					printf(" --------------------------------------------------------------------------------------------------------------- \n\n");
					record++;
				}
				
				else {
					fprintf(fpTemp, "%s|%s|%s|%s|%d|0%d\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
				}

				fclose(fpTemp);

			}

			if (record == 0) {
				printf("-----------------------\n");
				printf("There Is No Such Record\n");
				printf("Unsuccessfully Modify  \n");
				printf("-----------------------\n\n");
			}

			fclose(fpFacility);

			fpFacility = fopen("facility.txt", "w");
			fclose(fpFacility);

			fpFacility = fopen("facility.txt", "a");
			fpTemp = fopen("temp.txt", "r");

			while (!feof(fpTemp)) {
				fscanf(fpTemp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);

				fprintf(fpFacility, "%s|%s|%s|%s|%d|0%d\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
			}

			fclose(fpFacility);
			fclose(fpTemp);

			fpTemp = fopen("temp.txt", "w");
			fclose(fpTemp);
		}

		if (toupper(choice) == 'N') {
			printf("-------------\n");
			printf("Cancel Delete\n");
			printf("-------------\n");
		}

		printf("\n----------------------------------\n");
		printf("Modify Another Record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &opt);
		printf("----------------------------------\n\n");

		while (toupper(opt) != 'Y' && toupper(opt) != 'N') {
			printf("----------------------------------\n");
			printf("Invalid Choice !\n");
			printf("Modify Another Record ? (Y/N) :");
			rewind(stdin);
			scanf("%c", &opt);
			printf("----------------------------------\n\n");
		}
		
	}while (toupper(opt) != 'N');
}

//done
void displayFacilityRecord() {
	system("cls");

	facilityInfo FI;

	FILE* fpFacility;
	fpFacility = fopen("facility.txt", "r");

	if (fpFacility == NULL) {
		printf("Error!\n");
		exit(-1);
	}

	int opt;

	do {
		printf("\n");
		printf("-------------------------------\n");
		printf("\tDisplay Record\n");
		printf("-------------------------------\n\n");

		printf(" -------------------------------------------------------------------------------------------------------------- \n");
		printf("| Facility ID |  Facility Types  |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
		printf("|-------------|------------------|------------------------|------------------|---------------|----------------|\n");

		while (!feof(fpFacility)) {
			fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);
			printf("|     %-7s |  %-14s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
		}

		printf(" --------------------------------------------------------------------------------------------------------------- \n");

		printf("\n------------------------\n");
		printf("Press 1 To Continue :");
		scanf("%d", &opt);
		printf("------------------------\n\n");

		while (opt != 1) {
			printf("-------------------------------\n");
			printf("Invalid Choice !\n");
			printf("Please Press 1 To Continue :");
			scanf("%d", &opt);
			printf("-------------------------------\n\n");
		}

		fclose(fpFacility);
	} while (opt != 1);
}

//done
void deleteFacilityRecord(){
	facilityInfo FI;

	FILE* fpFacility;
	FILE* fpTemp;

	char search[5];
	char opt;
	char choice;

	do {
		system("cls");
		printf("\n");
		printf("-------------------------------\n");
		printf("\tDelete A Record\n");
		printf("-------------------------------\n\n");

		FILE* fpFacility;
		fpFacility = fopen("facility.txt", "r");

		if (fpFacility == NULL) {
			printf("Error!\n");
			exit(-1);
		}

		printf(" -------------------------------------------------------------------------------------------------------------- \n");
		printf("| Facility ID |  Facility Types  |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
		printf("|-------------|------------------|------------------------|------------------|---------------|----------------|\n");

		while (!feof(fpFacility)) {
			fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);
			printf("|     %-7s |  %-14s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
		}
		printf(" --------------------------------------------------------------------------------------------------------------- \n");
		fclose(fpFacility);
		
		printf("\n");
		printf("Enter Facility ID to Delete :");
		rewind(stdin);
		gets(search);

		fpFacility = fopen("facility.txt", "r");

		if (fpFacility == NULL) {
			printf("Error!\n");
			exit(-1);
		}

		int record = 0;

		while (!feof(fpFacility)) {
			fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);

			if (strcmp(search, FI.facilityID) == 0) {
				printf(" --------------------------------------------------------------------------------------------------------------- \n");
				printf("| Facility ID |  Facility Types    |  Facility Description  |  Facility Venue  | Maximum Users | Contact Number |\n");
				printf("|-------------|--------------------|------------------------|------------------|---------------|----------------|\n");
				printf("|     %-7s |  %-16s  |  %-20s  |  %-14s  |      %-8d |   0%-10d  |\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
				printf(" --------------------------------------------------------------------------------------------------------------- \n\n");
				record++;
			}
		}

		if (record == 0) {
			printf("----------\n");
			printf("No records\n");
			printf("----------\n\n");
		}

		printf("Are You Sure To Delete ? (Y/N) :",search);
		rewind(stdin);
		scanf("%c", &choice);
	

		if (toupper(choice) == 'Y') {
			fpFacility = fopen("facility.txt", "r");

			if (fpFacility == NULL) {
				printf("Error!\n");
				exit(-1);
			}

			int record = 0;

			while (!feof(fpFacility)) {
				fscanf(fpFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);

				if (strcmp(search, FI.facilityID) == 0) {
					record++;
					printf("-------------------\n");
					printf("Successfully Delete\n");
					printf("-------------------\n");
				}

				else {
					fpTemp = fopen("temp.txt", "a");

					if (fpTemp == NULL) {
						printf("Error!\n");
						exit(-1);
					}

					fprintf(fpTemp, "%s|%s|%s|%s|%d|0%d\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);

					fclose(fpTemp);
				}
			}

			if (record == 0) {
				printf("---------------------\n");
				printf("Record not found     \n");
				printf("Unsuccessfully Delete\n");
				printf("---------------------\n");
			}


			fclose(fpFacility);

			fpFacility = fopen("facility.txt", "w");
			fclose(fpFacility);

			fpFacility = fopen("facility.txt", "a");
			fpTemp = fopen("temp.txt", "r");

			while (!feof(fpTemp)) {
				fscanf(fpTemp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n", &FI.facilityID, &FI.FT.type, &FI.FT.desc, &FI.venue, &FI.maxUser, &FI.phone);

				fprintf(fpFacility, "%s|%s|%s|%s|%d|0%d\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);
			}

			fclose(fpFacility);
			fclose(fpTemp);

			fpTemp = fopen("temp.txt", "w");
			fclose(fpTemp);
		}
		
		if (toupper(choice) == 'N') {
			printf("-------------\n");
			printf("Cancel Delete\n");
			printf("-------------\n");
		}

		printf("\n----------------------------------\n");
		printf("Delete Another Record ? (Y/N) :");
		rewind(stdin);
		scanf("%c", &opt);
		printf("----------------------------------\n\n");

		while (toupper(opt) != 'Y' && toupper(opt) != 'N') {
			printf("----------------------------------\n");
			printf("Invalid Choice !\n");
			printf("Delete Another Record ? (Y/N) :");
			rewind(stdin);
			scanf("%c", &opt);
			printf("----------------------------------\n\n");
		}

	} while (toupper(opt) != 'N');

}



