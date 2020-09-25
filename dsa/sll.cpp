#include <iostream>
using namespace std;

struct stack
{
	int data;
	stack *next;
};

stack *top=NULL;

void pop()
	{
		if(top==NULL) return;
		cout<<top->data<<" has been popped"<<endl;
		stack *temp=top;
		top=top->next;
		delete temp;
	}

int main()
{
	int i=0;
	stack *s;
	//push
	while(i<5)
	{
		s=new stack;
		s->data=i;
		s->next=top;
		top=s;
		i++;
	}
	s=top;
	while(s!=NULL)
	{
		cout<<s->data<<" ";
		s=s->next;
	}
	pop();
	return 0;
}