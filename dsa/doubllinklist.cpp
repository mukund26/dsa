#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next,*prev;
};

Node *head,*temp1;

void insertattail(int x){
	Node *temp=new Node;
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(!head){
	head=temp;
	temp1=temp;
	}
	else{
	temp1->next=temp;
	temp->prev=temp1;
	temp1=temp;
	}
}

void insertathead(int x){
	Node *temp=new Node;
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(!head){
	head=temp;	
	}
	else{
	temp->next=head;
	head->prev=temp;
	head=temp;
	}
}

int main(){
	head=NULL;
	int i=1;
	while(i<=5){
		if(i%2!=0)
		insertattail(i);
		else
		insertathead(i);
		i++;
	}
	Node *temp=head;
	while(temp!=NULL)
		{cout<<temp->data<<" "; temp=temp->next;}

	cout<<"\nReverse print\n";
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->prev;
	}

	return 0;
}