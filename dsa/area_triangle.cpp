#include <bits/stdc++.h>
using namespace std;

struct points{
	double x,y;
};

double cross_product(points a, points b){
	return (a.x*b.y-a.y*b.x);
}

double ar(points a,points b, points c){
	return abs(cross_product(a,b)+cross_product(b,c)+cross_product(c,a))/2;
}

int main(){
	points a,b,c;
	cin>>a.x>>a.y;
	cin>>b.x>>b.y;
	cin>>c.x>>c.y;
	double area=ar(a,b,c);
	cout<<area<<endl;
	return 0;
}