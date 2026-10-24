#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(node *start)
{
    int val;
    node *newNode = (node *)malloc(sizeof(node));
    printf("enter the data value : ");
    scanf("%d", &val);
    if (!newNode)
    {
        printf("node not created !");
        return newNode;
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

node *insert(node *start)
{
    node *currNode = createNode(start);
    if (!currNode)
    {
        printf("node not created !");
        return start;
    }
    if (start == NULL)
    {
        start = currNode;
        printf("---------------------------\n");
        printf("NODE INSERTED !\n");
        printf("---------------------------\n");
        return start;
    }
    node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = currNode;
    currNode->next = NULL;
    printf("---------------------------\n");
    printf("NODE INSERTED !\n");
    printf("---------------------------\n");
    return start;
}

void split(node *start, node *start1)
{
    while (start != NULL && start1 != NULL)
    {
        start->next = start1->next;
        start = start->next;

        start1->next = start->next;
        start1 = start1->next;
    }
}

void display(node *start)
{
    if (start == NULL)
    {
        printf("no node exist !\n");
        return;
    }
    node *temp = start;
    while (temp->next != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    node *start = NULL, *start1 = NULL;
    printf("Enter value to insert in linked list : \n");
    start = insert(start);
    char ch;
    printf("Do you want to continue (Y/N) :: ");
    fflush(stdin);
    scanf("%c", &ch);
    while (ch == 'y' || ch == 'Y')
    {
        insert(start);
        printf("Do you want to continue (Y/N) :: ");
        fflush(stdin);
        scanf("%c", &ch);
    }
    display(start);
    start1 = start->next;
    if(start1 != NULL)
        split(start, start1);
    printf("Even list : ");
    display(start);
    printf("Odd list : ");
    display(start1);
}