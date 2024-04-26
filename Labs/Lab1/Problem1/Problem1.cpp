#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Enter your name and birth year ");
    char name[100];
    unsigned int year;
    fgets(name, 100, stdin);
    scanf_s("%d", &year);
    printf("Hello %s, you are %d years old\n", name, 2023 - year);
    return 0;
}