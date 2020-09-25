#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

struct pairsum{
	int first,second,total;
};

bool compare(pairsum a,pairsum b){
    return a.total<b.total;
}

bool notcommon(pairsum a, pairsum b) { 
    if (a.first == b.first || a.first == b.second || 
            a.second == b.first || a.second == b.second) 
        return false; 
    return true; 
} 

void findfourelements(int a[],int n,int s){
	int size = n*(n-1)/2;
	pairsum aux[size];
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			aux[k].first=i;
			aux[k].second=j;
			aux[k].total=a[i]+a[j];
			k++;
		}
	}
	//auto compare=[](auto a,auto b){ return a.total < b.total; }; 
	sort(aux,aux+size,compare);
	int i=0,j=size-1;
	while(i<size && j>=0){
		if(aux[i].total+aux[j].total==s && notcommon(aux[i],aux[j])){
			cout<<a[aux[i].first]<<" "<<a[aux[i].second]<<" "<<a[aux[j].first]<<" "<<a[aux[j].second];
			//cout<<"$";//break;
		}
		else if(aux[i].total+aux[j].total<s)
			i++;
		else
			j--;
	} 
	return;
}
 
int main(){
    int t; cin>>t;
    while(t--){
    	int n; 
    	int s; 
    	cin>>n>>s;
    	int a[n];
    	for(int i=0;i<n;i++) cin>>a[i];
    	findfourelements(a,n,s);
    	cout<<endl;
    }
	return 0;
}
