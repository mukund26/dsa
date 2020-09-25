#include <bits/stdc++.h>
using namespace std;

struct Node{
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

bool isbst(Node *root,int minv,int maxv){
	if(root==NULL) return true;

	if(root->data>minv&&root->data<maxv&&isbst(root->left,minv,root->data)&&isbst(root->right,root->data,maxv))
		return true;
	else 
		return false;
}

bool isBST(Node* root) {
    static struct Node *prev = NULL; 
    // traverse the tree in inorder fashion and keep track of prev node 
    if (root) 
    { 
        if (!isBST(root->left)) 
          return false; 
        
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data){ 
          cout<<root->data<<" "<<prev->data<<endl;
          return false; 
  		}
        prev = root; 
        return isBST(root->right); 
    } 
  
    return true;  
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
	Node *prev = NULL;
	if(isBST(root)){
		cout<<"yo"<<endl;
	}
	//inorder(root);
	//cout<<INT_MIN<<endl;
	if(isbst(root,INT_MIN,INT_MAX)){
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}


// O(n) solution