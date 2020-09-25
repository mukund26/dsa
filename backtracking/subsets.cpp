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

void subsetsUtil(vi &v,vector<vector<int>> &ans,vector<int> &subset,int pos,int n){
	ans.push_back(subset);
	for(int i=pos;i<n;i++){
		subset.PB(v[i]);
		subsetsUtil(v,ans,subset,i+1,n);
		subset.pop_back();
	}
	return;
}

void cal(vi &v,int n,int pos,vector<int> &subset){
	if(pos==n){
		for(auto x:subset){
			cout<<x<<" ";
		}
		cout<<endl;
	}else{
		cal(v,n,pos+1,subset);
		subset.PB(v[pos]);
		cal(v,n,pos+1,subset);
		subset.pop_back();
	}
}

 
int main(){
	int n = scan();
	vi v(n);
	for(auto &it:v){
		cin>>it;
	}
	vector<vector<int>> ans;
	vector<int> subset;
	int pos=0;
	subsetsUtil(v,ans,subset,pos,n);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	subset.erase(BE(subset));
	pos=0;
	cal(v,n,pos,subset);
	return 0;
}
