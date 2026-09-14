//Author: Hue Khoi Ly
//Email address: huekhoily@gmail.com
//Description: This is .h file to declare the Binary Search Tree data structure.

#include "request.h"

struct node{
	request data;
	node* left;
	node* right;
};

class tree{
	public:
		tree();
		~tree();
		int insert(const request& add);
		int display_all();
		int remove_closed(char* t);
		int peek (char* i, request& found);
		int display_t(char* t);
		int height();	
	private:
		node * root;

		//Recursive functions
		int insert(node *& root, const request& add);
		int display_all(node*& root) const;
		int remove_closed(node*& root, char* t);
		int peek(node*& root, char* i, request& found) const;
		int display_t(node *& root, char *t) const;
		int height(node*& root);
		int clear_all(node*& root);
};
