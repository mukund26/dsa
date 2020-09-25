//Split a array into two subsets of equal sum -- a DP based approach also exists
#include<bits/stdc++.h>
using namespace std;

bool issubset(int a[],int n,int sum){
	if(sum==0) return true;
	else if(n==0&&sum!=0) return false;
	else if(a[n]>sum)
		return issubset(a,n-1,sum);
	else 
		return issubset(a,n-1,sum)||issubset(a,n-1,sum-a[n]);
}

int main(){
	int n;
	cin>>n;
	int a[n],su=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		su+=a[i];
	}
	if(su%2!=0) cout<<"no"<<endl;
	else
		issubset(a,n-1,su/2)?cout<<"yes":cout<<"no";
	cout<<endl;
	return 0;
}
