// C++ program to find Vertical Sum in 
// a given Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

struct Node{ 
	int data; 
	struct Node *left, *right; 
}; 

Node* newNode(int data){ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Traverses the tree in Inoorder form and 
// populates a hashMap that contains the 
// vertical sum 
void verticalSumUtil(Node *node, int hd, map<int, int> &m){ 
	if(node==NULL) return;

	verticalSumUtil(node->left,hd-1,m);

	m[hd]+=node->data;

	verticalSumUtil(node->right,hd+1,m); 
} 

// Function to find vertical sum 
void verticalSum(Node *root) { 
	map<int,int> m;
	verticalSumUtil(root,0,m);
	for(auto x:m){
		cout<<x.first<<" "<<x.second<<endl;
	}
} 

// Driver program to test above functions 
int main() 
{ 
	// Create binary tree shown in above figure 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->right->left->right = newNode(8); 
	root->right->right->right = newNode(9); 
	
	verticalSum(root); 

	return 0; 
}  
