#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ar=0,r,i=0;
	while(n){
		r=n%2;
		ar=ar+pow(10,i)*r;
		n/=2;
		i++;
	}
	cout<<ar<<endl;
	return 0;
}