#include <stdio.h>
#include <stdio.h>

#include <ctype.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>

#include <time.h>

#include <dos.h>

#include <Windows.h>

#pragma warning(disable: 4996)

struct bookingID {
    char bookingID[30];
};

struct Member {
    char name[51], sex;
    int age;
    char address[101];
    int tel, duration;
};

typedef struct {
    struct bookingID bookingid;
    char todayDate[30], bookingDate[30], facilityID[30], bookingID[30];
    int bookingTimeMin, bookingTimeHour, day, month, year;
}
booking;

typedef struct {
    struct bookingID bookingid;
    char todayDate[30], bookingDate[30], facilityID[30], bookingID[30];
    int bookingTimeMin, bookingTimeHour, day, month, year;
}
bookingModify;

typedef struct {
    int hours;
    int minutes;
    int seconds;
}
time1;

typedef struct {
    int day;
    int month;
    int year;
    char facilityID[20];
    char memberID[20];
    char Usagetype[20];
    int contactno;
    time1 start, stop, diff;
}
FU;

typedef struct {
    int totalhr;
    int totalmin;
    int totalsec;
}
Facility;

typedef struct {
    char type[21];
    char desc[51];
}
facilityType;

typedef struct {
    char facilityID[5];
    facilityType FT;
    facilityType MT;
    char venue[51];
    int maxUser;
    int phone;
}
facilityInfo;

typedef struct {
    char name[41];
    char gender;
}
staffInfo;

typedef struct {
    char ID[21];
    staffInfo SI;
    int phoneNo;
    char password[100];
    char position[51];
}
staffDetails;

typedef struct {
    char ID[21];
    staffInfo MI;
    int phoneNo;
    char password[100];
    char position[51];
}
staffModify;

void add_member();
void search_member();
void modify_member();
void erase_member();
void display_member();
void countTotalMember();
void addBooking();
void displayBooking();
void searchBooking();
void modifyBooking();
void deleteBooking();
void countBooking();
void AddFU();
void SearchFU();
void ModifyFU();
void DeleteFU();
void DisplayallFU();
void ReportsFU();
void addFacilityRecord();
void searchFacilityRecord();
void countFacilityType();
void modifyFacilityRecord();
void displayFacilityRecord();
void deleteFacilityRecord();
void addStaffInformation();
void searchStaffInformation();
void modifyStaffInformation();
void displayStaffInformation();
void deleteStaffInformation();
void countStaffPosition();
void mainStaffInfo();
void mainFU();
void mainFacilityInfo();
void mainBooking();
void mainMemberInfo();

void main() {
    int opt;

    do {
		system("cls");
        //Prompt user to choose 
        printf(" ----------------------------- \n");
        printf("|          Main Page          |\n");
        printf("|-----------------------------|\n");
        printf("| 1  |  Staff Information     |\n");
        printf("| 2  |  Facility Usage        |\n");
        printf("| 3  |  Facility Information  |\n");
        printf("| 4  |  Booking               |\n");
        printf("| 5  |  Member Information    |\n");
        printf("| 6  |  Exit                  |\n");
        printf(" ----------------------------- \n");
        printf("\nEnter your choice :");
        scanf("%d", &opt);
        printf("\n");

        switch (opt) {
        case 1:
            system("cls");
            mainStaffInfo();
            break;
        case 2:
            system("cls");
            mainFU();
            break;
        case 3:
            system("cls");
            mainFacilityInfo();
            break;
        case 4:
            system("cls");
            mainBooking();
            break;
        case 5:
            system("cls");
            mainMemberInfo();
            break;
        case 6:
            exit(-1);
        default:
            printf("Wrong Choice. Please enter again\n\n");
            break;
        }
    } while (opt != 6);

}

void mainStaffInfo() {

    int select;

    printf("\n---------------------------------\n");
    printf("\tStaff Information \n");
    printf("---------------------------------\n\n");
    printf(" --------------------------------- \n");
    printf("|         Staff Information       |\n");
    printf("|---------------------------------|\n");
    printf("|1  | Add staff information       |\n");
    printf("|2  | Search staff information    |\n");
    printf("|3  | Modify staff information    |\n");
    printf("|4  | Display staff information   |\n");
    printf("|5  | Delete staff information    |\n");
    printf("|6  | Count staff position        |\n");
    printf("|7  | Exit to main page           |\n");
    printf(" --------------------------------- \n");

    printf("\n");
    printf("Please select one :");
    scanf("%d", &select);

    if (select == 1) {
        addStaffInformation();
        printf("\n");
        system("cls");
        mainStaffInfo();
    }

    if (select == 2) {
        searchStaffInformation();
        printf("\n");
        system("cls");
        mainStaffInfo();
    }

    if (select == 3) {
        modifyStaffInformation();
        printf("\n");
        system("cls");
        mainStaffInfo();
    }

    if (select == 4) {
        displayStaffInformation();
        printf("\n");
        system("cls");
        mainStaffInfo();
    }

    if (select == 5) {
        deleteStaffInformation();
        printf("\n");
        system("cls");
        mainStaffInfo();
    }

    if (select == 6) {
        countStaffPosition();
        printf("\n");
        system("cls");
        mainStaffInfo();
    }

    if (select == 7) {
        main();
    }
}

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

void modifyStaffInformation() {
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
                    printf("%s record has been modified to \n", search);
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

void displayStaffInformation() {
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

        while (option != 1) {
            printf("Invalid Choice\n");
            printf("Press 1 to continue :");
            scanf("%d", &option);
        }

    } while (option != 1);
}

void deleteStaffInformation() {

    staffDetails SD;

    FILE* fpStaff;
    FILE* fpChange;

    char search[20];
    char option;
    char select;

    do {
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

        printf("Are you sure to delete %s record ? (Y/N) :", search);
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

void countStaffPosition() {
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

void mainFU() {
    int Opt;

    do {
        printf("\n------------------------------\n");
        printf("\tFacility Usage\n");
        printf("------------------------------\n\n");
        printf(" ----------------------------------------- \n");
        printf("|              Facility Usage             |\n");
        printf("|-----------------------------------------|\n");
        printf("| 1  | Add Facility Usage                 |\n");
        printf("| 2  | Search Facility Usage              |\n");
        printf("| 3  | Modify Facility Usage              |\n");
        printf("| 4  | Delete Facility Usage              |\n");
        printf("| 5  | Display All Facility Usage         |\n");
        printf("| 6  | Reports of all the Facility Usage  |\n");
        printf("| 7  | Exit To Main Page                  |\n");
        printf(" ----------------------------------------- \n");

        printf("\n");
        printf("Select your option :");
        scanf("%d", &Opt);

        switch (Opt) {
        case 1:
            AddFU();
            printf("\n");
            system("cls");
            mainFU();
            break;

        case 2:
            SearchFU();
            printf("\n");
            system("cls");
            mainFU();
            break;

        case 3:
            ModifyFU();
            printf("\n");
            system("cls");
            mainFU();
            break;

        case 4:
            DeleteFU();
            printf("\n");
            system("cls");
            mainFU();
            break;

        case 5:
            DisplayallFU();
            printf("\n");
            system("cls");
            mainFU();
            break;

        case 6:
            ReportsFU();
            printf("\n");
            system("cls");
            mainFU();
            break;

        case 7:
            main();
            printf("\nThank You\n");
            break;

        default:
            printf("\nPlease Select a proper option!!!\n\n");
            break;
        }

    } while (Opt != 1 && Opt != 2 && Opt != 3 && Opt != 4 && Opt != 5 && Opt != 6 && Opt != 7);

}

void AddFU() {
    FU U;
    char Opt;

    FILE* newFU;
    newFU = fopen("FacilityUsage.txt", "a");

    if (newFU == NULL) {
        printf("Error!! \n");
        exit(-1);
    }

    do {
        system("cls");
        printf("\n");
        printf("----------------------------------\n");
        printf("\tAdd Facility Usage\n");
        printf("----------------------------------\n\n");

        printf("Enter Member ID                                : ");
        rewind(stdin);
        gets(U.memberID);

        printf("Enter Facility ID                              : ");
        rewind(stdin);
        gets(U.facilityID);

        printf("Enter date (dd/mm/yyyy)                        : ");
        scanf("%d/%d/%d", &U.day, &U.month, &U.year);
        rewind(stdin);

        printf("Enter hours, minutes and seconds of start time : ");
        rewind(stdin);
        scanf("%d%d%d", &U.start.hours, &U.start.minutes, &U.start.seconds);

        printf("Enter hours, minutes and seconds of stop time  : ");
        rewind(stdin);
        scanf("%d%d%d", &U.stop.hours, &U.stop.minutes, &U.stop.seconds);

        if (U.start.seconds > U.stop.seconds) {
            U.stop.seconds += 60;
            --U.stop.minutes;
        }

        if (U.start.minutes > U.stop.minutes) {
            U.stop.minutes += 60;
            --U.stop.hours;
        }

        U.diff.seconds = U.stop.seconds - U.start.seconds;
        U.diff.minutes = U.stop.minutes - U.start.minutes;
        U.diff.hours = U.stop.hours - U.start.hours;

        printf("Enter Usage type                              : ");
        rewind(stdin);
        gets(U.Usagetype);

        printf("Enter Contact Numbers                         : ");
        scanf("%d", &U.contactno);

        fprintf(newFU, "\n%s|%s|%02d-%02d-%4d|%02d:%02d:%02d-%02d:%02d:%02d|%02d:%02d:%02d|%s|0%d|", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);

        printf("\n--------------------------------------------\n");
        printf("continue add new Facility Usage?? (Y/N) :");
        rewind(stdin);
        scanf("%c", &Opt);
        printf("------------------------------------------------\n");

    } while (Opt == 'Y' || Opt == 'y');

    fclose(newFU);
}

void SearchFU() {
    FU U;
    FILE* newFU;
    char memberid[20], facilityid[20];
    char Opt;

    do {
        system("cls");
        printf("\n");
        printf("-------------------------------------\n");
        printf("\tSearch Facility Usage\n");
        printf("-------------------------------------\n\n");

        printf("Enter member ID to search   : ");
        rewind(stdin);
        scanf("%s", &memberid);

        printf("Enter facility ID to search : ");
        rewind(stdin);
        gets(facilityid);

        newFU = fopen("FacilityUsage.txt", "r");

        if (newFU == NULL) {
            printf("Error!! Please try again");
            exit(-1);
        }

        int time = 0;
        while (!feof(newFU)) {
            fscanf(newFU, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);

            if (strcmp(memberid, U.memberID) == 0 && strcmp(facilityid, U.facilityID) == 0) {
                time++;
                printf(" --------------------------------------------------------------------------------------------------------------------- \n");
                printf("|  MemberID  |  FacilityID  |  DateBooked  |  Start_Time - End_Time  |  Total Time  |  Usage Type  |  Contact Number  |\n");
                printf("|------------|--------------|--------------|-------------------------|--------------|--------------|------------------|\n");
                printf("|  %-8s  |      %s     |  %02d-%02d-%02d  |   %02d:%02d:%02d - %02d:%02d:%02d   |   %02d:%02d:%02d   |  %-10s  |    0%d    |\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
                printf(" --------------------------------------------------------------------------------------------------------------------- \n");
            }
        }

        if (time == 0) {
            printf("--------------------------\n");
            printf("There is no record found!!\n");
            printf("--------------------------\n");
        }

        printf("\n------------------------------------------\n");
        printf("Do you want to keep searching ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &Opt);
        printf("------------------------------------------\n\n");

    } while (Opt == 'Y' || Opt == 'y');

    fclose(newFU);
}

void ModifyFU() {
    FU U;
    FU M;

    FILE* real;
    FILE* temp;

    char memberid[20], facilityid[20], Opt;

    do {
        system("cls");
        printf("\n");
        printf("-------------------------------------\n");
        printf("\tModify Facility Usage\n");
        printf("-------------------------------------\n\n");

        real = fopen("FacilityUsage.txt", "r");

        if (real == NULL) {
            printf("Error!! Please try again.");
            exit(-1);
        }

        printf(" --------------------------------------------------------------------------------------------------------------------- \n");
        printf("|  MemberID  |  FacilityID  |  DateBooked  |  Start_Time - End_Time  |  Total Time  |  Usage Type  |  Contact Number  |\n");
        printf("|------------|--------------|--------------|-------------------------|--------------|--------------|------------------|\n");

        while (!feof(real)) {
            fscanf(real, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);
            printf("|  %-8s  |      %s     |  %02d-%02d-%02d  |   %02d:%02d:%02d - %02d:%02d:%02d   |   %02d:%02d:%02d   |  %-10s  |    0%d    |\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
        }
        printf(" --------------------------------------------------------------------------------------------------------------------- \n");

        fclose(real);

        printf("\n");
        printf("Enter member ID To Modify   : ");
        rewind(stdin);
        gets(memberid);

        printf("Enter facility ID to modify : ");
        rewind(stdin);
        gets(facilityid);

        real = fopen("FacilityUsage.txt", "r");

        if (real == NULL) {
            printf("Error!! Please try again.");
            exit(-1);
        }

        while (!feof(real)) {
            fscanf(real, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);

            if (strcmp(memberid, U.memberID) == 0 && strcmp(facilityid, U.facilityID) == 0) {
                printf(" --------------------------------------------------------------------------------------------------------------------- \n");
                printf("|  MemberID  |  FacilityID  |  DateBooked  |  Start_Time - End_Time  |  Total Time  |  Usage Type  |  Contact Number  |\n");
                printf("|------------|--------------|--------------|-------------------------|--------------|--------------|------------------|\n");
                printf("|  %-8s  |      %s     |  %02d-%02d-%02d  |   %02d:%02d:%02d - %02d:%02d:%02d   |   %02d:%02d:%02d   |  %-10s  |    0%d    |\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
                printf(" --------------------------------------------------------------------------------------------------------------------- \n");
            }
        }

        real = fopen("FacilityUsage.txt", "r");

        if (real == NULL) {
            printf("Error !! Please try again.\n");
            exit(-1);
        }

        int time = 0;

        while (!feof(real)) {
            fscanf(real, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);

            temp = fopen("temp.txt", "a");

            if (real == NULL) {
                printf("Error\n");
                exit(-1);
            }

            if (strcmp(memberid, U.memberID) == 0 && strcmp(facilityid, U.facilityID) == 0) {
                printf("\n");
                printf("Enter New Member ID                                : ");
                rewind(stdin);
                gets(M.memberID);

                printf("Enter New Facility ID                              : ");
                rewind(stdin);
                gets(M.facilityID);

                printf("Enter New date (dd/mm/yyyy)                        : ");
                scanf("%d/%d/%d", &M.day, &M.month, &M.year);

                printf("Enter hours, minutes and seconds of New start time : ");
                scanf("%d%d%d", &M.start.hours, &M.start.minutes, &M.start.seconds);

                printf("Enter hours, minutes and seconds of New stop time  : ");
                scanf("%d%d%d", &M.stop.hours, &M.stop.minutes, &M.stop.seconds);

                if (M.start.seconds > M.stop.seconds) {
                    M.stop.seconds += 60;
                    --M.stop.minutes;
                }

                if (M.start.minutes > M.stop.minutes) {
                    M.stop.minutes += 60;
                    --M.stop.hours;
                }

                M.diff.seconds = M.stop.seconds - M.start.seconds;
                M.diff.minutes = M.stop.minutes - M.start.minutes;
                M.diff.hours = M.stop.hours - M.start.hours;

                printf("Enter New Usage type                               : ");
                rewind(stdin);
                gets(M.Usagetype);

                printf("Enter new Contact Numbers                          : ");
                scanf("%d", &M.contactno);

                fprintf(temp, "%s|%s|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%s|0%d|\n", M.memberID, M.facilityID, M.day, M.month, M.year, M.start.hours, M.start.minutes, M.start.seconds, M.stop.hours, M.stop.minutes, M.stop.seconds, M.diff.hours, M.diff.minutes, M.diff.seconds, M.Usagetype, M.contactno);

                printf("\nSuccessfully Modify\n");
                printf("%s Member ID & %s Facility ID has modified to\n ", memberid, facilityid);
                printf(" --------------------------------------------------------------------------------------------------------------------- \n");
                printf("|  MemberID  |  FacilityID  |  DateBooked  |  Start_Time - End_Time  |  Total Time  |  Usage Type  |  Contact Number  |\n");
                printf("|------------|--------------|--------------|-------------------------|--------------|--------------|------------------|\n");
                printf("|  %-8s  |      %s     |  %02d-%02d-%02d  |   %02d:%02d:%02d - %02d:%02d:%02d   |   %02d:%02d:%02d   |  %-10s  |    0%d    |\n", M.memberID, M.facilityID, M.day, M.month, M.year, M.start.hours, M.start.minutes, M.start.seconds, M.stop.hours, M.stop.minutes, M.stop.seconds, M.diff.hours, M.diff.minutes, M.diff.seconds, M.Usagetype, M.contactno);
                printf(" --------------------------------------------------------------------------------------------------------------------- \n");
                time++;
            }
            else {
                fprintf(temp, "%s|%s|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%s|0%d|\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
            }

            fclose(temp);

        }

        if (time == 0) {
            printf("\n---------------------------\n");
            printf("There is no record found !!\n");
            printf("---------------------------\n");
        }

        fclose(real);

        real = fopen("FacilityUsage.txt", "w");
        fclose(real);

        real = fopen("FacilityUsage.txt", "a");
        temp = fopen("temp.txt", "r");

        while (!feof(temp)) {
            fscanf(temp, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);

            fprintf(real, "%s|%s|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%s|0%d|\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
        }

        fclose(real);
        fclose(temp);

        temp = fopen("temp.txt", "w");
        fclose(temp);

        printf("\n------------------------------------------------\n");
        printf("Do you want to modify another record ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &Opt);
        printf("------------------------------------------------\n\n");

    } while (Opt == 'y' || Opt == 'Y');

}

void DeleteFU() {
    FU U;

    FILE* real;
    FILE* temp;

    char memberid[20], facilityid[20], Opt;

    do {
        system("cls");
        printf("\n");
        printf("-------------------------------------\n");
        printf("\tDelete Facility Usage\n");
        printf("-------------------------------------\n\n");

        real = fopen("FacilityUsage.txt", "r");

        if (real == NULL) {
            printf("Error!! Please try again.");
            exit(-1);
        }

        printf(" --------------------------------------------------------------------------------------------------------------------- \n");
        printf("|  MemberID  |  FacilityID  |  DateBooked  |  Start_Time - End_Time  |  Total Time  |  Usage Type  |  Contact Number  |\n");
        printf("|------------|--------------|--------------|-------------------------|--------------|--------------|------------------|\n");

        while (!feof(real)) {
            fscanf(real, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);
            printf("|  %-8s  |      %s     |  %02d-%02d-%02d  |   %02d:%02d:%02d - %02d:%02d:%02d   |   %02d:%02d:%02d   |  %-10s  |    0%d    |\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
        }
        printf(" --------------------------------------------------------------------------------------------------------------------- \n");

        fclose(real);

        printf("\n");
        printf("Enter member ID to Delete   : ");
        rewind(stdin);
        gets(memberid);

        printf("Enter facility ID to Delete : ");
        rewind(stdin);
        gets(facilityid);

        real = fopen("FacilityUsage.txt", "r");

        if (real == NULL) {
            printf("Error!\n");
            exit(-1);
        }

        int time = 0;

        while (!feof(real)) {
            fscanf(real, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);

            if (strcmp(memberid, U.memberID) == 0 && strcmp(facilityid, U.facilityID) == 0) {
                time++;
                printf("-------------------\n");
                printf("Successfully Delete\n");
                printf("-------------------\n");
            }
            else {
                temp = fopen("temp.txt", "a");

                if (temp == NULL) {
                    printf("Error!\n");
                    exit(-1);
                }

                fprintf(temp, "%s|%s|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%s|%d|\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);

                fclose(temp);
            }
        }

        if (time == 0) {
            printf("--------------------------\n");
            printf("There is no record found!!\n");
            printf("--------------------------\n");
        }

        fclose(real);

        real = fopen("FacilityUsage.txt", "w");
        fclose(real);

        real = fopen("FacilityUsage.txt", "a");
        temp = fopen("temp.txt", "r");

        while (!feof(temp)) {
            fscanf(temp, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);

            fprintf(real, "%s|%s|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%s|0%d|\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
        }

        temp = fopen("temp.txt", "w");
        fclose(temp);

        printf("\n------------------------------------------------\n");
        printf("Do you want to delete another record ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &Opt);
        printf("------------------------------------------------\n\n");

    } while (Opt != 'n' && Opt != 'N');
    fclose(real);
    fclose(temp);
}

void DisplayallFU() {
    FU U;
    FILE* real;

    int choice;

    real = fopen("FacilityUsage.txt", "r");

    if (real == NULL) {
        printf("Error!! Please try again.");
        exit(-1);
    }

    do {
        system("cls");
        printf("\n");
        printf("------------------------------------------\n");
        printf("\tDisplay All Facility Usage\n");
        printf("------------------------------------------\n\n");

        printf(" --------------------------------------------------------------------------------------------------------------------- \n");
        printf("|  MemberID  |  FacilityID  |  DateBooked  |  Start_Time - End_Time  |  Total Time  |  Usage Type  |  Contact Number  |\n");
        printf("|------------|--------------|--------------|-------------------------|--------------|--------------|------------------|\n");

        while (!feof(real)) {
            fscanf(real, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);
            printf("|  %-8s  |      %s     |  %02d-%02d-%02d  |   %02d:%02d:%02d - %02d:%02d:%02d   |   %02d:%02d:%02d   |  %-10s  |    0%d    |\n", U.memberID, U.facilityID, U.day, U.month, U.year, U.start.hours, U.start.minutes, U.start.seconds, U.stop.hours, U.stop.minutes, U.stop.seconds, U.diff.hours, U.diff.minutes, U.diff.seconds, U.Usagetype, U.contactno);
        }
        printf(" --------------------------------------------------------------------------------------------------------------------- \n");

       
        printf("Press 1 to continue :");
        scanf("%d", &choice);
        printf("\n------------------------\n");

        while (choice != 1) {
            printf("-------------------------------\n");

            printf("Invalid Choice\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &choice);
            printf("-------------------------------\n\n");
        }

    } while (choice != 1);
    fclose(real);
}

void ReportsFU() {
    FU U;
    Facility SP, KA, BB, BC, PP, TC;
    FILE* real;

    int choice;

    SP.totalhr = 0;
    SP.totalmin = 0;
    SP.totalsec = 0;

    KA.totalhr = 0;
    KA.totalmin = 0;
    KA.totalsec = 0;

    BB.totalhr = 0;
    BB.totalmin = 0;
    BB.totalsec = 0;

    BC.totalhr = 0;
    BC.totalmin = 0;
    BC.totalsec = 0;

    PP.totalhr = 0;
    PP.totalmin = 0;
    PP.totalsec = 0;

    TC.totalhr = 0;
    TC.totalmin = 0;
    TC.totalsec = 0;

    real = fopen("FacilityUsage.txt", "r");

    if (real == NULL) {
        printf("Error!! Please try again.");
        exit(-1);
    }
    do {
        system("cls");
        printf("\n");
        printf("------------------------------------------------\n");
        printf("\tReport Of The All Facility Usage\n");
        printf("------------------------------------------------\n\n");

        while (!feof(real)) {
            fscanf(real, "%[^|]|%[^|]|%d-%d-%d|%d:%d:%d-%d:%d:%d|%d:%d:%d|%[^|]|%d|\n", &U.memberID, &U.facilityID, &U.day, &U.month, &U.year, &U.start.hours, &U.start.minutes, &U.start.seconds, &U.stop.hours, &U.stop.minutes, &U.stop.seconds, &U.diff.hours, &U.diff.minutes, &U.diff.seconds, &U.Usagetype, &U.contactno);
            if (strcmp("SP1", U.facilityID) == 0 || strcmp("SP2", U.facilityID) == 0) {

                SP.totalhr += U.diff.hours;
                SP.totalmin += U.diff.minutes;
                SP.totalsec += U.diff.seconds;
            }

            if (strcmp("KA1", U.facilityID) == 0 || (strcmp("KA2", U.facilityID) == 0) || (strcmp("KA3", U.facilityID) == 0) || (strcmp("KA4", U.facilityID) == 0) || (strcmp("KA5", U.facilityID) == 0) || (strcmp("KA6", U.facilityID) == 0)) {
                KA.totalhr += U.diff.hours;
                KA.totalmin += U.diff.minutes;
                KA.totalsec += U.diff.seconds;
            }

            if (strcmp("BB1", U.facilityID) == 0 || strcmp("BB2", U.facilityID) == 0 || strcmp("BB3", U.facilityID) == 0 || strcmp("BB4", U.facilityID) == 0 || strcmp("BB5", U.facilityID) == 0 || strcmp("BB6", U.facilityID) == 0) {

                BB.totalhr += U.diff.hours;
                BB.totalmin += U.diff.minutes;
                BB.totalsec += U.diff.seconds;
            }

            if (strcmp("BC1", U.facilityID) == 0 || strcmp("BC2", U.facilityID) == 0 || strcmp("BC3", U.facilityID) == 0 || strcmp("BC4", U.facilityID) == 0 || strcmp("BC5", U.facilityID) == 0 || strcmp("BC6", U.facilityID) == 0) {

                BC.totalhr += U.diff.hours;
                BC.totalmin += U.diff.minutes;
                BC.totalsec += U.diff.seconds;
            }

            if (strcmp("PP1", U.facilityID) == 0 || strcmp("PP2", U.facilityID) == 0 || strcmp("PP3", U.facilityID) == 0 || strcmp("PP4", U.facilityID) == 0 || strcmp("PP5", U.facilityID) == 0 || strcmp("PP6", U.facilityID) == 0) {

                PP.totalhr += U.diff.hours;
                PP.totalmin += U.diff.minutes;
                PP.totalsec += U.diff.seconds;
            }

            if (strcmp("TC1", U.facilityID) == 0 || strcmp("TC2", U.facilityID) == 0 || strcmp("TC3", U.facilityID) == 0 || strcmp("TC4", U.facilityID) == 0) {

                TC.totalhr += U.diff.hours;
                TC.totalmin += U.diff.minutes;
                TC.totalsec += U.diff.seconds;
            }
        }
        printf(" ------------------------------------- \n");
        printf("|     Facility      | Total Time Used |\n");
        printf("|-------------------|-----------------|\n");
        printf("|  Swimming Pools   |    %02d:%02d:%02d     |\n", SP.totalhr, SP.totalmin, SP.totalsec);
        printf("|  Karaoke Rooms    |    %02d:%02d:%02d     |\n", KA.totalhr, KA.totalmin, KA.totalsec);
        printf("|  Basketball Court |    %02d:%02d:%02d     |\n", BB.totalhr, BB.totalmin, BB.totalsec);
        printf("|  Badminton Court  |    %02d:%02d:%02d     |\n", BC.totalhr, BC.totalmin, BC.totalsec);
        printf("|  Ping Pong Rooms  |    %02d:%02d:%02d     |\n", PP.totalhr, PP.totalmin, PP.totalsec);
        printf("|  Tennis Court     |    %02d:%02d:%02d     |\n", TC.totalhr, TC.totalmin, TC.totalsec);
        printf(" ------------------------------------- \n");

        printf("\n------------------------\n");
        printf("Press 1 to continue :");
        scanf("%d", &choice);
        printf("------------------------\n");

        while (choice != 1) {
            printf("\n-------------------------------\n");
            printf("Invalid Choice\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &choice);
            printf("-------------------------------\n\n");
        }
    } while (choice != 1);

    fclose(real);

}

void mainFacilityInfo() {

    int choice;
    char opt;

    printf("\n------------------------\n");
    printf("\tFacility\n");
    printf("------------------------\n\n");
    printf(" ------------------------------- \n");
    printf("|           Facility            |\n");
    printf("|-------------------------------|\n");
    printf("| 1  | Add Facility Record      |\n");
    printf("| 2  | Search Facility Record   |\n");
    printf("| 3  | Count Facility Types     |\n");
    printf("| 4  | Modify Facility Record   |\n");
    printf("| 5  | Display Facility Record  |\n");
    printf("| 6  | Delete Facility Record   |\n");
    printf("| 7  | Exit To Main Page        |\n");
    printf(" ------------------------------- \n");

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
        mainFacilityInfo();
    }

    if (choice == 2) {
        searchFacilityRecord();
        printf("\n");
        system("cls");
        mainFacilityInfo();
    }

    if (choice == 3) {
        countFacilityType();
        printf("\n");
        system("cls");
        mainFacilityInfo();
    }

    if (choice == 4) {
        modifyFacilityRecord();
        printf("\n");
        system("cls");
        mainFacilityInfo();
    }

    if (choice == 5) {
        displayFacilityRecord();
        printf("\n");
        system("cls");
        mainFacilityInfo();
    }

    if (choice == 6) {
        deleteFacilityRecord();
        printf("\n");
        system("cls");
        mainFacilityInfo();
    }

    if (choice == 7) {
        main();
    }
}

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

        fprintf(fpFacility, "%s|%s|%s|%s|%d|0%d\n", FI.facilityID, FI.FT.type, FI.FT.desc, FI.venue, FI.maxUser, FI.phone);

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

void searchFacilityRecord() {
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

        if (record == 0) {
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

    } while (toupper(opt) != 'N');
}

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

        printf("Are You Sure To Modify %s ? (Y/N) :", search);
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

    } while (toupper(opt) != 'N');
}

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

void deleteFacilityRecord() {
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

        printf("Are You Sure To Delete ? (Y/N) :", search);
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

/*
int isLeap(int y)
{
    if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
        return 1;

    return 0;
}

int offsetDays(int d, int m, int y)
{
    int offset = d;

    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }

    if (isLeap(1) && m > 2)
        offset += 1;

    return offset;
}

void revoffsetDays(int offset, int y, int* d, int* m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

void addDays(int d1, int m1, int y1, int x)
{
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1) ? (366 - offset1) : (365 - offset1);

    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }

    else
    {

        x -= remDays;
        y2 = y1 + 1;
        int y2days = isLeap(y2) ? 366 : 365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2) ? 366 : 365;
        }
        offset2 = x;
    }


    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);
}
*/

void mainBooking() {
    int choice;
    char optiom;
    do {
        printf("\n-----------------------\n");
        printf("\t\n");
        printf("-----------------------\n\n");
        printf(" ------------------------- \n");
        printf("|         Booking         |\n");
        printf("|-------------------------|\n");
        printf("| 1  | Add Booking        |\n");
        printf("| 2  | Search Booking     |\n");
        printf("| 3  | Count Booking      |\n");
        printf("| 4  | Modify Booking     |\n");
        printf("| 5  | Display Booking    |\n");
        printf("| 6  | Delete Booking     |\n");
        printf("| 7  | Exit To Main Page  |\n");
        printf(" ------------------------- \n");

        printf("\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        if (choice == 1) {
            system("cls");
            addBooking();
        }
        else if (choice == 2) {
            system("cls");
            searchBooking();
        }
        else if (choice == 3) {
            system("cls");
            countBooking();
        }
        else if (choice == 4) {
            system("cls");
            modifyBooking();
        }
        else if (choice == 5) {
            system("cls");
            displayBooking();
        }
        else if (choice == 6) {
            system("cls");
            deleteBooking();
        }
        else if (choice == 7) {
            main();
        }
        else {
            printf("Invalid choice!\n");

        }
    } while (choice != 7);
}

void addBooking() {

    FILE* fpbooking;

    booking book;
    SYSTEMTIME t;
    GetLocalTime(&t);
    int count = 12, i = 1;
    int selectionRoom, selection;

    do {
        printf("\n");
        printf("-------------------------------\n");
        printf("\tAdd New Booking\n");
        printf("-------------------------------\n\n");

        fpbooking = fopen("booking.bin", "ab");

        if (fpbooking == NULL) {
            printf("file open error!");
            exit(-1);
        }
        rewind(stdin);
        printf(" ------------------------------ \n");
        printf("|            Venue             |\n");
        printf("|------------------------------|\n");
        printf("| 1  | Karaoke Room (KA)       |\n");
        printf("| 2  | Swimming Pool (SP)      |\n");
        printf("| 3  | Basketball Court (BC)   |\n");
        printf("| 4  | Badminton Court (BB)    |\n");
        printf("| 5  | Tennis Court (TC)       |\n");
        printf("| 6  | Ping Pong Room (PP)     |\n");
        printf("| 7  | Back to main Menu       |\n");
        printf(" ------------------------------ \n");

        printf("\n");
        printf("Please enter your selection for booking : ");
        rewind(stdin);
        scanf("%d", &selection);
        printf("\n");

        if (selection == 1) {
            count += 1;
            snprintf(book.bookingID, 20, "KA%d", count);
            printf("Please enter time of booking(dd/mm/yy)  : "); /*02 01 2023*/ /*03 01 2023*/ /*31 5 2022*/
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);*/
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2*/
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n----------------------------\n");
                            printf("Succesfully booked room KA%d\n", i);
                            printf("Time of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("----------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n\n");
                    }
                }
                else if (book.month > t.wMonth) {
                    /*if its 1 month diff*/
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n----------------------------\n");
                            printf("Succesfully booked room KA%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("----------------------------\n\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room KA%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }

                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else {
                printf("\n-------------\n");
                printf("Invalid date!\n");
                printf("-------------\n\n");
            }

            fclose(fpbooking);
        }
        else if (selection == 2) {
            count += 1;
            snprintf(book.bookingID, 20, "SP%d", count);
            printf("Please enter time of booking(dd/mm/yy)  : "); /*02 01 2023*/ /*03 01 2023*/ /*31 5 2022*/
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);*/
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2*/
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room SP%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else if (book.month > t.wMonth) {
                    /*if its 1 month diff*/
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room SP%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room SP%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }

                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else {
                printf("\n-------------\n");
                printf("Invalid date!\n");
                printf("-------------\n\n");
            }

            fclose(fpbooking);
        }
        else if (selection == 3) {
            count += 1;
            snprintf(book.bookingID, 20, "BC%d", count);
            printf("Please enter time of booking(dd/mm/yy)  : "); /*02 01 2023*/ /*03 01 2023*/ /*31 5 2022*/
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);*/
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2*/
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room BC%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("\n---------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else if (book.month > t.wMonth) {
                    /*if its 1 month diff*/
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room BC%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room BC%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }

                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else {
                printf("\n-------------\n");
                printf("Invalid date!\n");
                printf("-------------\n\n");
            }

            fclose(fpbooking);
        }
        else if (selection == 4) {
            count += 1;
            snprintf(book.bookingID, 20, "BB%d", count);
            printf("Please enter time of booking(dd/mm/yy)  : "); /*02 01 2023*/ /*03 01 2023*/ /*31 5 2022*/
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);*/
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2*/
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room BB%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else if (book.month > t.wMonth) {
                    /*if its 1 month diff*/
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room BB%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room BB%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }

                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else {
                printf("\n-------------\n");
                printf("Invalid date!\n");
                printf("-------------\n\n");
            }

            fclose(fpbooking);
        }
        else if (selection == 5) {
            count += 1;
            snprintf(book.bookingID, 20, "TC%d", count);
            printf("Please enter time of booking(dd/mm/yy)  : "); /*02 01 2023*/ /*03 01 2023*/ /*31 5 2022*/
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);*/
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2*/
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room TC%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else if (book.month > t.wMonth) {
                    /*if its 1 month diff*/
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room TC%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room TC%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }

                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else {
                printf("\n-------------\n");
                printf("Invalid date!\n");
                printf("-------------\n\n");
            }

            fclose(fpbooking);
        }
        else if (selection == 6) {
            count += 1;
            snprintf(book.bookingID, 20, "PP%d", count);
            printf("Please enter time of booking(dd/mm/yy)  : "); /*02 01 2023*/ /*03 01 2023*/ /*31 5 2022*/
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);*/
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2*/
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room PP%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else if (book.month > t.wMonth) {
                    /*if its 1 month diff*/
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room PP%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }
                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            printf("\n-----------------------------------------\n");
                            printf("Succesfully booked room PP%d\n", i);
                            printf("Date(Day Month Year) of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n\n", book.bookingID);
                            printf("-----------------------------------------\n");
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("\n-------------\n");
                            printf("Invalid date!\n");
                            printf("-------------\n\n");
                        }
                    }
                    else {
                        printf("\n-------------\n");
                        printf("Invalid date!\n");
                        printf("-------------\n\n");
                    }

                }
                else {
                    printf("\n-------------\n");
                    printf("Invalid date!\n");
                    printf("-------------\n\n");
                }
            }
            else {
                printf("\n-------------\n");
                printf("Invalid date!\n");
                printf("-------------\n\n");
            }

            fclose(fpbooking);
        }
        else if (selection == 7) {
            system("cls");
            break;
        }
        else {
            printf("\n--------------\n");
            printf("Invalid input!\n");
            printf("--------------\n\n");
        }

    } while (selection != 7);
    fclose(fpbooking);

}

void displayBooking() {
    char option;
    int select;
    booking book;

    FILE* fpbooking;
    fpbooking = fopen("booking.bin", "rb");

    if (fpbooking == NULL) {
        printf("Error opening file!");
        exit(-1);
    }

    do {
        system("cls");
        printf("\n");
        printf("-------------------------------\n");
        printf("\tDisplay Booking\n");
        printf("-------------------------------\n\n");

        printf(" ----------------------------- \n");
        printf("|  Booking ID  |     Date     |\n");
        printf("|------------- |--------------|\n");
        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            printf("|     %-7s  |   %d-%d-%d   |\n", book.bookingID, book.day, book.month, book.year);
        }
        printf(" ----------------------------- \n");

        printf("Press 1 to continue :");
        scanf("%d", &select);
        printf("------------------------\n\n");

        while (select != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &select);
            printf("-------------------------------\n\n");
        }

    } while (select != 1);

    fclose(fpbooking);
    system("cls");
}

void searchBooking() {
    system("cls");
    char search[20];
    int select;

    booking book;

    FILE* fpbooking;
    fpbooking = fopen("booking.bin", "rb");

    if (fpbooking == NULL) {
        printf("Error\n");
        exit(-1);
    }
    do {
        printf("\n");
        printf("-------------------------------\n");
        printf("\tSearch Booking\n");
        printf("-------------------------------\n\n");

        printf("Enter Booking ID to search: ");
        rewind(stdin);
        gets(search);

        int out = 0;

        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            if (strcmp(search, book.bookingID) == 0) {
                printf(" ----------------------------- \n");
                printf("|  Booking ID  |     Date     |\n");
                printf("|------------- |--------------|\n");
                printf("|     %-7s  |   %d-%d-%d   |   \n", book.bookingID, book.day, book.month, book.year);
                printf(" ----------------------------- \n");
                out++;
            }
        }

        if (out == 0) {
            printf("----------\n");
            printf("No Booking\n");
            printf("----------\n");
        }

        
        printf("Press 1 To Continue :");
        scanf("%d", &select);
        printf("------------------------\n\n");

        while (select != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &select);
            printf("-------------------------------\n\n");
        }

    } while (select != 1);

    fclose(fpbooking);
    system("cls");
}

void modifyBooking() {

    SYSTEMTIME t;
    GetLocalTime(&t);
    booking book;
    bookingModify bookMD;

    FILE* fpbooking;
    FILE* fpMD;

    char search[21];
    int select;
    char option;

    do {
        system("cls");
        printf("\n--------------------------------\n");
        printf("\tModify BookingID\n");
        printf("--------------------------------\n\n");

        FILE* fpbooking;
        fpbooking = fopen("booking.bin", "rb");

        if (fpbooking == NULL) {
            printf("Error\n");
            exit(-1);
        }

        printf(" ----------------------------- \n");
        printf("|  Booking ID  |     Date     |\n");
        printf("|------------- |--------------|\n");
        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            printf("|     %-7s  |   %d-%d-%d   |\n", book.bookingID, book.day, book.month, book.year);
        }
        printf(" ----------------------------- \n\n");
        fclose(fpbooking);

        printf("Enter bookingID to modify record :");
        rewind(stdin);
        gets(search);

        fpbooking = fopen("booking.bin", "rb");

        if (fpbooking == NULL) {
            printf("Error\n");
            exit(-1);
        }

        int out = 0;
        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            if (strcmp(search, book.bookingID) == 0) {
                printf(" ----------------------------- \n");
                printf("|  Booking ID  |     Date     |\n");
                printf("|------------- |--------------|\n");
                printf("|     %-7s  |   %d-%d-%d   |\n", book.bookingID, book.day, book.month, book.year);
                printf(" ----------------------------- \n\n");
                out++;
            }
        }

        if (out == 0) {
            printf("------------------\n");
            printf("No such booking ID\n");
            printf("------------------\n\n");
        }

        printf("Sure to modify booking date ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &option);

        if (toupper(option) == 'Y') {
            fpbooking = fopen("booking.bin", "rb");

            if (fpbooking == NULL) {
                printf("Error\n");
                exit(-1);
            }

            int out = 0;
            while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
                fpMD = fopen("bookingMD.bin", "ab");

                if (fpMD == NULL) {
                    printf("Error\n");
                    exit(-1);
                }

                if (strcmp(search, book.bookingID) == 0) {
                    printf("\n");
                    printf("Modify Date of booking : ");
                    rewind(stdin);
                    scanf("%d/%d/%d", &bookMD.day, &bookMD.month, &bookMD.year);
                    /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
                    addDays(d, m, y, x);*/
                    int reDay, reMonth;
                    /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2*/
                    if (t.wYear == bookMD.year) {
                        if (t.wMonth == bookMD.month) {
                            if (t.wDay < bookMD.day) {
                                reDay = bookMD.day - t.wDay;
                                if (reDay >= 0 && reDay <= 2) {
                                    strcpy(bookMD.bookingID, book.bookingID);
                                    fwrite(&bookMD, sizeof(bookingModify), 1, fpMD);
                                    printf("\nModify Success\n");
                                    out++;

                                }
                                else {
                                    printf("Invalid date!\n\n");
                                    strcpy(book.bookingID, bookMD.bookingID);
                                    fwrite(&book, sizeof(booking), 1, fpbooking);
                                }
                            }
                            else {
                                printf("Invalid date!\n\n");
                                strcpy(book.bookingID, bookMD.bookingID);
                                fwrite(&book, sizeof(booking), 1, fpbooking);
                            }
                        }
                        else if (bookMD.month > t.wMonth) {
                            /*if its 1 month diff*/
                            reMonth = bookMD.month - t.wMonth;
                            if (reMonth == 1) {
                                reDay = t.wDay - bookMD.day;
                                reDay = t.wDay - reDay;
                                if (reDay >= 0 && reDay <= 2) {
                                    strcpy(bookMD.bookingID, book.bookingID);
                                    fwrite(&bookMD, sizeof(bookingModify), 1, fpMD);
                                    printf("\nModify Success\n");
                                    out++;
                                }
                                else {
                                    printf("Invalid date!\n\n");
                                    strcpy(book.bookingID, bookMD.bookingID);
                                    fwrite(&book, sizeof(booking), 1, fpbooking);
                                }
                            }
                            else {
                                printf("Invalid date!\n\n");
                                strcpy(book.bookingID, bookMD.bookingID);
                                fwrite(&book, sizeof(booking), 1, fpbooking);
                            }
                        }
                        else {
                            printf("Invalid date!\n\n");
                            strcpy(book.bookingID, bookMD.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                        }
                    }
                    else if (t.wYear < bookMD.year) {
                        if (t.wMonth < bookMD.month) {
                            if (t.wDay > bookMD.day) {
                                reDay = t.wDay - bookMD.day;
                                if (reDay >= 0 && reDay <= 2) {
                                    strcpy(bookMD.bookingID, book.bookingID);
                                    fwrite(&bookMD, sizeof(bookingModify), 1, fpMD);
                                    printf("\nModify Success\n");
                                    printf("Booking date has been modified to \n");
                                    printf(" ----------------------------- \n");
                                    printf("|  Booking ID  |     Date     |\n");
                                    printf("|------------- |--------------|\n");
                                    printf("|     %-7s  |   %d-%d-%d   |\n\n", bookMD.bookingID, bookMD.day, bookMD.month, bookMD.year);
                                    printf(" ----------------------------- \n");
                                    out++;
                                }
                                else {
                                    printf("Invalid date!\n\n");
                                    strcpy(book.bookingID, bookMD.bookingID);
                                    fwrite(&book, sizeof(booking), 1, fpbooking);
                                }
                            }
                            else {
                                printf("Invalid date!\n\n");
                                strcpy(book.bookingID, bookMD.bookingID);
                                fwrite(&book, sizeof(booking), 1, fpbooking);
                            }

                        }
                        else {
                            printf("Invalid date!\n\n");
                            strcpy(book.bookingID, bookMD.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                        }
                    }
                    else {
                        printf("Invalid date!\n\n");
                        strcpy(book.bookingID, bookMD.bookingID);
                        fwrite(&book, sizeof(booking), 1, fpbooking);

                    }
                }
                else {
                    fwrite(&book, sizeof(booking), 1, fpMD);
                }
                fclose(fpMD);
            }

            if (out == 0) {
                printf("-------------\n");
                printf("No Booking\n");
                printf("Modify Failed\n");
                printf("-------------\n\n");
            }
            fclose(fpbooking);

            fpbooking = fopen("booking.bin", "wb");
            fclose(fpbooking);

            fpbooking = fopen("booking.bin", "ab");
            fpMD = fopen("bookingMD.bin", "rb");

            while (fread(&book, sizeof(booking), 1, fpMD) != 0) {
                fwrite(&book, sizeof(booking), 1, fpbooking);
            }

            fclose(fpbooking);
            fclose(fpMD);

            fpMD = fopen("bookingMD.bin", "wb");
            fclose(fpMD);

        }

        if (toupper(option) == 'N') {
            printf("-------------\n");
            printf("Modify Failed\n");
            printf("-------------\n");
        }

    
        printf("Press 1 to continue :");
        scanf("%d", &select);
        printf("-----------------------\n\n");

        while (select != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &select);
            printf("-------------------------------\n\n");
        }
    } while (select != 1);

    system("cls");

}

void deleteBooking() {

    booking book;

    FILE* fpbooking;
    FILE* fpMD;

    char search[20];
    char option;
    int select;

    do {
        system("cls");
        printf("\n----------------------------------------\n");
        printf("\tDelete Booking\n");
        printf("----------------------------------------\n\n");

        fpbooking = fopen("booking.bin", "rb");

        if (fpbooking == NULL) {
            printf("Error\n");
            exit(-1);
        }

        printf(" ----------------------------- \n");
        printf("|  Booking ID  |     Date     |\n");
        printf("|------------- |--------------|\n");
        while (fread(&book, sizeof(book), 1, fpbooking) != 0) {
            printf("|     %-7s  |   %d-%d-%d   |\n", book.bookingID, book.day, book.month, book.year);
        }

        printf(" ----------------------------- \n\n");
        fclose(fpbooking);

        printf("Enter booking to delete :");
        rewind(stdin);
        gets(search);

        fpbooking = fopen("booking.bin", "rb");

        if (fpbooking == NULL) {
            printf("Error\n");
            exit(-1);
        }

        int out = 0;
        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            if (strcmp(search, book.bookingID) == 0) {
                printf(" ----------------------------- \n");
                printf("|  Booking ID  |     Date     |\n");
                printf("|------------- |--------------|\n");
                printf("|     %-7s  |   %d-%d-%d   |\n", book.bookingID, book.day, book.month, book.year);
                printf(" ----------------------------- \n");
                out++;
            }
        }

        if (out == 0) {
            printf("------------------\n");
            printf("No such booking id\n");
            printf("------------------\n\n");
        }

        printf("\nAre you sure to delete booking ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &option);

        if (toupper(option) == 'Y') {
            fpbooking = fopen("booking.bin", "rb");

            if (fpbooking == NULL) {
                printf("Error\n");
                exit(-1);
            }

            int out = 0;

            while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
                if (strcmp(search, book.bookingID) == 0) {
                    out++;
                    printf("--------------\n");
                    printf("Delete success\n");
                    printf("--------------\n");
                }
                else {
                    fpMD = fopen("bookingMD.bin", "ab");

                    if (fpMD == NULL) {
                        printf("Error\n");
                        exit(-1);
                    }

                    fwrite(&book, sizeof(booking), 1, fpMD);
                    fclose(fpMD);
                }
            }

            if (out == 0) {
                printf("-------------\n");
                printf("No Booking\n");
                printf("Delete Failed\n");
                printf("-------------\n");
            }

            fclose(fpbooking);

            fpbooking = fopen("booking.bin", "wb");
            fclose(fpbooking);

            fpbooking = fopen("booking.bin", "ab");
            fpMD = fopen("bookingMD.bin", "rb");

            while (fread(&book, sizeof(booking), 1, fpMD) != 0) {
                fwrite(&book, sizeof(booking), 1, fpbooking);
            }

            fclose(fpbooking);
            fclose(fpMD);

            fpMD = fopen("bookingMD.bin", "wb");
            fclose(fpMD);

        }

        if (toupper(option) == 'N') {
            printf("-------------\n");
            printf("Delete Failed\n");
            printf("-------------\n");
        }
        
        printf("Press 1 to continue :");
        scanf("%d", &select);
        printf("------------------------\n\n");

        while (select != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &select);
            printf("-------------------------------\n\n");
        }
    } while (select != 1);

    system("cls");
}

void countBooking() {
    char search[20];
    int select;

    booking book;

    do {
        system("cls");
        printf("\n------------------------------------\n");
        printf("\tCount Booking\n");
        printf("------------------------------------\n\n");

        FILE* fpbooking;
        fpbooking = fopen("booking.bin", "rb");

        if (fpbooking == NULL) {
            printf("Error\n");
            exit(-1);
        }

        int count = 0;
        int out = 0;

        printf(" ----------------------------- \n");
        printf("|  Booking ID  |     Date     |\n");
        printf("|------------- |--------------|\n");
        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            printf("|     %-7s  |   %d-%d-%d   |\n", book.bookingID, book.day, book.month, book.year);
            count++;
            out++;
        }
        printf(" ---------------------------\n");
        printf("There is a total %d booking \n", count);

        if (out == 0) {
            printf("----------\n");
            printf("No Booking\n");
            printf("----------\n");
        }

        fclose(fpbooking);

        printf("Press 1 To Continue :");
        scanf("%d", &select);
        printf("------------------------\n\n");

        while (select != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &select);
            printf("-------------------------------\n\n");
        }

    } while (select != 1);
    system("cls");
}

void mainMemberInfo() {
    int opt;

    do {
        system("cls");
        printf("\n----------------------------------\n");
        printf("\tMember Information\n");
        printf("----------------------------------\n\n");
        //Prompt user to choose 
        printf(" ---------------------------- \n");
        printf("|          Member            |\n");
        printf("|----------------------------|\n");
        printf("| 1  |  Add New Member       |\n");
        printf("| 2  |  Search Member        |\n");
        printf("| 3  |  Modify Member info   |\n");
        printf("| 4  |  Remove Member        |\n");
        printf("| 5  |  Display Member info  |\n");
        printf("| 6  |  Show report          |\n");
        printf("| 7  |  Exit to main page    |\n");
        printf(" ---------------------------- \n");
        printf("\nEnter your choice:");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            add_member();
            break;
        case 2:
            search_member();
            break;
        case 3:
            modify_member();
            break;
        case 4:
            erase_member();
            break;
        case 5:
            display_member();
            break;
        case 6:
            countTotalMember();
            break;
        case 7: //Back to main menu
            main();
            break;
        default:
            printf("Wrong Choice. Please enter again\n\n");
            break;
        }
    } while (opt != 7);

}

void add_member() {
    //To add a single new member info
    system("cls");
    printf("\n");
    printf("------------------------------\n");
    printf("\tAdd New Member\n");
    printf("------------------------------\n\n");
    struct Member new;

    //Open File 
    FILE* fp;
    fp = fopen("newMember.bin", "ab");
    if (fp == NULL) {
        printf("File can't be open");
        exit(-1);
    }

    char option;
    int back;

    do {
        //Prompt user to enter new member info
        printf("Name                             : ");
        rewind(stdin);
        gets(new.name);
        printf("Gender (M/F)                     : ");
        rewind(stdin);
        scanf(" %c", &new.sex);
        printf("Age                              : ");
        scanf("%d", &new.age);
        printf("Address                          : ");
        rewind(stdin);
        gets(new.address);
        printf("Phone number (without '-')       : +60");
        scanf("%d", &new.tel);
        printf("Duration of membership by months : ");
        scanf("%d", &new.duration);

        //Check if user wants to save the record
        printf("\n-----------------------------------------\n");
        printf("Do you want to save this record (Y/N) :");
        rewind(stdin);
        scanf("%c", &option);
        printf("-----------------------------------------\n");

        //Record is save if type 'Y' or 'y'
        //Record is not save if type 'N' or 'n' and user is bring back to the main menu
        if (toupper(option) == 'Y') {
            fwrite(&new, sizeof(new), 1, fp);
            fclose(fp);

            printf("Record is save ! \n");
        }
        else {
            printf("Record did not saved!\n");
        }

        printf("Press 1 To Continue :");
        scanf("%d", &back);
        printf("------------------------\n");

        while (back != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &back);
            printf("-------------------------------\n\n");
        }
    } while (back != 1);

}

void search_member() {
    char search[20];
    int back;

    struct Member new;

    do {
        system("cls");
        printf("\n-----------------------------------------\n");
        printf("\tSearch Member Information\n");
        printf("-----------------------------------------\n\n");

        FILE* fpMember;
        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        printf("Enter name to search : ");
        rewind(stdin);
        gets(search);

        int none = 0;

        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            if (strcmp(search, new.name) == 0) {
                printf(" ------------------------------------------------------------------------------- \n");
                printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
                printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
                printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", new.name, new.sex, new.age, new.address, new.tel, new.duration);
                printf(" ------------------------------------------------------------------------------- \n");
                none++;
            }
        }

        if (none == 0) {
            printf("--------------\n");
            printf("No such member\n");
            printf("--------------\n");
        }

        fclose(fpMember);

       
        printf("Press 1 To Continue :");
        scanf("%d", &back);
        printf("------------------------\n");

        while (back != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &back);
            printf("-------------------------------\n\n");
        }
    } while (back != 1);

}

void modify_member() {
    /*data can be found, but cant be change*/
    struct Member new;
    struct Member newModify;

    FILE* fpMember;
    FILE* fpMemberMD;

    char search[21];
    char select;
    int back;

    do {
        system("cls");
        printf("\n-----------------------------------------\n");
        printf("\tModify Member Information\n");
        printf("-----------------------------------------\n\n");

        FILE* fpMember;
        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        printf(" ------------------------------------------------------------------------------- \n");
        printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
        printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", new.name, new.sex, new.age, new.address, new.tel, new.duration);
        }
        printf(" ------------------------------------------------------------------------------- \n\n");
        fclose(fpMember);

        printf("Enter member name to modify information :");
        rewind(stdin);
        gets(search);

        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        int none = 0;
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            if (strcmp(search, new.name) == 0) {
                printf(" ------------------------------------------------------------------------------- \n");
                printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
                printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
                printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", new.name, new.sex, new.age, new.address, new.tel, new.duration);
                printf(" ------------------------------------------------------------------------------- \n\n");
                none++;
            }
        }

        if (none == 0) {
            printf("--------------\n");
            printf("No such member\n");
            printf("--------------\n");
        }

        printf("Sure to modify ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &select);

        if (toupper(select) == 'Y') {
            fpMember = fopen("newMember.bin", "rb");

            if (fpMember == NULL) {
                printf("Error\n");
                exit(-1);
            }

            int none = 0;
            while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
                fpMemberMD = fopen("memberTemp.bin", "ab");

                if (fpMemberMD == NULL) {
                    printf("Error\n");
                    exit(-1);
                }

                if (strcmp(search, new.name) == 0) {
                    printf("\n");
                    printf("Modify name                : ");
                    rewind(stdin);
                    gets(newModify.name);

                    printf("Modify sex                 : ");
                    rewind(stdin);
                    scanf("%c", &newModify.sex);

                    printf("Modify age                 : ");
                    rewind(stdin);
                    scanf("%d", &newModify.age);

                    printf("Modify address             : ");
                    rewind(stdin);
                    gets(newModify.address);

                    printf("Modify tel                 : +60");
                    rewind(stdin);
                    scanf("%d", &newModify.tel);

                    printf("Modify member duration     : ");
                    rewind(stdin);
                    scanf("%d", &newModify.duration);

                    fwrite(&newModify, sizeof(struct Member), 1, fpMemberMD);

                    printf("\nSuccess\n");
                    printf("Member Information has been modified to \n");
                    printf(" ------------------------------------------------------------------------------- \n");
                    printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
                    printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
                    printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", newModify.name, newModify.sex, newModify.age, newModify.address, newModify.tel, newModify.duration);
                    printf(" ------------------------------------------------------------------------------- \n\n");
                    none++;

                }
                else {
                    fwrite(&new, sizeof(struct Member), 1, fpMemberMD);
                }
                fclose(fpMemberMD);
            }

            if (none == 0) {
                printf("--------------\n");
                printf("No such member\n");
                printf("Fail\n");
                printf("--------------\n");

            }
            fclose(fpMember);

            fpMember = fopen("newMember.bin", "wb");
            fclose(fpMember);

            fpMember = fopen("newMember.bin", "ab");
            fpMemberMD = fopen("memberTemp.bin", "rb");

            while (fread(&new, sizeof(struct Member), 1, fpMemberMD) != 0) {
                fwrite(&new, sizeof(struct Member), 1, fpMember);
            }

            fclose(fpMember);
            fclose(fpMemberMD);

            fpMemberMD = fopen("memberTemp.bin", "wb");
            fclose(fpMemberMD);

        }

        if (toupper(select) == 'N') {
            printf("------\n");
            printf("Cancel\n");
            printf("------\n");
        }

        
        printf("Press 1 To Continue :");
        scanf("%d", &back);
        printf("------------------------\n");

        while (back != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &back);
            printf("-------------------------------\n\n");
        }
    } while (back != 1);

}

void erase_member() {
    /*Can work , but did not delete the file*/
    struct Member new;

    FILE* fpMember;
    FILE* fpMemberMD;

    char search[20];
    int back;
    char select;

    do {
        system("cls");
        printf("\n-----------------------------------------\n");
        printf("\tDelete Member Information\n");
        printf("-----------------------------------------\n\n");

        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        printf(" ------------------------------------------------------------------------------- \n");
        printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
        printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", new.name, new.sex, new.age, new.address, new.tel, new.duration);
        }
        printf(" ------------------------------------------------------------------------------- \n");
        fclose(fpMember);

        printf("Enter member name to delete :");
        rewind(stdin);
        gets(search);

        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        int none = 0;
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            if (strcmp(search, new.name) == 0) {
                printf(" ------------------------------------------------------------------------------- \n");
                printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
                printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
                printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", new.name, new.sex, new.age, new.address, new.tel, new.duration);
                printf(" ------------------------------------------------------------------------------- \n\n");
                none++;
            }
        }

        if (none == 0) {
            printf("--------------\n");
            printf("No such member\n");
            printf("--------------\n\n");
        }

        printf("Sure to delete this member ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &select);

        if (toupper(select) == 'Y') {
            fpMember = fopen("newMember.bin", "rb");

            if (fpMember == NULL) {
                printf("Error\n");
                exit(-1);
            }

            int none = 0;

            while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
                if (strcmp(search, new.name) == 0) {
                    printf("-------\n");
                    printf("Success\n");
                    printf("-------\n");
                    none++;
                }
                else {
                    fpMemberMD = fopen("memberTemp.bin", "ab");

                    if (fpMemberMD == NULL) {
                        printf("Error\n");
                        exit(-1);
                    }

                    fwrite(&new, sizeof(struct Member), 1, fpMemberMD);
                    fclose(fpMemberMD);
                }
            }

            if (none == 0) {
                printf("--------------\n");
                printf("No such member\n");
                printf("Fail\n");
                printf("--------------\n");
            }

            fclose(fpMember);

            fpMember = fopen("newMember.bin", "wb");
            fclose(fpMember);

            fpMember = fopen("newMember.bin", "ab");
            fpMemberMD = fopen("memberTemp.bin", "rb");

            while (fread(&new, sizeof(struct Member), 1, fpMemberMD) != 0) {
                fwrite(&new, sizeof(struct Member), 1, fpMember);
            }

            fclose(fpMember);
            fclose(fpMemberMD);

            fpMemberMD = fopen("memberTemp.bin", "wb");
            fclose(fpMemberMD);

        }

        if (toupper(select) == 'N') {
            printf("------\n");
            printf("Cancel\n");
            printf("------\n");
        }

       
        printf("Press 1 To Continue :");
        scanf("%d", &back);
        printf("------------------------\n");

        while (back != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &back);
            printf("-------------------------------\n\n");
        }
    } while (back != 1);
}

void display_member() {
    char option;
    int back;
    struct Member new;

    FILE* fp;
    fp = fopen("newMember.bin", "rb");

    if (fp == NULL) {
        printf("File does not exist !");
        exit(-1);
    }
    do {
        system("cls");
        printf("\n------------------------------------------\n");
        printf("\tDisplay Member Information\n");
        printf("------------------------------------------\n\n");

        printf(" ------------------------------------------------------------------------------- \n");
        printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
        printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
        while (fread(&new, sizeof(struct Member), 1, fp) != 0) {
            printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", new.name, new.sex, new.age, new.address, new.tel, new.duration);
        }
        printf(" ------------------------------------------------------------------------------- \n");

   
        printf("Press 1 To Continue :");
        scanf("%d", &back);
        printf("------------------------\n");

        while (back != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &back);
            printf("-------------------------------\n\n");
        }
    } while (back != 1);
    fclose(fp);
}

void countTotalMember() {
    /*can't work */
    FILE* fpMember = fopen("newMember.bin", "rb");
    struct Member new;
    int count = 0;
    int back;
    if (!fpMember) {
        exit(-1);
    }

    do {
        system("cls");
        printf("\n-----------------------------------------\n");
        printf("\t\n");
        printf("-----------------------------------------\n\n");

        printf(" ------------------------------------------------------------------------------- \n");
        printf("|   Member Name   | Gender | Age |   Member Address   |   Phone No   | Duration |\n");
        printf("|-----------------|--------|-----|--------------------|--------------|----------|\n");
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            printf("|    %-10s   |   %-3c  | %-2d  |    %-14s  |  0%-7d  |    %-6d|\n", new.name, new.sex, new.age, new.address, new.tel, new.duration);
            count++;
        }
        printf(" ------------------------------------------------------------------------------- \n");

        printf("Total %d member\n", count);

      
        printf("Press 1 To Continue :");
        scanf("%d", &back);
        printf("------------------------\n");

        while (back != 1) {
            printf("-------------------------------\n");
            printf("Invalid Choice !\n");
            printf("Please Press 1 To Continue :");
            scanf("%d", &back);
            printf("-------------------------------\n\n");
        }
    } while (back != 1);

}