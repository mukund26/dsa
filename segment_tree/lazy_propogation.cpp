// Lazy Propogation

#include<bits/stdc++.h>
using namespace std;

const int n=100000;
int t[n*4],lazy[4*n];
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

void updaterange(int node,int start,int end,int l,int r,int value){
	if(lazy[node]!=0){
		t[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}	
		lazy[node]=0;	
	}
	if(start>end || start>r || end<l) return;
	if(l<=start && end<=r){
//		cout<<pos<<" "<<start<<endl;
		t[node]+=(end-start+1)*value;
		if(start!=end){
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}
	//	a[pos]=value;
		return;	
	}
	int mid=(start+end)/2;
	updaterange(2*node,start,mid,l,r,value);
	updaterange(2*node+1,mid+1,end,l,r,value);
	t[node]=t[2*node]+t[2*node+1];
}

int queryrange(int node,int start,int end,int l,int r){
	if(lazy[node]!=0){
		t[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(r<start || l>end)
		return 0;
	else if(l<=start && end<=r)
		return t[node];
	else{
		int mid=(start+end)/2;
		int p1=queryrange(2*node,start,mid,l,r);
		int p2=queryrange(2*node+1,mid+1,end,l,r);
		return p1+p2;
	}
}

int main(){
	cin>>size;
	a=new int[size];
	for(int i=0;i<size;i++) cin>>a[i];
	memset(lazy,0,sizeof(0));
	build(1,0,size);
	updaterange(1,0,size,0,4,1);
	cout<<queryrange(1,0,size,0,5)<<endl;
}
