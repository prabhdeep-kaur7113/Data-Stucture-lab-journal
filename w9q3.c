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

void split(node **start1, node **start2, int val, node *head)
{
    int i = 1;
    if(head == NULL)  return;
    *start1 = head;
    node *temp = head;
    while(temp->next!= head && i < val)
    {
        temp = temp->next;
        i++;
    }
    *start2 = temp->next;
    temp->next = head;

    node *temp2 = *start2;
    while(temp2->next != head)
        temp2 = temp2->next;
    temp2->next = *start2;
}

int main()
{
    node *head = NULL, *start1 = NULL , *start2 = NULL;
    char ch;
    int val;
    printf("Enter vlaues in 1st linked list :\n");
    do{
        printf("vlaue : ");
        scanf("%d",&val);
        head = insertEnd(head, val);
        printf("do you want to continue (Y/N) : ");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch == 'y' || ch == 'Y');
    printf("linked list : \n");
    display(head);
    printf("---------------------------------\n");
    printf("Enter the value to split linked list from : ");
    scanf("%d",&val);
    split(&start1, &start2, val, head);

    printf("1st linked list : \n");
    display(start1);
    printf("---------------------------------\n");

    printf("2nd linked list : \n");
    display(start2);
    printf("----------------------------------\n");
    return 0;
}
