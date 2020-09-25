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

int first,last,x;

void binary_search(int a[],int low,int high,int t){
	if(low>high) return;
	int mid = (low+high)/2;
	if(a[mid]==x){
		if(t==1){
			first=mid;
			binary_search(a,low,mid-1,t);
		}
		else{
			last=mid;
			binary_search(a,mid+1,high,t);
		}
	}
	if(a[mid]<x)
		binary_search(a,mid+1,high,t);
	if(a[mid]>x)
		binary_search(a,low,mid-1,t);
}

int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cin>>x;
	first=last=-1;
	binary_search(a,0,n-1,1);
	if(first!=-1) binary_search(a,0,n-1,2);
	if(first!=-1) cout<<last-first+1<<endl;
	else cout<<"Not Found"<<endl;
	return 0;
}
