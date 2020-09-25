#include <bits/stdc++.h>
using namespace std;

vector <int> func(int n,int m,vector< vector <int> > matrix){
	vector <int> a; 
	int k=0,l=0,i,j;
	while(k<n && l<m){
		for(i=l;i<m;i++)
			a.push_back(matrix[k][i]);
		k++;
		if(!(k<n && l<m))break;

		if(i==m){
		for(j=k;j<n;j++)
		{
			a.push_back(matrix[j][i-1]);
		}
		}
		m--;
		if(!(k<n && l<m))break;
		
		if(j==n)
		{
			for(i=m-1;i>=l;i--)
				a.push_back(matrix[j-1][i]);
		}
		n--;
		if(!(k<n && l<m))break;
		
		for(j=n-1;j>=k;j--)
			a.push_back(matrix[j][l]);

		l++; 
		if(!(k<n && l<m))break;		
	}
	return a;
}

int main(){
	int n,m,i,j;
	cin>>n>>m;
	vector <vector <int> > matrix(n);
	int matrixinput;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			//vector<int> vect;
			cin>>matrixinput;
			matrix[i].push_back(matrixinput);
		}
	vector <int> ar;
	ar=func(n,m,matrix);
	for(i=0;i<ar.size();i++)
		cout<<ar[i]<<" ";
	cout<<endl;
	return 0;
}