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

bool getpath(int r,int c,vii &path,set< ii > &failedpoints){
	if(r<0 || c<0){
		return false;
	}
	ii p;
	p=mp(r,c);

	if(failedpoints.find(p)!=failedpoints.end()){
		return false;
	}

	bool isatorigin = ((r==0) && (c==0));

	if(isatorigin || getpath(r-1,c,path,failedpoints) || getpath(r,c-1,path,failedpoints)){
		path.push_back(p);
		return true;
	}

	failedpoints.insert(p);
	return false;
}
 
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}*/
	vii path;
	set < ii > failedpoints;
	bool ans=getpath(n-1,m-1,path,failedpoints);
	for(auto x:path){
		cout<<x.first<<" "<<x.second<<endl;
	}
	return 0;
}
