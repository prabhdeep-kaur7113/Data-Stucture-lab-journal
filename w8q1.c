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
    printf("Enter the value : ");
    scanf("%d",&val);
    newNode->data = val;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}

node* insertAtFront(node *head)
{
    node *currNode = createNode();
    if(currNode ==  NULL)   return NULL;
    if(head == NULL)
    {
        head = currNode;
        return head;
    }
    node *temp = head;
    currNode->next = head;
    temp->pre = currNode;
    head = currNode;
    return head;
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

node *deleteFront(node* head)
{
    if(head == NULL)    return NULL;
    head = head->next;
    head->pre = NULL;
    return head;
}

node *deleteAtEnd(node *head)
{
    if(head == NULL)    return NULL;
    node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
    return head;
}

int size(node *head)
{
    int size =0;
    while(head !=NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}

int isEmpty(node *head)
{
    if(head == NULL)
        return 1;
    return 0;
}

void findMiddle(node *head)
{
    if(head ==  NULL){
        printf("no node exist\n");
        return;
    }
    node *temp1 = head;
    node *temp2 = head;
    while(temp2 != NULL && temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    printf("--------------Middle element is :: %d------------\n",temp1->data);
}

node *insertImmediate(node *head, int k)
{
    int i =1;
    node *currNode = createNode();
    node *temp = head;
    while(temp->next != NULL && i<k-1)
    {
        i++;
        temp = temp->next;
    }
    currNode->next = temp->next;
    currNode->pre = temp;
    temp->next = currNode;
    return head;
}

node *deleteIntermediate(node *head, int k)
{
    int i =1;
    node *temp = head;
    if(k > size(head))
    {
        printf("invalid node enterred to delle\n");
        return head;
    }
    while(temp->next != NULL && i<k-1)
    {
        i++;
        temp = temp->next;
    }
    node *ptr = temp->next;
    temp->next = ptr->next;
    ptr->next->pre = temp;
    ptr->next= NULL;
    ptr->pre = NULL;
    free(ptr); 
    return head;
}

int main()
{
    int ch, val;
    node *head = NULL;
    while(1)
    {
        printf("\n1.To insert at front\t2.toinsert at end\t3.to delete at front\t4.to delete at end\t5.to check size\t6.is empty\t7.find middle\t8.to add intermediate vlaue\t9.to delete intermediate\t10.to display the values\t11.to EXIT\n");
        printf("\nEnter your choice :: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            head = insertAtFront(head);
            printf("====NODE INSERTED====\n");
            break;
        case 2 : 
                head = insertAtEnd(head);
            printf("====NODE INSERTED====\n");
                break;
        case 3 : 
                head = deleteFront(head);
            printf("====NODE DELETED====\n");

                break;
        case 4 : 
                head = deleteAtEnd(head);
            printf("====NODE DELETED====\n");

                break;
        case 5 : printf("----------size of the linked list is : %d-----------\n",size(head));
                break;
        case 6 : if(isEmpty(head))
                    printf("----Empty-----\n");
                else    
                    printf("---------not empty----------\n");
                break;
        case 7 : findMiddle(head);
                break;
        case 8 : printf("Enter the postion to add intermediate : \t");
                scanf("%d",&val);
                insertImmediate(head, val);
                printf("====NODE INSERTED====\n");
                break;
        case 9 : printf("Enter the position to delete intermeidate : \t");
                 scanf("%d",&val);
                 deleteIntermediate(head, val);
                printf("====NODE DELETED====\n");
                break;
        case 10 : printf("-------------------------------\n");
                  display(head);
                  printf("-------------------------------\n");
                break;
        case 11 : printf("\n***********EXIT***************\n");
                exit(0);
        default:printf("INVALID CHOICE ! CHOOSE AGAIN\n");
            break;
        }
    }
}