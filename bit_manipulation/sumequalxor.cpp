// a^x = a+x 
// find number of x's smaller than equal to a for whom above condition holds


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

int solve(int n){
	int ans=0;
	while(n){
		if((n&1)==0) ans++;
		n>>=1;
	}
	return 1<<ans;
}
 
int main(){
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
