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
/*
ll modular(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}*/

ll modular(ll a,ll n){
	if(n==0) return 1;
   	else if(n&1){
   		cout<<modular((a*a)%mod,n/2)<<endl;
   		cout<<((a*(modular((a*a)%mod,n/2)))%mod)<<endl;
   		return ((a*(modular((a*a)%mod,n/2)))%mod);
   	} //odd n
    	
   	else 		// even n
    	return modular((a*a)%mod,n/2);
}
 
int main(){
	ll a,n;
	cin>>a>>n;
	cout<<modular(a,n)<<endl;
	return 0;
}
