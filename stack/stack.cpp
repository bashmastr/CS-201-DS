#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class stack {

private:
	node *top,*temp;
public:
	stack():top(NULL),temp(NULL){}

	void push(int value){
		if(top == NULL){
			top = new node;
			cout<<"First node add\n";
			top->next = NULL;
			top->info = value;
			return;
		}
		temp = new node;
		temp->info = value;
		temp->next = top;
		top = temp;
	}

	void pop(){
		temp = top;
		top = top->next;
		delete temp;
	}
};

int main(){
	stack s;
	s.push(5);
	s.push(3);
	s.push(3);
	s.push(4);

	s.pop();
	s.pop();

	return 0;
}