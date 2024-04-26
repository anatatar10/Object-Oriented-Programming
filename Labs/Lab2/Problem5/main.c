#include <math.h>
#include <stdio.h>
#include <limits.h>
#include "tests.h"
#include<malloc.h>

void showMenu()
{
    printf("-h: display information about how the game is played and exit.\n -s: save all the possible solutions for the game in a text file called \"solution.txt\" and then exit.\n -e : play the game in easy mode.\n");
    printf("To exit the game, type q\n");
    char command;
    scanf(" %c", &command);
    if (command == 'h')
    {
        printf("The 24 puzzle is math game in the player is given 4 digits and he/she must figure out a way of combing these digits and the addition (+), subtraction (-), multiplication (*), and division (/) operators such that the result is 24.");
    }
    else if (command == 's')
    {
        /*FILE* fp;
        fp = fopen("solution.txt", "w");
        for (int i = 0; v[i][7] == '\n'; i++)
        {
            for(int j = 0; j < 7; j++)
                fputc(v[i][j], fp);
        }
        fclose(fp);
        free(v);*/
        exit(0);
    }
    else if (command = 'e')
    {
        printf("The game will start in easy mode\n");
        int nr = easyMode();
        int l = nr % 10;
        int k = nr / 10 % 10;
        int j = nr / 100 % 10;
        int i = nr / 1000 % 10;
        printf("The numbers to use are: %d, %d, %d, %d.", i, j, k, l);
        printf("Enter the three operators to be used, in order(+, -, *, or /): ");
        char ope1, ope2, ope3;
        char str[4];
        int ok = 0;
        scanf("%s", &str);        
        while (ok == 0)
        {
            ok = 1;
            for (int i = 0; str[i] == '\n'; i++)
            {
                if (str[i] != '+' || str[i] != '-' || str[i] != '*' || str[i] != '/')
                {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0)
            {
                scanf("%s", &str);
            }
        }
        ope1 = str[0];
        ope2 = str[1];
        ope3 = str[2];
        printf("The operators to be used are: %c%c%c", ope1, ope2, ope3);
    }
    else if (command == 10)
    {
        printf("The game will start in full mode");
    }
        
        
   
    else if (command == 'q') {
        exit(0);
    }
}

int signToInt(char sign) {
    if (sign == '+')
    {
        return 0;
    }
    else if (sign == '-')
    {
        return 1;
    }
    else if (sign == '/')
    {
        return 3;
    }
    else if (sign == '*')
    {
        return 2;
    }
}

int easyMode()
{
    int arr[7] = {1146, 1138, 1226, 1234, 1139, 4446, 1888};
    srand(time(NULL));
    return arr[rand() % 7];
}

char intToOperation(int op)
{
    if (op == 0)
        return '+';
    else if (op == 1)
        return '-';
    else if (op == 2)
        return '*';
    else if (op == 3)
        return '/';

}

double operations(int i, int j, int k, int l, int op1, int op2, int op3)
{
    double result = 0;
    if (op1 == 0)
    {
        result = i + j;
    }
    else if (op1 == 1)
    {
        result = i - j;
    } 
    else if (op1 == 2)
    {
        result = i * j;
    }
    else if (op1 == 3)
    {
        result = (1.0*i) / j;
    }
    //printf("\n %d %c %d = %lf\n %lf", i, intToOperation(op1), j, result, result);

    if (op2 == 0)
    {
        result = result + k;
    }
    else if (op2 == 1)
    {
        result = result - k;
    }
    else if (op2 == 2)
    {
        result = result * k;
    }
    else if (op2 == 3)
    {
        result = result / k;
    }
    //printf(" %c %d = %lf\n %lf", intToOperation(op2), k, result, result);

    if (op3 == 0)
    {
        result = result + l;
    }
    else if (op3 == 1)
    {
        result = result - l;
    }
    else if (op3 == 2)
    {
        result = result * l;
    }
    else if (op3 == 3)
    {
        result = result / l;
    }
    //printf(" %c %d = %lf\n", intToOperation(op3), l, result);

    return result;
}

int generateAllCombinations(int** numbers, char** operators) {
    int contor = 0;
    
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                for (int l = 1; l <= 9; l++)
                {
                    for (int op1 = 0; op1 <= 3; op1++)
                    {
                        for (int op2 = 0; op2 <= 3; op2++)
                        {
                            for (int op3 = 0; op3 <= 3; op3++)
                            {
                                double result = operations(i, j, k, l, op1, op2, op3);
                                if (fabs(result - 24) < 0.001)
                                {
                                    numbers[contor][0] = i;
                                    numbers[contor][1] = j;
                                    numbers[contor][2] = k;
                                    numbers[contor][3] = l;
                                    operators[contor][0] = intToOperation(op1);
                                    operators[contor][1] = intToOperation(op2);
                                    operators[contor][2] = intToOperation(op3);
                                    
                                    contor++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (contor > 0) {
        int** vector = (int**)malloc((contor+1) * sizeof(int*));
        for (int i = 0; i < contor+1; i++)
        {
            vector[i] = (int*)malloc(7 * sizeof(int));
        }
        for (int i = 0; i < contor; i++)
        {
            vector[i][0] = numbers[i][0];
            vector[i][1] = operators[i][0];
            vector[i][2] = numbers[i][1];
            vector[i][3] = operators[i][1];
            vector[i][4] = numbers[i][2];
            vector[i][5] = operators[i][2];
            vector[i][6] = numbers[i][3];
        }

        vector[contor][0] = '\n';
        
        return vector;
    }
    return 0;
}

int main()
{
#if ENABLE_TESTS > 0

    run_tests(true);
#endif
    int** numbers = (int**)malloc(3188 * sizeof(int*));
    char** operators = (char**)malloc(3188 * sizeof(char*));
    for (int i = 0; i < 3188; i++)
    {
        numbers[i] = (int*)malloc(4*sizeof(int));
        operators[i] = (int*)malloc(3 * sizeof(int));
    }
    
    showMenu();
    free(numbers);
    free(operators);
    
	
    return 0;

}
