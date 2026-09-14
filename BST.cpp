//Author: Hue Khoi Ly
//Email address: huekhoily@gmail.com
//Description: This .cpp file defines functions in .h file and how I build Binary search tree to store the request data

#include "BST.h"
using namespace std;

//Constructor
tree::tree(){
	root = nullptr;
}


//Destructor
tree::~tree(){
	clear_all(root);	
}


//Insert function into the binary tree according to the type of request
//Input: request item passed as argument
//Output: 1 or 0;
int tree::insert(const request& add){
	return insert(root, add);
}

//Display function display all of requests sorted in oreder by the request type
//Input: None
//Output: number of items in the tree or 0
int tree::display_all(){
	return display_all(root);
}


//Remove function to remove a particular request type based on if the status was "Closed"
//Input: t as char string
//Output: 0 or numeber of requests deleted 
int tree::remove_closed(char* t){
	int s_t = strlen(t);
	for (int i =0; i <s_t;i++){
		t[i] = tolower(t[i]);
	}
	t[s_t] = '\0';
	if (!root){
		return 0;
	}
	int count = remove_closed(root, t);
	return count;
}


//Retrieve function to search the id of the request
//Input: i as char string and found as a request type
//output: 1 or 0
int tree::peek (char* i, request& found){
	int s_i = strlen(i);
	for(int k = 0; k <s_i; k++){
		i[k] = toupper(i[k]);
	}
	i[s_i] = '\0';
	
	if(!root){
		return 0;
	}
	return peek(root,i,found);
}


//Display type function to display all requests of  particular type
//Input: t as a char string
//Output: 0 or number of requests
int tree::display_t(char* t){
	int s_t = strlen(t);
	for (int i = 0; i < s_t; i++){
		t[i] = tolower(t[i]);
	}
	t[s_t] = '\0';
	if (!root){
		return 0;
	}
	int count = display_t(root,t);
	return count;
}


//This function to help to determine the height of the tree
//Input: None
//Output: the number of height of the tree
int tree::height(){
	return height(root);
}

//Recursive functions


//This is recursive funtion to help insert funtion
//Input: root as node, and add as request item
//Output: 0 or 1
int tree::insert(node *& root, const request& add){
	if(!root){
		root = new node;
		if (!root->data.copy(add)){
			return 0;
		}
		root->left = root->right = nullptr;
		return 1;
	}	
	int count = 0;
	if (root->data.islargerthan(add) > 0){
		count = insert(root -> left,add);
	}
	else{
		count = insert (root ->right,add);
	}
	return count;
}


//This recursive function to help display_all function
//Input: root as node
//Output: 0 and numebr of data items
int tree::display_all(node*& root) const{
	if (!root){
		return 0;
	}
	
	int c_l = display_all(root->left);
	int count = root->data.display();	
	int c_r = display_all(root->right);
	return c_l + count + c_r;
}


//This recursive function to help the remove funtion
//Input: root as node
//Output: 0 or number requests deleted 
int tree::remove_closed(node*& root, char* t){
	if (!root){
		return 0;
	}
	int count = 0;
	if (root -> data.compare(t) == 0){
		if (root->data.isClosed()){
			if (root->left == nullptr && root->right == nullptr){
				delete root;
				root = nullptr;
			}
			else if (root->left && root->right == nullptr){
				node* hold = root->left;
				delete root;
				root = hold;
			}
			else if (root->left == nullptr && root->right){
				node* hold = root->right;
				delete root;
				root = hold;	
			}
			else{
				node* curr = root->right;
				node* prev = nullptr;
				if (!curr->left){
					node* hold = curr->right;
					root -> data.copy(curr->data);
					delete curr;
					root->right = hold;
				}
				else{
					while(curr->left){
						prev = curr;
						curr = curr ->left;
					}
					root->data.copy(curr->data);
					node* hold = curr->right;
					delete curr;
					prev -> left = hold;
				}
			}
			count = remove_closed(root, t) + 1;
		}
		else{
			count = remove_closed(root->right,t);
		}
	}
	else if (root->data.compare(t) > 0){
		count = remove_closed(root->left, t);
	}
	else{
		count = remove_closed(root->right,t);
	}
	return count;
}


//This recursive function is to help retrieve function
//Input: root as node, i as char string and found as request type
//output: 0 or 1
int tree::peek(node*& root, char* i, request& found) const{
	if (!root){
		return 0;
	}
	if (root->data.retrieve(i,found)){
		return 1;
	}
	int c_l = peek(root->left, i, found);
	int c_r = peek(root->right,i,found);
	return c_l + c_r;
}


//This recursive function is to help the display_t function
//input : root as node, t as char string
//output: 0 or numebr of requests
int tree::display_t(node *& root, char *t) const{
	if (!root){
		return 0;
	}

	if (root->data.compare(t) == 0){
		root->data.display();
		return display_t(root->right,t) + 1;
	}
	else if (root->data.compare(t) > 0){
		return display_t(root->left,t);
	}
	return display_t(root->right,t);
}


//This recursive function helps height function
//Input:root as node
//output: number of node from root to leaf
int tree::height(node*& root){
	if (!root){
		return 0;
	}
	int c_l = height(root->left);
	int c_r = height(root->right);
	if (c_l > c_r){
		return c_l + 1;
	}
	return c_r + 1;
}


//This function is to help the destructor
//Input:None
//Output: 1 or 0
int tree::clear_all(node*& root){
	if (!root){
		return 0;
	}
	int c_l = clear_all(root->left);
	int c_r = clear_all(root->right);
	delete root;
	root = nullptr;
	return c_l + c_r + 1;
}
