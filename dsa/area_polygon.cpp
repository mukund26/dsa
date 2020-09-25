#include <bits/stdc++.h>
using namespace std;

struct points{
	double x,y;
};

double cross_product(points a, points b){
	return (a.x*b.y-a.y*b.x);
}

double ar(points a[],int n){
	double s=0.0;
	for(int i=0;i<n;i++){
		s+=cross_product(a[i],a[(i+1)%n]);
	}
	return abs(s)/2.0;
}

int main()
{
	int n;
	cin>>n;
	points a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
	}
	double area=ar(a,n);
	cout<<area<<endl;
	return 0;
}