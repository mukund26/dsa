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

int peak_finder(int a[],int low,int high,int n){
	int mid = (low+high)/2;
	if((mid==0 || a[mid-1]<=a[mid]) && (mid==n-1 || a[mid+1]<=a[mid]))
		return mid;
	else if(mid>0 && a[mid-1]>a[mid])
		return peak_finder(a,low,mid-1,n);
	else
		return peak_finder(a,mid+1,high,n);
}
 
int main(){
	int n;
	n=scan();
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<peak_finder(a,0,n-1,n)<<endl;
	return 0;
}
