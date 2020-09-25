#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

int eggdroppingproblem(int n,int k){ //n eggs and k floors
	int dp[n+1][k+1];
	for(int i=0;i<n+1;i++){ 
		dp[i][0]=0;
		dp[i][1]=1;
	}
	for(int i=0;i<k+1;i++){ 
		dp[1][i]=i;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				int res=1+max(dp[i-1][x-1],dp[i][j-x]);
				if(res<dp[i][j])
					dp[i][j]=res;
			}
		}
	}	
	return dp[n][k];
}
 
int main(){
	int n,k;
	cin>>n>>k;
	cout<<eggdroppingproblem(n,k)<<endl;
	return 0;
}
