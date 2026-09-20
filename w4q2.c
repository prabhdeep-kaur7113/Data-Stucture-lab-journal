#include <stdio.h>
#include<stdlib.h>

void push(int arr[], int v, int *top, int *othertop)
{
    printf("\n----------------------------------------\n");    
    if (*top == (*othertop)+1 || (*top)+1 == *othertop)
    {
        printf("stack overflow ! cant enter any more elements !\n");
    }
    else{
    int val;
    printf("enter element to store in stack : ");
    scanf("%d", &val);
    printf("element entered !\n");
    *top = *top + v;
    arr[*top] = val;
    }
    printf("\n----------------------------------------\n");
}

void pop(int *top, int n, int val)
{
    printf("\n----------------------------------------\n");
    if (*top < 0 || *top > n - 1)
        printf("stack is empty \n");
    else{
        *top = *top - val;
    printf("element pop !\n");
    }
    printf("\n----------------------------------------\n");
}

void print(int arr[], int top, int val, int start, int n)
{
    printf("\n----------------------------------------\n");
    if (top < 0 || top > n - 1)
    {
        printf("stack is empty\n");
    }
    else{
    printf("elements of the stack are : \n");
    int i = start;
    while (i != top)
    {
        printf("%d ", arr[i]);
        i += val;
    }
    printf("%d\n", arr[i]);
    }
    printf("\n----------------------------------------\n");
}

void printall(int arr[], int top1, int top2, int n)
{
    printf("\n----------------------------------------\n");
    if (top1 < 0 && top2 > n - 1)
    {
        printf("stack is empty\n");
    }
    else{
    int val = 1, i = 0;
    printf("elements od the stack are : \n");
    while (i <= top1)
    {
        printf("%d ", arr[i]);
        i += val;
    }
    val = -1, i = n-1;
    while (i >= top2)
    {
        printf("%d ", arr[i]);
        i += val;
    }
    }
    printf("\n----------------------------------------\n");
}

int main()
{
    int n;
    printf("enter the size of array : \n");
    scanf("%d", &n);
    int arr[n], top1 = -1, top2 = n, choice;
    while (1)
    {
        
        printf("enter choice : \n");
        printf("1. to push element into stack-1\n2. to push element into stack-2\n 3. to pop element from stack-1\n4. to pop element from stack-2\n5. to print elements of stack-1\n6. to print elements of stack-2\n7. to print all the elements\n8. EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(arr, 1, &top1, &top2);
            break;
        case 2:
            push(arr, -1, &top2, &top1);
            break;
        case 3:
            pop(&top1, n, 1);
            break;
        case 4:
            pop(&top2, n, -1);
            break;
        case 5:
            print(arr, top1, 1, 0, n);
            break;
        case 6:
            print(arr, top2, -1, n - 1, n);
            break;
        case 7:
            printall(arr, top1, top2, n);
            break;
        case 8:
            printf("**************************\nyou are exit from the stack\n**************************\n");
            exit(0);
        default:
            printf("wrong choice enterred ! choose again\n");
            break;
        }
    }
    return 0;
}