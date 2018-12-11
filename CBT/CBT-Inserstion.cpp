#include <iostream>
#include <cmath>
using namespace std;

struct node {

    int info;
    node *left;
    node *right;
    int h;
};

class CBT {
public:
    node *root, *temp;
    int G_height, no_nodes ,flage;
    int num, del;
    int flage2;
    CBT(){
        no_nodes = 0;
        flage = 0;
        flage2 = 0;
        G_height = 0;
        root = NULL;
        temp = NULL;
    }

    void insert (node *temp){
        if(flage == 1)
            return;

        if (root == NULL){
            temp = new node;
            temp->info = num;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
            G_height = 0;
            root->h = 0;
            no_nodes += 1;
            flage = 1;
            return;
        }
        if(root->left== NULL){
          root->left = new node;
          root->left->info = num;
          root->left->left = NULL;
          root->left->right = NULL;
          no_nodes += 1;
          G_height = 1;
          root->left->h = 1;
          return;
        }
        if(root->right== NULL){
          root->right = new node;
          root->right->info = num;
          root->right->left = NULL;
          root->right->right = NULL;
          root->right->h = 1;
          no_nodes += 1;
          return;
        }

        if (temp->left != NULL){
            insert(temp->left);
        }

        if (no_nodes == pow(2,G_height+1)-1){
        	temp->left = new node;
        	temp->left->info = num;
        	temp->left->left = NULL;
        	temp->left->right = NULL;
        	no_nodes += 1;
        	G_height += 1;
        	temp->left->h = G_height;
        	flage = 1;
        	return; 
        }
        if(no_nodes < (pow(2,G_height+1)-1)  && G_height - temp->h == 1){
        	

        	if(temp->right == NULL){
        		temp->right = new node;
        		temp->right->info = num;
        		temp->right->left = NULL;
        		temp->right->right = NULL;
        		no_nodes += 1;
        		flage = 1;
        		flage2 = 1;
        		temp->right->h = G_height;
        		return;
        	}
        	if(temp->left == NULL){
        		temp->left = new node;
        		temp->left->info = num;
        		temp->left->left = NULL;
        		temp->left->right = NULL;
        		no_nodes += 1;
        		flage = 1;
        		flage2 = 1;
        		temp->left->h = G_height;
        		return;
        	}
        }
        if (temp->right != NULL){
            insert(temp->right);
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

    CBT b;
    b.num = 5;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 9;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 67;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 7;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 78;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;
   
    b.flage = 0;
    b.num = 24;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 9;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 4;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;
    //b.show_inorder(b.root);

    return 0;
}