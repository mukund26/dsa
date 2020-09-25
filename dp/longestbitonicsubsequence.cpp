#include<bits/stdc++.h>
using namespace std;

int lis(int a[],int n){
	int dp[n];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(a[i]>a[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
	int lds[n];
	memset(lds,0,sizeof(lds));
	for(int i=n-2;i>=0;i--)
		for(int j=n-1;j>i;j--)
			if(a[i]>a[j] && lds[i]<lds[j]+1)
				lds[i]=lds[j]+1;
//	for(int i=0;i<n;i++) cout<<lds[i]<<" ";
//	cout<<endl;
	int maximum=-1;  //to calculate maximum length based element in dp
	for(int i=0;i<n;i++)	
		if(maximum<dp[i]+lds[i])
			maximum=dp[i]+lds[i];
	return maximum+1;
}

int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<lis(a,n)<<endl;
}
