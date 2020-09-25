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
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int cur_sum=0,start=0;
	int s; cin>>s;
	for(int i=0;i<=n;i++){
		while(cur_sum>s && start<i){
			cur_sum-=a[start];
			start++;
		}
		if(cur_sum==s){
			cout<<start<<" "<<i-1<<endl;
			break;
		}
		if(i<n) cur_sum+=a[i];
	}
	return 0;
}
