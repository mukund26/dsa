#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

// using other string
/*
string replace(string s){
	string s1;
	for(int i=0;i<s.length();i++){
		if(s[i]!=32){
			s1+=s[i];
		}
		else{
			s1+="%20";
		}
	}
	return s1;
}*/

// without using another string  
string replace(string s){
	int n=s.length(),i=0;
	while(i<n){
		if(s[i]==32){
			s=s.substr(0,i)+"%20"+s.substr(i+1,n);
			i+=3;
		}
		else i++;
	}
	return s;
}

int main(){
	string s;
	getline(cin,s);
	cout<<replace(s)<<endl;
	return 0;
}
