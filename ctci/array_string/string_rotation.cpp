#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

bool isSubstring(string s1,string s2){
	if(s1.find(s2)!=string::npos)
		return true;
	else return false;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<isSubstring(s1+s1,s2)<<endl;
	return 0;
}
