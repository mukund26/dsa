#include<bits/stdc++.h>
using namespace std;
int start,maxlength;

void print(string s){
	for(int i=start;i<start+maxlength;i++){
		cout<<s[i];
	}
	cout<<endl;
}

int palindrome(string s){
	int n=s.length();
	bool dp[n][n];
	memset(dp,false,sizeof(dp));
	maxlength=1;
	//for palindrome of length 1
	for(int i=0;i<n;i++)
			dp[i][i]=true;
	//for palindrome of length 2
	start=0;
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			start=i;
			dp[i][i+1]=true; 
			maxlength=2;
		}
	}
	//for length greater than 2
	for(int i=3;i<=n;i++){
		for(int j=0;j<n-i+1;j++){
			int k=j+i-1;
			if(s[j]==s[k] && dp[j+1][k-1]){
				dp[j][k]=true;
				if(i>maxlength){
					start=j; 
					maxlength=i;
				}
			}
		}
	}
	return maxlength;	
}


int main(){
	string s;
	cin>>s;
	cout<<palindrome(s)<<endl;
	print(s);
}
