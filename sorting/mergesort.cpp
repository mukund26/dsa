#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void merge(int l[],int r[],int a[],int n,int m){
	int i=0,j=0,k=0;
	while(i<n && j<m){
		if(l[i]<=r[j]){
			a[k++]=l[i++];
		}
		else 
			a[k++]=r[j++];
	}
	while(i<n)
		a[k++]=l[i++];
	while(j<m)
		a[k++]=r[j++];
}

void mergesort(int a[],int n){
	if(n==1) return;
	int mid=n/2;
	int left[mid],right[n-mid];
	for(int i=0;i<mid;i++)
		left[i]=a[i];
	for(int i=0;i<n-mid;i++)
		right[i]=a[mid+i];
	mergesort(left,mid);
	mergesort(right,n-mid);
	merge(left,right,a,mid,n-mid);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	mergesort(a,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
