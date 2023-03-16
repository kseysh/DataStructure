#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class listStack {
public:
	listStack();
	bool empty();
	void size();
	void top();
	void push(int data);
	void pop();
private:
	node* topNode;
	int listSize;
};

listStack::listStack() {
	topNode = NULL;
	listSize = 0;
}

bool listStack::empty() {
	if (listSize == 0) {
		return true;
	}
	else {
		return false;
	}
}
void listStack::size() {
	cout << listSize << endl;
}
void listStack::top() {
	if (empty()) {
		cout << "empty" << endl;
	}
	cout << topNode->data << endl;
}
void listStack::push(int data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->next = topNode;
	topNode = newNode;
	listSize++;
}
void listStack::pop() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	node* curNode = topNode;
	topNode = topNode->next;
	cout << curNode->data << endl;
	delete curNode;
	listSize--;
}

int main() {
	int commandCount = 0;
	cin >> commandCount;
	string command = "";
	listStack stack;
	for (int n = 0; n < commandCount; n++)
	{
		cin >> command;
		if (command == "push")
		{
			int inputValue = 0;
			cin >> inputValue;
			stack.push(inputValue);
		}
		else if (command == "pop")
		{
			stack.pop();
		}
		else if (command == "size")
		{
			stack.size();
		}
		else if (command == "empty")
		{
			if (stack.empty()) {
				cout << "empty" << endl;
			}
			else {
				cout << "not empty" << endl;
			}
		}
		else if (command == "top")
		{
			stack.top();
		}
	}


	return 0;
}