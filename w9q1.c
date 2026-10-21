#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode()
{
    int val;
    node *newNode = (node *)malloc(sizeof(node));
    printf("enter the data value : ");
    scanf("%d", &val);
    if (!newNode)
    {
        printf("node not created !\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = newNode;
    return newNode;
}

node *insertAtBeg(node *start)
{
    node *currNode = createNode();
    if (!currNode)
    {
        printf("node not created !");
        return start;
    }
    if (start == NULL)
        return currNode;

    node *temp = start;
    currNode->next = start;
    start = currNode;
    while (temp->next != start)
        temp = temp->next;
    temp->next = currNode;
    printf("\n---------------------------\n");
    printf("NODE INSERTED !\n");
    printf("---------------------------\n");
    return start;
}

node *insertAtEnd(node *start)
{
    node *currNode = createNode();
    if (!currNode)
    {
        printf("node not created !");
        return NULL;
    }
    if (start == NULL)
        return currNode;

    node *temp = start;
    while (temp->next != start)
        temp = temp->next;
    temp->next = currNode;
    currNode->next = start;
    printf("\n---------------------------\n");
    printf("NODE INSERTED !\n");
    printf("---------------------------\n");
    return start;
}

struct node *deleteAtBeg(node *start)
{
    node *temp = start;
    if (start == NULL)
        return NULL;
    if (start->next == start)
    {
        free(start);
        printf("\n---------------------------\n");
        printf("NODE DELETED !\n");
        printf("---------------------------\n");
        return NULL;
    }

    while (temp->next != start)
        temp = temp->next;

    node *del = start;
    start = start->next;
    temp->next = start;
    free(del);
    printf("\n---------------------------\n");
    printf("NODE DELETED !\n");
    printf("---------------------------\n");
    return start;
}

struct node *deleteAtEnd(node *start)
{
    struct node *temp = start;
    struct node *ptr = NULL;
    if (start == NULL)
        return NULL;
    if (start->next == start)
    {
        free(start);
        printf("\n---------------------------\n");
        printf("NODE DELETED !\n");
        printf("---------------------------\n");
        return NULL;
    }
    if (start->next == NULL)
    {
        free(start);
        printf("\n---------------------------\n");
        printf("NODE DELETED !\n");
        printf("---------------------------\n");
        return NULL;
    }
    while (temp->next != start)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = start;
    temp->next = NULL;
    free(temp);
    printf("\n---------------------------\n");
    printf("NODE DELETED !\n");
    printf("---------------------------\n");
    return start;
}

void size(node *start)
{
    if (start == NULL)
    {
        printf("Size of list is: 0\n");
        return;
    }
    int cnt = 0;
    node *temp = start;
    while (temp->next != start)
    {
        cnt++;
        temp = temp->next;
    }
    printf("\n---------------------------\n");
    printf("size of list is : %d\n", ++cnt);
    printf("---------------------------\n");
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
    }
}

void display(node *start)
{
    node *temp = start;
    if (start == NULL)
    {
        printf("no node exist\n");
        return;
    }
    while (temp->next != start)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

node *insertAtposition(node *start)
{
    node *currNode = createNode();
    if (!currNode)
    {
        printf("node not created !");
        return start;
    }
    if (start == NULL)
        return start;

    int pos;
    printf("enter after how many nodes to insert new node : ");
    scanf("%d", &pos);
    if (pos < 1)
        return start;

    node *temp = start;
    int cnt = 1;
    while (temp->next != start && cnt < pos)
    {
        cnt++;
        temp = temp->next;
    }
    currNode->next = temp->next;
    temp->next = currNode;

    printf("\n---------------------------\n");
    printf("NODE INSERTED!\n");
    printf("---------------------------\n");
    return start;
}

node *deleteAtposition(node *start)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    int pos;
    printf("enter th value node to delete : ");
    scanf("%d", &pos);

    if (pos < 1)
        return start;

    node *temp = start->next, *ptr = start;
    int cnt = 2;
    if (pos == 1)
    {
        start = deleteAtBeg(start);
        return start;
    }
    while (temp != start && cnt < pos)
    {
        cnt++;
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = temp->next;
    free(temp);

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
        printf("\n1.insert at beginning\n2.insert at end\n3.insert after a node\n4.delete at begining\n5.delete at end\n6.delete at position\n7.check if empty\n8.check size\n9..display\n10.EXIT\n");
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
            display(start);
            break;
        case 10:
            printf("------------------EXIT-------------------\n");
            exit(0);
        default:
            printf("invlaid choice !\n");
            break;
        }
    }
}