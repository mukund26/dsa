#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void bubblesort(int a[],int n){
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n-k-1;i++){
			if(a[i]>a[i+1]){
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}	
		}	
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	bubblesort(a,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
