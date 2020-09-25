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
 
set<string> st;

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *ch,int s,int e){
    if(s==e){
        string s = ch;
        st.insert(s);
   }
    else{
        for(int i=s;i<=e;i++){
            swap((ch+i),(ch+s));
            permute(ch,s+1,e);
            swap((ch+i),(ch+s));
        }
    }
}

int main(){
    char *ch = new char;
    cin>>ch;
    permute(ch,0,strlen(ch)-1);
    for(auto x: st){
        cout<<x<<" "; 
    }
    cout<<endl;
    return 0;
}
