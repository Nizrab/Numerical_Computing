// nermericalLab1.cpp : Defines the entry point for the application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n, i;
    unsigned long long factorial = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    // Show error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist");
    else
    {
        for (i = 1; i <= n; ++i)
            factorial *= i;
        printf("Factorial of %d = %llu", n, factorial);
    }
    return 0;
}