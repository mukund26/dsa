#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

struct node{
	int data;
	node *next;
};
node *head;

node *insert(int x){
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		node *temp1=head;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
	return head;
}

node *delete_node(int pos){
	if(head==NULL) return NULL;
	if(pos==0){
		node *temp=head;
		head=head->next;
		delete temp;
	}
	else{
		node *temp=head;
		while(pos!=1){
			pos--;
			temp=temp->next;
		}
		node *temp1=temp->next;
		temp->next=temp->next->next;
		delete temp1;
	}
	return head;
}

node *insert_nth(int x,int pos){
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(pos==0){
		temp->next=head;
		head=temp;
	}
	else{
		node *temp1=head;
		while(pos!=1){
			pos--;
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
	return head;
}

void print(){
	node *temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

node *iterative_reversal(){
	node *prev=NULL,*curr=new node;
	if(head==NULL) return NULL;
	node *temp=head;
	curr=head;
	while(temp!=NULL){
		temp=temp->next;
		curr->next=prev;	
		prev=curr;
		curr=temp;
	}
	head=prev;
	return head;
}

int main(){
	int n,x;
	cin>>n;
	head=NULL;
	while(n--){
		cin>>x;
		head=insert(x);
	}
	print();
	delete_node(2);
	print();
	insert_nth(6,3);
	print();
	head=iterative_reversal();
	print();
	return 0;
}
