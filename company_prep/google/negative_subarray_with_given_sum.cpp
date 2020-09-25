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
	int n,s; cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	cin>>s;
	unordered_map<int,int> m;
	int curr_sum=0;
	int count=0;
	for(int i=0;i<n;i++){
		curr_sum+=a[i];
		if(curr_sum==s){
			count++;
		}
		if(m.find(curr_sum-s)!=m.end()){
			count+=m[curr_sum-s];
		}
		m[curr_sum]++;
	}
	//cout<<m[10]<<endl;
	cout<<count<<endl;
	//if(!found) cout<<-1<<endl;
	return 0;
}
