#include "BST.h"

// TODO: put in constructors/destructors



/* Yes, this isn't the greatest method of doing an insert,
   but this form helps with doing inserts for variations 
   on the BST                                             */
void BST::insert(int val) {
	Node *n = new Node(val);
	insert(n);
}

void BST::insert(Node *n) {
	if (root == nullptr) {
		root = n;
	}
	else {
		Node *itr = root;
	
	/* I use an infinite for-loop for BST's. I think it's funny.
	   Not really great practice, but I just wanted to show you 
	   it could be done.
	*/
		for(;;) {
			if (n->data < itr->data) {
				if (itr->left == nullptr) {
					itr->left = n;
					n->parent = itr;
					break;
				}
				else itr = itr->left;
			}
			// there should be no duplicates in the tree
			else {
				if (itr->right == nullptr) {
					itr->right = n;
					n->parent = itr;
					break;
				}	
				else itr = itr->right;
			}
		}
	}
}

Node *BST::find(int val) {
	Node *itr = root;
	while (itr != nullptr) {
		if (val < itr->data) itr = itr->left;
		else if (val > itr->data) itr = itr->right;
		else if (val == itr->data) return itr;
		else return nullptr; // This should never happen . . .
	}
	return nullptr;
}


void BST::print_helper(Node *n) {
	if (n == nullptr) return;
	print_helper(n->left);
	std::cout << n->data << ", ";
	print_helper(n->right);
}

void BST::print() {
	print_helper(root);
	std::cout << std::endl;
}

