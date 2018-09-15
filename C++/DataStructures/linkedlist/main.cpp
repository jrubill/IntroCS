#include <iostream>

class Node {
public:
	Node(int v = 0, Node *n = nullptr) : val(v), next(n) {}
	int val;
	Node *next;
};

class LinkedList {
public:
	LinkedList(Node *h = nullptr, int s = 0) : head(h), size(s) {}

	/* destructor: for everything we new, we must delete. This iterates through our list and deletes
	   all of the nodes
	*/
	~LinkedList() {
		if (head == nullptr) return;
		if (head->next == nullptr) delete head;
		else {
			Node *prev = head;
			Node *curr = head->next;
			for (; curr != nullptr; curr = curr->next, prev = prev->next)
				delete prev;
			delete prev;
		}
	}
	/* this is a slick way to do inserts on a linked list. Instead of adding nodes to the end,
	you create a node and make it point towards the head node
	*/
	void insert(int k) { head = new Node(k, head); size++; }
	
	void print() {
		for (Node *itr = head; itr != nullptr; itr = itr->next)
			std::cout << itr->val << ", ";
		std::cout << std::endl;
	}
private:
	Node *head;
	int size;
};

int main() {
	LinkedList list;
	for (int i = 0; i < 10; i++)
		list.insert(i*i);
	list.print();
}
