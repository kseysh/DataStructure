#include<iostream>
using namespace std;

class Stack
{
private:
	int* stackArray;
	int stackSize = 0;
	int topIndex = -1;

public:
	Stack(int commandCount) {
		stackArray = new int[commandCount];
		stackSize = commandCount;
	}
	~Stack() { delete[] stackArray; }

	void push(int inputValue)
	{
		if (topIndex == stackSize - 1) {
			cout << "½ºÅÃÀÌ ²Ë Ã¡½À´Ï´Ù.\n";
		}
		else {
			stackArray[++topIndex] = inputValue;
		}
	}

	void pop()
	{
		if (topIndex < 0) {
			cout << "empty." << endl;
		}
		else {
			cout << stackArray[topIndex--] << endl;
		}
	}

	void size() {
		cout << topIndex + 1 << endl; // top_index + 1 == size
	}
	

	void empty() {
		if (topIndex == -1) {
			cout << "empty" << endl;
		}
		else {
			cout << "not empty" << endl;
		}
	}
	

	void top()
	{
		if (topIndex < 0) {
			cout << "empty." << endl;
		}
			
		cout << stackArray[topIndex] << endl;
	}
};

int main()
{
	int commandCount=0;
	cin >> commandCount;
	string command="";
	Stack stack(commandCount);
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
			stack.empty();
		}
		else if (command == "top")
		{
			stack.top();
		}
	}

	return 0;
}