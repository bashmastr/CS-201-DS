#include <iostream>
using namespace std;

class hash1{

private:
	int index , *array, size;

public:
	hash1(){

		size = 5;
		array = new int[10];
		for (int i = 0; i < 10 ; i++){
			array[i] = -1;
		}	
	}
	~hash1(){
			delete [] array;
		array = NULL;
	}


	void hash_function(){
		int c = 0;
		for (int i  = 0; i < size; i++ ){
			int var = 0;
			cin>>var;

			index  = var % size;

			if(array[index] == -1)
				array[index] = var;
			else{
				for(int j = index; j < size; j++){
					if(array[j] == -1){
						array[j]  = var;
						break;
					}
					cout<<j;
					if(j == size){
						j = 0;
					}
				}
			}
		}
	}


	void print(){

		for (int i = 0 ; i < size; i++){
			cout<< "index : "<<i<<" = "<<array[i]<<endl;
		}

	}

};






int main(){
	hash1 obj;

	obj.hash_function();
	obj.print();

	return 0;
}