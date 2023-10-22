#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable:4996)

#define PRC_A 24.50 
#define PRC_B 26.00
#define PRC_C 27.50
#define PRC_D 29.00
#define DELIVERY_FEE 5.00

void pricelist() {
	printf("\t\t\t\t\t     PRICE LIST\n");
	printf("\t\t\t\t\tPackage A = RM24.50\n");
	printf("\t\t\t\t\tPackage B = RM26.00\n");
	printf("\t\t\t\t\tPackage C = RM27.50\n");
	printf("\t\t\t\t\tPackage D = RM29.50\n");
}

void main() {

	int  qtyA = 0, qtyB = 0, qtyC = 0, qtyD = 0, customer_no = 1, ttl_qty_A = 0, ttl_qty_B = 0, ttl_qty_C = 0, ttl_qty_D = 0, total_qty;
	char name[20], address1[20], address2[20], address3[20], phonenum[20], nextcustomer, menu_option;
	double ttlPA, ttlPB, ttlPC, ttlPD, SUM, Discount, delivery_fees, totalpay, total_sales_A, total_sales_B, total_sales_C, total_sales_D, total_sales, Price_A, Price_B, Price_C, Price_D, ttldiscount = 0, ttlearning, ttldlvfee = 0;
	do
	{
		printf("\t\t\t\t<<< Welcome to JK Organic Vegetable Farm >>>\n");
		printf("\n");

		printf("Customer No= %d\n", customer_no);

		printf("Enter surname :");
		rewind(stdin);
		gets(name);

		printf("Enter phone number :");
		scanf("%s", &phonenum);

		printf("Enter address :\n");

		printf("    address 1 :");
		rewind(stdin);
		gets(address1);

		printf("    address 2 :");
		gets(address2);


		printf("    address 3 :");
		gets(address3);

		qtyA = 0, qtyB = 0, qtyC = 0, qtyD = 0, ttldiscount = 0;

		pricelist();

		do
		{


			printf("\nPACKAGE A,B,C,D (x = Exit) :");
			rewind(stdin);
			scanf("%c", &menu_option);
			menu_option = toupper(menu_option);



			switch (menu_option)
			{
			case 'A':
				Price_A = PRC_A;
				printf("Quantity :");
				scanf("%d", &qtyA);
				break;

			case 'B':
				Price_B = PRC_B;
				printf("Quantity :");
				scanf("%d", &qtyB);
				break;

			case 'C':
				Price_C = PRC_C;
				printf("Quantity :");
				scanf("%d", &qtyC);
				break;

			case 'D':
				Price_D = PRC_D;
				printf("Quantity :");
				scanf("%d", &qtyD);
				break;

			case 'x':break;

			default:
				printf("Invalid Package.Please Reenter Package\n");
				break;
			}
			if (menu_option == 'X') break;


			ttlPA = PRC_A * qtyA;
			ttlPB = PRC_B * qtyB;
			ttlPC = PRC_C * qtyC;
			ttlPD = PRC_D * qtyD;



		} while (menu_option != 'X');




		printf("\n");
		printf("\t\t\t\t\t\t    INVOICE        \n");
		printf("\t\t\t\t\tName      :Mr/Ms %s\n", name);
		printf("\t\t\t\t\tTelephone :%s\n", phonenum);
		printf("\t\t\t\t\tAddress   :%s\n", address1);
		printf("\t\t\t\t\t           %s\n", address2);
		printf("\t\t\t\t\t           %s\n", address3);


		printf("\n");
		printf("\t\t\t\t\t          CUSTOMER ORDERS\n");
		printf("\t\t\t\t\tPACKAGE A %d @ RM24.50 =RM %.2f\n", qtyA, ttlPA);
		printf("\t\t\t\t\tPACKAGE B %d @ RM26.00 =RM %.2f\n", qtyB, ttlPB);
		printf("\t\t\t\t\tPACKAGE C %d @ RM27.50 =RM %.2f\n", qtyC, ttlPC);
		printf("\t\t\t\t\tPACKAGE D %d @ RM29.00 =RM %.2f\n", qtyD, ttlPD);

		//
		SUM = ttlPA + ttlPB + ttlPC + ttlPD;
		delivery_fees = DELIVERY_FEE;

		ttl_qty_A += qtyA;
		ttl_qty_B += qtyB;
		ttl_qty_C += qtyC;
		ttl_qty_D += qtyD;


		if (SUM >= 80) {
			delivery_fees = 0;




			if (SUM >= 100) {
				double Discount = SUM * 0.15;
				ttldiscount += Discount;

				totalpay = SUM - Discount;
				printf("\t\t\t\t\tPACKAGE Charge =RM%.2f\n", SUM);
				printf("\t\t\t\t\tDelivery Fees  =RM%.2f\n", delivery_fees);
				printf("\t\t\t\t\tTotal discount =RM%.2f\n", Discount);
				printf("\t\t\t\t\tTotal to pay   =RM%.2f\n", totalpay);
				printf("\n");
			}
			else {
				totalpay = SUM;
				printf("\t\t\t\t\tPACKAGE Charge =RM%.2f\n", SUM);
				printf("\t\t\t\t\tDelivery Fees  =RM%.2f\n", delivery_fees);

				printf("\t\t\t\t\tTotal to pay   =RM%.2f\n", totalpay);
				printf("\n");
			}
		}

		else {
			ttldlvfee += delivery_fees;
			totalpay = SUM + delivery_fees;
			printf("\t\t\t\t\tPACKAGE Charge =RM%.2f\n", SUM);
			printf("\t\t\t\t\tDelivery Fees  =RM%.2f\n", delivery_fees);

			printf("\t\t\t\t\tTotal to pay   =RM%.2f\n", totalpay);
			printf("\n");
		}



		printf("\t\t\t\t\tTHANK YOU ,HAVE A NICE DAY!!");
		printf("\n\n");

		printf("Next customer (Y = yes/N = no) >");
		rewind(stdin);
		scanf("%c", &nextcustomer);
		nextcustomer = toupper(nextcustomer);

		if (nextcustomer == 'y' || nextcustomer == 'Y')
			customer_no++;




	} while (nextcustomer == 'y' || nextcustomer == 'Y');

	total_sales_A = ttl_qty_A * PRC_A;
	total_sales_B = ttl_qty_B * PRC_B;
	total_sales_C = ttl_qty_C * PRC_C;
	total_sales_D = ttl_qty_D * PRC_D;
	total_qty = ttl_qty_A + ttl_qty_B + ttl_qty_C + ttl_qty_D;
	total_sales = total_sales_A + total_sales_B + total_sales_C + total_sales_D;
	ttlearning = total_sales + ttldlvfee - ttldiscount;


	printf("\t\t\t\t\tDaily Sales Summary Report\n");
	printf("\t\t\tTotal number of customer = %d\n", customer_no);
	printf("\t\t\tPACKAGE\t\tQUANTITY SOLD\t\tSALES AMOUNT\n");
	printf("\t\t\t   A   \t\t     %d      \t\t     %.2lf    \n", ttl_qty_A, total_sales_A);
	printf("\t\t\t   A   \t\t     %d      \t\t     %.2lf    \n", ttl_qty_B, total_sales_B);
	printf("\t\t\t   A   \t\t     %d      \t\t     %.2lf    \n", ttl_qty_C, total_sales_C);
	printf("\t\t\t   A   \t\t     %d      \t\t     %.2lf    \n", ttl_qty_D, total_sales_D);
	printf("\t\t\t========================================================\n");
	printf("\t\t\t TOTAL \t\t     %d      \t\t     %.2lf    \n", total_qty, ttlearning);

	system("pause");
}