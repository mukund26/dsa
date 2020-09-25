//Tree using class - insert, min, max, delete, height, bfs, dfs

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
	node *left,*right;
};

class tree{
	public:	
		node *root;
		tree(){
			root=NULL;
		}
		node* newnode(int val){
			node *temp=new node;
			temp->data=val;
			temp->left=temp->right=NULL;
			return temp;
		}
		node* insert(node *root,int val){
			if(root==NULL)
				root=newnode(val);
			else if(root->data>=val)
				root->left=insert(root->left,val);
			else 
				root->right=insert(root->right,val);
			return root;
		}
		node *minimum(node *root){
			if(root==NULL) return NULL;
			if(root->left==NULL)
				return root;
			else	
				return minimum(root->left);
		}
		node *maximum(node *root){
			if(root==NULL) return NULL;
			if(root->right==NULL) return root;
			else
				return maximum(root->right);
		}
		void preorder(node *root){
			if(root==NULL) return;
			cout<<root->data<<" ";
			if(root->left!=NULL) preorder(root->left);
			if(root->right!=NULL) preorder(root->right);
		}	
		void inorder(node *root){
			if(root==NULL) return;
			if(root->left!=NULL) inorder(root->left);
			cout<<root->data<<" ";
			if(root->right!=NULL) inorder(root->right);
		}
		void postorder(node *root){
			if(root==NULL) return;
			if(root->left!=NULL) postorder(root->left);
			if(root->right!=NULL) postorder(root->right);
			cout<<root->data<<" ";
		}
		int height(node *root){
			if(root==NULL) return -1;
			else
				return max(height(root->left),height(root->right))+1;
		}
		void bfs(node *root){
			if(root==NULL) return;
			queue<node *> q;
			q.push(root);
			while(!q.empty()){
				node *temp =  q.front();
				cout<<temp->data<<" ";
				if(temp->left!=NULL) q.push(temp->left);
				if(temp->right!=NULL) q.push(temp->right);
				q.pop();
			}
		}
		node *del(node *root,int val){
			if(root==NULL) return root;
			else if(root->data>val) root->left=del(root->left,val);
			else if(root->data<val) root->right=del(root->right,val);
			else{
				if(root->left==NULL&&root->right==NULL){
					delete root;
					root=NULL;
				}
				else if(root->left==NULL){
					node *temp=root;
					root=root->right;
					delete temp;
				}
				else if(root->right==NULL){
					node *temp=root;
					root=root->left;
					delete temp;
				}
				else{
					node *temp=minimum(root->right);
					root->data=temp->data;
					root->right=del(root->right,temp->data);
				}
			}
			return root;
		}	
};

int main(){
	tree t;
	int n;
	cin>>n;
	while(n--){
		int val;
		cin>>val;
		t.root=t.insert(t.root,val);
	}
	cout<<t.minimum(t.root)->data<<" "<<t.maximum(t.root)->data<<endl;
	cout<<"Preorder: "; t.preorder(t.root); cout<<endl;
	cout<<"Inorder: "; t.inorder(t.root); cout<<endl;
	cout<<"Postorder: "; t.postorder(t.root); cout<<endl;
	cout<<t.height(t.root)<<endl;
	cout<<"BFS: "; t.bfs(t.root); cout<<endl;
	return 0;
}
