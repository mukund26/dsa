#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define BE(x) begin(x),end(x)
#define F first
#define S second
#define SQ(a) (a)*(a)
#define REP(i,a,b) for(int i=a;i<=b;i++)

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
		void boundaryTraversal(node *root);
		void leftboundary(node *root);
		void leaves(node *root);
		void rightboundary(node *root);
};

void tree :: leaves(node *root){
	if(root==NULL){
		return;
	}
	leaves(root->left);
	if(!(root->left) && !(root->right)){
		cout<<root->data<<" ";
	}
	leaves(root->right);
}

void tree :: leftboundary(node *root){
	if(root==NULL){
		return;
	}
	if(root->left){
		cout<<root->data<<" ";
		leftboundary(root->left);
	}
	else if(root->right){
		cout<<root->data<<" ";
		leftboundary(root->right);
	}
}

void tree :: rightboundary(node *root){
	if(root==NULL){
		return;
	}
	if(root->right){
		rightboundary(root->right);
		cout<<root->data<<" ";
	}
	else if(root->left){
		rightboundary(root->left);
		cout<<root->data<<" ";	
	}
}

void tree :: boundaryTraversal(node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	leftboundary(root->left);
	leaves(root->left);
	leaves(root->right);
	rightboundary(root->right);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	tree t;
	int n;
	cin>>n;
	while(n--){
		int val;
		cin>>val;
		t.root=t.insert(t.root,val);
	}
	t.boundaryTraversal(t.root);

	return 0;
}

