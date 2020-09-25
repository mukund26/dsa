#include<bits/stdc++.h>
using namespace std;

struct points{
double x,y;
};

double cross_product(points b,points p){
	return (b.x*p.y-b.y*p.x);
}

void direction(points a,points b,points p){
	b.x=b.x-a.x;
	b.y=b.y-a.y;
	p.x=p.x-a.x;
	p.y-=a.y;
	double cros=cross_product(b,p);
	if (cros>0)	cout<<"LEFT"<<endl;
	else if(cros<0) cout<<"RIGHT"<<endl;
	else cout<<"on the line"<<endl;
}

int main(){
	points a,b,p;
	cin>>a.x>>a.y;
	cin>>b.x>>b.y;
	cin>>p.x>>p.y;
	direction(a,b,p);
	return 0;
}
