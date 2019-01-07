#include <iostream>
using namespace std;

struct node{
	int info;
	node *next,*pre;
};


class doubly_circular_linklist{

private:			
	node *head, *temp, *temp1, *tail;

public:
	doubly_circular_linklist(){
		head = temp = temp1 = tail = NULL;
	}

	void append(int value){
		if (head == NULL){
			head = new node;
			head->info = value;
			head->next = head;
			head->pre = head;
			cout<<"First node add\n";
			return;
		}
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next->pre = new node;         ///////adding node without using extra pointer/
		temp->next->pre->info = value;	
		temp->next->pre->next = temp ->next;
		temp->next->pre->pre = temp;
		temp->next = temp->next->pre;
		return;
	}

	void insertion(int value,int key){
		if(head == NULL)
			append(value);
		if(head->info == key){
			head->next->pre = new node;         ///////adding node without using extra pointer/
			head->next->pre->info = value;	
			head->next->pre->next = head ->next;
			head->next->pre->pre = head;
			head->next = head->next->pre;
			return;
		}
		temp = head;
		while(temp->next != head){
			if(temp->info == key){
			temp->next->pre = new node;         ///////adding node without using extra pointer/
			temp->next->pre->info = value;	
			temp->next->pre->next = temp ->next;
			temp->next->pre->pre = temp;
			temp->next = temp->next->pre;
			return;
			}
			temp = temp->next;

		}
		if(temp->info == key){
			temp->next->pre = new node;         ///////adding node without using extra pointer/
			temp->next->pre->info = value;	
			temp->next->pre->next = temp ->next;
			temp->next->pre->pre = temp;
			temp->next = temp->next->pre;
		}
	}

	

	void show(){
		if(head == NULL)
			cout<<"Empty List\n";
		temp = head;
		while(temp->next != head){
			cout<<temp->info<<" ";
			temp = temp->next;
		}
		cout<<temp->info;
	}
	
};


int main(){

	doubly_circular_linklist l;
	l.append(1);
	l.append(2);
	l.append(3);
	l.append(5);
	l.append(9);
	l.insertion(8,1);
	l.append(55);
	l.show();

	return 0;
}