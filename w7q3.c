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

void isEmpty(node *start)
{
    if (start == NULL)
    {
        printf("\n---------------------------\n");
        printf("list is empty\n");
        printf("---------------------------\n");
    }
    else
    {
        printf("\n---------------------------\n");
        printf("list is not empty\n");
        printf("---------------------------\n");
        printf("list is not empty\n");
    }
}

void size(node *start)
{
    int cnt = 0;
    node *temp = start;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    printf("\n---------------------------\n");
    printf("size of list is : %d\n", ++cnt);
    printf("---------------------------\n");
}

struct node *deleteAtBeg(node *start)
{
    start = start->next;
    printf("\n---------------------------\n");
    printf("NODE DELETED !\n");
    printf("---------------------------\n");
    return start;
}

node *insertAtBeg(node *start)
{
    node *currNode = createNode(start);
    if (!currNode)
    {
        printf("node not created !");
        return start;
    }
    currNode->next = start;
    start = currNode;
    printf("\n---------------------------\n");
    printf("NODE INSERTED !\n");
    printf("---------------------------\n");
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
    int ch;
    node *start = NULL;
    while (1)
    {
        printf("1.push\n2.pop\n3.check if empty\n4.size\n5.display\n6. EXIT\n");
        printf("enter a choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = insertAtBeg(start);
            break;
        case 2:
            start = deleteAtBeg(start);
            break;
        case 3:
            isEmpty(start);
            break;
        case 4:
            size(start);
            break;
        case 5:
            display(start);
            break;
        case 6:
            printf("------------------EXIT-------------------\n");
            exit(0);
        default:
            printf("invlaid choice !\n");
            break;
        }
    }
}