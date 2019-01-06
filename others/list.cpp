#include <iostream>
using namespace std;

class list{

private:
	int *l1,lenght , i;
public:
	list(){
		cout<<"Enter the size of list\n";
		cin>>lenght;
		l1 = new int [lenght];
		for( i = 0; i < lenght; i++){
			l1[i] = 0; 
		}

	}
	void get(){
		cout<<"Enter the values in list\n";
		for(i = 0; i < lenght; i++ ){
			cout<<" At Postion no = "<<i<<endl;
			cin>>l1[i];
		}
	}

	void show(){
		for (i = 0; i < lenght; i++){
			cout<<" "<<i+1<<". "<<l1[i]<<endl;
		}
	}

	void update(){
		//show();
		cout<<"Enter the Postion you want to update\n";
		int x,var;
		cin>>x;
		cout<<"Enter the updated value\n";
		cin>>var;
		l1[x-1] = var;
		cout<<"value updated\n";
		show();
	}
	void len(){
		cout<<"Size of list ="<<lenght<<endl;
	}
	void remove(){
		cout<<"Enter the value you want to remove\n";
		int x;
		cin>>x;
		for (int i = 0; i < lenght; i++){
			if(l1[i] == x){
				for(int j = i; j < lenght; j++){
					l1[i] = l1[i+1];
				}
				break;
			}
		}
	}
};

int main (){
	list l;
	l.get();
	//l.show();
	//l.update();
	l.len();
	l.remove();
	l.show();
	return 0;
}