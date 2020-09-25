#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

bool onereplace(string s1,string s2){
	bool found=false;
	for(int i=0;i<s1.length();i++){
		if(s1[i]!=s2[i]){
			if(found)
				return false;
			found=true;
		}
	}
	return true;
}

bool oneinsert(string s1,string s2){
	int i=0,j=0;
	while( i<s1.length() && j<s2.length()){
		if(s1[i]!=s2[j]){
			if(i!=j){ 
				return false;
			}
			i++;
		}
		else{
			i++;
			j++;
		}
	}
	return true;
}

bool check(string s1,string s2){
	if(s1.length()==s2.length())
		return onereplace(s1,s2);
	else if(s1.length()==s2.length()+1)
		return oneinsert(s1,s2);
	else if(s1.length()+1==s2.length())
		return oneinsert(s2,s1);
	else
		return false;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<check(s1,s2)<<endl;
	return 0;
}
