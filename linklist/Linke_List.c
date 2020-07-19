<<<<<<< HEAD
# include <stdio.h>
# include <stdlib.h>
struct Node{

	int value;
  struct Node *next;
  

};
struct Node *head;
struct Node *tail;
void InsertAtHead(int n)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=head;
	if(head==NULL)
	head=tail=temp;
	else
		head=temp;
	
}

void InsertAtPosition(int n,int index)
{
	int count=0;
	struct Node *pointer=head;
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=NULL;
	head=tail;
	if(index==0)
	{
		InsertToHead(n);
	}

	else
	{
	
	while(count!=(index-1))
	{
		tail=tail->next;
		
		count+=1;

	}
	temp->next=tail->next;
	tail->next=temp;
	
	}

		
}
void Append(int n)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=NULL;
	head=tail;
	if(head==NULL)
		head=tail=temp;
	else
	{
		temp->next=tail->next;
		tail->next=temp;
		
		
	}

	


	
}
int len()
{int c=0;
struct Node* temp;
temp=head;

while(temp!=NULL)
{
	temp=temp->next;
	c+=1;
}
return c;
}
void Reverse()
{
struct Node* temp;
int val,count;
count=len();
temp=head;


while(temp!=NULL&&count!=1)
{
	val=temp->value;
	Append(val);
	temp=temp->next;
	count-=1;
}



}


void DeleteAtPosition(int x)
{
	struct Node* pos;
	head=tail=pos;
	if(head->value==x)
		head=tail->next;
	while((pos->next)->value!=x)
	{
		pos=pos->next;
	}
	pos=(pos->next)->next;
	tail=pos;


}
void Print()
{
	struct Node *temp=head;
	while(temp!=NULL)
	{
		printf(" %d",temp->value);
		temp=temp->next;


	}
	printf("\n");

}

int main()
{
	head=NULL;
	InsertAtHead(1);
	InsertAtHead(2);
   InsertAtHead(3);
	Print();
	//head=InsertToHead(78);
//	head=InsertToEnd(8);*/
	
	Append(1);
	
	print();
	
	InsertAtPosition(4,3);
	 Reverse();
	 DeleteAtPosition(2);
	print();





	return 0;
}
=======
# include <stdio.h>
# include <stdlib.h>
struct Node{

	int value;
  struct Node *next;
  

};
struct Node *head;
struct Node *tail;
void InsertToHead(int n)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=head;
	if(head==NULL)
	head=tail=temp;
	else
		head=temp;
	
}

void InsertToindex(int n,int index)
{
	int count=0;
	struct Node *pointer=head;
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=NULL;
	head=tail;
	if(index==0)
	{
		InsertToHead(n);
	}

	else
	{
	
	while(count!=(index-1))
	{
		tail=tail->next;
		
		count+=1;

	}
	temp->next=tail->next;
	tail->next=temp;
	
	}

		
}
void InsertToEnd(int n)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->value=n;
	temp->next=NULL;
	head=tail;
	if(head==NULL)
		head=tail=temp;
	else
	{
		temp->next=tail->next;
		tail->next=temp;
		
		
	}

	


	
}
int len()
{int c=0;
struct Node* temp;
temp=head;

while(temp!=NULL)
{
	temp=temp->next;
	c+=1;
}
return c;
}
void revers()
{
struct Node* temp;
int val,count;
count=len();
temp=head;


while(temp!=NULL&&count!=1)
{
	val=temp->value;
	InsertToEnd(val);
	temp=temp->next;
	count-=1;
}



}


void del(int x)
{
	struct Node* pos;
	head=tail=pos;
	if(head->value==x)
		head=tail->next;
	while((pos->next)->value!=x)
	{
		pos=pos->next;
	}
	pos=(pos->next)->next;
	tail=pos;


}
void print()
{
	struct Node *temp=head;
	while(temp!=NULL)
	{
		printf(" %d",temp->value);
		temp=temp->next;


	}
	printf("\n");

}

int main()
{
	head=NULL;
	InsertToHead(1);
	InsertToHead(2);
    InsertToHead(3);
	print();
	//head=InsertToHead(78);
//	head=InsertToEnd(8);*/
	
	/*InsertToEnd(1);
	InsertToEnd(2);
	InsertToEnd(3);
	InsertToEnd(4);
	
	print();
	//revers();
	//print();
	//InsertToindex(4,3);*/
	
//	revers();
	
	del(2);
	print();





	return 0;
}
>>>>>>> 94ae953b8af6a953ec48536d549d2856c2c90c9c
