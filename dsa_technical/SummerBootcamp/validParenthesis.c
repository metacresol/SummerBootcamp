#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    printf("Enter expression: ");
    scanf("%s", s);

    char stack[1000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }

        else
        {
            if (top == -1)
            {
                printf("Invalid");
                return 0;
            }

            if ((ch == ')' && stack[top] != '(') ||
                (ch == '}' && stack[top] != '{') ||
                (ch == ']' && stack[top] != '['))
            {
                printf("Invalid");
                return 0;
            }

            top--;
        }
    }

    if (top == -1)
        printf("Valid");
    else
        printf("Invalid");

    return 0;
}