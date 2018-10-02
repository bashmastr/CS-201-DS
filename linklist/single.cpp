#include <iostream>
using namespace std;

struct node {

	int info = 0;
	node *next;
};


class single_linklist{

private:

	node *head,*temp;

public:

	single_linklist():head(NULL),temp(NULL){}

	void insertion(int key){
		
		if (head == NULL){
			temp = new node;
			cout<<"First node add value rondomly \n";
			cin>>temp->info;
			temp->next = NULL;
			head = temp;
			temp = NULL; 
			return;
		}
		temp = head;
		while(temp != NULL){
			if(temp->info == key){
				node *temp1 = new node;
				cout<<"Key match\n";
				cout<<"Enter value\n";
				cin>>temp1->info;
				temp1->next = temp->next;
				temp->next = temp1;
			}
			temp = temp->next;
		}
	}

	void del(int key){
		if(head == NULL)
			cout<<"No list found\n";
		if(head->info == key){
			temp = head;
			head = head->next;
			delete temp;
			return;
		}
		temp = head;
		while(temp != NULL){

			if(temp->next->info == key){
				node *temp1 = temp->next;
				temp->next = temp->next->next;
				delete temp1; 
			}
			temp = temp->next;
		}
	}


	void show_list(){
		temp = head;
		while(temp != NULL){
			cout<<temp->info<<" ";
			temp = temp->next;
		}
	}

};


int main(){

	single_linklist l;
	l.insertion(4);
	l.insertion(5);
	l.insertion(5);
	l.insertion(4);
	l.insertion(4);
	l.del(8);

	l.show_list();
	return 0;
}