// Count all distinct pair with difference equal to k

#include<bits/stdc++.h>
using namespace std;

int counting(int a[],int n,int k){
	int count=0;
	int l=0,r=0;
	while(r<n){
		if(a[r]-a[l]==k){
			count++; r++; l++;
		//	cout<<a[l]<<" "<<a[r]<<endl;
		}	
		else if(a[r]-a[l]>k) l++;
		else r++;
	}
	return count;
}


int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int count=0;
	sort(a,a+n);
	int l=0,r=n-1;
	for(int i=0;i<n;i++){
		r=n-1;
		l=i;
		while(l<r){
			if(a[r]-a[l]==k){
				//cout<<a[l]<<" "<<a[r]<<endl;
				count++; r--; l++;
			}
			else{
				r--;
			}
		}
	}
	cout<<count<<endl;
	//for(int i=0;i<n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	cout<<counting(a,n,k)<<endl;
}

