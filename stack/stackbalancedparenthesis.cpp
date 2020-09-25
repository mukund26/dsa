#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool compare(char a,char b){
	if(a=='['&&b==']'||a=='{'&&b=='}'||a=='('&&b==')')
		return true;
	else
		return false;
}

int main(){
	int t;
	cin>>t;
	cin.ignore(256, '\n');
	//fflush(stdin);
	while(t--){
		bool flag=true;
		char ch[101],c;
		stack <char> s; 
		cin.get(ch,101);
		getchar();
		for(int i=0;i<strlen(ch);i++){
			if(ch[i]=='{'||ch[i]=='['||ch[i]=='('){
				s.push(ch[i]);
			}
			else if(ch[i]=='}'||ch[i]==']'||ch[i]==')'){
				if(s.empty()){
					flag=false;
					break;
				}
				else{
					c=s.top();
					if(compare(c,ch[i])) s.pop();
					else{
						flag=false;
						break;
					}
				}
			}
		}
		if(flag && s.empty()){
			cout<<"balanced"<<endl;
		}
		else
			cout<<"not balanced"<<endl;
	}
	return 0;
}
