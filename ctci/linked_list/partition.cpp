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

void print(){
	node *temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

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

node *partition(node *head,int x){
	node *ans=new node;
	ans=NULL;
	while(head!=NULL){
		if((head->data)<x){
			ans=insert_beg(ans,head->data);
		}
		else{
			ans=insert_end(ans,head->data);
		}
		head=head->next;
	}
	return ans;
}

int main(){
	int n,x;
	cin>>n;
	head=NULL;
	while(n--){
		cin>>x;
		head=insert(x);
	}
	cin>>x;
	head=partition(head,x);
	print();
	return 0;
}
