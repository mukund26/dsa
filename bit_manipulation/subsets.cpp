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
 
int main(){
	int n = scan();
	vi v(n);
	for(auto &it:v){
		cin>>it;
	}
	int i,j;
	REP(i,0,(1<<n)-1){
		REP(j,0,n){
			if((i&(1<<j))>0){
				cout<<v[j]<<" ";
			}
		}
		cout<<endl;
	}	
	return 0;
}
