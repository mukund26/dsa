#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
 

int main(){
	int n,s; cin>>n>>s;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	int curr_sum=a[0],start=0;
	for(int i=1;i<=n;i++){
		while(curr_sum>s && start<i-1){
			curr_sum-=a[start];
			start++;
		}
		if(curr_sum==s){
			cout<<start<<" "<<i-1<<endl;
			break;
		}
		if (i<n){
			curr_sum+=a[i];
		}		
	}
	return 0;
}
