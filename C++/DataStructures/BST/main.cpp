#include "BST.h"

int main() {
	BST tree;
	for (int i = 0; i < 100; i++)
		tree.insert(i*i);
	tree.print();
}
