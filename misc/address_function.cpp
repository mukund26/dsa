//use of %p helps print address of a pointer to void.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector< ii > vii;
typedef vector <int> vi;

int main(){
	int a;
	int *b=&a;
	printf("%p\n",main);  
	printf("%p\n",b); //b is pointer reference to a
	printf("%p\n",(void *)&a);
	return 0;
}
