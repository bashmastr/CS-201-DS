#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class silngly_circular_linklist{

private:

	node *head,*temp,*temp1,*tail;

public:

	silngly_circular_linklist():head(NULL),temp1(NULL),temp(NULL){}

	void append(int value){
		if (head == NULL){
			head = new node;
			head->info = value;
			head ->next = head;
			cout<<"First node add\n";
			return;
		}
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp1 = new node;
		temp1->info = value;
		temp1->next = temp->next;
		temp->next = temp1;
	}

	void insertion(int value,int key){
		if(head == NULL)
			append(value);
		if(head->info == key){
			temp1 = new node;
			temp1->info = value;
			temp1->next = head->next;
			head->next = temp1;
			return;
		}
		temp = head;
		while(temp->next != NULL){
			if (temp->next->info == key){
				temp1 = new node;
				temp1->info = value;
				temp1->next = temp->next->next;
				temp->next->next = temp1;
				temp = temp->next;
				return;
			}
				temp = temp->next;
		}
	}

	void deletion(int value){
		if (head == NULL)
			cout<<"List empty"<<endl;
		temp = head;


		while(temp->next != head){//////to get end node for point to next head
			temp= temp->next;
		}
		tail = temp;

		if (head->info == value){
			temp1 = head;
			head = head->next;
			tail->next = head;
			delete temp1;
			return;
		}

		temp = head;
		while(temp->next != head){
			if(temp->next->info == value){
				temp1 = temp->next;
				temp->next = temp->next->next; 
				delete temp1;

				return;
			}
			temp = temp->next;
		}
	}

	void show(){
		if(head == NULL)
			cout<<"List Empty\n";
		temp = head;
		while(temp->next != head){
			cout<<temp->info<<" ";
			temp = temp->next;
		}
		cout<<temp->info;
	}
};

int main(){
	silngly_circular_linklist l;
	l.append(4);
	l.append(9);
	l.append(8);
	l.append(10);
	//l.insertion(7,8);
	l.deletion(10);
	l.show();
	return 0;
}
