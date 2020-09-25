#include <string.h> 
#include <iostream> 

using namespace std; 


int main(int argc, char *argv[]) 
{ 
	char abc[27]; 
	char *ptr = abc; 
	strcpy(abc, "abcdefgxyz"); 
	/* 
	* What are the types and values of expressions: 
	* 

	* 1. abc 
	* 2. *abc 
	* 3. abc[2] 
	* 4. &abc[3] 
	* 5. abc+4 
	* 6. *(abc+5) + 2 
	* 7. abc[10] 
	* 8. abc[12] 
	* 9. &ptr// ??? a = &ptr; 
	*/
    cout<<abc<<endl;
    cout<<*abc<<endl;
    cout<<abc[2]<<endl;
    cout<<&abc[3]<<endl;
    cout<<abc+4<<endl;
    cout<<*(abc+5) + 2 <<endl;
    cout<<&ptr<<endl;
	cout << &abc << endl; 
	
	
	return 0; 
} 

