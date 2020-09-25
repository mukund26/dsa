/*	
	Prints all permutation of a string in lexicographical order
*/
#include<bits/stdc++.h>
using namespace std;

set<string> st;

void permute(string ch,int s,int e){
	if(s==e){
		st.insert(ch);
	}
	else{
    	for(int i=s;i<=e;i++){
	    	swap((ch[s]),(ch[i]));
	    	permute(ch,s+1,e);
	    	swap((ch[s]),(ch[i])); //backtrack  -- to return to original configuration
    	}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string ch;
		cin>>ch;
		permute(ch,0,ch.length()-1);
		for(auto it:st)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
