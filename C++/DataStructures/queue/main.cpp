#include <iostream>

class Node {
public:
	Node(int v = 0, Node *n = nullptr) : val(v), next(nullptr) {}
	int val;
	Node *next;
};

class Queue {
public:
	Queue() : head(nullptr), tail(nullptr) {}
	
	void enqueue(int val) {
		Node *toAdd = new Node(val);
		if (head == nullptr) {
			head = toAdd;
			tail = toAdd;
		}
		else {
			tail->next = toAdd;
			tail = tail->next;
		}
	}

	int dequeue() {
		if (head == nullptr) return -1;
		else {
			Node *temp = head;
			int val = temp->val;
			head = head->next;
			delete temp;
			return val;
		}
	}
private:
	Node *head, *tail;
};

int main() {
	Queue q;
	for (int i = 0; i < 10; i++)
		q.enqueue((i+1)*i);
	for (int i = 0; i < 10; i++) 
		std::cout << q.dequeue() << std::endl;
}
