// Doubly Circual Linked List
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
int Length=0;
struct Node * Creat_new_Node(int n)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=NULL;
	temp->prev=NULL;
	Length++;
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
		tail->next=head;
		head->prev=temp;
		tail=head;
		
		
		
	}
}
void Search(int x)
{
	struct Node* temp;
	int flage,count;
	flage=0;
	count=Length;
	temp=head;
	while(count>0&&flage!=1)
	{
		if(temp->value==x)
			flage=1;
		count--;
		temp=temp->next;

	}
	if(flage ==1)
		printf(" yes the value in the list\n");
	else
		printf(" NO the value isn't in the list\n");



}
void Print()
{
	struct Node *temp;
	int c;
	c=Length;
	temp=head;
	while(c>0)
	{
		printf(" %d",temp->value);
		c--;


	}
	printf("\n");

}
void Update(int oldval,int newval)
{
	struct Node *temp;
	int c;
	c=Length;
	temp=head;
	while(c>0)
	{
		if(temp->value==oldval)
		{
			temp->value=newval;
			break;
		}
		c--;
		temp=temp->next;


	}


}
void DelteNodeAtPosition(int position)
{
	struct Node *temp;
	int c;
	c=Length;
	temp=head;
	if(position==1)
	{
		temp=temp->next;
		head=temp;
	}

	else{
	while(c==position)
	{
		c--;
		temp=temp->next;
	}
	temp->prev=temp->next;
	tail=temp;
	}


}

	int main()
	{
		head=NULL;
		Append(8);
		Append(9);
		Append(1);
		Append(2);
		//printf("the head is =%d \n",head->value);
		//printf("the tail is =%d \n",tail->value);
		Print();
		//Search(5);
		DelteNodeAtPosition(1);
		Print();


return 0;
		
	}



