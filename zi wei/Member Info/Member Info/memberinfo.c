#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#pragma warning (disable:4996)

//Structure consists of information of member
struct Member {
    char name[51], sex;
    int age;
    char address[101];
    int tel, duration;
};

//Declare function
void add_member();
void search_member();
void modify_member();
void erase_member();
void display_member();
void report_member();

void main() {

    int opt;

    do {
        //Prompt user to choose 
        printf(" --------------------------------------- \n");
        printf("|               Member                  |\n");
        printf("|---------------------------------------|\n");
        printf("| 1  | Add New Member                   |\n");
        printf("| 2  | Search Member                    |\n");
        printf("| 3  | Modify Member info               |\n");
        printf("| 4  | Remove Member                    |\n");
        printf("| 5  | Display Member info              |\n");
        printf("| 6  | Show report                      |\n");
        printf("| 7  | Exit Member Module               |\n");
        printf(" --------------------------------------- \n");
        printf("Enter your choice:");
        scanf("%d", &opt);

        //Lead user to choosen option
        switch (opt) {
        case 1: add_member();       //Add a new member information
            break;
        case 2: search_member();    //Search for a specific member information
            break;
        case 3: modify_member();    //Modify a member's information
            break;
        case 4: erase_member();     //Delete a member's information
            break;
        case 5: display_member();   //Display all member's information
            break;
        case 6: report_member();    //Report the total number of member
            break;
        case 7: exit(-1);           //Back to main menu 
            break;
        default: printf("Wrong Choice. Please enter again\n\n");
            break;
        }
    } while (opt > 7);

}

void add_member() {
    system("cls");

    printf("\n----------------------------------------\n");
    printf("\tAdd Member Information\n");
    printf("----------------------------------------\n\n");

    struct Member new;

    //Open File 
    FILE* fp;
    fp = fopen("newMember.bin", "ab");
    if (fp == NULL) {
        printf("File can't be open");
        exit(-1);
    }

    char option;

    //Prompt user to enter new member info
    printf("Name :");
    rewind(stdin);
    gets(new.name);
    printf("Gender (M/F) :");
    rewind(stdin);
    scanf(" %c", &new.sex);
    printf("Age :");
    scanf("%d", &new.age);
    printf("Address :");
    rewind(stdin);
    gets(new.address);
    printf("Phone number (without '-') : +60");
    scanf("%d", &new.tel);
    printf("Duration of membership by months :");
    scanf("%d", &new.duration);

    //Check if user wants to save the record
    printf("Do you want to save this record (Y/N):");
    rewind(stdin);
    scanf("%c", &option);

    system("cls");

    //Record is save if type 'Y' or 'y' and user is bring back to the menu 
    //Record is not save if type 'N' or 'n' and user is bring back to the menu
    if (toupper(option) == 'Y') {
        fwrite(&new, sizeof(new), 1, fp);
        fclose(fp);

        printf("Record is save ! \n");
    }
    else {
        printf("Record did not saved!\n");
    }

    printf("\n");
    main();

}

void search_member() {
    char search[20];
    char option;

    struct Member new;

    do {
        system("cls");
        printf("\n----------------------------------------\n");
        printf("\tSearch Member Information\n");
        printf("----------------------------------------\n\n");

        //Open File 
        FILE* fpMember;
        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        //Prompt user to key in name to be search 
        printf("Enter name to search : ");
        rewind(stdin);
        gets(search);

        int check = 0;

        //Read File and compare to see if info existed 
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            if (strcmp(search, new.name) == 0) {
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("|    Name    | Gender |  Age |       \t\t\tAddress\t\t\t\t\t\t\t\t|  Contact Number   | Duration    |\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("|  %-9s |   %c    |  %d  |    %-78s        |    0%-10d    |  %-3d month  |\n", new.name, toupper(new.sex), new.age, new.address, new.tel, new.duration);
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                check++;
            }
        }

        if (check == 0) {
            printf("----------------\n");
            printf("Record Not Found\n");
            printf("----------------\n");
        }

        //Close File 
        fclose(fpMember);

        printf("\n----------------------------------------------------\n");
        printf("Continue to search name ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &option);
        printf("----------------------------------------------------\n\n");

    } while (toupper(option) == 'Y');

    system("cls");
    main();

}

void modify_member() {
    struct Member new;
    struct Member newModify;

    FILE* fpMember;
    FILE* fpMemberMD;

    char search[21];
    char select;
    char option;

    do {
        system("cls");
        printf("\n----------------------------------------\n");
        printf("\tModify Member Information\n");
        printf("----------------------------------------\n\n");

        //Open File 
        FILE* fpMember;
        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        //Read the file for all info and close the file to prepare for modification if any 
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            printf("|  %-9s |   %c    |  %d  |    %-78s        |    0%-10d    |  %-3d month  |\n", new.name, toupper(new.sex), new.age, new.address, new.tel, new.duration);
        }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fclose(fpMember);

        //Prompt user to enter name to change it's record
        printf("Enter member id to modify record :");
        rewind(stdin);
        gets(search);

        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        //Compare and allows changes if there is a match 
        int check = 0;
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            if (strcmp(search, new.name) == 0) {
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("|  %-9s |   %c    |  %d  |    %-78s        |    0%-10d    |  %-3d month  |\n", new.name, toupper(new.sex), new.age, new.address, new.tel, new.duration);
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
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
            fpMember = fopen("newMember.bin", "rb");

            if (fpMember == NULL) {
                printf("Error\n");
                exit(-1);
            }

            int check = 0;
            while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
                fpMemberMD = fopen("memberTemp.bin", "ab");

                if (fpMemberMD == NULL) {
                    printf("Error\n");
                    exit(-1);
                }

                //Re-enter new information of a member
                if (strcmp(search, new.name) == 0) {
                    printf("\n");
                    printf("Modify name             : ");
                    rewind(stdin);
                    gets(newModify.name);

                    printf("Modify sex              : ");
                    rewind(stdin);
                    scanf("%c", &newModify.sex);

                    printf("Modify age              : ");
                    rewind(stdin);
                    scanf("%d", &newModify.age);

                    printf("Modify address          : ");
                    rewind(stdin);
                    gets(newModify.address);

                    printf("Modify tel              :+60");
                    rewind(stdin);
                    scanf("%d", &newModify.tel);

                    printf("Modify member duration  : ");
                    rewind(stdin);
                    scanf("%d", &newModify.duration);

                    fwrite(&newModify, sizeof(struct Member), 1, fpMemberMD);

                    printf("\nModify Successfully\n");
                    printf(" '%s' record has been modified to \n", search);
                    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("|  %-9s |   %c    |  %d  |    %-78s        |    0%-10d    |  %-3d month  |\n", new.name, toupper(new.sex), new.age, new.address, new.tel, new.duration);
                    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    check++;

                }

                else {
                    fwrite(&new, sizeof(struct Member), 1, fpMemberMD);
                }
                fclose(fpMemberMD);
            }
            // If no record is found, error message will be shown 
            if (check == 0) {
                printf("---------------------\n");
                printf("No record\n");
                printf("Modify Unsuccessfully\n");
                printf("---------------------\n\n");
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
        // If choose to not modify, a message will be shown 
        if (toupper(select) == 'N') {
            printf("-------------\n");
            printf("Modify Cancel\n");
            printf("-------------\n\n");
        }

        //Asking user to modify a another member record again 
        printf("----------------------------------------------------\n");
        printf("Continue to modify another member record ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &option);
        printf("----------------------------------------------------\n\n");

    } while (toupper(option) == 'Y');

    system("cls");
    main();

}

void erase_member() {
    struct Member new;

    FILE* fpMember;
    FILE* fpMemberMD;

    char search[20];
    char option;
    char select;

    do {
        system("cls");
        printf("\n----------------------------------------\n");
        printf("\tDelete Member Information\n");
        printf("----------------------------------------\n\n");

        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            printf("|  %-9s |   %c    |  %d  |    %-78s        |    0%-10d    |  %-3d month  |\n", new.name, toupper(new.sex), new.age, new.address, new.tel, new.duration);
        }

        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fclose(fpMember);

        //Prompt user to enter name to be deleted 
        printf("Enter Name to delete :");
        rewind(stdin);
        gets(search);

        fpMember = fopen("newMember.bin", "rb");

        if (fpMember == NULL) {
            printf("Error\n");
            exit(-1);
        }

        //Reads the file and compare to see whether the name type exists or not 
        int check = 0;
        while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
            if (strcmp(search, new.name) == 0) {
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("|  %-9s |   %c    |  %d  |    %-78s        |    0%-10d    |  %-3d month  |\n", new.name, toupper(new.sex), new.age, new.address, new.tel, new.duration);
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                check++;
            }
        }

        if (check == 0) {
            printf("------------------\n");
            printf("Record not found\n");
            printf("------------------\n\n");
        }

        //To confirm user on deleting a member's record 
        printf("Are you sure to delete %s record ? (Y/N) :", search);
        rewind(stdin);
        scanf("%c", &select);

        //If 'Y' is key in, record is deleted
        if (toupper(select) == 'Y') {
            fpMember = fopen("newMember.bin", "rb");

            if (fpMember == NULL) {
                printf("Error\n");
                exit(-1);
            }

            int check = 0;

            while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
                if (strcmp(search, new.name) == 0) {
                    check++;
                    printf("-------------------\n");
                    printf("Delete successfully\n");
                    printf("-------------------\n");
                }

                //If 'N', record won't be deleted 
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

            //If no record is found, this is shown 
            if (check == 0) {
                printf("----------------------\n");
                printf("There is no record\n");
                printf("Delete Unsuccesfully\n");
                printf("----------------------\n");
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

        //If 'N' was choosen to not delete the file, this message will be shown 
        if (toupper(select) == 'N') {
            printf("-------------\n");
            printf("Delete cancel\n");
            printf("-------------\n");
        }


        //Asking user to continue or back to main menu 
        printf("\n----------------------------------------------------\n");
        printf("Continue to delete name record ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &option);
        printf("----------------------------------------------------\n\n");
    } while (toupper(option) == 'Y');

    system("cls");
    main();

}

void display_member() {
    system("cls");

    printf("\n----------------------------------------\n");
    printf("\tDisplay Member Information\n");
    printf("----------------------------------------\n\n");

    char option;
    struct Member new;

    //Open Files 
    FILE* fp;
    fp = fopen("newMember.bin", "rb");

    if (fp == NULL) {
        printf("File does not exist !");
        exit(-1);
    }

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|    Name    | Gender |  Age |       \t\t\tAddress\t\t\t\t\t\t\t\t|  Contact Number   | Duration    |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    //Reads the files and displays all the records in it 
    while (fread(&new, sizeof(struct Member), 1, fp) != 0) {
        printf("|  %-9s |   %c    |  %d  |    %-78s        |    0%-10d    |  %-3d month  |\n", new.name, toupper(new.sex), new.age, new.address, new.tel, new.duration);

    }

    //Asking user to either return to menu, or choose to stay on this page
    fclose(fp);
    do {
        printf("Back to main menu(Y/N) ? ");
        rewind(stdin);
        scanf("%c", &option);

        if (toupper(option) == 'Y') {
            system("cls");
        }
        if (toupper(option) == 'N') {
            display_member();
        }
        else {
            printf("Error! Please choose again \n");
        }
    } while (toupper(option) != 'Y' && toupper(option) != 'N');

    system("cls");
    main();

}

void report_member() {
    system("cls");
    char option;

    printf("\n----------------------------------------\n");
    printf("\tReport \n");
    printf("----------------------------------------\n\n");

    FILE* fpMember = fopen("newMember.bin", "rb");
    struct Member new;
    int count = 0;
    if (fpMember == NULL) {
        exit(-1);
    }

    //Count the total number of records in the file 
    while (fread(&new, sizeof(struct Member), 1, fpMember) != 0) {
        //If a record is read, the count will plus 1 
        count++;

    }

    //Shows the total number of members 
    printf("Total number of members = %d\n", count);

    //Asking user to go back to the menu or stay 
    printf("Back to main menu (Y/N) ?");
    scanf("%c", &option);

    if (toupper(option) == 'Y') {
        system("cls");
        main();
    }
    else {
        report_member();
    }


}
