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

void printmaxk(int n,int a[],int k){
	deque<int> q(k);
	int i=0;
	for(;i<k;i++){
		while((!q.empty()) && (a[i]>=a[q.back()]))
			q.pop_back();
		q.push_back(i);
	}
	for(;i<n;i++){
		cout<<a[q.front()]<<" ";
		
		while((!q.empty()) && q.front()<=i-k)
			q.pop_front();

		while((!q.empty()) && (a[i]>=a[q.back()]))
			q.pop_back();

		q.push_back(i);
	}
	cout<<a[q.front()]<<endl;
}
 
int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k; cin>>k;
	printmaxk(n,a,k);
	return 0;
}