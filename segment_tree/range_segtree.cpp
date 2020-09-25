#include<bits/stdc++.h>
using namespace std;
const int n=100000;
int t[n*4];
int *a;
int size;

void build(int node,int start,int end){
	if(start==end) t[node]=a[start];
	else{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		t[node]=t[2*node]+t[2*node+1];
	}
}

void update(int node,int start,int end,int l,int r,int value){
	if(start>end || start>r || end<l)
		return;
	if(start==end){
		t[node]=t[node]-a[start]+value;
		a[start]=value;
	}
	else{
		int mid=(start+end)/2;
		update(2*node,start,mid,l,r,value);
		update(2*node+1,mid+1,end,l,r,value);
		t[node]=t[2*node]+t[2*node+1];
	}
}

int query(int node,int start,int end,int l,int r){
	if(r<start || l>end)
		return 0;
	else if(l<=start && end<=r)
		return t[node];
	else{
		int mid=(start+end)/2;
		int p1=query(2*node,start,mid,l,r);
		int p2=query(2*node+1,mid+1,end,l,r);
		return p1+p2;
	}
}

int main(){
	cin>>size;
	a=new int[size];
	for(int i=0;i<size;i++) cin>>a[i];
	build(1,0,size);
	update(1,0,size,1,2,4);
	cout<<query(1,0,size,0,5)<<endl;
}
