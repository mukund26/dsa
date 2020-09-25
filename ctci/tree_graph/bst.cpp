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
	int val;
	node *left,*right;
}

class tree{
	public:
		node *root;
		tree(){
			root=NULL;
		}
		node *newnode(int x){
			node *temp=new node;
			temp->val=x;
			temp->left=temp->right=NULL;
			return temp;
		}
		node *insert(node *root,int x){
			if(root==NULL){
				root=newnode(x);
			}
			else if(root->val>=x){
				root->left=insert(root->left,x);
			}	
			else{
				root->right=insert(root->right,x);
			}
			return root;
		}
		node *minimum(node *root){
			if(root==NULL) return root;
			if(root->left==NULL) return root;
			else
				return minimum(root->left);
		}
}

int main(){

	return 0;
}
