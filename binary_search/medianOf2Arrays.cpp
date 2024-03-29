#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
//increase stack size
#pragma comment(linker, "/STACK:16777216")
 
ll mxm() {return LLONG_MIN;}
template<typename... Args>
ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }
 
ll mnm() {return LLONG_MAX;}
template<typename... Args>
ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }
 
template<class T> ostream& operator<<(ostream& os,vector<T> V){
	os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream& os,pair<L,R> P){
	return os<<"("<<P.first<<","<<P.second<<")";
}
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template <typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
	const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif
 
#define ld long double
#define pll pair<ll,ll>
#define ii pair<int,int>
#define vll vector<ll>
#define vii vector<ii>
#define vi vector<int>
#define vpll vector<pll>
#define vld vector<ld>
#define vvld vector<vld>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvpll vector<vpll>
#define vvii vector<vii>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x)	x.begin(),x.end()
 
const int mod=1e9+7;
// 128 bit: __int128
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}
 
struct compare{
	bool operator() (const int &a,const int &b) const{
		return a>b;
	}
};

double solve(vi a,vi b,int n,int m){
	if(n>m){
		return solve(b,a,m,n);
	}
	int sz = (n+m+1)/2;
	int maxleftx,maxlefty,minrightx,minrighty,midx,midy;
	int l=0,h=n;
	while(l<=h){
		midx = (l+h)/2;
		midy = sz-midx;
		maxleftx = (midx==0)?INT_MIN:a[midx-1];
		minrightx = (midx==n)?INT_MAX:a[midx];
		maxlefty = (midy==0)?INT_MIN:b[midy-1];
		minrighty = (midy==m)?INT_MAX:b[midy];

		if(maxleftx<=minrighty && maxlefty<=minrightx){
			if((n+m)&1){
				return (double)(max(maxlefty,maxleftx));
			}
			else{
				return ((double)(max(maxleftx,maxlefty))+(double)(min(minrightx,minrighty)))/2;
			}
		}

		else if(maxleftx>minrighty){
			h=midx-1;
		}

		else{
			l=midx+1;
		}
	}
	return 0.0;
} 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	vi a(n,0),b(m,0);
	for(auto &it:a){
		cin>>it;
	}
	for(auto &it:b){
		cin>>it;
	}
	sort(all(a));
	sort(all(b));
	cout<<solve(a,b,n,m)<<endl;
    return 0;
}
