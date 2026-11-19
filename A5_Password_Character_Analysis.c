#include <stdio.h>

int main()
{
    char password[100];
    char *ptr = password;
    int upper = 0, lower = 0, digit = 0, special = 0, length = 0;
    printf("Enter password: ");
    scanf("%99s", password);

    for( ;*ptr != '\0';ptr++)                            
    {
        if (*ptr >= 'A' && *ptr <= 'Z')
            upper++;
        else if (*ptr >= 'a' && *ptr <= 'z')
            lower++;
        else if (*ptr >= '0' && *ptr <= '9')
            digit++;
        else
            special++;
        length++;
    }
    printf("\nCharacter Counts:\n");
    printf("Uppercase: %d\nLowercase: %d\nDigits: %d\nSpecial Characters: %d\n",upper, lower, digit, special);

    if (length >= 8 && upper >= 1 && lower >= 1 && digit >= 1 && special >= 1)
    {
        printf("Password Strength: Strong\n");
    }
    else
    {
        printf("Password Strength: Weak\n");
    }
    return 0;
}