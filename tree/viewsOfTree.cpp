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
		void leftView(node *root);
		void leftViewUtil(node *root,int level,int &maxlevel);
		void rightView(node *root);
		void rightViewUtil(node *root,int level,int &maxlevel);
		void topView(node *root);
		void bottomView(node *root);
};

void tree :: leftViewUtil(node *root,int level,int &maxlevel){
	if(root==NULL)
		return;
	if(maxlevel<level){
		cout<<root->data<<" ";
		maxlevel = level;
	}	
	leftViewUtil(root->left,level+1,maxlevel);
	leftViewUtil(root->right,level+1,maxlevel);
}

void tree :: leftView(node *root){
	int maxlevel = 0;
	leftViewUtil(root,1,maxlevel);
}

void tree :: rightViewUtil(node *root,int level,int &maxlevel){
	if(root==NULL)
		return;
	if(maxlevel<level){
		cout<<root->data<<" ";
		maxlevel = level;
	}	
	rightViewUtil(root->right,level+1,maxlevel);
	rightViewUtil(root->left,level+1,maxlevel);
}

void tree :: rightView(node *root){
	int maxlevel = 0;
	rightViewUtil(root,1,maxlevel);
}

void tree :: topView(node *root){
	queue<pair<node *,int>> q;
	q.push({root,0});
	map<int,int> m;
	while(!q.empty()){
		node *t = q.front().first;
		int hd = q.front().second; // horizontal distance
		q.pop();
		if(m.count(hd)==0){
			m[hd] = t->data;
		}
		if(t->left!=NULL){
			q.push({t->left,hd-1});
		}
		if(t->right!=NULL){
			q.push({t->right,hd+1});
		}
	}
	for(auto x:m){
		cout<<x.second<<" ";
	}
	cout<<endl;
}

void tree :: bottomView(node *root){
	queue<pair<node *,int>> q;
	q.push({root,0});
	map<int,int> m;
	while(!q.empty()){
		node *t = q.front().first;
		int hd = q.front().second; // horizontal distance
		q.pop();
		m[hd] = t->data;
		if(t->left!=NULL){
			q.push({t->left,hd-1});
		}
		if(t->right!=NULL){
			q.push({t->right,hd+1});
		}
	}
	for(auto x:m){
		cout<<x.second<<" ";
	}
	cout<<endl;
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
	t.leftView(t.root);
	cout<<endl;
	t.rightView(t.root);
	cout<<endl;
	t.topView(t.root);
	t.bottomView(t.root);
	return 0;
}

