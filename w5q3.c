#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int isFull(int r1, int r2)
{
    if(r1 == r2)
        return 1;
        return 0;
}

void enqueue(int queue[] , int *rear, int otherRear, int step)
{
    if(isFull(*rear, otherRear)){
        printf("\n<<<<<<<<< queue is full ! >>>>>>>>>>>>>>\n");
        return ;
    }
    int val;
    printf("enter vlaue to enter : ");
    scanf("%d",&val);
    *rear = *rear+step;
    queue[*rear] = val;
    printf("\n<<<<<<<<  value entered in queue >>>>>>>>>>>>>>>\n");
}

int isEmpty(int front)
{
    if(front == -1 || front == MAX)
        return 1;
        return 0;
}

void dequeue(int queue[] , int *front, int otherFront, int step)
{
    if(isEmpty(*front))
    {
        printf("\n<<<<<<<<< queue is empty ! >>>>>>>>>>>>>>\n");
        return;
    }
    printf("\n<<<<<<<<  deleted element is: %d  >>>>>>>>>\n", queue[*front]);
    *front = *front + step;
}

void display(int queue[], int front, int rear, int step)
{
    if(isEmpty(front))
    {
        printf("\n<<<<<<<<< queue is empty ! >>>>>>>>>>>>>>\n");
        return;
    }
    while(front != rear)
    {
        printf("%d\t", queue[front]);
        front = front+ step;
    }
    printf("%d\n", queue[front]);
}

int main()
{
    int queue[MAX];
    int f1 = -1, r1 = -1, f2 = MAX, r2 = MAX , choice;
    while(1)
    {
        printf("enter choice : \n");
        printf("1. enqueue from front\n2.dequeue from front\n3.enqueue from rear\n4.dequeue from rear\n5.display from front\n6.display from rear\n7.EXIT\n");
        printf("-----ENTER YOUR OPTION----------- ::  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1 :   enqueue(queue, &r1, r2, 1);
                        if(f1 == -1)
                            f1 = r1;
                        break;
            case 2 :    dequeue(queue, &f1, f2, 1);
                        if(f1 > r1)
                            f1 = r1 = -1;
                        break;
            case 3 :   enqueue(queue, &r2, r1, -1);
                        if(f2 == MAX)
                            f2 = r2;
                        break;
            case 4 :   dequeue(queue, &f2, f1, -1);
                        if(f2 < r2)
                            f2 = r2 = MAX;
                        break;
            case 5 :    display(queue, f1, r1, 1);
                               break;
            case 6 :    display(queue, f2, r2, -1);
                        break;
            case 7 :    printf("\n---------------EXIT---------------------\n");
                        exit(0);
        }
    }    
    return 0;
}