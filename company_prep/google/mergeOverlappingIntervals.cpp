#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

struct Interval{
	int start, end;
}; 
 
int main(){
	int n; cin>>n;
	Interval ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i].start>>ar[i].end;
	}
	auto compare = [](auto a,auto b){ return a.start < b.start; };
	sort(ar,ar+n,compare);
	stack<Interval> s;
	s.push(ar[0]);
	Interval top;
	for(int i=1;i<n;i++){
		top = s.top();

		if(top.end < ar[i].start){
			s.push(ar[i]);
		}

		if( top.end <= ar[i].end && top.end >= ar[i].start ){
			top.end = ar[i].end;
			s.pop();
			s.push(top);
		}	
	}
	vector<Interval> v;
	while(!s.empty()){
		top = s.top();
		v.push_back(top);
		s.pop();
	}
	sort(begin(v),end(v),compare);
	for(auto it:v){
		cout<<it.start<<" "<<it.end<<" ";
	}
	cout<<endl;
	return 0;
}
