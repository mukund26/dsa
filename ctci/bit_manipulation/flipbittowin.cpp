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
	int a;
	cin>>a;
	if(~a==0){
		cout<<"All bits are one"<<endl;
		return 0;
	}
	int curr=0,maxl=1,prev=0;
	while(a!=0){
		if((a&1)==1){ 
			curr++;
			//cout<<curr<<endl;
		}
		else if((a&1)==0){
			prev=((a&2)==0)?0:curr;
			curr=0;
		}
		maxl=max(prev+curr+1,maxl);
		a>>=1;
	}
	cout<<maxl<<endl;
	return 0;
}