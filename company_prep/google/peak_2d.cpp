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

const int MAX = 100;

int maxincolumn(int a[][MAX],int n,int mid,int &max){
	int max_index;
	for(int i=0;i<n;i++){
		if(max<a[i][mid]){
			max=a[i][mid];
			max_index=i;
		}
	}
	return max_index;
}

int peak_finderutil(int a[][MAX],int n,int m,int mid){
	int max=0;
	int max_index=maxincolumn(a,n,mid,max);

	if(mid==0 || mid==m-1)
		return max;

	else if(max>=a[max_index][mid-1] && max>=a[max_index][mid+1])
		return max;

	else if(mid>0 && max<a[max_index][mid-1])
		return peak_finderutil(a,n,m,mid-mid/2);

	else 
		return peak_finderutil(a,n,m,mid+mid/2);
}

int peak_finder(int a[][MAX],int n,int m){
	return peak_finderutil(a,n,m,m/2);
}
 
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	cout<<peak_finder(a,n,m)<<endl;
	return 0;
}
