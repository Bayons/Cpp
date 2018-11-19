#include <iostream>
#include <string>
#include <vector>

#define DSU std::string("Sunday")
#define DMO std::string("Monday")
#define DTU std::string("Tuesday")
#define DWE std::string("Wednesday")
#define DTH std::string("Thursday")
#define DFR std::string("Friday")
#define DSA std::string("Saturday")

#define MJAN std::string("January")
#define MFEB std::string("February")
#define MMAR std::string("March")
#define MAPR std::string("April")
#define MMAY std::string("May")
#define MJUN std::string("June")
#define MJUL std::string("July")
#define MAUG std::string("August")
#define MSEP std::string("September")
#define MOCT std::string("October")
#define MNOV std::string("November")
#define MDEC std::string("December")

#define OLD std::string("*")
#define END std::string("#")

/**
 * Given a year, determines whether it is or not a leap year. It is a leap
 * year if it is divisible by 4. But if it is divisible by 100, it must
 * also be divisible by 400 for being a leap year.
 *
 * @param year
 * 	unsigned int with the year value.
 *
 * @returns true if it is a leap year.
 */
bool isLeapYear(unsigned int year)
{
	if(year % 400 == 0)
		return true;
	if(year % 100 == 0)
		return false;
	if(year % 4 == 0)
		return true;
	return false;
}

/**
 * https://ide.geeksforgeeks.org/index.php
 */
unsigned int zellerFunction(unsigned int day, unsigned int month,
		unsigned int year){
    if (month == 1) 
    { 
    	month = 13; 
    	year--; 
    } 
    if (month == 2) 
    { 
    	month = 14; 
    	year--; 
    } 
    int q = day; 
    int m = month; 
    int k = year % 100; 
    int j = year / 100; 
    int h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j; 
    h = h % 7; 
    switch (h) 
    { 
	case 0 : std::cout << "Saturday \n"; break; 
    	case 1 : std::cout << "Sunday \n"; break; 
    	case 2 : std::cout << "Monday \n"; break; 
    	case 3 : std::cout << "Tuesday \n"; break; 
    	case 4 : std::cout << "Wednesday \n"; break; 
    	case 5 : std::cout << "Thursday \n"; break; 
    	case 6 : std::cout << "Friday \n"; break; 
    } 
    return h; 
}

/**
 * The program will calculate the day of the week of the incoming date 
 * (Zeller's rule) and find out if it is the same one as the incoming day
 * of the week. If not, the style is the old one.
 */
int main(void){
	std::cout << zellerFunction(1, 1, 1900) << "\n";
	
	return 0;
}
