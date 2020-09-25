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
int eggdrops(int n,int k){
	if(k==0 || k==1)
		return k;

	if(n==1) 
		return k;
	
	int res,ans=INT_MAX;
	for(int i=1;i<=k;i++){
		res=max(eggdrops(n-1,i-1),eggdrops(n,k-i));
		if(ans>res){
			ans=res;
		} 
	}

	return ans+1;
}
*/

int eggdrops(int n,int k){
	int dp[n+1][k+1];
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
		dp[i][1]=1;
	}
	for(int i=1;i<=k;i++){
		dp[1][i]=i;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				int res = 1+max(dp[i-1][x-1],dp[i][j-x]);
				if(dp[i][j]>res)
					dp[i][j]=res;
			}
		}
	}
	return dp[n][k];
}

int binomial(int x,int n,int k){
	int sum=0,term=1;
	for(int i=1;i<=n;i++){
		term*=(x-i+1);
		term/=i;
		sum+=term;
	}
	return sum;
}

int mintrials(int n,int k){
	int low = 1, high = k;
	int mid;
	while(low<high){
		mid = (low+high)/2;
		if(binomial(mid,n,k)<k){
			low=mid+1;
		}
		else{
			high=mid;
		}
	}
	return low;
}
 
int main(){
	int n,k; //n eggs k floors;
	cin>>n>>k;
	cout<<eggdrops(n,k)<<endl;
	cout<<mintrials(n,k)<<endl;
	return 0;
}
