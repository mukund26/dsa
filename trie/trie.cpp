#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
 
int scan(){
	register int c = getchar_unlocked();
	register int n = 0;
	register int neg=0;
	for( ; ((c<48 || c>57)&&c!='-'); c = getchar_unlocked() );
	if(c=='-') {
		neg=1; c=getchar_unlocked();
	}
	for( ; (c>47 && c<58); c = getchar_unlocked() ){
		n = (n<<1) + (n<<3) +c -48;
	}
	if(neg) return -n;
	else return n;
}

const int child_size = 26;

struct TrieNode{
	TrieNode *child[child_size];
	bool isEndword;
};

TrieNode *getnode(){
	TrieNode *result = new TrieNode;
	result->isEndword = false;
	for(int i=0;i<child_size;i++){
		result->child[i]=NULL;
	}
	return result;
}

void insert(TrieNode *root,string key){
	TrieNode *present = root;
	for(int i=0;i<key.length();i++){
		int index = key[i]-'a';
		if(!present->child[index]){
			present->child[index]=getnode();
		}
		present = present->child[index];
	}
	present->isEndword = true;
}

bool search(TrieNode *root,string key){
	TrieNode *present = root;
	for(int i=0;i<key.length();i++){
		int index = key[i]-'a';
		if(!present->child[index]){
			return false;
		}
		present = present->child[index];
	}
	return (present!=NULL && present->isEndword);
}

void display(TrieNode *root,int level,char st[]){
	if(root->isEndword){
		st[level]='\0';
		string s = st;
		cout<<s<<endl;
	}
	for(int i=0;i<child_size;i++){
		if(root->child[i]){
			st[level]=i+'a';
			display(root->child[i],level+1,st);
		}
	}
}
 
int main(){
	int n; cin>>n;
	vector<string> st(n);
	TrieNode *root = new TrieNode;
	root = getnode();
	for(int i=0;i<n;i++){
		cin>>st[i];
		insert(root,st[i]);
	}
	string s;
	cin>>s;
	cout<<search(root,s)<<endl;
	char sx[20];
	display(root,0,sx);
	return 0;
}
