#include <iostream>
using namespace std;

struct node {
	int info;
	node *next;
};

class singly_linklist{

private:
	node *head , *temp,*temp1;

public:
	singly_linklist():head(NULL),temp(NULL){}

////////////add node at the end//////////

	void append(int value){
		if(head == NULL){
			cout<<"Add first member\n";
			head = new node;
			head->info = value;
			head->next = NULL;
			return;
		}
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = new node;
		temp->next->info = value;
		temp->next->next = NULL;
	}

/////////////add node multiple times after key match////////

	void instertion(int value,int key){
		if(head == NULL)
			append(value);
		temp = head;
		while(temp != NULL){
			if(temp->info == key){
				temp1 = new node;
				temp1->info = value;
				temp1->next = temp->next;
				temp->next = temp1;
				temp=temp->next;
			}
			temp = temp->next;
		}
	}
	void deletion(int value){
		if(head == NULL)
			cout<<"Empty list\n";
		if(head->info == value){
			temp = head;
			head = head->next;
			delete temp;
			return; //if we want to remove multiple values, remove the return statment
		}
		temp = head;
		while(temp != NULL){
			if(temp->next != NULL && temp->next->info == value){
				temp1 = temp->next;
				temp->next = temp->next->next;
				delete temp1;
				return;    //if we want to remove multiple values, remove the return statment
			}
			temp = temp->next;
		}
	}

/////////////find how many times key in list/////////

	void searching(int key){
		temp = head;
		int count = 0;
		while(temp != NULL){
			if(temp->info == key){
				count += 1;
			}
			temp = temp->next;
		}
		cout<<"The "<<key<<" : "<<count<<" found\n";
	}
/////////print on console//////////
	void show(){

		if(head == NULL)
			cout<<"Empty list\n";
		temp = head;
		while (temp != NULL){
			cout<<temp->info<<" ";
			temp = temp->next;
		}
	}

};


int main(){

	singly_linklist l;
	l.append(7);
	l.append(7);
	l.append(5);
	l.append(4);
	l.append(7);
	l.deletion(7);
	l.instertion(9,7);
	l.deletion(7);
	l.deletion(7);
	l.searching(4);

	l.show();



	return 0;
}