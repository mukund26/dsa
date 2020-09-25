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
    int a,b;
    cin>>a>>b;
    cout<<__builtin_popcount(a^b)<<endl;
    return 0;
}
