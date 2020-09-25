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

int findMedian(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    int max = INT_MIN, min = INT_MAX;
    for(int i=0;i<row;i++){
        if(max<A[i][col-1])
            max=A[i][col-1];
        if(min>A[i][0])
            min=A[i][0];
    }
    
    int desired=(row*col+1)/2;
    int mid,lessthan;
    while(min<max){
        lessthan=0;
        cout<<"! "<<min<<" - "<<max<<endl;
        mid = min + (max-min)/2;
        for(int i=0;i<row;i++){
            lessthan+= (upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
            cout<<i<<" - "<<lessthan<<endl;
        }
        if(lessthan<desired){
            min=mid+1;
        }
        else{
            max=mid;
        }
    }
    return min;
}
 
int main(){
	int n,m;
	cin>>n>>m;
	vector< std::vector<int> > A(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x; cin>>x;
			A[i].push_back(x);
		}
	}
	cout<<findMedian(A)<<endl;
	return 0;
}
