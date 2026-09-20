#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

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

void findMiddle(node *start)
{
    node *temp1 = start;
    node *temp2 = start;
    if (temp1->next == NULL)
    {
        printf("\n---------------------------\n");
        printf("element at middle of list is : %d\n", temp1->data);
        printf("---------------------------\n");
    }
    else
    {
        while (temp1->next->next != NULL)
        {
            temp2 = temp2->next;
            temp1 = temp1->next->next;
        }
        printf("\n---------------------------\n");
        printf("element at middle of list is : %d\n", temp2->data);
        printf("---------------------------\n");
    }
}

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

node *insertAtEnd(node *start)
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
        return start;
    }
    node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = currNode;
    currNode->next = NULL;
    printf("\n---------------------------\n");
    printf("NODE INSERTED !\n");
    printf("---------------------------\n");
    return start;
}

node *insertAtposition(node *start)
{
    node *currNode = createNode(start);
    if (!currNode)
    {
        printf("node not created !");
        return start;
    }
    int pos;
    printf("enter after how many nodes to insert new node : ");
    scanf("%d", &pos);
    node *temp = start, *ptr = NULL;
    int cnt = 0;
    while (temp->next != NULL && cnt < pos)
    {
        cnt++;
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = currNode;
    currNode->next = temp;
    printf("\n---------------------------\n");
    printf("NODE INSERTED!\n");
    printf("---------------------------\n");
    return start;
}

struct node *deleteAtBeg(node *start)
{
    start = start->next;
    printf("\n---------------------------\n");
    printf("NODE DELETED !\n");
    printf("---------------------------\n");
    return start;
}

struct node *deleteAtEnd(node *start)
{
    struct node *temp = start;
    struct node *ptr = NULL;
    if (start->next == NULL)
    {
        return NULL;
    }
    while (temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = NULL;
    printf("\n---------------------------\n");
    printf("NODE DELETED !\n");
    printf("---------------------------\n");
    return start;
}

node *deleteAtposition(node *start)
{
    int pos;
    printf("enter th =e node to delete : ");
    scanf("%d", &pos);
    node *temp = start, *ptr = start;
    int cnt = 1;
    if (pos == 1)
    {
        start = deleteAtBeg(start);
        return start;
    }
    while (temp->next != NULL && cnt < pos)
    {
        cnt++;
        ptr = temp;
        temp = temp->next;
    }
    temp = temp->next;
    ptr->next = temp;
    printf("\n---------------------------\n");
    printf("NODE DELETED !\n");
    printf("---------------------------\n");
    return start;
}

int main()
{
    node *start = NULL;
    int ch;

    while (1)
    {
        printf("1.insert at beginning\n2.insert at end\n3.insert after a node\n4.delete at begining\n5.delete at end\n6.delete at position\n7.check if empty\n8.check size\n9.find middle element\n10.display\n11.EXIT\n");
        printf("enter a choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = insertAtBeg(start);
            break;
        case 2:
            start = insertAtEnd(start);
            break;
        case 3:
            start = insertAtposition(start);
            break;
        case 4:
            start = deleteAtBeg(start);
            break;
        case 5:
            start = deleteAtEnd(start);
            break;
        case 6:
            start = deleteAtposition(start);
            break;
        case 7:
            isEmpty(start);
            break;
        case 8:
            size(start);
            break;
        case 9:
            findMiddle(start);
            break;
        case 10:
            display(start);
            break;
        case 11:
            printf("------------------EXIT-------------------\n");
            exit(0);

        default:
            printf("invlaid choice !\n");
            break;
        }
    }
}