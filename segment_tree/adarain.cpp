#include<bits/stdc++.h>
using namespace std;
const int n=1000000;
int t[n*4],lazy[4*n];
int *a;
int size;


void build(int node,int start,int end){
	if(start==end) t[node]=0;
	else{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		t[node]=t[2*node]+t[2*node+1];
	}
}

void update(int node,int start,int end,int l,int r,int value){
	if(lazy[node]!=0){
		t[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l) return;
	if(start>=l && end<=r){
		t[node]+=(end-start+1)*value;
		if(start!=end){
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}	
		return;
	}
	int mid=(start+end)/2;
	update(2*node,start,mid,l,r,value);
	update(2*node+1,mid+1,end,l,r,value);
	t[node]=t[2*node]+t[2*node+1];
}

int query(int node,int start,int end,int l,int r){
	if(r<start || l>end || start>end)
		return 0;
	if(lazy[node]!=0){
		t[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l<=start && end<=r)
		return t[node];

	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r);
	int p2=query(2*node+1,mid+1,end,l,r);
	return p1+p2;
}

int main(){
	int q,m;
	cin>>q>>m>>size;
//	memset(t,0,sizeof(t));
	memset(lazy,0,sizeof(lazy));
	build(1,0,size);
	while(q--){
		int l,r;
		cin>>l>>r;
		update(1,0,size-1,l,r,1);		
	}
	while(m--){
		int l;	
		cin>>l;
		cout<<query(1,0,size-1,l,l)<<endl;
	}
}
