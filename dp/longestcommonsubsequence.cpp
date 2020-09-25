// Find length of LCS(S for Subsequence) as well as print it

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int n,int m){
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}	
	}
	return dp[n][m];
}

string print_lcs(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int index = dp[n][m],i=n,j=m;
    char ch[index+1];
    ch[index]=0;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            ch[index-1]=s1[i-1];
            i--; j--; index--;
        }
        else{
            if(dp[i-1][j]>=dp[i][j-1]) i--;
            else j--;
        }
    }
//  cout<<ch<<endl;
    return string(ch);
}

int main(){
	int n,m; cin>>n>>m;
	string s1,s2;
	cin>>s1; 
	cin>>s2;
	cout<<lcs(s1,s2,n,m)<<endl;
    cout<<print_lcs(s1,s2,n,m)<<endl;
	return 0;
}
