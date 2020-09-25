#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define BE(x) begin(x),end(x)
#define F first
#define S second
#define SQ(a) (a)*(a)
#define REP(i,a,b) for(int i=a;i<=b;i++)
 

ii findUnassignedLocation(vector<vector<int>> &grid){
	int i;
	ii p;
	p.F=-1;
	p.S=-1;
	REP(i,0,8){
		REP(j,0,8){
			if(grid[i][j]==0){
				p.F=i;
				p.S=j;
				return p;
			}
		}
	}
	return p;
}

bool inRow(vector<vector<int>> &grid,int r,int num){
	int i;
	REP(i,0,8){
		if(grid[r][i]==num) 
			return true;
	}
	return false;
}

bool inColumn(vector<vector<int>> &grid,int c,int num){
	int i;
	REP(i,0,8){
		if(grid[i][c]==num) 
			return true;
	}
	return false;
}

bool inBox(vector<vector<int>> &grid,auto p,int num){
	p.F-=p.F%3;
	p.S-=p.S%3;
	int i,j;
	REP(i,p.F,p.F+2){
		REP(j,p.S,p.S+2)
			if(grid[i][j]==num) 
				return true;
	}
	return false;
}

bool isSafe(vector<vector<int>> &grid,auto p,int num){
	return !inRow(grid,p.F,num) && !inColumn(grid,p.S,num) && !inBox(grid,p,num);
}

bool solve(vector<vector<int>> &grid){
	auto index = findUnassignedLocation(grid);
	if(index.F==-1 && index.S==-1){
		return true;
	}
	int i;
	REP(i,1,9){
		if(isSafe(grid,index,i)){
			grid[index.F][index.S]=i;
			if(solve(grid))
				return true;
			grid[index.F][index.S]=0;
		}
	}
	return false;
}	

void print(vector<vector<int>> &grid){
	for(auto x:grid){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<"\n";
	}
}
 
int main(){
	vector<vector<int>> grid(9,vector<int>(9,0));
	int i,j;
	REP(i,0,8){
		REP(j,0,8){
			cin>>grid[i][j];
		}
	}
	if(solve(grid)){
		cout<<"Solved\n";
		print(grid);
	}
	else{
		cout<<"Cannot be Solved\n";
	}
	return 0;
}
