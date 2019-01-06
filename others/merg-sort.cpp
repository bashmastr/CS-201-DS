#include <iostream>
using namespace std;

void merg_sort_divide(int *array, int left , int right){
	cout<<"yes\n";

	int mid;
	mid = (left + (right - left))/2;

	if(left < right){
		cout<<array[left]<<" "<<array[right]<<endl;
		merg_sort_divide(array,left,mid);
		merg_sort_divide(array,mid+1,right);
	}

}


int main(){

	int array[10] = {1,8,7,2};

	int right = 3;

	int left = 0;
	
	int mid = (right + left)/ 2;

	merg_sort_divide(array,left,3);


	return 0;
}