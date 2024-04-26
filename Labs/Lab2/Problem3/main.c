#include <stdio.h>
#include <limits.h>
#include "tests.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// Using the function that you wrote for problem 2, write a function that computesand returns an array with all the positions of the occurrences of a character in a string.
const char* my_strchr(const char* s, char character) {
    // TODO your code here
    char* p = s;
    while (*p != '\0') //valoarea pointerului p
    {
        if (*p == character)
        {
            return p;
        }
        else
        {
            p++;
        }
    }
    return NULL;
}

void find_all(const char* str, char character, int* positions, unsigned int cap, unsigned int* l) {
    char* p = str; 
    p = my_strchr(p, character);
    int i = 0, pos;
    for (int j = 0; j < cap; j++)
    {
        positions[j] = -1;
    }
    while (p != NULL) //pointerul pointeaza spre o zona nenula
    {
        if (i < cap)
        {
            pos = p - str;
            positions[i] = pos;
            i++;
        }
        else
            break;
        
        p = my_strchr(p + 1, character); //noua pozitie 

    }
    *l = i;
 
 }

int main()
{
#if  ENABLE_TESTS > 0
    run_tests(true);
#endif 
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
    /*char str[100];
    fgets(str, 100, stdin);
    char character;
    
    find_all(str, 'a', NULL, 0, NULL);*/
    return 0;
}
