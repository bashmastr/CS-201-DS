#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;


#define Count 10 


struct node {

    int info;
    node *left;
    node *right;
    int h;
};

class CBT {
public:

    node *root, *temp,*temp3;
    int G_height, no_nodes ,flage,swap;
    int num, del,f;
    int flage2;
    node *last;   // point to last node
    CBT(){
        no_nodes = 0;
        flage = 0;
        flage2 = 0;
        G_height = 0;
        root = NULL;
        temp = NULL;
        f = 0;
    }

    void insert (node *temp){
        if(flage == 1)
            return;

        if (root == NULL){
            temp = new node;
            last = root;
            temp->info = num;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
            G_height = 0;
            root->h = 0;
            no_nodes += 1;
            flage = 1;
            f  = 1;
            return;
        }
        if(root->left== NULL){
          root->left = new node;
          last = root;
          root->left->info = num;
          root->left->left = NULL;
          root->left->right = NULL;
          no_nodes += 1;
          G_height = 1;
          f  = 1;
          root->left->h = 1;
          return;
        }
        if(root->right== NULL){
          root->right = new node;
          last = root;
          root->right->info = num;
          root->right->left = NULL;
          root->right->right = NULL;
          root->right->h = 1;
          no_nodes += 1;
          f  = 1;
          return;
        }

        if (temp->left != NULL){
            insert(temp->left);
        }

        if (no_nodes == pow(2,G_height+1)-1){
        	temp->left = new node;
        	last = temp;
        	temp->left->info = num;
        	temp->left->left = NULL;
        	temp->left->right = NULL;
        	no_nodes += 1;
        	G_height += 1;
        	temp->left->h = G_height;
        	flage = 1;
        	f  = 1;
        	return; 
        }
        if(no_nodes < (pow(2,G_height+1)-1)  && G_height - temp->h == 1){
        	

        	if(temp->right == NULL){
        		temp->right = new node;
        		last = temp;
        		temp->right->info = num;
        		temp->right->left = NULL;
        		temp->right->right = NULL;
        		no_nodes += 1;
        		flage = 1;
        		flage2 = 1;
        		temp->right->h = G_height;
        		f  = 1;
        		return;
        	}
        	if(temp->left == NULL){
        		temp->left = new node;
        		last = temp;
        		temp->left->info = num;
        		temp->left->left = NULL;
        		temp->left->right = NULL;
        		no_nodes += 1;
        		flage = 1;
        		flage2 = 1;
        		temp->left->h = G_height;
        		f  = 1;
        		return;
        	}
        }
        if(f == 1 && temp->left != NULL || temp->right != NULL){
        	if(temp->left != NULL && temp->left->info < temp->info){
        		int z = temp->left->info;
        		temp->left->info = temp->info;
        		temp->info = z;
        	}
        	if(temp->right != NULL && temp->right->info < temp->info){
        		int y = temp->right->info;
        		temp->right->info = temp->info;
        		temp->info = y; 
        	}
        }
        if (temp->right != NULL){f  = 1;
            insert(temp->right);
        }
    }


     void swap_value_form_last(node *temp){

        if (root == NULL){
            cout<<"Tree is emty\n";
            return;
        }

        if (temp->left != NULL){
            swap_value_form_last(temp->left);
        }

        if(temp->left != NULL){
        	cout<<"df";
        	if(temp->info > temp->left->info ){
        		int x = 0;
        		x = temp->info;
        		temp->info = temp->left->info;
        		temp->left->info = x;
        	}
        }

        if (temp->right != NULL){
            swap_value_form_last(temp->right);
        }

        if(temp->right != NULL){
        	
        	if(temp->info > temp->right->info ){
        		swap(temp->info,temp->right->info);
        		int x = 0;
        		x = temp->info;
        		temp->info = temp->right->info;
        		temp->right->info = x;
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

    void pity_print(node *root, int space) { 
    	if (root == NULL) 
        	return; 
      	space +=  Count;
  
    	pity_print(root->right, space); 
  
    	cout<<"\n"; 
    	for (int i = Count; i < space; i++) 
        	cout<<" "; 
    	printf("%d\n", root->info); 
    	//cout<<"%d\n", root->info; 
  
    	pity_print(root->left, space); 
	}
        

};

int main(){

    CBT b;
    b.num = 5;
    b.insert(b.root);
    // b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 9;
    b.insert(b.root);
    // b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 67;
    b.insert(b.root);
    // b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 7;
    b.insert(b.root);
    // b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 78;
    b.insert(b.root);
    // b.show_inorder(b.root);
    cout<<endl;
   
    b.flage = 0;
    b.num = 24;
    b.insert(b.root);
    // b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 9;
    b.insert(b.root);
    // b.show_inorder(b.root);
    cout<<endl;

    b.flage = 0;
    b.num = 4;
    b.insert(b.root);
    b.show_inorder(b.root);
    cout<<endl;


    b.pity_print(b.root,0);
    cout<<endl; 


    b.del = 4;
   	b.swap_value_form_last(b.root);  /////deletion
    cout<<endl;
    b.show_inorder(b.root);

    b.pity_print(b.root,0);

    return 0;
}