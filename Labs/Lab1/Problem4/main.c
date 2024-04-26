#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tests.h"

// Substitution cipher or Caesar’s cipher.

// This program which reads a natural number n and a string s. The string s is encoded using Caesar’s cipher with a displacement of n (either positive or negative).
// The program decodes the message and display it on the screen. Punctuation marks and numbers are left as they are.


// DO NOT CHANGE THE SIGNATURE OF THIS METHOD

int getIndex(char alphabet1[], char character) //function to return the position of a given letter in the alphabet (normal/rotated)
{
	int i;
	for (i = 0; i < 26; i++)
	{
		if (alphabet1[i] == character)
			return i;
	}
	return -1; //returns -1 if the letter is not found
}

void encrypt(char s[], int n) {
	// TODO your code here
	// add your encryption code here. the string s will be modified in place, using a displacement of n
	char alphabet[26], rotatedAlphabet[26];
	int i, posN;
	if (n < 0)
		posN = -n;
	else
		posN = n;
	for (i = 0; i < 26; i++) //creating the normal alphabet with the small letters from 'a' to 'z'
	{
		alphabet[i] = 'a' + i;
	}
	for (i = 0; i < 26; i++) //creating the rotated alphabet with the given rotation
	{
		rotatedAlphabet[i] = alphabet[(i + posN) % 26]; //
	}
	for (i = 0; i < strlen(s); i++) //we are going through the normal message or the encrypted one, depending on n, if it is positive/negative
	{
		if (s[i] >= 'a' && s[i] <= 'z') //changing only the letters
		{
			if (n < 0) // the encrypted message is given
			{
				int index = getIndex(rotatedAlphabet, s[i]); //we take the index of the letters in the encrypted message
				s[i] = alphabet[index]; //we decode each letter accordin to the normal alphabet
			}
			else
			{
				int index = getIndex(alphabet, s[i]); //we take the index of the letters in the message
				s[i] = rotatedAlphabet[index]; //we encode each letter accordin to the normal alphabet
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') //in case there are upper letters in the normal/encrypted message, they are first lowered, the index is found, and transformed back into an upper letter
		{
			if (n < 0)
			{
				int index = getIndex(rotatedAlphabet, tolower(s[i]));
				s[i] = toupper(alphabet[index]);
			}
			else
			{
				int index = getIndex(alphabet, tolower(s[i]));
				s[i] = toupper(rotatedAlphabet[index]);
			}
		}
	}
}

int main()
{

	// To enable the tests, ctrl+click on ENABLE_TESTS (or go to the file "tests.h") and change the line
	// #define ENABLE_TESTS 0
	// to:
	// #define ENABLE_TESTS 1
#if ENABLE_TESTS > 0
	run_tests(true);
#endif

	// TODO your code here
	int n;
	char message[100];
	scanf("%d\n", &n);
	fgets(message, 100, stdin);
	encrypt(message, n);
	printf("%s\n", message);
	return 0;
}