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

int binary_search(int a[],int low,int high){
	if(low>high) return 0;
	if(high==low) return low;
	int mid = (low+high)/2;
	if(mid<high && a[mid+1]<a[mid])
		return mid+1;
	if(mid>low && a[mid-1]>a[mid])
		return mid;
	if(a[mid]<a[high])
		return binary_search(a,low,mid-1);
	return binary_search(a,mid+1,high);
}

int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<binary_search(a,0,n-1)<<endl;
	return 0;
}
