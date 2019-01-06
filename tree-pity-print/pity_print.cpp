

    #define Count  10

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
        
