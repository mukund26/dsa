#include<bits/stdc++.h>
using namespace std;

/*int kadane(int a[],int n){
	int current=a[0],major=a[0];
	for(int i=1;i<n;i++){
		current=max(a[i],current+a[i]);
		major=max(major,current);
	}
	return major;
}*/

int kadane(int a[],int n){
        int csum=0,msum=0;
        for(int i=0;i<n;i++){
            csum+=a[i];
            if(msum<csum) msum=csum;
            if(csum<0) csum=0;
        }
        return msum;
    }
    

int main(){
	int n;
	cin>>n;
	int a[n]; 
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<kadane(a,n)<<endl;
}
