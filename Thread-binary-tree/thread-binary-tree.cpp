#include <iostream>
using namespace std;

struct node {
	int LTH,RTH,info;
	node *left,*right;
};

class thread_binary_tree{

private:
	node *temp1;

public:
	node *root, *dummy;
	thread_binary_tree(){
		root = NULL;
		dummy = new node;
		dummy->right = dummy;
		//dummy->info = 99;
		dummy->RTH = 1;
		dummy->LTH = 1;
	}
	int num,del;
	void insert(node *temp){
		if(temp == NULL){
			temp = new node;
			temp->info = num;
			temp->left = dummy;
			temp->LTH = 0;
			temp->right = dummy;
			temp->RTH = 0;
			root = temp;
			dummy->left = root;
			return;
		}
		if (temp->info == num){
			cout<<"Already exist\n";
			return;	
		}
		if (temp->info > num){
			if(temp->LTH != 0){
				insert(temp->left);
				return;
			}
			else{
				temp1 = new node;
				temp1->info = num;
				temp1->left = temp->left;
				temp1->LTH = 0;
				temp->LTH = 1;
				temp1->right = temp;
				temp1->RTH = 0;
				temp->left = temp1;
				return;
			}
		}
		if (temp->info < num){
			if (temp->RTH != 0){
				insert(temp->right);
				return;
			}
			else{
				temp1 = new node;
				temp1->info = num;
				temp1->right = temp->right;
				temp1->RTH = 0;
				temp1->left = temp->right;
				temp1->RTH = 0;
				temp->right = temp1;
				temp->RTH = 1;
				return;
			}
		}
	}

	node *next_Inorder(node *p){
		if (p->RTH == 0)
			return (p->right);
		else{
			p = p->right;
			while(p->LTH == 1)
				p = p->left;
			return p;
		}
	}

	void fast_Inorder(node *p){
		while ((p = next_Inorder(p)) != dummy)
			cout<<p->info<<" ";
	}

	void show_inorder(node *temp){
		if (root == NULL){
			cout<<"Tree is emty\n";
			return;
		}
		if (temp->LTH != 0){
			show_inorder(temp->left);
		}

		cout<<temp->info<<" ";

		if (temp->RTH != 0){
			show_inorder(temp->right);
		}
	}
};

int main(){

	thread_binary_tree b;
	b.num = 7;
	b.insert(b.root);
	b.num = 5;
	b.insert(b.root);
	b.num = 6;
	b.insert(b.root);
	b.num = 0;
	b.insert(b.root);
	//b.show_inorder(b.root);
	b.dummy->left = b.root;
	b.fast_Inorder(b.dummy);
	return 0;
}