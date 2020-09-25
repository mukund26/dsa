/*
	Add two numbers using printf
*/

// printf() returns int as it gives result of number of characters printed
// printf("%*d",width,num) * specifies width on screen

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
#define pb push_back
 
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

int add(int x,int y){
    return printf("%*c%*c",x,' ',y,' ');
}

int main(){
    int a=2,b=3;
    printf("%*c",a,' ');
    printf("%d",add(a,b));
	return 0;
}
