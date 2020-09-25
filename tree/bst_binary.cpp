
// O(n^2) solution

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

/*void inorder(Node *root){
	if (root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}*/


bool isless(Node *root,int data){
	if (root==NULL)
		return true;
	if ((root->data<=data)&&isless(root->left,data)&&isless(root->right,data))
		return true;
	else
		return false;
}

bool isgreater(Node *root,int data){
	if (root==NULL)
		return true;
	if ((root->data>data)&&isgreater(root->right,data)&&isgreater(root->left,data))
		return true;
	else
		return false;
}

bool isbst(Node *root){
	if(root==NULL) return true;

	if(isless(root->left,root->data)&&isgreater(root->right,root->data)&&isbst(root->left)&&isbst(root->right))
		return true;
	else 
		return false;
}


Node * insert(Node *root,int v){
	if(root==NULL){
		Node *temp=new Node;
		temp->data=v;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
	}
	else if(v<=root->data){
		root->left=insert(root->left,v);
	}
	else
		root->right=insert(root->right,v);

	return root;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Node *root=NULL;
	int i=5,val;
	while(i--){
		cin>>val;
		if(root==NULL){
			Node *temp=new Node;
			temp->data=val;
			temp->left=NULL;
			temp->right=NULL;
			root=temp;
		}
		else{
			root=insert(root,val);
		}
	}
	//inorder(root);
	if(isbst(root)==true){
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}


