// this is dp based approach 
// more faster binary_search based approach can be found in binary_search folder
#include<bits/stdc++.h>
using namespace std;

int lis(int a[],int n){
	int dp[n];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(a[i]>a[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
	int maximum=-1;  //to calculate maximum length based element in dp
	for(int i=0;i<n;i++)	
		if(maximum<dp[i])
			maximum=dp[i];
	return maximum+1;
}

int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<lis(a,n)<<endl;
}
