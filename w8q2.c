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

node *reverse(node *head)
{

    if(head == NULL)    return NULL;
    if(head->next == NULL)  return head;
    node *temp = head;
    node *ptr = NULL;
    while(temp != NULL)
    {
        temp->pre = temp->next;
        temp->next = ptr;
        ptr = temp;
        temp = temp->pre;
    }
    head= ptr;
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
    head = reverse(head);
    printf("Reversed linked list is : \n");
    display(head);
    return 0;
}