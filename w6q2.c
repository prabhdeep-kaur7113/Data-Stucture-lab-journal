#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int isFull(int top){
    if(top >= MAX-1)
        return 1;
    return 0;
}
int isEmpty(int top){
    if(top == -1)
        return 1;
    return 0;
}
int enqueue(int stack[] , int queue[] , int top)
{
    if(isFull(top))
    {
        printf("QUEUE IS FULL \n");
        return top;
    }
    int val;
    printf("enter value : ");
    scanf("%d", &val);
    top = top+1;
    queue[top] = stack[top] = val;
    return top;
}

int dequeue(int stack[] , int queue[] , int top)
{
    if(isEmpty(top)){
        printf("QUEUE IS EMPTY \n");
        return top;
    }

    int s2[MAX] , i=0 , temp = top;
    while(temp >= 0)
    {
        s2[i] = stack[temp--];
        i++;
    }
    printf("element deleted is : %d\n", s2[top--]);
    i =0, temp = top;
    while(temp >=0)
    {
       queue[i] = stack[i] = s2[temp--];
        i++;
    }
    top = i-1;
    return top;
}

void size(int top)
{
    if (isEmpty(top))
    {
        printf("stack is empty\n");
        return;
    }
    printf("size is : %d\n", top+1);
}

void show(int queue[] , int top)
{
    if (isEmpty(top))
    {
        printf("stack is empty\n");
        return;
    }
    printf("the values are :-\t");
    int i=0;
    while(i <= top)
    {
        printf("%d\t", queue[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int queue[MAX], stack[MAX], top =-1 , ch;

    while (1)
    {
        printf("enter choice : \n");
        printf("1.to enter elements\n2. to delete elements\n3. to check if queue is empty\n4. to check size\n5.to print elements\n6.EXIT\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            top = enqueue(stack, queue , top);
            break;
        case 2:
            top = dequeue(stack , queue , top);
            break;
        case 3:
            if(isEmpty(top))
                printf("stack is empty !\n");
            else
                printf("not empty\n");
            break;
        case 4:
            size(top);
            break;
        case 5:
            show(queue , top);
            break;
        case 6:
            printf("\n-----------EXIT----------------\n");
            exit(0);
        default:printf("INVALID CHOICE !\n");
            break;
        }
    }
    return 0;
}