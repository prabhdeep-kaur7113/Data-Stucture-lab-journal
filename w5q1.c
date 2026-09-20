#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int isfull(int rear)
{
    if(rear == MAX)
        return 1;
    return 0;
}
int isempty(int front)
{
    if(front == -1)
        return 1;
    return 0;
}

int enqueue(int rear, int queue[])
{
    if(isfull(rear))
    {
        printf("queue is full !OVERFLOW\n ");
        return rear;
    }
    int val;
    printf("enter the vlue to insert in queue : ");
    scanf("%d",&val);
    rear++;
    queue[rear] = val;
    return rear;
}

int dequeue(int front, int queue[])
{
    if(isempty(front))
    {
        printf("queue is empty ! UNDERFLOW \n");
        return front;
    }
    printf("element deleted is : %d",queue[front]);
    front++;
    return front;
}
void size(int front, int rear)
{
    if(isempty(front) &&(isempty(rear)))
    {
        printf("queue is empty ! UNDERFLOW \n");
        return ;
    }
    printf("size of the queue is : %d", rear-front+1);
}
void display(int front, int rear, int queue[])
{
    if(isempty(front))
    {
        printf("queue is empty ! UNDERFLOW \n");
        return ;
    }
    printf("elemenst of the queue are : \n");
    for(int i =front; i<=rear; i++)
        printf("%d\t",queue[i]);
    printf("\n");
}
int main()
{
    int queue[MAX], choice, front = -1, rear =-1;
    while(1)
    {
        printf("\nenter choice !\n");
        printf("1.to insert value\n2.to delete value\n3.to check if empty\n4. to check size\n5.todisplay elemtents\n6.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            rear = enqueue(rear, queue);
            if(front == -1)
                front = rear;
            break;
        case 2:
            front = dequeue(front, queue);
            if(front > rear)
                front = rear = -1;
            break;
        case 4:
            size(front, rear);
            break;
        case 3:
            if(isempty(front))
                printf("queue is empty\n");
            else    
                printf("queue is not empty\n");
            break;
        case 5 :
            display(front,rear, queue);
            break;
        case 6 :
            printf("\n--------EXIT----------\n");
            exit(0);
        default:
            printf("invalid choice !\n");
            break;
        }
    }
}