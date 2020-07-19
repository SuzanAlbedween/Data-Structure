#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head,*last;
struct Node* create_new_node(int value)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}
void push_to_end(int value)
{
    struct Node *temp,*p;
    temp=create_new_node( value);
    if(head==NULL)
    {
    head=temp;
    last=head;
    return;
    }
    while(last->next!= NULL)
    last=last->next;
    last->next=temp;
}
void push_to_head(int value)
{
     struct Node *temp;
     temp=create_new_node( value);
     if(head==NULL)
     {
         head=temp;
         last=head;
     }
     else
     temp->next=head;
     head=temp;
     return;
    
}
struct Node* delete_node(struct Node *head1,int value)
{
    struct Node *temp=head1,* prev;
    prev=head1;
    if(temp!=NULL&& temp->data==value)
    {
        head1=temp->next;
        free(temp);
        return head1;
    }
    while(temp!=NULL && temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }
    
    if(temp==NULL) return NULL;
    prev->next=temp->next;
    free(temp);
    return head1;
}
void print()
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}

int main()
{   int num;
    head=NULL;
    last=NULL;
    push_to_end(1);
    push_to_end(2);
    push_to_end(3);
    push_to_end(4);
    print();
    printf("Enter a number to delete it  \n ");
    scanf("%d",&num);
   head= delete_node(head,num);
    print();

    return 0;
}