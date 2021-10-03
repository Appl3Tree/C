/*
 *  Programmer: Forrest Connelly
 *  Program: Tithing
 *  Goal: Determine the amount for tithe, first fruits, and third tithe.
 */

// Include the standard input/output and math header.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NIKI 2500.00
#define NIKI_FIRSTFRUITS 60.00
#define NIKI_TITHE 240.00
#define FIRSTFRUITS 0.025
#define TITHE 0.10
#define TAX 0.743720525559226

// Function prototype(s) before the main function.
char showMenu();
double getGross(int hoursWorked, double rate);
int convertToCents(int pennies);
int convertToDollars(int pennies);
int convertToPennies(double money);
void changeHourlyRate(double *rate);
void convertToDollarsAndCents(int *dollars, int *cents, int pennies);
void doMenuAction(char userChoice, double *hourlyRate);
void titheAndFirstFruits(double rate);

 // Every C program needs a main function.
 int main()
 {
    // Declare and initialize variable(s) needed.
    char userChoice = '0';
    double hourlyRate = 19.8265;
     
    // Display a blank line for readability.
    puts("");

    //  Call the menu so the user can select what they'd like to do.
    while (userChoice != '4')
    {
        userChoice = showMenu();
        doMenuAction(userChoice, &hourlyRate);
        
        //  Display two blank lines to separate the end of the loop from 
        // the next iteration or the end of the program's execution.
        printf("%s", "\n\n");
    }

    printf("%s", "\n");

    return 0;
 }

char showMenu()
{
    //  Declare and initialize variable(s) needed.
    char userChoice[2] = {'0'};
    char dump = '0';

    do
    {
        printf("%s", "-----------------------------------------------------------\n");
        printf("%s", "| 1) Change hourly rate. (default is $19.8265)            |\n");
        printf("%s", "| 2) Display hourly rate.                                 |\n"); 
        printf("%s", "| 3) Determine the tithe and first fruits.                |\n");
        printf("%s", "| 4) Exit.                                                |\n");
        printf("%s", "-----------------------------------------------------------\n");
        printf("%s", "Please enter your choice: ");
        scanf(" %c%c", userChoice, &dump);

        //  If the user's option is not 1, 2, or 3, inform them and ask them to enter
        //  an actual choice.
        if (userChoice[0] < '1' || userChoice[0] > '4' )
        {
            puts("");
            printf("%s", "That is not a valid option. Please enter 1, 2, 3, or 4.\n");
        }
    } while (userChoice[0] < '1' || userChoice[0] > '4');

    return userChoice[0];
}

double getGross(int hoursWorked, double rate)
{
    double grossIncome = 0;

	grossIncome = hoursWorked * rate;

    return grossIncome;
}

int convertToCents(int pennies)
{
    int cents = 0;

    cents = pennies % 100;
    return cents;
}

int convertToDollars(int pennies)
{
    int dollars = 0;

    dollars = pennies / 100;
    return dollars;
}


int convertToPennies(double money)
{
    //  Declare and initialize variable(s) needed.
    int pennies = 0;

    //  Set the variable "pennies" to the total money paramater multiplied by 100.
    //  Floor this result to remove decimal values.
    pennies = floor(money * 100);
    return pennies;
}

void changeHourlyRate(double *rate)
{
    printf("%s", "Please enter the new hourly rate: ");
    scanf("%lf", rate);
}

void convertToDollarsAndCents(int *dollars, int *cents, int pennies)
{
    *dollars = convertToDollars(pennies);
    *cents = convertToCents(pennies);
}

void doMenuAction(char userChoice, double *hourlyRate)
{
    switch (userChoice)
    {
        case '1':
            changeHourlyRate(hourlyRate);
            printf("%.4lf", *hourlyRate);
            break;
        
        case '2':
            printf("Current hourly rate is set to $%.2lf.\n", *hourlyRate);
            break;
            
        case '3':
            titheAndFirstFruits(*hourlyRate);
            break;

        case '4':
            exit(0);
            break;
           
        default:
            printf("%s", "Uh oh, something went wrong. Please try again!\n");
            exit(1);
            break;
    }
}

void titheAndFirstFruits(double rate)
{
    //  Declare and initialize variable(s) needed.
    char continueChoice[2] = {'n'};
    char dump = '0';
    int cents = 0;
    int dollars = 0;
    int firstFruits = 0;
    int hoursWorked = 0;
    int netIncome = 0;
    int pennies = 0;
    int tithe = 0;
    double grossIncome = 0.00;
    
    
    printf("%s", "Please enter the amount of hours worked this month: ");
    scanf("%d%c", &hoursWorked, &dump);
    puts("");

    grossIncome = getGross(hoursWorked, rate);

    //  Display gross incomes.
    printf("Forrest's Gross Monthly Income:%12s%7.2lf\n", "$", grossIncome);
    printf("Niki's Gross Monthly Income:%15s%7.2lf\n", "$", NIKI);
	printf("%50s\n", "--------");
    printf("Combined Gross Income:%21s%7.2lf\n\n", "$", grossIncome + NIKI);

    //  Turn the gross income into pennies to make accurate calculations
    //  of money.
    pennies = convertToPennies(grossIncome);

    //  Find the amount removed for taxes.
    netIncome = pennies * TAX;

    //  Convert the penny value of gross income into net income.
    convertToDollarsAndCents(&dollars, &cents, pennies);
    

    //  Perform arithmetic to find the first fruits.
    firstFruits = floor(pennies * FIRSTFRUITS);

    //  Subtract the first fruits from the total gross income so that the
    //  correct % will be set to the tithe.
    pennies -= firstFruits; 

    //  Perform arithmetic to find the tithe.
    tithe = floor(pennies * TITHE);

    //  Subtract the first fruits from the total gross income so that the
    //  correct % will be set to the tithe.
    pennies -= tithe; 

    //  Convert the penny value  of first fruits into a "dollar" and "cent"
    //  value.
    convertToDollarsAndCents(&dollars, &cents, firstFruits);

    //  Display the First Fruits and Tithe.
    if (firstFruits % 100 < 10)
    {
        printf("First Fruits 2.5%%:%25s%4d.0%d. Niki's is: $%6.2lf.\n", "$", dollars, cents, NIKI_FIRSTFRUITS);
    }
    else
    {
        printf("First Fruits 2.5%%:%25s%4d.%d. Niki's is: $%6.2lf.\n", "$", dollars, cents, NIKI_FIRSTFRUITS);
    }

    //  Convert the penny value of tithe into a "dollar" and "cent" value.
    convertToDollarsAndCents(&dollars, &cents, tithe);

    //  Tithe
    if (tithe % 100 < 10)
    {
        printf("Tithe 10%%:%33s%4d.0%d. Niki's is: $%6.2lf.\n", "$", dollars, cents, NIKI_TITHE);
    }
    else
    {
        printf("Tithe 10%%:%33s%4d.%d. Niki's is: $%6.2lf.\n", "$", dollars, cents, NIKI_TITHE);
    }

    //  Convert the penny value of the net income into a "dollar" and "cent" value.
    convertToDollarsAndCents(&dollars, &cents, netIncome);

	//	Separation of tithes and net income.
	printf("%50s\n", "--------");

    //  Display the net income.
    if (netIncome % 100 < 10)
    {
        printf("Net Income:%32s%4d.0%d.\n", "$", dollars, cents);
    }
    else
    {
        printf("Net Income:%32s%4d.%d.\n", "$", dollars, cents);
    }

    //  Determine if the user wants to continue running the program after
    //  displaying the previous data.
    do
    {
        printf("%s", "Would you like to continue running the program? (y/n)\n");
        scanf(" %c%c", continueChoice, &dump);
    
        switch (continueChoice[0])
        {
            case 'N':
            case 'n':
                puts("");
                exit(0);
        
            case 'Y':
            case 'y':
                break;

           default:
               printf("That is not a valid option. Please enter 'y' or 'n'.\n");
               continueChoice[0] = '?';
               break;
        }
    }
    while (continueChoice[0] == '?');
    
}
