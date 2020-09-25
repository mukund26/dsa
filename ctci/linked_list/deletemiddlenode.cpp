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

bool removemid(node *n){
	if(n==NULL || n->next==NULL)
		return false;
	node *temp=n->next;
	n->data=temp->data;
	n->next=temp->next;
	return true;
}

int main(){
	int n,x;
	cin>>n;
	head=NULL;
	while(n--){
		cin>>x;
		head=insert(x);
	}
	node *temp=head;
	for(int i=0;i<3;i++){
		temp=temp->next;
	}
	bool found = removemid(temp);
	print();
	return 0;
}
