#include <iostream>
using namespace std;

class arrayStack {
public:
	arrayStack(int capacity);
	bool empty();
	void size();
	void top();
	void push(int data);
	void pop();

private:
	int* arr; // ������ ���Ҹ� �����ϴ� �迭
	int capacity; // ������ �ִ� ũ�⸦ �����ϴ� ����
	int topIndex; // �迭���� ������ top�� ����Ǿ� �ִ� �ε����� �����ϴ� ����
};

arrayStack::arrayStack(int capacity) {
	this->capacity = capacity;
	arr = new int[capacity];
	topIndex = -1;
}
bool arrayStack::empty() {
	if (topIndex == -1) {
		return true;
	}
	else {
		return false;
	}
}
void arrayStack::size() {
	cout << topIndex + 1 << endl;
}
void arrayStack::top() {
	if (empty()) {
		cout << "empty" << endl;
	}
	else {
		cout << arr[topIndex] << endl;

	}
}
void arrayStack::push(int data) {
	if (topIndex+1 == capacity) {
		cout << "error" << endl;
		return;
	}
	arr[++topIndex] = data;
}
void arrayStack::pop() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	cout << arr[topIndex--] << endl;
}

int main() {
	int commandCount = 0;
	cin >> commandCount;
	string command = "";
	arrayStack stack(commandCount);
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