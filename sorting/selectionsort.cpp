#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void selectionsort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min=a[i],index=i;
		for(int j=i+1;j<n;j++){
			if(min>a[j]){
				min=a[j];
				index=j;
			}
		}
		int temp=a[i];
		a[i]=min;
		a[index]=temp;	
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	selectionsort(a,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
