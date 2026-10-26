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

node *reverse(node *start)
{
    if(start == NULL || start->next == NULL)
        return start;
    node *pre = NULL, *curr = start , *nxt = start->next;
    while(curr->next != NULL)
    {
        curr->next = pre;
        pre = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = pre;
    start = curr;
    return start;
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
    printf("Linked List is ::\n");
    display(start);
    printf("Linked List in reverse is ::\n");
    start = reverse(start);
    display(start);
}