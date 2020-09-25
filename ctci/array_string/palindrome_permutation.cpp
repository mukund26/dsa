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
	int n=s.length();
	int a[26]={0};
	for(int i=0;i<n;i++){
		if(tolower(s[i])!=32)
			a[s[i]-'a']++;
	}
	int odd=0;
	for(int i=0;i<26;i++){
		if(a[i]%2==1) odd++;
		if(odd>1) return false;
	}
	return true;
}

int main(){
	string s;
	getline(cin,s);
	if(check(s)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
