#include<stdio.h>
#define MAX 10

int main(){
    char str[MAX];
    int stack[MAX];
    int top = 0, val, maxval=0, i=0;
    stack[top] = -1;
    printf("enter string : ");
    scanf("%s",str);
    while(str[i]!='\0'){
        if(str[i]=='('){
            top++;
            stack[top] = i;
        }
        else{
                stack[top] = i;
                if(top > 0){
                val = stack[top] - stack[top-1];
                if(val > maxval)
                    maxval = val;
                top--;
                }
            }
        i++;
    }
    printf("count of correct parenthesis in string is : %d\n", maxval);
    return 0;
}