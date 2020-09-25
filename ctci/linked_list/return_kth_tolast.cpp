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

node *returnkthtolast(node *head,int k){
	node *p1=head,*p2=head;
	for(int i=0;i<k;i++){
		p1=p1->next;
		if(p1==NULL) return NULL;
	}
	while(p1!=NULL){
		p1=p1->next;
		p2=p2->next;
	}
	return p2;
}

int main(){
	int n,x;
	cin>>n;
	head=NULL;
	while(n--){
		cin>>x;
		head=insert(x);
	}
	int k;
	cin>>k;
	//head=remove_duplicates(head);
	node *val=returnkthtolast(head,k);
	cout<<val->data<<endl;
	return 0;
}
