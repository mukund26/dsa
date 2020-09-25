#include<bits/stdc++.h>
using namespace std;
 
int good;

void binary_search(vector<int> &v,int l,int r,int val){
	int mid=(l+r)/2;
	if(l>r) return;
	if(v[mid]>=val)
		binary_search(v,l,mid-1,val);
	if(v[mid]<val){
		good=mid;
		binary_search(v,mid+1,r,val);
	}
}

int lis(int a[],int n){
	if(n==0) return 0;
	vector<int> tail(n,0);
	int length=1;
	tail[0]=a[0];
	for(int i=1;i<n;i++){
		if(a[i]<tail[0])	
			tail[0]=a[i];
		else if(a[i]>tail[length-1])
			tail[length++]=a[i];
		else{
			good=-1;
			binary_search(tail,0,length-1,a[i]);	
			tail[good+1]=a[i];		
		}
	}
	for(auto x:tail){
		cout<<x<<" ";
	}
	/*
		Replacement of for loop conditions
		good=-1;		
		binary_search(tail,0,,a[i]);
	*/
	return length;
}

int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<lis(a,n)<<endl;
}
