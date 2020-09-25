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
}*head;

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

node *remove_duplicates(node *head){
	set<int> s;
	node *temp=head;
	node *prev=head;
	while(temp!=NULL){
		if(s.find(temp->data)!=s.end()){
			prev->next=temp->next;
		}
		else{
			s.insert(temp->data);
			prev=temp;
		}
		temp=temp->next;
	}
	return head;
}

//runner's technique
void remove(node *head){
	node *curr=head,*fast=head;
	while(curr!=NULL){
		fast=curr;
		while(fast->next!=NULL){
			if(fast->next->data==curr->data){
				fast->next=fast->next->next;
			}
			else{
				fast=fast->next;
			}
		}
		curr=curr->next;
	}
}

void print(){
	node *temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
	int n,x;
	cin>>n;
	head=NULL;
	while(n--){
		cin>>x;
		head=insert(x);
	}
	//head=remove_duplicates(head);
	remove(head);
	print();
	return 0;
}
