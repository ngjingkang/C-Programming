//
/*


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <Windows.h>
#pragma warning(disable: 4996)

struct bookingID{
    char bookingID[30];
};

typedef struct {
    struct bookingID bookingid;
    char todayDate[30], bookingDate[30], facilityID[30], bookingID[30];
    int bookingTimeMin, bookingTimeHour, day, month, year;
}booking;

void addBooking();
void displayBooking();
void searchBooking();
void modifyBooking();
void deleteBooking();
void countBooking(); 

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

    // y2 is going to store result year and
    // offset2 is going to store offset days
    // in result year.
    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }

    else
    {
        // x may store thousands of days.
        // We find correct year and offset
        // in the year.
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

    // Find values of day and month from
    // offset of result year.
    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);
}


void main() {
    int choice;
    char optiom;
    do {
        printf(" ------------------------ \n");
        printf("|         Booking        |\n");
        printf("|------------------------|\n");
        printf("| 1  | Add Booking       |\n");
        printf("| 2  | Search Booking    |\n");
        printf("| 3  | Count Booking     |\n");
        printf("| 4  | Modify Booking    |\n");
        printf("| 5  | Display Booking   |\n");
        printf("| 6  | Delete Booking    |\n");
        printf("| 7  | Exit              |\n");
        printf(" ------------------------ \n");

        printf("\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        if (choice == 1) {
            addBooking();
        }
        else if (choice == 2) {
            searchBooking();
        }
        else if (choice == 3) {
            countBooking();
        }
        else if (choice == 4) {
            modifyBooking();
        }
        else if (choice == 5) {
            displayBooking();
        }
        else if (choice == 6) {
            deleteBooking();
        }
        else if (choice == 7) {
            abort();
        }
        else {
            printf("Invalid choice!\n");
        }
    } while (choice != 7);
}


void addBooking() {
    system("cls");
 
    FILE* fpbooking;

    booking book;
    SYSTEMTIME t;
    GetLocalTime(&t);
    int count = 12, i = 1;
    int selectionRoom, selection;

    do {


        fpbooking = fopen("booking.bin", "ab");

        if (fpbooking == NULL) {
            printf("file open error!");
            exit(-1);
        }

        printf("Please select the venue of booking\n");
        printf("1. Karaoke Room(KA)\n");
        printf("2. Swimming Pool(SP)\n");
        printf("3. Basketball Court(BC)\n");
        printf("4. Badminton Court(BB)\n");
        printf("5. Tennis Court(TC)\n");
        printf("6. Ping Pong Room(PP)\n");
        printf("7. Back to main Menu\n");
        printf("Please enter your selection: ");
        rewind(stdin);
        scanf("%d", &selection);
        if (selection == 1) {
            count += 1;
            snprintf(book.bookingID, 20, "KA%d", count);
            printf("Please enter time of booking(dd/mm/yy)"); 
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            int reDay, reMonth;

            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room KA%d\n", i);
                            printf("Time of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else if (book.month > t.wMonth) { 
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room KA%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else {
                    printf("Invalid date!/n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room KA%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }

                }
                else {
                    printf("Invalid date!\n");
                }
            }
            else {
                printf("Invalid date!\n");
            
            }
        
 
           



            fclose(fpbooking);
        }
        else if (selection == 2) {
            count += 1;
            snprintf(book.bookingID, 20, "SP%d", count);
            printf("Please enter time of booking(dd/mm/yy)"); /*02 01 2023 /*03 01 2023 /*31 5 2022
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room SP%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else if (book.month > t.wMonth) { /*if its 1 month diff
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room SP%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else {
                    printf("Invalid date!/n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room SP%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }

                }
                else {
                    printf("Invalid date!\n");
                }
            }
            else {
                printf("Invalid date!\n");

            }






            fclose(fpbooking);
        }
        if (selection == 3) {
            count += 1;
            snprintf(book.bookingID, 20, "BC%d", count);
            printf("Please enter time of booking(dd/mm/yy)"); /*02 01 2023 /*03 01 2023 /*31 5 2022
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room BC%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else if (book.month > t.wMonth) { /*if its 1 month diff
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room BC%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else {
                    printf("Invalid date!/n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room BC%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }

                }
                else {
                    printf("Invalid date!\n");
                }
            }
            else {
                printf("Invalid date!\n");

            }






            fclose(fpbooking);
        }
        if (selection == 4) {
            count += 1;
            snprintf(book.bookingID, 20, "BB%d", count);
            printf("Please enter time of booking(dd/mm/yy)"); /*02 01 2023 /*03 01 2023 /*31 5 2022
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room BB%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else if (book.month > t.wMonth) { /*if its 1 month diff
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room BB%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else {
                    printf("Invalid date!/n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room BB%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }

                }
                else {
                    printf("Invalid date!\n");
                }
            }
            else {
                printf("Invalid date!\n");

            }






            fclose(fpbooking);
        }
        if (selection == 5) {
            count += 1;
            snprintf(book.bookingID, 20, "TC%d", count);
            printf("Please enter time of booking(dd/mm/yy)"); /*02 01 2023 /*03 01 2023 /*31 5 2022
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room TC%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else if (t.wDay == book.day) {
                        system("cls");
                        printf("Succesfully booked room TC%d\n", i);
                        printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                        printf("Your booking id is %s\n", book.bookingID);
                        fwrite(&book, sizeof(booking), 1, fpbooking);
                        fclose(fpbooking);
                        i++;
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else if (book.month > t.wMonth) { /*if its 1 month diff
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room TC%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else {
                    printf("Invalid date!/n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room TC%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }

                }
                else {
                    printf("Invalid date!\n");
                }
            }
            else {
                printf("Invalid date!\n");

            }






            fclose(fpbooking);
        }
        if (selection == 6) {
            count += 1;
            snprintf(book.bookingID, 20, "PP%d", count);
            printf("Please enter time of booking(dd/mm/yy)"); /*02 01 2023 /*03 01 2023 /*31 5 2022
            scanf("%d/%d/%d", &book.day, &book.month, &book.year);
            /*int d = t.wDay, m = t.wMonth, y = t.wYear, x = 2;
            addDays(d, m, y, x);
            int reDay, reMonth;
            /*input today is 31 input is 2, 31 - 2  = 29 31 - 29 = 2
            if (t.wYear == book.year) {
                if (t.wMonth == book.month) {
                    if (t.wDay < book.day) {
                        reDay = book.day - t.wDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room PP%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else if (book.month > t.wMonth) { /*if its 1 month diff
                    reMonth = book.month - t.wMonth;
                    if (reMonth == 1) {
                        reDay = t.wDay - book.day;
                        reDay = t.wDay - reDay;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room PP%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }
                }
                else {
                    printf("Invalid date!/n");
                }
            }
            else if (t.wYear < book.year) {
                if (t.wMonth < book.month) {
                    if (t.wDay > book.day) {
                        reDay = t.wDay - book.day;
                        if (reDay >= 0 && reDay <= 2) {
                            system("cls");
                            printf("Succesfully booked room PP%d\n", i);
                            printf("Date of booking: %d %d %d\n", book.day, book.month, book.year);
                            printf("Your booking id is %s\n", book.bookingID);
                            fwrite(&book, sizeof(booking), 1, fpbooking);
                            fclose(fpbooking);
                            i++;
                        }
                        else {
                            printf("Invalid date!\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n");
                    }

                }
                else {
                    printf("Invalid date!\n");
                }
            }
            else {
                printf("Invalid date!\n");

            }






            fclose(fpbooking);
        }
        if (selection == 7) {
            break;
        }
        

    } while (selection != 7);
    fclose(fpbooking);
}

void displayBooking() {

    char option;
    booking book;

    FILE* fpbooking;
    fpbooking = fopen("booking.bin", "rb");

    if (fpbooking == NULL) {
        printf("Error opening file!");
        exit(-1);
    }


    while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
        printf("%s %d %d %d\n", book.bookingID, book.day, book.month, book.year);
    }
}

void searchBooking() {

    char search[20];

    booking book;

    FILE* fpbooking;
    fpbooking = fopen("booking.bin", "rb");

    if (fpbooking == NULL) {
        printf("Error\n");
        exit(-1);
    }

    printf("Enter Booking ID to search: ");
    rewind(stdin);
    gets(search);




    while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
        if (strcmp(search, book.bookingID) == 0) {
            printf("%s %d %d %d\n", book.bookingID, book.day, book.month, book.year);
        }
    }
    fclose(fpbooking);
}

void modifyBooking() {

    char search[100], search2[100];
    booking book[50];

    int count = 0, selection;

    FILE* fpbooking;

    fpbooking = fopen("booking.bin", "rb");

    if (fpbooking == NULL) {
        printf("Error\n");
        exit(-1);
    }

    while (fread(&book[count], sizeof(booking), 1, fpbooking) != 0) {
        count++;
    }


    rewind(stdin);

    printf("Please enter Booking id");
    gets(search);
    count = 0;

    while (count < 50) {
        if (strcmp(search, book[count].bookingID) == 0) {
            printf("%s", book[count].bookingID);

            printf("Select what do you want to change\n");
            printf("1. Booking id");
            scanf("%d", &selection);
            if (selection == 1) {
                printf("What do you want to change to: ");
                rewind(stdin);
                gets(search2);
                strcpy(book[count].bookingID, search2);
                fclose(fpbooking);
            }
        }
        count++;
    }
    fpbooking = fopen("booking.bin", "wb");

    fwrite(&book, sizeof(booking), 1, fpbooking);

    fclose(fpbooking);


}

void deleteBooking() {

    booking book;

    FILE* fpbooking;
    FILE* fp_tmp;

    char searchName[20];
    char option;

    do {
        system("cls");
        printf("\n-----------------------------------\n");
        printf("\tDelete Booking\n");
        printf("-----------------------------------\n\n");

        fpbooking = fopen("booking.bin", "rb");

        if (fpbooking == NULL) {
            printf("Error\n");
            exit(-1);
        }

        printf(" ----------------------------------------------------------------------------------------------------------- \n");
        printf("|   Booking ID |    date    |\n");
        printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");

        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            printf("|  %s  %d %d %d|", book.bookingID, book.day, book.month, book.year);
        }

        printf(" ----------------------------------------------------------------------------------------------------------- \n\n");
        fclose(fpbooking);

        printf("Enter booking id to delete :");
        rewind(stdin);
        gets(searchName);

        fpbooking = fopen("booking.bin", "rb");

        if (fpbooking == NULL) {
            printf("Error\n");
            exit(-1);
        }

        int check = 0;
        while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
            if (strcmp(searchName, book.bookingID) == 0) {
                printf(" ----------------------------------------------------------------------------------------------------------- \n");
                printf("|   Booking ID |    date    |\n");
                printf("|--------------|--------------|----------------|----------------------|------------------|------------------|\n");
                printf("|  %s  %d %d %d|", book.bookingID, book.day, book.month, book.year);
                printf(" ----------------------------------------------------------------------------------------------------------- \n\n");
                check++;
            }
        }

        if (check == 0) {
            printf("------------------\n");
            printf("Record not found\n");
            printf("------------------\n\n");
        }

        printf("Are you sure to delete %s record ? (Y/N) :", searchName);
        rewind(stdin);
        scanf("%c", &option);

        if (toupper(option) == 'Y') {
            fpbooking = fopen("booking.bin", "rb");

            if (fpbooking == NULL) {
                printf("Error\n");
                exit(-1);
            }

            int check = 0;

            while (fread(&book, sizeof(booking), 1, fpbooking) != 0) {
                if (strcmp(searchName, book.bookingID) == 0) {
                    check++;
                    printf("-------------------\n");
                    printf("Delete successfully\n");
                    printf("-------------------\n");
                }

                else {
                    fp_tmp = fopen("change.bin", "ab");

                    if (fp_tmp == NULL) {
                        printf("Error\n");
                        exit(-1);
                    }

                    fwrite(&book, sizeof(booking), 1, fp_tmp);
                    fclose(fp_tmp);
                }
            }

            if (check == 0) {
                printf("----------------------\n");
                printf("There is no record\n");
                printf("Delete Unsuccesfully\n");
                printf("----------------------\n");
            }

            fclose(fpbooking);

            fpbooking = fopen("booking.bin", "wb");
            fclose(fpbooking);

            fpbooking = fopen("booking.bin", "ab");
            fp_tmp = fopen("booking_tmp.bin", "rb");

            while (fread(&book, sizeof(booking), 1, fp_tmp) != 0) {
                fwrite(&book, sizeof(booking), 1, fpbooking);
            }

            fclose(fpbooking);
            fclose(fp_tmp);

            fp_tmp = fopen("booking_tmp.bin", "wb");
            fclose(fp_tmp);

        }

        if (toupper(option) == 'N') {
            printf("-------------\n");
            printf("Delete cancel\n");
            printf("-------------\n");
        }

        printf("\n----------------------------------------------------\n");
        printf("Continue to delete another booking record ? (Y/N) :");
        rewind(stdin);
        scanf("%c", &option);
        printf("----------------------------------------------------\n\n");
    } while (toupper(option) == 'Y');

}

void countBooking() {
    FILE* fpbooking;

    fpbooking = fopen("booking.bin", "rb");


}
*/