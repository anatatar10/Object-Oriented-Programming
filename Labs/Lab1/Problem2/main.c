#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Alice forgot her card’s PIN code.She remembers that her PIN code had 4 digits, all the digits were distinctand in decreasing order, and that the sum of these digits was 24. 
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints. 

int main(int argc, char* argv[]) {
	int a, b, c, d;
	for (a = 9; a >= 6; a--) //the least number whose digits are sum of 24 is 6*4 - 6666
	{
		for (b = a - 1; b >= 0; b--)
		{
			for (c = b - 1; c >= 0; c--)
			{
				d = 24 - a - b - c;
				if (d <= 9 && d >= 0 && d < c)
				{
					printf("%d%d%d%d\n", a, b, c, d);
				}
			}
		}
	}
	return 0;
}

