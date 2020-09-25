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

bool palindrome(node *head){
	node *slow  = head, *fast = head;
	stack<int> s;
	while(fast!=NULL && fast->next!=NULL){
		s.push(slow->data);
		slow=slow->next;
		fast=fast->next->next;
	}

	if(fast!=NULL){
		slow=slow->next;
	}

	while(slow!=NULL){
		//cout<<slow->data<<" ";
		int top = s.top();
		s.pop();
		if(top!=slow->data){
			return false;
		} 
		slow=slow->next;
	}
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
	//print();
	cout<<palindrome(head)<<endl;
	return 0;
}
