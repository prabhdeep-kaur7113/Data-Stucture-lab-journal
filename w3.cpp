#include<stdio.h>
#include<string.h>
#define MAX 100
void push(int stack[MAX],int *top,int value)
{
    if(*top==MAX-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        (*top)++;
        stack[*top]=value;
    }
}
void pop(int stack[MAX],int *top)
{
    if(*top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        (*top)--;
    }
}
int main()
{
    int stack[MAX];
    char str[MAX];
    printf("enter expression: ");
    scanf("%s",str);
    int i,start=-1,top=-1;
    int max=0,length;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
        {
            push(stack,&top,i);
        }
        else
        {
            if(top!=-1)
            {
                pop(stack,&top);
                if(top==-1)
                   length=i-start;
                else
                    length=i-stack[top];
                if(length>max)
                    max=length;
            }
            else
            {
                start=i;
            }
        }
    }
    printf("length of longest valid parenthesis substring = %d",max);
    return 0;
}