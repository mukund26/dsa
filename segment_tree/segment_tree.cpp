#include<bits/stdc++.h>
using namespace std;
const int n=100000;
int t[n*4];
int *a;
int size;

void build(int node,int start,int end){
    if(start==end) {t[node]=a[start];return;}
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    t[node]=t[2*node]+t[2*node+1];// logic change
}

void update(int node,int start,int end,int pos,int value){
    if(start==end){
        t[node]=value;
        return;
    }
    int mid=(start+end)/2;
    if(pos<=mid) update(2*node,start,mid,pos,value);
    else update(2*node+1,mid+1,end,pos,value);
    t[node]=t[2*node]+t[2*node+1];
}

int query(int node,int start,int end,int l,int r){
    if(l==start && end==r) return t[node];
    int mid=(start+end)/2;
    if(r<=mid) return query(2*node,start,mid,l,mid);
    if(l>mid) return query(2*node+1,mid+1,end,mid+1,r);
    int p1=query(2*node,start,mid,l,mid);
    int p2=query(2*node+1,mid+1,end,mid+1,r);
    return p1+p2;
}

int main(){
    cin>>size;
    a=new int[size];
    for(int i=0;i<size;i++) cin>>a[i];
    build(1,0,size-1);
    update(1,0,size-1,2,4);
    cout<<query(1,0,size-1,0,4)<<endl;
}
