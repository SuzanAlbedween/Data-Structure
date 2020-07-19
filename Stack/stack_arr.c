// C program for array implementation of stack 
#include <stdio.h>
#include <stdlib.h>
// A structure to represent a stack 
struct stack{
	int top;
	int size;
	int *arr;
};

struct stack* create_new_stack(int value)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=value;
	s->arr=(int*)malloc(s->size*sizeof(int));
	return s;
}
int isfull(struct stack* s)
{
	return s->size==s->top;
}
int isempty(struct stack* s)
{
	return s->top==-1;
}
void push(struct stack* s,int item)
{
	if(isfull(s))
	{
	    printf("Sorry, the stack is full !!! \n");
		return ;
	}
 s->arr[++(s->top)]=item;
 printf("%d pushed to stack\n", item); 	
}
int pop(struct stack *s)
{
	if(isempty(s))
	{
	     printf("Sorry, the stack is empty !!! \n");
		return -9990;// that means empty stack
	}
	return s->arr[(s->top)--];
	
}
// Function to return the top from stack without removing it 
int peek(struct stack *s)
{
	if(isempty(s))
	{

        printf("Sorry, the stack is empty !!! \n");
		return -9990;// that means empty stack
	}

	return s->arr[s->top];
}
void print(struct stack *s)
{
	for(int i=0;i<s->size;i++)
	printf(" %d  ",s->arr[i]);
	printf("\n");
		
}

int main(void){
 
    struct stack *s1=create_new_stack(4);
    int sum=0;
	push(s1,4);
	push(s1,3);
	push(s1,2);
	push(s1,1);
	print(s1);
	for(int i=0;i<s1->size;i++)
	{
	    if(pop(s1)!=9990)
	    sum+=pop(s1);
	}
	printf("sum is %d\n",sum);

	
	return 0;
    
}
