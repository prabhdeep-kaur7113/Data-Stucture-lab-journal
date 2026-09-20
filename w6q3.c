#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int isFull(int rear, int front)
{
    if((rear+1)%MAX == front)
        return 1;
    return 0;
}

void enqueue(int *rear, int queue[], int front)
{
    if(isFull(*rear, front))
    {
        printf("queue is full\n");
        return;
    }
    int val;
    printf("enter value to insert : ");
    scanf("%d",&val);
    *rear = (*rear + 1)%MAX;
    queue[*rear] = val;
}


int isEmpty(int front)
{
    if(front == -1)
        return 1;
    return 0;
}

void dequeue(int *front, int queue[], int rear)
{
    if(isEmpty(*front))
    {
        printf("queue is empty ! UNDERFLOW \n");
       return;
    }
    printf("element deleted is : %d",queue[*front]);
    *front = (*front + 1)%MAX;
    if(*front == rear)
         *front = -1;
}

void display(int front, int rear, int queue[])
{
    if(isEmpty(front))
    {
        printf("queue is empty ! UNDERFLOW \n");
        return;
    }
    printf("element of queue are : \n");
    while(front != rear)
    {
        printf("%d\t", queue[front++]);
    }
    printf("%d\n", queue[front]);
}

int main()
{
    int queue[MAX] , rear = -1, front = -1 , ch;

    while(1)
    {
        printf("1.to insert element in queue\n2. to delete elements from queue\n3. to check if queeu is empty\n4. find element at front\n5. find element at rear\n6. display elements of queue\n7.to EXIT   \n");
        printf("-----ENTER YOUR CHOICE---- :-  ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : enqueue(&rear, queue, front);
                     if(front == -1)
                        front = rear;
                    break;
            case 2 : dequeue(&front, queue, rear);
                     if(front == -1)
                        rear = -1;
                    break;
            case 3 : if(isEmpty(front))
                        printf("queue is empty ! UNDERFLOW \n");
                    else
                        printf("queue is not empty\n");
                    break;
            case 4 : if(isEmpty(front))
                        printf("queue is empty ! UNDERFLOW \n");
                    else 
                        printf("element at front is : %d\n", queue[front]);
                    break;
            case 5 : if(isFull(rear, front))
                        printf("queue is empty ! UNDERFLOW \n");
                    else 
                        printf("element at rear of queue is : %d\n", queue[rear]);
                    break;
            case 6 : display(front, rear, queue);
                    break;
            case 7 : printf("--------EXIT----------\n");
                    exit(0);
        }
    }
    return 0;
}