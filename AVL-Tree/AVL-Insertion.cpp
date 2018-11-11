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
		if ( temp != NULL && temp->info == number){
			cout<<"Given number is already present in tree\n";
			return;
		}
		if (temp == NULL){
			temp = new node;
			temp->info = number;
			temp->left = NULL;
			temp->right = NULL;
			root = temp;
			return;
		}
		if (temp->info > number){
			if (temp->left != NULL){
				insert(temp->left);
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
			}
			else{
				temp->right = new node;
				temp->right->info = number;
				temp->right->left = NULL; 
				temp->right->right = NULL;
				return; 
			}
		}
		if(temp == root)
			return;
		int BF = Height(temp->left) - Height(temp->right);
		if(BF < -1 or BF > 1){
			if(number > temp->info){
				if(number > temp->right->info){
					Zig_Zig(temp);
					return;
				}
				else{
					Zig_Zig(temp);
					return;
				}
			}
			else{
				if(number < temp->left->info){
					Zag_Zag(temp);
					return;
				}
				else{
					Zag_Zag(temp);
					return;
				}
			}
		}
	}

	void Zig_Zig(node *temp){
		swap(temp->info,temp->right->info);
		temp1 = temp->right;
		temp->right = temp->right->right;
		temp->left = temp1; 
		temp->left->right = NULL;
		if (temp->left->left != NULL){
			temp->left->right = temp->left->left;
			temp->left->left = NULL; 
		}
		
	}

	void Zag_Zag(node *temp){
		swap(temp->info, temp->left->info);
		temp1 = temp->left;
		temp->left = temp->left->left;
		temp->right = temp1;
		temp->right->left = NULL;
		if(temp->right->right != NULL){
			temp->right->left = temp->right->right;
			temp->right->right = NULL;
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
	int Height(node *root) {
    	if (root == NULL)
        return 0;

        // find the height of each subtree
        int lh = Height(root->left);
    	int rh = Height(root->right);

    	return 1 + max(lh,rh);
	}

};

int main(){

	// Do this idiot
	// bin_search_tree b;
	// for (int i = 0; i < 7; i++)
	// {
	// 	cout << "enter the number \n";
	// 	cin >> b.number;
	// 	b.insert(b.root);
	// }
	bin_search_tree b;
	b.number = 4;
	b.insert(b.root);
	b.number = 2;
	b.insert(b.root);
	b.number = 1;
	b.insert(b.root);
	b.number = 3;
	b.insert(b.root);
	b.number = 6;
	b.insert(b.root);
	///////////////
	//bin_search_tree b;
	b.number = 5;
	b.insert(b.root);
	//b.number = 0;
	//b.insert(b.root);
	b.number = 7;
	b.insert(b.root);
	b.number = 16;
	b.insert(b.root);
	b.number = 15;
	b.insert(b.root);


	// b.number = 17;
	// b.insert(b.root);


	// b.show_inorder(b.root); /// print the tree 
	// cout<<endl;
	// b.del = 5;
	// b.deletion(b.root);
	b.show_inorder(b.root);
	// cout<<b.Height(b.root);

	return 0;
}