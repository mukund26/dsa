#include <bits/stdc++.h>
using namespace std;

int a[100000];

int gcd(int a,int b){
	if (b == 0)
	return a;
	return gcd(b, a%b);
}

int findgcd(int ar[],int n){
	int result=ar[0];
	for(int i=1;i<n;i++)
		result=gcd(ar[i],result);
	return result;
}

int main(){
	int i,r;
	cin>>r;
	for(i=0;i<r;i++)
		cin>>a[i];
	r=findgcd(a,r);
	cout<<r<<endl;
}