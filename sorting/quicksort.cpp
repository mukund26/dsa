#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int partition(int a[],int n){
	int pivot=n-1;
	int pindex=0;
	for(int i=0;i<n-1;i++){
		if(a[i]<=a[pivot]){
			int temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;		
		}	
	}
	int t=a[pivot];
	a[pivot]=a[pindex];
	a[pindex]=t;
	return pindex+1;
}

void quicksort(int a[],int start,int end){
	if(start<end){
	 	int pindex=partition(a,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
	return;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	quicksort(a,0,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
