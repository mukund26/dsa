/** O(n) solution using stack 
	to find next greater element for each element in an unsorted array 
 **/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n],b[n],x; 
	memset(b,0,sizeof(b));
	for(int i=0;i<n;i++) cin>>a[i];
	stack<int> s;
	s.push(0);
	int i=1;
	for(;i<n;i++){
		x=s.top();
		s.pop();
		while(a[i]>a[x]){
			b[x]=i;
			if(s.empty()) break;
			x=s.top();
			s.pop();
		}
		if(a[i]<=a[x]){ 
			s.push(x);
		}
		s.push(i);
	}
	while(!s.empty()){
		x=s.top();
		b[x]=-1;
		s.pop();
	}
	for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
}
	
