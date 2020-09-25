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
    return ((n&(1<<i))!=0);
}

int setbit(int n,int i){
    return n|(1<<i);
}

int clearbit(int n,int i){
    return n&(~(1<<i));
}

int clearmsbbits(int n,int i){
	return n&((1<<i)-1);
}

int clearlsbbits(int n,int i){
	return n&(~(1<<i)+1);
}

int updatebit(int n,int i){
	int v = ~getbit(n,i);
	int mask = (1<<i);
	return (n&~mask) | ((v<<i)&mask);
}

int main(){
    cout<<"enter number on which operation to be perfromed"<<endl;
    int n;
    cin>>n;
    cout<<"enter bit to get"<<endl;
    int i;
    cin>>i;
    cout<<getbit(n,i-1)<<endl;
    cout<<"enter bit to be set"<<endl;
    cin>>i;
    cout<<setbit(n,i-1)<<endl;
    cout<<"enter bit to be cleared"<<endl;
    cin>>i;
    cout<<clearbit(n,i-1)<<endl;
    cout<<"enter pos from where to clear bits towards msb"<<endl;
    cin>>i;
    cout<<clearmsbbits(n,i-1)<<endl;
    cout<<"enter pos from where to clear bits towards lsb"<<endl;
    cin>>i;
    cout<<clearlsbbits(n,i)<<endl;
    cout<<"enter bit to be updated"<<endl;
    cin>>i;
    cout<<updatebit(n,i-1)<<endl;
	return 0;
}
