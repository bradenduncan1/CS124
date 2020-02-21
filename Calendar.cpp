/***********************************************************************
* Program:
*    Project 07, Calendar project          (e.g. Assignment 10, Hello World)
*    Brother Birch, CS124
* Author:
*    Braden Duncan
* Summary: 
*    This program takes user input for a month number and year
*    then it returns a calendar to the user considering in what day
*    of the month that calendar will start and when it will end. 
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;


/**********************************************************************
 * getMonth prompts the user for a month as a number
 ***********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;

   return month;
}


/**********************************************************************
 * getYear prompts the user for a year at least at 1753
 ***********************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;

   return year;
}


/**********************************************************************
 * Determines if a year is a leap year
 ***********************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 == 0 && year % 100 != 0)
   {
      return true;
   }
   else if (year % 400 == 0) 
   {
      return true;
   }
   else 
   {
      return false;
   }
}


/**********************************************************************
 * Takes the year given and calculates the number of days that have
 * passed since january first 1753 and returns it
 ***********************************************************************/
int numDaysInYear(int year)
{
   int numDaysYear = 0;
   for (int i = 1753; i < year; i++)
   {
      if (isLeapYear(i) == true) 
      {
         numDaysYear += 366;
      }
      else
      {
         numDaysYear += 365;
      }
   }
   return numDaysYear;
}


/**********************************************************************
 * Calculates numbers of days that have passed this year since Jan 1
 ***********************************************************************/
int numDaysSinceJan(int year, int month)
{
   int numDaysSince = 0;
   for (int i = 0; i < month; i++)
   {
      if (i == 1) 
      {
         numDaysSince += 31;
      }
      else if (i == 2 && isLeapYear(year) == true) 
      {
         numDaysSince += 29;
      }
      else if (i == 2) 
      {
         numDaysSince += 28;
      }
      else if (i == 3) 
      {
         numDaysSince += 31;
      }
      else if (i == 4) 
      {
         numDaysSince += 30;
      }
      else if (i == 5) 
      {
         numDaysSince += 31;
      }
      else if (i == 6) 
      {
         numDaysSince += 30;
      }
      else if (i == 7)
      {
	     numDaysSince += 31;
      }
      else if (i == 8) 
      {
	     numDaysSince += 31;
      }
      else if (i == 9) 
      {
	     numDaysSince += 30;
      }
      else if (i == 10) 
      {
	     numDaysSince += 31;
      }
      else if (i == 11) 
      {
	     numDaysSince += 30;
      }  

   }
   return numDaysSince;
}


/**********************************************************************
 * Takes the month given and returns the number of days in that month
 ***********************************************************************/
int numDaysInMonth(int year, int month)
{
   int numDaysMonth = 0;
   if (month == 1) 
   {
      numDaysMonth = 31;
   }
   else if (month == 2 && isLeapYear(year) == true)
   {
      numDaysMonth = 29;
   }
   else if (month == 2) 
   {
      numDaysMonth = 28;
   }
   else if (month == 3) 
   {
      numDaysMonth = 31;
   }
   else if (month == 4) 
   {
      numDaysMonth = 30;
   }
   else if (month == 5) 
   {
      numDaysMonth = 31;
   }
   else if (month == 6) 
   {
      numDaysMonth = 30;
   }
   else if (month == 7) 
   {
      numDaysMonth = 31;
   }
   else if (month == 8) 
   {
      numDaysMonth = 31;
   }
   else if (month == 9) 
   {
      numDaysMonth = 30;
   }
   else if (month == 10) 
   {
      numDaysMonth = 31;
   }
   else if (month == 11) 
   {
      numDaysMonth = 30;
   }
   else if (month == 12) 
   {
      numDaysMonth = 31;
   }
   return numDaysMonth;
}

/**********************************************************************
 * Dertermine the day of the week that the month will start on
 * pass in number of days from year and months passed
 * divide total number of days that have passed by 7 to determine weeks
 * that have passed. The remainder will give us our offset.
 ***********************************************************************/
int computeOffset(int year, int month, int numDaysYear, int numDaysSince)
{
   int totalDays = numDaysYear + numDaysSince;

   int offset = totalDays % 7;
   
   return offset;
}


/**********************************************************************
 * Take the month number and print out the correct month and year
 ***********************************************************************/
void displayHeader(int year, int month)
{
   cout << endl;
   if (month == 1) 
   {
      cout <<  "January, " << year << endl;
   }
   else if (month == 2) 
   {
      cout <<  "February, " << year << endl;
   }
   else if (month == 3) 
   {
      cout << "March, " << year << endl;
   }
   else if (month == 4) 
   {
      cout <<  "April, " << year << endl;
   }
   else if (month == 5) 
   {
      cout << "May, " << year << endl;
   }
   else if (month == 6) 
   {
      cout << "June, " << year << endl;
   }
   else if (month == 7) 
   {
      cout << "July, " << year << endl;
   }
   else if (month == 8)
   {
      cout << "August, " << year << endl;
   }
   else if (month == 9)
   {
      cout << "September, " << year << endl;
   } 
   else if (month == 10) 
   {
      cout << "October, " << year << endl;
   }
   else if (month == 11) 
   {
      cout << "November, " << year << endl;
   }
   else if (month == 12) 
   {
      cout << "December, " << year << endl;
   }
}


/**********************************************************************
 * Take in the offset and print the calendar depending on which day 
 * the month starts on
 ***********************************************************************/
void displayTable(int numDaysMonth, int offset)
{
   int count = 0;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   for (int j = 0; j <= offset; j++) 
   {
      if (offset != 6) 
      {
         cout << "    ";
      }
   }
   for (int i = 1; i <= numDaysMonth; i++)
   {
      cout << setw(4) << i;
      count++;
      
      if (count % 7 == 0 || i == numDaysMonth) 
	  {
         cout << endl;
         count = 0;
      }
      if (offset == 0 && i == 6) 
      {
         cout << endl;
         count = 0;
      }
      if (offset == 1 && i == 5) 
      {
         cout << endl;
         count = 0;
      }
      else if (offset == 2 && i == 4)
      {
         cout << endl;
         count = 7;
      }
      else if (offset == 3 && i == 3)
      {
         cout << endl;
         count = 7;
      }
      else if (offset == 4 && i == 2)
      {
         cout << endl;
         count = 7;
      }
      else if (offset == 5 && i == 1)
      {
         cout << endl;
         count = 7;
      }
   }
   }


/**********************************************************************
 * Main calls all the functions into action, setting variables after
 * prompting the user for the month and year.
 * Calls on display functions to show us our finished calendar
 ***********************************************************************/
int main()
{
	int month;
	do 
	{
		month = getMonth();
		if (month > 12 || month < 1)
		{
			cout << "Month must be between 1 and 12.\n";
		}
	}
    while (month > 12 || month < 1);

    int year;
	do 
	{
		year = getYear();
		if (year < 1753)
		{
			cout << "Year must be 1753 or later.\n";
		}
	}
    while (year < 1753);

	int numDaysYear = numDaysInYear(year);
	int numDaysMonth = numDaysInMonth(year, month);
	int numDaysSince = numDaysSinceJan(year, month);

	int offset = computeOffset(year, month, numDaysYear, numDaysSince);

	displayHeader(year, month);
	displayTable(numDaysMonth, offset);

	return 0;
}
