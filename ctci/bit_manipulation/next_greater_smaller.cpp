#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
 
int scan(){
	register int c = getchar_unlocked();
	register int n = 0;
	register int neg=0;
	for( ; ((c<48 || c>57)&&c!='-'); c = getchar_unlocked() );
	if(c=='-') {
		neg=1; c=getchar_unlocked();
	}
	for( ; (c>47 && c<58); c = getchar_unlocked() ){
		n = (n<<1) + (n<<3) +c -48;
	}
	if(neg) return -n;
	else return n;
}

int next_greater(int n){
	int c1=0,c0=0,c=n;
	while(((c&1)==0)&&(c!=0)){
		c0++;
		c>>=1;
	}
	while((c&1)==1){
		c1++;
		c>>=1;
	}
	if(c0+c1==31 || c0+c1==0) return -1;
	int p = c0+c1;
	n|=(1<<p);
	n&=~((1<<p)-1);
	n|=((1<<(c1-1))-1);
	return n;
}

int next_smaller(int n){
	int c1=0,c0=0,c=n;
	while(c&1==1){
		c1++;
		c>>=1;
	}
	if(c==0) return -1;
	while(((c&1)==0)&&(c!=0)){
		c0++;
		c>>=1;
	}
	int p = c0+c1;
	n&=((1<<p)-1);
	int mask = (1<<(c1+1)-1);
	n|=(mask<<(c0-1));
	return n;
}
 
int main(){
	int n;
	cin>>n;
	cout<<next_greater(n)<<endl;
	cout<<next_smaller(n)<<endl;
	return 0;
}
