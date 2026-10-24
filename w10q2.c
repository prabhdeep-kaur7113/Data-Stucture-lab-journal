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

void findNthNode(node *start, int n)
{
    if(start == NULL)
    {
        printf("No node exist !\n");
        return;
    }
    node *temp = start;
    int i =1;
    while( i<n && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if(temp == NULL)
    {
        printf("Invalid Position Entered !\n");
        return;
    }
    while(temp->next != NULL)
    {
        start = start->next;
        temp = temp->next;
    }
    printf("Value of Nth node from last is : %d\n",start->data);
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
    int n;
    printf("Enter the Nth node value to print from last of linked list : ");
    scanf("%d",&n);
    findNthNode(start, n);
    
}