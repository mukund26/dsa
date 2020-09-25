#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector< ii > vii;
typedef vector <int> vi;
#define INF 1000000000

int scan(){
	register int c = getchar_unlocked();
    register int n = 0;
    register int neg=0;
    for( ; ((c<48 || c>57)&&c!='-'); c = getchar_unlocked() );
    if(c=='-') {
    	neg=1; c=getchar_unlocked();
    }
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(neg) return -n;
    else return n;
}

struct node{
	int data;
	node *next;
}*head;


node *insert_beg(node *head,int x){
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		temp->next=head;
		head=temp;
	}
	return head;
}

node *insert_end(node *head,int x){
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL) head=temp;
	else{
		node *temp1=head;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
	}
	return head;
}

node *delete_node(node *head,int pos){
	if(pos==0){
		node *temp=head;
		head=head->next;
		delete temp;
	}
	else{
		node *temp=head;
		while(pos--!=1){
			temp=temp->next;
		}
		node *temp1=temp->next;
		temp->next=temp->next->next;
		delete temp1;
	}
	return head;
}

node *insert_nth(node *head,int loc,int x){
	if(loc==0){
		node *temp=new node;
		temp->data=x;
		temp->next=head;
		head=temp;
	}
	else{
		node *temp=head;
		while(loc--!=1){
			temp=temp->next;
		}
		node *temp1=new node;
		temp1->data=x;
		temp1->next=temp->next;
		temp->next=temp1;
	}	
	return head;
}

node *iterative_rev(node *head){
	node *temp=head,*prev=NULL,*current=new node;
	current=head;
	while(temp!=NULL){
		temp=temp->next;
		current->next=prev;
		prev=current;
		current=temp;
	}
	head=prev;
	return head;
}

void recursion_forward(node *head){
	if(head==NULL) return;
	else{
		cout<<head->data<<" ";
		recursion_forward(head->next);
	}
}

void recursion_rev(node *head){
	if(head==NULL) return;
	else{
		recursion_rev(head->next);
		cout<<head->data<<" ";
	}
}

void perma_rec_rev(node *p){
	if(p->next==NULL){
		head=p;
		return;
	} 
	else{
		perma_rec_rev(p->next);
		node *curr=p->next;
		curr->next=p;
		p->next=NULL;
	}
}

int main(){
	int n=scan();
	//node *head;
	head=NULL;
	while(n--){
		int x=scan();
		if(n%2==0)
		head=insert_beg(head,x);
		else 
		head=insert_end(head,x);	
	}	
	cout<<"Insert at ith place and no";
	n=scan();
	int x=scan();
	head=insert_nth(head,n,x);
	head=delete_node(head,0);
	head=delete_node(head,6);
	head=delete_node(head,4);
	node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"next"<<endl;
	head=iterative_rev(head);
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"all"<<endl;
	recursion_forward(head); cout<<endl;
	recursion_rev(head); cout<<endl;
	perma_rec_rev(head);
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	return 0;
}
