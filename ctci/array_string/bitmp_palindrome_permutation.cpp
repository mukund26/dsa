#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

int createbitvector(string s){
	int bitvector=0,n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]!=32){
			int val=tolower(s[i])-'a';
			if((bitvector&(1<<val))==0){
				bitvector|=(1<<val);
			}
			else{
				bitvector&=~(1<<val);
			}
		}
	}
	return bitvector;
}

int checkforoddbit(int bitvector){
	return ((bitvector&(bitvector-1))==0);
}

bool check(string s){
	int bitvector = createbitvector(s);
	return bitvector==0 || checkforoddbit(bitvector);
}

int main(){
	string s;
	getline(cin,s);
	if(check(s)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
