#include <bits/stdc++.h>
using namespace std;

string solve(long long n){
	map<int,vector<string>> m;
  m[2].push_back("two");
  m[2].push_back("twenty");
   m[3].push_back("three");
   m[3].push_back("thirty");
   m[4].push_back("four");
   m[4].push_back("fourty");
   m[5].push_back("five");
   m[5].push_back("fifty");
   m[6].push_back("six");
   m[6].push_back("sixty");
   m[7].push_back("seven");
   m[7].push_back("seventy");
   m[8].push_back("eight");
   m[8].push_back("eighty");
   m[9].push_back("nine");
   m[9].push_back("ninety");
  m[10].push_back("ten");	
  m[1].push_back("one");
   m[11].push_back("eleven");
   m[12].push_back("tweleve");
   m[13].push_back("thirteen");
   m[14].push_back("fourteen");
   m[15].push_back("fifteen");
   m[16].push_back("sixteen");
   m[17].push_back("seventeen");
   m[18].push_back("eighteen");
   m[19].push_back("nineteen");
  // m[11].push_back("eleven");
  string numberRep = to_string(n);
  int quotient = numberRep.length()/3; // 2
  int rem = numberRep.length()%3; // 0
  if(rem!=0){
    quotient++;
  }
  
  // 23,456
  vector<string> v;
  v.push_back("hundred");
  v.push_back("thousand");
  v.push_back("million");
  v.push_back("billion"); 
  
  bool flag = false;
  string ans="";
  int i=0;
  if(rem==2){
   if(numberRep[rem-2]=='1'){
        int no = 10;
        no+=(numberRep[rem-1]-'0');
        ans+=m[no][0];
        ans+=' ';
        flag=true;
    }
    else{
      	ans+=m[numberRep[i]-'0'][rem-1];  
        ans+=' ';
    }
    //rem--;
    i++;
  }
  if(rem>=1 && numberRep[i]!='0'){
      //cout<<"yhn aya\n";
      if(!flag){
        if(rem==2)  
      	    ans+=m[numberRep[i]-'0'][rem-2];
      	else
      	    ans+=m[numberRep[i]-'0'][rem-1];
        ans+=' ';
      }
      //cout<<ans<<endl;
    //rem--;
    i++;       
  }
  if(rem>0){
    if(quotient>1){  
  	    ans+=v[quotient-1];
    }
    quotient--;
  }
  int count=0;
  
  for(;i<numberRep.length();i+=3){
      count=0;
      flag=false;
  	if(numberRep[i]!='0'){
  	    ans+=m[numberRep[i]-'0'][0];
        ans+=" hundred ";
        count++;
  	}
    if(numberRep[i+1]!='0'){
        if(numberRep[i+1]=='1'){
            int no = 10;
            no+=(numberRep[i+2]-'0');
            ans+=m[no][0];
            flag=true;
        }
        else{
        	ans+=m[numberRep[i+1]-'0'][1];
            ans+=' ';
        }
      count++;
    }
   	if(numberRep[i+2]!='0' && !flag){
    	ans+=m[numberRep[i+2]-'0'][0];
      ans+=' ';
      count++;
    }
    if(quotient>1){
        if(count>0){
            ans+=v[quotient-1];
            ans+=' ';
        }
        quotient--;
    }
  }
  
  return ans;
}

int main() {
	// your code goes here
	long long n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
