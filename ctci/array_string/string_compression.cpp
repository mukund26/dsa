#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

string compressed(string s){
	if(s.length()==1) return s;
	int count=1;
	char last=s[0];
	//cout<<last<<endl;
	string ans;
	for(int i=1;i<s.length();i++){
		if(s[i]==last){
			count++;
		}
		else{
			ans+=(char)last;
			ans+=to_string(count);
			last=s[i];
			count=1;
		}
	}
	if(count){
		ans+=last; 
		ans+=to_string(count);
	}
	if(ans.length()>s.length()) return s;
	return ans;
}

int main(){
	string s;
	cin>>s;
	cout<<compressed(s)<<endl;
	return 0;
}
