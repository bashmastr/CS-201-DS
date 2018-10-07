#include <iostream>
using namespace std;

struct  node{
	int info;
	node *next;
	node *pre;
};


class doubly_linklist{

private:
	node *head;
	node *temp , *temp1;

public:
	doubly_linklist():head(NULL),temp(NULL),temp1(NULL){}

	void append(int value){
		if(head == NULL){
			cout<<"First node add\n";
			head = new node;
			head->info = value;
			head->next = NULL;
			head->pre = head;
			return;
		}
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new node;

		temp->next->info = value;
		temp->next->next = NULL;
		temp->next->pre = temp;
	}

	void insertion(int value, int key){
		temp = head;
		if(head == NULL){
			append(value);
			temp = head->next;
		}
		while(temp != NULL){
			if(temp->info == key){
				temp1 = new node;
				temp1->info = value;
				temp1->next = temp->next;
				temp1->pre = temp;
				temp->next = temp1;
				if(temp1->next != NULL)
					temp1->next->pre = temp1->next;
				temp = temp->next;
			}
			temp = temp->next;

		}
	}

	void deletion(int value){
		if (head == NULL)
			cout<<"Empty list\n";
		if (head->info == value){
			temp1 = head;
			head = head -> next;
			head->pre = head;
			delete temp1;
		}
		temp = head;
		while(temp != NULL){
			if(temp->info == value){
				temp1 = temp;
				temp->pre->next = temp->next;
				if(temp->next != NULL)
					temp->next->pre = temp->pre;
				delete temp1;

			}
			temp = temp->next;
		}

	}

	void show(){
		if (head == NULL)
			cout<<"list Empty\n";
		temp = head;
		while(temp != NULL){
			cout<<temp->info<<" ";
			temp = temp->next;
		}
	}
};

int main(){

	doubly_linklist l;
	l.append(8);
	l.append(8);
	l.append(8);
	l.append(8);
	//l.insertion(5,7);
	l.deletion(8);
	// l.deletion(8);
	l.show();

	return 0;
}
