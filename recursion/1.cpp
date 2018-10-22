#include <iostream>
using namespace std;

//////////////////////////////////

int factorial(int var){
	if (var == 0)
		return 1;
	return (var*factorial(var-1));

}

////////////////////////////////

int sum_natural(int n){
	if (n == 0)
		return 0;
	return n + sum_natural(n -1);
}

//////////////////////////////////

bool isPalRec(char str[], int s, int e) { 
    // If there is only one character
    if (s == e) 
    return true; 
  
    
    if (str[s] != str[e]) 
    return false; 
  
    if(s < e+1){
    	return isPalRec(str, s + 1, e - 1); 
  	}
    return true; 
} 

int main(){
	char array[] = {"1881"};
	cout<<isPalRec(array,0,3);
	cout<<factorial(3);
	cout<<sum_natural(4);
	return 0;
}