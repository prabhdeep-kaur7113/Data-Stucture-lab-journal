#include<stdio.h>
#include<stdlib.h>

int create(){
    int n;
    printf("enter stack size : ");
    scanf("%d",&n);
    return n;
}

void push(int arr[100] , int n, int* top){
    if(*top >= n-1){
        printf("stack overflow ! cant enter any more elements !\n");
    }
    else{
        int val;
        printf("enter element to store in stack : ");
        scanf("%d" , &val);
        *top = *top + 1;
        arr[*top] = val;
    }
}

void pop (int* top){
    if(*top == -1)
        printf("stack is empty \n");
    else
        *top = *top-1;
        printf("element poped !\n");
}

void isEmpty(int *top){
    if(*top == -1)
        printf("stack is empty\n");
    else    printf("stack is not empty\n");
}

void size(int* top){
    int size = *top;
    if(*top == -1)
        printf("stack is empty\n");
    else    printf("the size if stack is : %d\n",size+1);
}

void print(int arr[100] , int n ,int* top){
    if(*top == -1)
        printf("stack is empty\n");
    else{
    printf("elements are : \n");
    int i =0;
    while(i <= *top){
        printf("%d\t", arr[i]);
        i++;
    }
    }
    printf("\n");
}

int main(){
    int arr[100];
    int n = create();
    int top = -1 , choice;
    while(1){
    printf("\n----------------------------------------\n");
    printf("enter choice : \n");
    printf("\n1. to push element into stack\n\
            2. to pop element from stack\n\
            3. to check if stack is empty\n\
            4. to check stack current size\n\
            5. to print stack elements\n\
            6.EXIT\n");
    printf("----------------------------------------\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        push(arr , n, &top);
        break;
    case 2:
        pop(&top);
        break;
    case 3:
        isEmpty(&top);
        break;
    case 4:
        size(&top);
        break;
    case 5:
        print(arr , n , &top);
        break;
    case 6:
        printf("**************************\nyou are exit from the stack\n**************************\n");
        exit(0);
    default: printf("wrong choice enterred ! choose again");
        break;
    }
}
    return 0;
}