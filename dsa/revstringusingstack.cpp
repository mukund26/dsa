#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

void rev(char c[],int n){
	stack <char> s;
	int i;
	for(i=0;i<n;i++)
		s.push(c[i]);

	for(i=0;i<n;i++){
		c[i]=s.top();
		s.pop();
	}
}

int main(){
	char c[50];
	cin.get(c,50);
	rev(c,strlen(c));
	cout<<c;
}
