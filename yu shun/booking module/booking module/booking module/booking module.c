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

typedef struct {
    struct bookingID bookingid;
    char todayDate[30], bookingDate[30], facilityID[30], bookingID[30];
    int bookingTimeMin, bookingTimeHour, day, month, year;
}booking;

typedef struct {
    struct bookingID bookingid;
    char todayDate[30], bookingDate[30], facilityID[30], bookingID[30];
    int bookingTimeMin, bookingTimeHour, day, month, year;
}bookingModify;

void addBooking();
void displayBooking();
void searchBooking();
void modifyBooking();
void deleteBooking();
void countBooking();
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
        printf("| 7  | Exit Booking      |\n");
        printf(" ------------------------ \n");

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
            abort();
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
                else if (book.month > t.wMonth) { /*if its 1 month diff*/
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
                else if (book.month > t.wMonth) { /*if its 1 month diff*/
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
                else if (book.month > t.wMonth) { /*if its 1 month diff*/
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
                else if (book.month > t.wMonth) { /*if its 1 month diff*/
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
                else if (book.month > t.wMonth) { /*if its 1 month diff*/
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
                else if (book.month > t.wMonth) { /*if its 1 month diff*/
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

//done
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
        printf("\n");

        printf("------------------------\n");
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

//done
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

        int out=0;

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


        printf("\n------------------------\n");
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

//md id wrong
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

                                }
                                else {
                                    printf("Invalid date!\n\n");
                                }
                            }
                            else {
                                printf("Invalid date!\n\n");
                            }
                        }
                        else if (bookMD.month > t.wMonth) { /*if its 1 month diff*/
                            reMonth = bookMD.month - t.wMonth;
                            if (reMonth == 1) {
                                reDay = t.wDay - bookMD.day;
                                reDay = t.wDay - reDay;
                                if (reDay >= 0 && reDay <= 2) {
                                    strcpy(bookMD.bookingID, book.bookingID);
                                    fwrite(&bookMD, sizeof(bookingModify), 1, fpMD);
                                    printf("\nModify Success\n");
                                }
                                else {
                                    printf("Invalid date!\n\n");
                                }
                            }
                            else {
                                printf("Invalid date!\n\n");
                            }
                        }
                        else {
                            printf("Invalid date!\n\n");
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
                                }
                                else {
                                    printf("Invalid date!\n\n");
                                }
                            }
                            else {
                                printf("Invalid date!\n\n");
                            }

                        }
                        else {
                            printf("Invalid date!\n\n");
                        }
                    }
                    else {
                        printf("Invalid date!\n\n");

                    }




                    printf("Booking date has been modified to \n");
                    printf(" ----------------------------- \n");
                    printf("|  Booking ID  |     Date     |\n");
                    printf("|------------- |--------------|\n");
                    printf("|     %-7s  |   %d-%d-%d   |\n\n", bookMD.bookingID, bookMD.day, bookMD.month, bookMD.year);
                    printf(" ----------------------------- \n");
                    out++;

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
            printf("-------------\n\n");
        }

        printf("-----------------------\n");
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
    } while (select !=1);

    system("cls");

}



//done
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
            printf("-------------\n\n");
        }
        printf("------------------------\n");
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
    } while (select !=1);

    system("cls");
}

//done
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
       
        printf("\n------------------------\n");
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


    } while (select!=1);
    system("cls");
}

