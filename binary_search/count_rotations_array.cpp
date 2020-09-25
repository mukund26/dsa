#include <bits/stdc++.h>
using namespace std;
int size;

int binarysearch(int a[],int low,int high){
	if(low>high)
		return 0;
	if(low==high){		
		return low;
	}
	int mid=(low+high)/2;
	if(mid<high && a[mid+1]<a[mid]){
		return mid+1;
	}
	if (mid > low && a[mid] < a[mid - 1]){
       return mid;
	}
	if (a[high] > a[mid])
    	return binarysearch(a, low, mid-1);

    return binarysearch(a, mid+1, high);
}


int main(){
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
	int good=binarysearch(a,0,size-1);
	cout<<good<<endl;
	return 0;
}
