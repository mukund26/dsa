// sliding window concept

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

int largest_subarray(int a[],int n,int k){
	int maxtillnow[n];
	maxtillnow[0]=a[0];
	int cur_sum=a[0];
	for(int i=1;i<n;i++){
		cur_sum=max(a[i],cur_sum+a[i]);
		maxtillnow[i]=cur_sum;
	}
	int s=0;
	for(int i=0;i<k;i++){
		s+=a[i];
	}
	int result = s;
	for(int i=k;i<n;i++){
		s = s + a[i] - a[i-k];
		result=max(result,s);
		result=max(result,s+maxtillnow[i-k]);
	}
	return result;
}
 
int main(){
	int n; cin>>n;
	int k; cin>>k;
	int a[n];
	for(int i=0;i<n;i++) 
		cin>>a[i];
	cout<<largest_subarray(a,n,k)<<endl;
	return 0;
}
