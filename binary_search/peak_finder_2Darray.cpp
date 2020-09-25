#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

const int MAX=100; 

int maxInColumn(int r,int mid,int a[][MAX],int &max){
	int max_index=0;
	for(int i=0;i<r;i++){
		if(a[i][mid]>max){
			max=a[i][mid];
			max_index=i;
		}
	}
	return max_index;	
}

int peak_finder_until(int r,int c,int a[][MAX],int mid){
	int max=0;
	int max_index=maxInColumn(r,mid,a,max);
	//cout<<max_index<<endl;
	if(mid==0 || mid==c-1){
		return max;
	}

	else if(max>=a[max_index][mid-1] && max>=a[max_index][mid+1])
		return max;

	else if(mid>0 && a[max_index][mid-1]>max)
		return peak_finder_until(r,c,a,mid/2);

	else
		return peak_finder_until(r,c,a,(mid+c)/2);
}

int peak_finder(int r,int c,int a[][MAX]){
	return peak_finder_until(r,c,a,c/2); 
}

int main(){
	int r,c; // r-rows c-columns
	cin>>r>>c;
	int a[r][MAX];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	cout<<peak_finder(r,c,a)<<endl;
	return 0;
}
