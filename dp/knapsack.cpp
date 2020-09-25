#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
 
int scan(){
	register int c = getchar_unlocked();
	register int n = 0;
	register int neg=0;
	for( ; ((c<48 || c>57)&&c!='-'); c = getchar_unlocked() );
	if(c=='-') {
		neg=1; c=getchar_unlocked();
	}
	for( ; (c>47 && c<58); c = getchar_unlocked() ){
		n = (n<<1) + (n<<3) +c -48;
	}
	if(neg) return -n;
	else return n;
}

int knapsack(int val[],int wt[],int W,int n){
	int k[n+1][W+1];
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0 || w==0){
				k[i][w]=0;
			}
			else if(wt[i-1]<=w){
				k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			}
			else{
				k[i][w]=k[i-1][w];
			}
		}
	}
	return k[n][W];
}
 
int main(){
	int n; cin>>n;
	int val[n],wt[n];
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	int W;
	cin>>W;
	cout<<knapsack(val,wt,W,n)<<endl;
	return 0;
}
