#include <iostream>
using namespace std;

struct node{
	int info;
	node *left,*right;
};

class bin_search_tree{
private:
	node *temp,*temp1,*temp2;
public:
	node *root;
	bin_search_tree(){
		root = NULL;
	}
	int number,del;
	void get(int var){
		number = var;
		return;
	}
	void  insert(node *temp){
		if (temp == NULL){
			temp = new node;
			temp->info = number;
			temp->left = NULL;
			temp->right = NULL;
			root = temp;
			return;
		}
		if (temp->info == number){
			cout<<"Given number is already present in tree\n";
			return;
		}
		if (temp->info > number){
			if (temp->left != NULL){
				insert(temp->left);
				return;
			}
			else{
				temp->left = new node;
				temp->left->info = number;
				temp->left->left = NULL;
				temp->left->right = NULL;
				return;
			}
		}
		if (temp->info < number){
			if (temp->right != NULL){
				insert(temp->right);
				return;
			}
			else{
				temp->right = new node;
				temp->right->info = number;
				temp->right->left = NULL; 
				temp->right->right = NULL;
				return; 
			}
		}
	}

	void deletion(node *temp){
		if (root == NULL){
			cout<<"Tree is empty\n";
			return;
		}
		if (root->info == del){
			if(root->left == NULL && temp->right == NULL){
				delete root;
				return;
			}
			if(root->left != NULL && temp->right == NULL){
				temp1 = root;
				root = root->left;
				delete temp1;
				return;
			}
			if(root->left == NULL && temp->right != NULL){
				temp1 = root;
				root = root->right;
				delete temp1;
				return;
			}
			if(root->left != NULL && temp->right != NULL){
				if(root->right->right == NULL && root->right->left == NULL){
					swap(root->right->info,root->info);
					delete root->right;
					root->right = NULL;
					return;
				}
				if(root->right->right != NULL && temp->right->left==NULL){
					swap(root->right->info,root->info);
					temp1 = root->right;
					root->right = root->right->right;
					delete temp1;
					return;
				}
				if(root->right->left != NULL){
					temp1 = root->right;
					while(temp1->left->left != NULL){
						temp1 = temp1->left;
					}
					swap(temp1->left->info,root->info);
					if(temp1->left->right == NULL){
						delete temp1->left;
						temp1->left = NULL;
						return;
					}
					else{
						temp2 = temp1->left;
						temp1->left = temp1->left->right;
						delete temp2;
						return;
					}
					return;
				}
			}
		}
		if (del < temp->info){
			if(temp->left != NULL){
				if(temp->left->info == del){
					if (temp->left->left == NULL && temp->left->right == NULL){
						delete temp->left;
						temp->left = NULL;
						return;
					}
					if(temp->left->left != NULL && temp->left->right == NULL){
						temp1 = temp->left;
						temp->left = temp->left->left;
						delete temp1;
						return;
					}
					if(temp->left->left == NULL && temp->left->right != NULL){
						temp1 = temp->left;
						temp->left = temp->left->right;
						delete temp1;
						return;
					}
					if(temp->left->left != NULL && temp->left->right != NULL){
						if(temp->left->left->right == NULL){
							swap(temp->left->left->info,temp->left->info);
							if (temp->left->left->left == NULL){
								delete temp->left->left;
								temp->left->left = NULL;
								return;
							}
							if (temp->left->left->left != NULL){
								temp1 = temp->left->left;
								temp->left->left = temp->left->left->left;
								delete temp1;
								return;
							}
						}
						if (temp->left->left->right != NULL){
							temp1 = temp->left->left;
							while(temp1->right->right != NULL){
								temp1 = temp1->right;
							}
							swap(temp->left->info,temp1->right->info);
							if (temp1->right->left == NULL){
								delete temp1->right;
								temp1->right = NULL;
								return;
							}
							else{
								temp2 = temp1->right;
								temp1->right = temp1->right->left;
								delete temp2;
							}
						}
					}
				}
				deletion(temp->left);
				return;
			}
		}
		if(del > temp->info){
			if(temp->right != NULL){
				if(temp->right->info == del){
					if(temp->right->right == NULL && temp->right->left == NULL){
						delete temp->right;
						temp->right = NULL;
						return;
					}
					if(temp->right->right != NULL && temp->right->left == NULL){
						temp1 = temp->right;
						temp->right = temp->right->right;
						delete temp1;
						return;
					}
					if(temp->right->right == NULL && temp->right->left != NULL){
						temp1 = temp->right;
						temp->right = temp->right->left;
						delete temp1;
						return;
					}
					if(temp->right->right != NULL && temp->right->left != NULL){
						if(temp->right->right->left == NULL){
							swap(temp->right->right->info,temp->right->info);
							if(temp->right->right->right == NULL){
								delete temp->right->right;
								temp->right->right = NULL;
								return;
							}
							if(temp->right->right->right != NULL){
								temp1 = temp->right->right;
								temp->right->right = temp->right->right->right;
								delete temp1;
								return;
							}
						}
						if(temp->right->right->left != NULL){
							temp1 = temp->right->right;
							while(temp1->right != NULL){
								temp1 = temp1->right;
							}
							swap(temp->right->right->info, temp1->right->info);
							if(temp1->right->right != NULL){
								temp2 = temp1->right;
								temp1->right = temp1->right->right;
								delete temp2;
								return;
							}
							else{
								delete temp1->right;
								temp1->right = NULL;
								return;
							}
						}
					}
				}
				deletion(temp->right);
			}		
		}		
	}

	void show_inorder(node *temp){
		if (root == NULL){
			cout<<"Tree is emty\n";
			return;
		}
		if (temp->left != NULL){
			show_inorder(temp->left);
		}

		cout<<temp->info<<" ";

		if (temp->right != NULL){
			show_inorder(temp->right);
		}
	}

};

int main(){

	// Do this idiot
	bin_search_tree b;
	for (int i = 0; i < 5; i++)
	{
		cout << "enter the number \n";
		cin >> b.number;
		b.insert(b.root);
	}
	// bin_search_tree b;
	// b.number = 5;
	// b.insert(b.root);
	// b.number = 1;
	// b.insert(b.root);
	// b.number = 6;
	// b.insert(b.root);
	// b.number = 7;
	// b.insert(b.root);
	// // b.number = 1;
	// b.insert(b.root);
	/////////////////
	// bin_search_tree b;
	// b.number = 5;
	// b.insert(b.root);
	// b.number = 8;
	// b.insert(b.root);
	// b.number = 2;
	// b.insert(b.root);
	// b.number = 9;
	// b.insert(b.root);
	// b.number = 1;
	// b.insert(b.root);

	b.show_inorder(b.root); /// print the tree 
	cout<<endl;
	b.del = 5;
	b.deletion(b.root);
	b.show_inorder(b.root);

	return 0;
}