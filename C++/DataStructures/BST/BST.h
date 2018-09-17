#ifndef __BST_H__
#define __BST_H__

#include <iostream>

class Node {
public:
	Node(int d = 0) : data(d), balance(0), left(nullptr), right(nullptr), parent(nullptr) {}
	int data;
	int balance;
	Node *left, *right, *parent;
};

class BST {
public:
	BST() : root(nullptr) {}

	void insert(int val);
	Node *find(int val);
	void print();

private:
	void insert(Node *n);

	void print_helper(Node *n);

protected:
	Node *root;
};

#endif // __BST_H__
