#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

void update(int a[],vi &v){
    a[3]+=10;
    v[1]=v[0];
}

int main(){
    string s;
    getline(cin,s);
    cout<<s;
    int a[5]={1,2,3,4,5};
    for(int i=0;i<5;i++) cout<<a[i]<<" ";
    cout<<endl;
    vi v;
    v.push_back(1); v.push_back(2);
    update(a,v);
    cout<<v[0]<<" "<<v[1]<<endl;
    for(int i=0;i<5;i++) cout<<a[i]<<" ";
	return 0;
}
