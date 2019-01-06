#include <iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main(){

// 	int *ptr1 = NULL;
// 	int *ptr2 = NULL;


// 	int x = 5;

// 	ptr1 = &x;
// 	ptr2 = &*ptr1;

// //	cout<<ptr1<<endl;
// 	cout<<*ptr2<<endl;

////////////////////////////////////////////////////
	// int x = 5;
	// int *ptr = NULL;
	// ptr = &x;
	// cout<<*ptr<<endl;
	// cout<<x<<endl;
	// *ptr = 9;
	// cout<<&x<<endl;
	// cout<<*&ptr<<endl;//////both & and * cancle the effect of each other
	// cout<<&*ptr<<endl;
	// cout<<ptr<<endl;
	// cout<<*ptr<<endl;
	// cout<<x<<endl;

///////////////////////////////////////////////////

	int *intptr = new int;
	char * namestr = new char[8];
	//strcpy(namestr,"datastructure");

	delete intptr;
	delete [] namestr;


	int *ptr1 = new int;
	int *ptr2 = new int;

	*ptr2 = 44;
	*ptr1 = *ptr2;
	ptr1 = ptr2;

	delete ptr2; //now ptr2 is dangling pointer due to deallocated 


	return 0;
}