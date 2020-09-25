#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,i;
	cin>>t;
	string ans;
	while(t--){
		cin>>n;
		ans="prime";
		if(n==1){
			cout<<"Not prime"<<endl;
			continue;
		}
		for(i=2;i<=sqrt(n);i++){
			if(n%i==0){
				ans="not prime";
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}