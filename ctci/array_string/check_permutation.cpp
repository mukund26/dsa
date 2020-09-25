// check if two string are permutation of each other (ASCII characters small caps)

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

bool check(string s,string s1){
	if(s.length()!=s1.length()){
		return false;
	}
	if(s.length()==0) return true;
	int a[26]={0};
	for(int i=0;i<s.length();i++){
		a[s[i]-'a']++;
		a[s1[i]-'a']--;
	}
	for(int i=0;i<s.length();i++){
		if(a[i]!=0)
			return false;
	}
	return true;
}

int main(){
	string s,s1;
	cin>>s>>s1;
	if(check(s,s1)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
