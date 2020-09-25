#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

typedef long long ll;

void merge(ll l[],ll r[],ll a[],ll n,ll m){
	ll i=0,j=0,k=0;
	ll rl=n-m;
	while(i<m&&j<rl){
		if(l[i]<=r[j]){
			a[k++]=l[i++];
		}
		else 
			a[k++]=r[j++];
	}
	while(i<m)
		a[k++]=l[i++];
	while(j<rl)
		a[k++]=r[j++];
}

void mergesort(ll a[],ll n){
	if(n==1) return;
	ll mid=n/2;
	ll left[mid],right[n-mid];
	for(ll i=0;i<mid;i++)
		left[i]=a[i];
	for(ll i=0;i<n-mid;i++)
		right[i]=a[mid+i];
//	cout<<1<<endl;
	mergesort(left,mid);
	mergesort(right,n-mid);
//	cout<<1<<endl;
	merge(left,right,a,n,mid);
}

int main(){
	int q,k;
	cin>>q>>k;
	map<string,ll> m; 
	ll a;
	string x;
	for(int i=0;i<q;i++){
	 	cin>>x>>a;
		auto it=m.find(x);
		if(it!=m.end()){
			it->second+=a;
		}
		else
			m.insert(make_pair(x,a));
	}
	ll sz=m.size();
	ll arr[sz],total=0,i=0;
	for(auto it=m.begin();it!=m.end();it++){
		arr[i++]=it->second;
	//	total+=it->second;
	}	
	mergesort(arr,sz);
	for(ll i=sz-1;i>=0;i--){
		if(k>0){
			total+=arr[i];
			k--;
		}
		else break;
	}
	cout<<total<<endl;
}
