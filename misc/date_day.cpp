#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int d,m,y;
		cin>>d>>m>>y;
		int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
		y-=m<3;
		int ans=(y+y/4-y/100+y/400+t[m-1]+d)%7;
		switch(ans){
			case 0:cout<<"Sunday"<<endl; break;
			case 1:cout<<"Monday"<<endl; break;
			case 2:cout<<"Tuesday"<<endl; break;
			case 3:cout<<"Wednesday"<<endl; break;
			case 4:cout<<"Thursday"<<endl; break;
			case 5:cout<<"Friday"<<endl; break;
			case 6:cout<<"Saturday"<<endl; break;
		}
	}
}
