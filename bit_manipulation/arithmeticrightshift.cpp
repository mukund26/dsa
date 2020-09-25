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
    int n,count;
    cin>>n>>count;
    for(int i=0;i<count;i++){
        n>>=1;
    }
    cout<<n<<endl;
	return 0;
}
