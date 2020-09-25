#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

int getbit(int n,int i){
	return (n&(1<<i)!=0);
}

int setbit(int n,int i){
	return n|(1<<i);
}

int clearbit(int n,int i){
	return n&~(1<<i);
}

int clearmsb(int n,int i){
	return n&((1<<i)-1);
}

int clearlsb(int n,int i){
	return n&(~(1<<i)+1);
}

int updatebit(int n,int i){
	int pos = ~getbit(n,i);
	int mask = 1<<i;
	return n&~(1<<i) | (pos<<i)&mask;
}

int main(){
	int n; cin>>n;
	int i; cin>>i;
	cout<<" bit at i: "<<getbit(n,i-1)<<endl;
	cout<<setbit(n,i-1)<<endl;
	cout<<clearbit(n,i-1)<<endl;
	cout<<clearmsb(n,i)<<endl;
	cout<<clearlsb(n,i)<<endl;
	cout<<updatebit(n,i-1)<<endl;
	return 0;
}
