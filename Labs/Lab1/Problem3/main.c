#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//
// This program takes as command line a single integer value which represents a year and then computes and displays the Easter date for that year
// The algorithm for computing the catholic Easter date is the following :
//	A = year mod 19
//	B = year mod 4
//	C = year mod 7
//	D = (19 * A + 24) mod 30
//	E = (2 * B + 4 * C + 6 * D + 5) mod 7 where mod is the remainder of the division of x to y.
// Easter day is then(22 + E + D) March.Note that this formula can give a date from April if 22 + E + D > 31; also take this case into account!
// The program will display the Easter date in the following way "The Easter day is 02 April " (use trailing zeros for the day if it is less than 10)

int main(int argc, char* argv[]) {
	int year, result, a, b, c, d, e, day, month = 3;
	result = scanf("%d", &year);
	if (result != 1) //checking if the input is an integer or invalid
		printf("Invalid input, the year should be greater or equal to 1876\n");
	else
	{
		if (year >= 1876)
		{
			a = year % 19;
			b = year % 4;
			c = year % 7;
			d = (19 * a + 24) % 30;
			e = (2 * b + 4 * c + 6 * d + 5) % 7;
			day = 22 + e + d;
			if (day > 31) //march has 31 days, so if day variable is greater than 31, we are in april
			{
				month = 4;
				day = day - 31; 
			}
			if (month == 3)
				printf("In year %d the Easter date is March %02d\n", year, day);
			else
				printf("In year %d the Easter date is April %02d\n", year, day);
		}
		else
		{
			printf("Invalid input, the year should be greater or equal to 1876\n");
		}
	}

	return 0;
}

