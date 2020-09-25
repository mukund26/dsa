// ASCII string has all unique characters without additional data structure

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

bool check(string s){
	if(s.length()>128) return false;
	int checker=0,val;
    for(int i=0;i<s.length();i++){
    	val=s[i]-'a';
        if((checker&(1<<val))>0){
            return false;
        }
        checker|=(1<<val);
    }
	return true;
}

int main(){
    string s;
    cin>>s;
    if(check(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
