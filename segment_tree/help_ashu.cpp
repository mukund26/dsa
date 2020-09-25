#include<bits/stdc++.h>
using namespace std;
const int n=100000;
int t[n*4];
int *a;
int size;

void build(int node,int start,int end){
	if(start==end){
	 	t[node]=(a[start]%2==0)?1:0;
//		cout<<t[node]<<" ";
	}
	else{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		t[node]=t[2*node]+t[2*node+1];
//		cout<<t[node]<<" ";
	}
}

void update(int node,int start,int end,int pos,int value){
	if(start==end){
//		cout<<pos<<" "<<start<<endl;
		t[node]=(value%2==0)?1:0;
		a[pos]=value;
	}
	else{
		int mid=(start+end)/2;
		if(start<=pos&&pos<=mid)
			update(2*node,start,mid,pos,value);
		else
			update(2*node+1,mid+1,end,pos,value);
		t[node]=t[2*node]+t[2*node+1];
//		cout<<t[node]<<" ";
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
	int q;
	cin>>q;
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t==0)
			update(1,0,size,x-1,y);
		if(t==1)
			cout<<query(1,0,size,x-1,y-1)<<endl;
		if(t==2)
			cout<<(y-x+1)-query(1,0,size,x-1,y-1)<<endl;
	}
	return 0;
}
