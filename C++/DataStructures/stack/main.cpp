#include <iostream>

class Node {
public:
	Node(int v = 0, Node *n = nullptr) : val(v), next(n) {}
	int val;
	Node *next;
};

class Stack {
public:
	Stack() : head(nullptr) {}

	// need to free all of our nodes
	~Stack() {
		if (head == nullptr) return;
		if (head->next == nullptr) delete head;
		else {
			Node *curr = head->next;
			Node *prev = head;
			for (; curr != nullptr; curr = curr->next, prev = prev->next)
				delete prev;
			delete prev;
		}
	}

	void push(int v) {
		head = new Node(v, head);
	}
	// move the head pointer, delete the old node, return the correct value
	int pop() {
		int v = head->val;
		Node *temp = head;
		head = head->next;
		delete temp;
		return v;
	}
	const int peek() {
		return head->val;
	}
private:
	Node *head;
};

int main() {
	Stack stack;
	for (int i = 0; i < 10; i++)
		stack.push(i*i*i);
	std::cout << "Peek: " << stack.peek() << std::endl;
	std::cout << "Pop: " << stack.pop() << std::endl;
	std::cout << "Peek: " << stack.peek() << std::endl;
}
