#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

int m,n;

int main(){
	cin>>m>>n;
	int a[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	bool rowhaszero=false,columnhaszero=false;
	for(int i=0;i<m;i++){
		if(a[i][0]==0){
			columnhaszero=true;
			break;
		}
	}
	for(int j=0;j<n;j++){
		if(a[0][j]==0){
			rowhaszero=true;
			break;
		}
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(a[i][j]==0){
				a[i][0]=0;
				a[0][j]=0;
			}
		}
	}
	for(int j=1;j<n;j++){
		if(a[0][j]==0){
			for(int i=1;i<m;i++){
				a[i][j]=0;
			}
		}
	}
	for(int i=1;i<m;i++){
		if(a[i][0]==0){
			//flag=true;
			for(int j=1;j<n;j++){
				a[i][j]=0;
			}
		}
	}
	if(rowhaszero){
		for(int j=0;j<n;j++){
			a[0][j]=0;
		}
	}
	if(columnhaszero){
		for(int i=0;i<m;i++){
			a[i][0]=0;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
