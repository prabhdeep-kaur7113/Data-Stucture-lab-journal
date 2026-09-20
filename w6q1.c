#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int isFull(int rear)
{
    if(rear >= MAX-1)
        return 1;
    return 0;
}

int isEmpty(int front)
{
    if(front == -1)
        return 1;
    return 0;
}

void size(int rear, int front)
{
    if (isEmpty(front))
    {
        printf("stack is empty\n");
        return;
    }
    printf("size is : %d\n", (rear-front+1));
}



void enqueue(int q1[] , int stack[], int *rear)
{
    if(isFull(*rear))
    {
        printf("queue overflow !\n");
        return;
    }
    int val;
    printf("enter value to insert : ");
    scanf("%d",&val);
    q1[++(*rear)] = val;
    stack[(*rear)] = val;
}

void dequeue(int q1[] , int stack[] ,int front, int *rear)
{
    if(isEmpty(front)){
        printf("queue is empty !\n");
        return;
    }
    int q2[MAX], i =0;
    int temp = *rear;
    while(temp >= front)
    {
        q2[i] = q1[temp--];
        i++;
    }
    printf("deleted element is : %d\n",q2[front++]);
    temp = *rear;
    i =0;
    while(temp >= front){
        stack[i] = q1[i] = q2[temp];
        i++;
        temp--;
    }
    *rear = i-1;
}

void show(int stack[] ,int rear,int front)
{
    if(isEmpty(front)){
        printf("queue is empty !\n");
        return;
    }
    printf("values are : \n");
    while(rear >=front)
    {
        printf("%d\t", stack[rear--]);
    }
    printf("\n");
}

int main()
{
    int front = -1, rear = -1, q1[MAX], stack[MAX], ch;
    while (1)
    {
        printf("enter choice : \n");
        printf("1.to enter elements\n2. to delete elements\n3. to check if stack is empty\n4. to check size\n5.to print elements\n6.EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(q1, stack,&rear);
            if(front == -1)
                front = rear;
            break;
        case 2:
            dequeue(q1, stack, front, &rear);
            if(front > rear)
                front = rear = -1;
            break;
        case 3:
            if(isEmpty(front)){
                printf("stack is empty !\n");
            }
            else    printf("not empty\n");
            break;
        case 4:
            size(rear, front);
            break;
        case 5:
            show(stack , rear, front);
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