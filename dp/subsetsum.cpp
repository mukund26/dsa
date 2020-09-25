#include<bits/stdc++.h>
using namespace std;

/*bool issubset(int a[],int n,int sum){
	if(sum==0) return true;
	if(n==0 && sum!=0) return false;
	if(a[n-1]>sum) return issubset(a,n-1,sum);
	else
		return issubset(a,n-1,sum) || issubset(a,n-1,sum-a[n-1]);
}*/

bool issubset(int a[],int n,int sum){
	bool dp[sum+1][n+1];
	for(int i=0;i<n+1;i++)
		dp[0][i]=true;
	for(int i=1;i<sum+1;i++)	
		dp[i][0]=false;
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i][j-1];
			if(i>=a[j-1])
				dp[i][j]=dp[i][j]||dp[i-a[j-1]][j-1];
		}
	}
	return dp[sum][n];
}

int main(){
	int n;
	cin>>n;
	int a[n];int s=0;
	for(int i=0;i<n;i++){
		cin>>a[i]; s+=a[i];
	}
	if(s%2!=0) cout<<"NO";
	else
		issubset(a,n,s/2)?cout<<"YES":cout<<"NO";
	cout<<endl;
	return 0;
}
