#include<stdio.h>
#include<string.h>

void revstr(char stack[], int top){
    if(top <=-1)  return;
    printf("%c",stack[top]);
    revstr(stack, top-1);
}

int main(){
    char str[100];
    int len, i=0, top=-1;
    printf("enter the string : ");
    scanf("%[^\n]s", str);
    len = strlen(str);
    char stack[len];
    while(str[i]!='\0'){
        stack[++top] = str[i];
        i++;
    }
    printf("reverse string with recursion is : ");
    revstr(stack, top);
    printf("\nreverse string without recursion is : ");
    while(top>=0){
        printf("%c",stack[top--]);
    }
    return 0;
}