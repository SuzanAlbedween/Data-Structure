// Doubly Linked List
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



 struct Node
 {
	int value;
  struct Node *next;
  struct Node *prev;
 };
 // static pointers
 struct Node *head;
struct Node *tail;
struct Node * Creat_new_Node(int n)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;


}
void Append(int n)
{
	
	struct Node* temp;
	temp= Creat_new_Node(n);

	if(head==NULL)
	{
		head=tail=temp;
		temp->prev=tail;

		
	}

	else
	{
		temp->next=tail->next;
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		
		
	}

}
void  isEmpty()
{
	if(head==NULL)
		printf("yes  is empty\n");
	else
		printf("no isn't\n");

}
void InsertAtHead(int v)
{
	
	struct Node* temp;
	temp= Creat_new_Node(v);
	temp->next=head;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=tail=temp;
	}
	else
	{
		
		temp->next=head;
		head->prev=temp;
		head=temp;
	
	
	
	}
}
void Print()
{
	struct Node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf(" %d",temp->value);
		temp=temp->next;


	}
	printf("\n");

}
int length()
{
	struct Node* temp;
	int c;
	temp=head;
	c=0;
	while(temp)
	{
		c++;
		temp=temp->next;
		
	}
	return c;



}
void Sort()
{
	
	struct Node* first;
	struct Node* last;
	int val;
	first=head;
	last=first;
	while(first->next!=NULL)
	{
		while(last!=NULL)
		{
			if(first->value<last->value)
			{
				val=first->value;
				first->value=last->value;
				last->value=val;

			}
			last=last->next;

		}
		first=first->next;
		last=first->next;


	}
	

}
void Reverse()
{
	struct Node* temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;

	}
	while(temp!=NULL)
	{
		printf(" %d  ",temp->value);
		temp=temp->prev;

	}



}
int main()
{


	head=NULL;
	Append(222);
	Append(3);
	Append(14);
	InsertAtHead(6);
	InsertAtHead(63);
	Append(0);
	Append(1);
	Print();
	printf("the tail is %d\n",tail->value);
	printf("the head is %d\n",head->value);

	printf(" ****%d \n",head->value);
	
	isEmpty();
	printf(" the length is =%d\n",length());
	Sort();
   Print();
	Reverse();
	Print();


	return 0;
}

