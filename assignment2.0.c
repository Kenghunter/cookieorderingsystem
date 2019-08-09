#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "Helper.h"
#define LOVELETTER 25.00
#define NUTCOOKIES 20.00

#define ASSORTEDCOOKIES 15.00
#define TAX 1.06
#pragma warning (disable: 4996)
//func col
void splashScreen();
void welcomeInput();
void orderList();
void Summary();
void mainMenu();
void orderProcess();
void ordermainMenuList();
void receipt();
void cash();
void smallChat();
void creditcard();
void memberPromotion();
float getDepositQuantity();
void printout();
///////////////////////////////////////////////////////////////////////
//global dec

int i = 1,i2=0, response = 0;
float total = 0, total2 = 0,total4=0,total3=0,
LoveLetterPrice, NutCookiesPrice, AssortedCookiesPrice,
NutCookiesQuantity, LoveLetterTotal, AssortedCookiesQuantity,
NutCookies, AssortedCookies, LoveLetterQuantityTotal, AssortedCookiesTotal, NutCookiesTotal,
total1, AssortedCookiesPriceTotal, LoveLetterPriceTotal, NutCookiesPriceTotal, LoveLetterQuantity;
double  DepositTotal = 0, FinalTotal = 0, depositAmmount;
char num[] = { '0','1','2','3','4','5','6','7','8','9' }, Deposit, quantity[100] ,date[30], name[40], CustomerTelephoneNumber[30], rply[5], companyName[] = "TARUC FESTIVE COOKIES SHD BHD", companyAddress[] = "Kampus Utama, Jalan Genting Kelang, 53300 Kuala Lumpur, Wilayah Persekutuan Kuala Lumpur",
companyTelephoneNumber[] = "Tel: 03-41450123. Fax: 03-41423166", reply[900], Quantity[] = "Quantity", price[] = "PRICE", product[] = "PRODUCT";;

enum CookieType { LoveLetter = 1, NutCookie = 2, AssortedCookie = 3 };

void main()
{
	/*printout();
	splashscreen();*/
	//welcomeInput();
	mainMenu();
	orderProcess();
	receipt();
	system("pause");
}
void splashScreen()
{
	printf(" _______  _______  ______    __   __  _______    _______  _______   _______  _______  ___  __   __  _______    _______  _______  _______  ___   _  ___  _______  _______\n");
	printf("|       ||   _   ||    _ |  |  | |  ||       |  |       ||       | |       ||       ||   ||  | |  ||       |  |       ||       ||       ||   | | ||   ||       ||       |\n");
	printf("|_     _||  |_|  ||   | ||  |  | |  ||       |  |    ___||   ___ | |  _____||_     _||   ||  |_|  ||    ___|  |       ||   _   ||   _   ||   |_| ||   ||    ___||  _____|\n");
	printf("  |   |  |       ||   |_||_ |  |_|  ||       |  |       ||   |___  | |_____   |   |  |   ||       ||   |      |       ||  | |  ||  | |  ||     __||   ||   |____|  |____\n");
	printf("  |   |  |       ||   __   ||       ||      _|  |    ___||   ___ | |_____  |  |   |  |   ||       ||    ___|  |      _||  |_|  ||  |_|  ||    |__ |   ||    ___||_____  |\n");
	printf("  |   |  |   _   ||  |  |  ||       ||     |_   |   |    |   |___   _____| |  |   |  |   | |     | |   |___   |     |_ |       ||       ||    _  ||   ||   |___  _____| |\n");
	printf("  |___|  |__| |__||__|  |__||_______||_______|  |___|    |_______| | ______|  |___|  |___|  |___|  |_______|  |_______ |_______||_______||___| |_||___||_______||_______|\n");
	printf(" _______   ______   __    _    _______   __   __  ______\n");
	printf("|        ||       ||  |  | |  |  _    | |  | |  ||      |\n");
	printf("|  _____ ||  _    ||   |_| |  | |_|   | |  |_|  ||  _    |\n");
	printf("| |_____ || | |   ||       |  |       | |       || | |   |\n");
	printf("|_____   || |_|   ||  _    |  |  _    | |       || |_|   |\n");
	printf("_____|   ||       || | |   |  | |_|   | |   _   ||       |\n");
	printf("|_______ || ______||_|  |__|  |_______| |__| |__||______| \n");
	smallChat();
	printf("\n");
	system("pause");
	system("cls");
}
void smallChat()
{
	int x;
	printf("%60c waking up the staffs  ");
	for (x = 0; x < 5; x++)
	{
		printf("\b\b...", x);
		Sleep(500);
	}
	printf("\n");
	printf("%60c Eating breakfast  ");
	for (x = 0; x < 5; x++)
	{
		printf("\b\b...", x);
		Sleep(500);
	}
	printf("\n");
	printf("%60c preheating the oven  ");
	for (x = 0; x < 5; x++)
	{
		printf("\b\b...", x);
		Sleep(500);
	}
	printf("\n");
	for (x = 0; x < 1; x++)
	{
		printf("\b%30c[xxx%", x);
		Sleep(100);
	}
	for (x = 0; x < 30; x++)
	{
		printf("\b\bxxxxx%", x);
		Sleep(50);
	}
	for (x = 0; x < 1; x++)
	{
		printf("\b\bx]%", x);
		Sleep(50);
		printf("\n%55c TARUC FESTIVE COOKIES SHD BHD AT YOUR SERVICE");
	}
}
void welcomeInput()
{
	printf("<<welcome to Cookies Ordering System>>\n");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	response = askQues("do you want to auto capture today's date ?else will considered as manual imput.(y=Yes n=No)");

	if (response == 1)
	{
		printf("Today's Date(DD MM YY): %d %d %d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	}
	else
	{
		printf("Enter the current date(date/month/year) :");
		rewind(stdin);
		scanf("%s", &date);
	}



	printf("enter user name :");
	rewind(stdin);
	scanf("%s", &name);
	printf("enter your phone number:");
	rewind(stdin);
	scanf("%s", &CustomerTelephoneNumber);
	

}
void mainMenu()
{
	printf("+==========================+========+=====================+\n|         Category         |  unit  | Price (RM) per unit |\n"
		"+==========================+========+=====================+\n| Love Letters(Kuih Kapit) | tin    |               25.00 |\n"
		"+--------------------------+--------+---------------------+\n| Nut Cookies              | jar    |               20.00 |\n"
		"+--------------------------+--------+---------------------+\n| Assorted Cookies         | jar    |               15.00 |\n"
		"+--------------------------+--------+---------------------+\n");

	printf("Discounts:\n"
		"5 percent off for orders totaling between RM 500 and RM 1000 (iNutCookieslusive)\n"
		"10 percent off for orders totaling more than 1000\n"
		"members will get additional 10 percent off at the final bill.\n");
		
}
void orderProcess()
{
	response = askQues("start ordering?(Y=yes N=No):");

	if (response == 1)
	{
		do
		{
			ordermainMenuList();
			response = askQues("Continues Order (y=yes n=no)? ");
			if (response == 1)
			{
				ordermainMenuList();


			}
			else
			{
				Summary();
			}
		} while (response == 1);


	}
	else
	{
		printf("awwww,see you again.\n ");
	}

}


float getOrderQuantity(int cookieType)
{
	goto ask;
ask:
	switch (cookieType)
	{
	case 1:
		printf("%-30s %-20f %-s", "LOVE LETTER", LOVELETTER, "");
		break;
	case 2:
		printf("%-30s %-20f %-s", "NUT COOKIES", NUTCOOKIES, "");
		break;
	case 3:
		printf("%-30s %-20f %-s", "ASSORTED COOKIES", ASSORTEDCOOKIES, "");
		break;
	default:
		break;
	}
	rewind(stdin);
	scanf("%s", &quantity);
	goto evalNum;

evalNum:
	while (NumberChecker(quantity) < 1)
	{
		goto ask;
	}
	goto returnResult;

returnResult:
	return atof(quantity);

}

void ordermainMenuList()
{

	do
	{
		do
		{
			printf("Order No : %d\n", i);
			i++;

			printf("%-30s %-20s %-s\n", product, price, Quantity);
			printf("--------------------------------------------------------------------\n");

			LoveLetterQuantity = getOrderQuantity(LoveLetter);
			LoveLetterPrice = LoveLetterQuantity * LOVELETTER;
			printf("\n");

			NutCookiesQuantity = getOrderQuantity(NutCookie);
			NutCookiesPrice = NutCookiesQuantity * NUTCOOKIES;
			printf("\n");


			AssortedCookiesQuantity = getOrderQuantity(AssortedCookie);
			AssortedCookiesPrice = AssortedCookiesQuantity * ASSORTEDCOOKIES;
			printf("\n");
		} while (rply == 'Y' || rply == 'y');
		LoveLetterTotal += LoveLetterQuantity;
		NutCookiesTotal += NutCookiesQuantity;
		AssortedCookiesTotal += AssortedCookiesQuantity;
		LoveLetterPriceTotal += LoveLetterPrice;
		NutCookiesPriceTotal += NutCookiesPrice;
		AssortedCookiesPriceTotal += AssortedCookiesPrice;
		i2 = i;

		printf("%-30s %-20s %-s\n", product, Quantity, price);
		printf("%-30s %-20.0f %-.2f\n", "love letter", LoveLetterQuantity, LoveLetterPrice);
		printf("%-30s %-20.0f %-.2f\n", "nut cookies", NutCookiesQuantity, NutCookiesPrice);
		printf("%-30s %-20.0f %-.2f\n", "assorted cookies", AssortedCookiesQuantity, AssortedCookiesPrice);
		printf("--------------------------------------------------------------------\n");
		total = (LoveLetterPrice + NutCookiesPrice + AssortedCookiesPrice);
		
		printf("%-10s = %30f\n", "total of the food without tax", total);
		printf("tax=%10f\n", TAX);
		if (total >= 500 && total <= 1000)
		{
			total=total* 0.95;
			printf("5 percent discount given\n");
		}
		else if (total >= 1000)
		{
			total = total * 0.90;
			printf("10 percent discount given\n");
		}
		else
		{
			total;
			printf("0 percent discount given\n");
		}
		
		getDepositQuantity();
		printf("your deposit is %f", atof(quantity));
		depositAmmount = atof(quantity);
		DepositTotal += depositAmmount;
		total1 = ((total * TAX) - depositAmmount);
		memberPromotion();
		printf("%-10s =%40f\n", "total of the food after tax", total1);
		total2 += total1;
		total3 = total2 - DepositTotal;
		
	} while (rply == 'Y' || rply == 'y');
	orderProcess();
}
float getDepositQuantity()
{
	goto ask;
ask:
	printf("how much deposit do you want to put ?");
	rewind(stdin);
	scanf("%s", &quantity);
	goto evalNum;
evalNum:
	while (NumberChecker(quantity) < 1)
	{
		goto ask;
	}
	goto returnResult;
returnResult:
	return atof(quantity);
}
void Summary()
{
	i--;
	printf("so here is your order of the day\n");//change to summart of the day 
	printf("total order number for today:%d\n", i);

	printf("%-30s %-20s %-s\n", product, Quantity, price);
	printf("%-30s %-20.0f %-f\n", "love letter", LoveLetterTotal, LoveLetterPriceTotal);
	printf("%-30s %-20.0f %-f\n", "nut cookies", NutCookiesTotal, NutCookiesPriceTotal);
	printf("%-30s %-20.0f %-f\n", "assorted cookies", AssortedCookiesTotal, AssortedCookiesPriceTotal);

	printf("your total is %f\n", total2);
	printf("your total deposit is %f\n", DepositTotal);
	printf("your final total is %f\n ", total3);
}
void receipt()
{
	char choice;//promt print receipt ltr 
	goto ask;
ask:

	response = askQues("do you want to pay in credit card or cash ?(y=credit card ,n=cash)\n");
	scanf("%c", &choice);
	goto verify;
	verify:
	switch (choice)
	{
	case 1:
		creditcard();
		break;
	case 2:
		cash();
		break;

	default:
		goto ask;
	}
}

void creditcard()
{
	total2 = total2 + 1;
	printf("Credit card transaction will cost addRm 1 \n");
	printf("the total after goverment tax and credit card fee %f", total3);
	printout();
}

void cash()
{
	
	printf("cash total is % f", total3);
	printout();
}

void memberPromotion()
{

	response = askQues("are you a member ?");


	if (response == 1)
	{
		total1 = total1 * 0.90;
		printf("additionnal 10 percent will be deducted from the nill\n");
	}
	else
	{
		total4 = total3;
		printf("no discount given\n");
	}
}

void printout()
{
	response = askQues("do you want a print out ?");
	if (response == 1)
	{
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		printf("%s\n%s\n", companyName, companyAddress);

		printf("%s\n", companyTelephoneNumber);
		printf("--------------------------------------------------------------------------------\n");
		printf("Invoice Date(DD MM YY): %d %d %d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		printf("order number:%d\n", i2);
		printf("--------------------------------------------------------------------------------\n");
		printf("%-30s %-20s %-s\n", product, Quantity, price);
		printf("%-30s %-20.0f %-.2f\n", "love letter", LoveLetterQuantity, LoveLetterPrice);
		printf("%-30s %-20.0f %-.2f\n", "nut cookies", NutCookiesQuantity, NutCookiesPrice);
		printf("%-30s %-20.0f %-.2f\n", "assorted cookies", AssortedCookiesQuantity, AssortedCookiesPrice);
		printf("--------------------------------------------------------------------------------\n");
		printf("%-10s = %30f\n", "SUBTOTAL", total2);
		printf("%-10s =%40f\n", "NET TOTAL", total3);

	}
	else {
		printf("Thank you very Much");
	}

}
