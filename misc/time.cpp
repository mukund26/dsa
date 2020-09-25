#include<bits/stdc++.h>
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
using namespace std;

string get_date() { 
	char buf[80]; 
	time_t now = time(0); 
	strcpy(buf, ctime(&now)); 
	return string(buf);
} 

int main(int argc, char *argv[]){ 
	string date = get_date(); 
//	printf("date=%s\n", date); 
    cout<<date<<endl;
	return 0; 
}

