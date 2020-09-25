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
 
int main(){
	double binary;
	cin>>binary;
	string ans;
	ans+='.';
	while(binary>0){
		if(ans.length()>32){
			cout<<"Error"<<endl;
			return 0;
		}
		double val = 2 * binary;
		if(val>=1){
			ans+='1';
			binary = val - 1; 
		}
		else{
			ans+='0';
			binary = val;
		}
	}
	cout<<ans<<endl;
	return 0;
}
