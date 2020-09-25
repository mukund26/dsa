#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

void inorder(Node *root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node *find(Node *root,int data){
	if(root==NULL)
		return NULL;
	else
	if(root->data>data)  
		find(root->left,data);
	else
	if(root->data<data)  
		find(root->right,data);
	else
		return root;
}

Node *inordersuccessor(Node *root,int val){
	Node *current=find(root,val); //O(h) for Search h-height of tree 
	//cout<<current->data<<endl; 
	if(current==NULL) return NULL;
	//right subtree
	if(current->right!=NULL){
		current=current->right;
		while(current->left!=NULL) current=current->left;
		return current;
	}

	//no right subtree 
	//deepest ancestor is found out 
	else{
		Node *successor=NULL;
		Node *ancestor=root;
		while(ancestor!=current){
			if(current->data<ancestor->data){
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else
				ancestor=ancestor->right;
		}
		return successor;
	}
}	

Node *insert(Node *root,int val){
	Node *temp=new Node;
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL){
		root=temp;
	}
	else{
		if(root->data>=val)
			root->left=insert(root->left,val);
		else
			root->right=insert(root->right,val);
	}
	return root;
}

int main()
{
	int val,i=11;
	Node *root=NULL;
	while(i--){
		cin>>val;
		root=insert(root,val);
	}
	root=inordersuccessor(root,27);
	if(root!=NULL)
		cout<<root->data<<endl;
	else
		cout<<"NOT FOUND"<<endl;
	//inorder(root);
	return 0;
}