#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *pre, *next;
}node;

node *createNode()
{
    int val;
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)     return NULL;
    printf("Enter value : ");
    scanf("%d",&val);
    newNode->data = val;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}

node *insertAtEnd(node* head)
{
    node *currNode = createNode();
    if(currNode ==  NULL)   return NULL;
    if(head == NULL)
    {
        head = currNode;
        return head;
    }
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = currNode;
    currNode->pre = temp;
    return head;
}

void display(node *head)
{
    if(head ==  NULL){
        printf("no node exist\n");
        return ;
    }
    while(head != NULL)
    {
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

node *removeDuplicate(node *head)
{
    if(head == NULL)    return NULL;
    node *ptr1 = NULL, *ptr2 = NULL, *temp = head;
    while(temp->next != NULL)
    {
        ptr1 = temp->next;
        while(ptr1 != NULL)
        {
            if(ptr1->data == temp->data)
            {
                ptr2 = ptr1->pre;
                ptr2->next = ptr1->next;
                if(ptr1->next != NULL)
                    ptr2->next->pre = ptr2;
                ptr1->pre = NULL;
                ptr1->next = NULL;
                ptr1 = ptr2->next;
            }
            else
                ptr1 = ptr1->next;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    node *head = NULL;
    char ch;
    printf("Enter the values to insert in the end of node : \n");
    do{
        head = insertAtEnd(head);
        printf("do you wnat to continue the insertion ? (Y/N): ");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch == 'y' || ch =='Y');
    head = removeDuplicate(head);
    display(head);
    return 0;
}