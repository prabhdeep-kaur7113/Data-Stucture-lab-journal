#include <stdio.h>

int close(char ch, int *top, char arr[100])
{
    int val = arr[*top];
    if(val+1 == ch || val+2 == ch || val+3 == ch){
        *top = *top-1;
        return 1;
    }
    return 0;  
}
int main()
{
    char arr[100];
    char str[100];
    printf("enter the string : ");
    fflush(stdin);
    gets(str);
    int i = 0, top = -1, flag = 1;
    while (str[i] != '\0')
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            top = top + 1;
            arr[top] = str[i];
        }
        else
        {
            flag = close(str[i], &top, arr);
            if (flag == 0)
                break;
        }
        i++;
    }
    if (flag == 1 && top == -1 && str[i]=='\0')
        printf("correct brakcets\n");
    else
        printf("wrong bracets!\n");
    return 0;
}

// OUTPUT : 
// enter the string : {{(()())}}
// correct brakcets
// enter the string : {()(()}
// wrong bracets!
// enter the string : ([][])(){(())}
// correct brakcets