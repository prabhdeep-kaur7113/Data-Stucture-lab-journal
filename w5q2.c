#include<stdio.h>
#define MAX 100

int isfull(int rear)
{
    if(rear == MAX)
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
int isempty(int front)
{
    if(front == -1)
        return 1;
    return 0;
}

void reversequeue(int front, int rear, int queue[])
{
    if(isempty(front) && isempty(rear))
    {
        printf("queue is empty ! UNDERFLOW \n");
    }
    else{
    printf("elemenst of the queue inreverse are : \n");
    for(int i =rear; i>=front; i--)
        printf("%d\t",queue[i]);
    printf("\n");
    }
}

int main()
{
    int queue[MAX],front = -1, rear =-1;
    char choice;
    while(1)
    {
        printf("enter 1 to enter elements in queue and any other key to exit :\n");
        scanf(" %c",&choice);
        if(choice == 49){
            rear = enqueue(rear, queue);
            if(rear == 0 && front == -1)
            front = 0;
        }
        else    break;
    }
    reversequeue(front, rear, queue);
    return 0;
}