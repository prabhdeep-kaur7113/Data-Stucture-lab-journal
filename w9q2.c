#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int val)
{
    node *newNode = (node*)malloc(sizeof(node));
    if(!newNode)    return NULL;
    newNode->data = val;
    newNode->next = newNode;
    return newNode;
}

node *insertEnd(node *start, int val)
{
    node *currNode = createNode(val);
    node *temp = start;
    if(currNode == NULL)    return NULL;
    if(start == NULL)
    {
        start = currNode;
        currNode->next = start;
        return start;
    }
    while(temp->next != start)
        temp = temp->next;
    temp->next = currNode;
    currNode->next = start;
    return start;
}

void display(node *start)
{
    node *temp = start;
    if(start == NULL){
        printf("no node exist\n");
        return;
    }
    while(temp->next != start)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

node* concat(node *start1, node *start2)
{
    node *temp = start1;
    if(start2 ==NULL)
        return start1;
    if(start1 == NULL)
        return start2;
    
    temp = start2;
    while(temp->next != start2)
        temp = temp->next;
    temp->next = start1;

    temp = start1;
    while(temp->next != start1)
        temp = temp->next;
    temp->next = start2;
    return start1;
}

int main()
{
    node *start1 = NULL , *start2 = NULL;
    char ch;
    int val;
    printf("Enter vlaues in 1st linked list :\n");
    do{
        printf("vlaue : ");
        scanf("%d",&val);
        start1 = insertEnd(start1, val);
        printf("do you want to continue (Y/N) : ");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch == 'y' || ch == 'Y');
    printf("Enter vlaues in 2st linked list :\n");
    do{
        printf("vlaue : ");
        scanf("%d",&val);
        start2 = insertEnd(start2, val);
        printf("do you want to continue (Y/N) : ");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch == 'y' || ch == 'Y');
    printf("linked list after concatination is : \n");
    start1 = concat(start1, start2);
    display(start1);
    return 0;
}
