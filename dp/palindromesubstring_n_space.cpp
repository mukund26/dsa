// O(N) Space Complexity

#include<bits/stdc++.h>
using namespace std;
int start,maxlength;

string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
//	cout<<s.substr(l+1,r-l-1)<<endl;
  return s.substr(l+1, r-l-1);
}
 
string palindrome(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}


int main(){
	string s;
	cin>>s;
	cout<<palindrome(s)<<endl;
}
