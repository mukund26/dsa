#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

int n;
int **arr;

void rotate(){
	int **rot;
	rot=new int*[n];
	int k=n-1,r=0;
	for(int i=0;i<n;i++){
		rot[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		//rot[i]=new int[n];
		r=0;
		for(int j=0;j<n;j++){
			rot[r++][k]=arr[i][j];
		}
		k--;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<rot[i][j]<<" ";
		}
		cout<<endl;
	}
}

void inplace_rotate(){
	int first,last,offset,top;
	for(int l=0;l<n/2;l++){
		first=l;
		last=n-1-l;
		for(int i=first;i<last;i++){
			offset=i-first;
			top = arr[first][i]; //top
			arr[first][i]=arr[last-offset][first]; //left->top
			arr[last-offset][first]=arr[last][last-offset]; //bottom->left
			arr[last][last-offset]=arr[i][last]; //right->bottom
			arr[i][last]=top; //top->right
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	cin>>n;
	arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	rotate();
	return 0;
}
