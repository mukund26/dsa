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
}*head,*head2;

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

node *intersection(node *head,node *head2){
	if()
}

int main(){
	int n,x;
	cin>>n;
	head=NULL;
	int i=0;
	while(i<n){
		cin>>x;
		head=insert(x);
		i++;
	}
	i=0;
	while(i<n){
		cin>>x;
		head2=insert(x);
		i++;
	}
	//head=remove_duplicates(head);
	node *val=returnkthtolast(head,k);
	cout<<val->data<<endl;
	return 0;
}
