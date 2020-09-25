#include <bits/stdc++.h>
using namespace std;
int first,last,x;

void binarysearch(int a[],int low,int high,int t){
	int mid=(low+high)/2;
	if(low>high)
		return;
	if(a[mid]==x){
		if(t==1){
			first=mid;
			binarysearch(a,low,mid-1,1);
		}		
		if(t==2){
			last=mid;
			binarysearch(a,mid+1,high,2);	
		}			
	}
	if(a[mid]>x)
		binarysearch(a,low,mid-1,t);
	if(a[mid]<x)
		binarysearch(a,mid+1,high,t);
}


int main(){
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
	sort(a,a+size);
	cin>>x;
	first=last=-1;
	binarysearch(a,0,size-1,1);
	if(first!=-1)
	binarysearch(a,0,size-1,2);
	if(first!=-1&&last!=-1)
	cout<<last-first+1<<endl;
	if(first==-1)
		cout<<0<<endl;
	return 0;
}