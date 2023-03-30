#include<iostream>
#include<string>
using namespace std;

class Vector
{
private:
	int* arr;
	int capacity;
	int size;
	int front, rear;	// front: 배열의 첫번째 원소, rear: 배열의 마지막 원소의 뒤

public:
	Vector()
	{
		this->capacity = 2;
		this->size = 0;
		this->front = 0;
		this->rear = 0;
		arr = new int[capacity];
	}
	~Vector() { delete[] arr; }

	bool empty()
	{
		return !size;
	}

	int at(int index)
	{
		if (empty() || index >= size)
			return -1;
		else
			return arr[(front + index) % capacity];
	}

	void set(int index, int data)
	{
		if (empty() || index >= size)
			cout << -1 << '\n';
		else
		{
			arr[(front + index) % capacity] = data;
		}
	}

	void doublingUp()
	{
		int* newArr = new int[capacity * 2];
		for (int i = 0; i < capacity; i++)
		{
			newArr[i] = arr[(front + i) % capacity];
		}
		capacity *= 2;
		front = 0;
		rear = size;
		delete[] arr;
		arr = newArr;
	}

	void doublingDown()
	{
		int* newArr = new int[capacity / 2];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[(front + i) % capacity];
		}

		capacity /= 2;
		front = 0;
		rear = size;
		delete[] arr;
		arr = newArr;
	}

	void insert(int index, int data)
	{
		if (size == capacity)
			this->doublingUp();
		for (int i = size; i > index; i--)
		{
			arr[(front + i) % capacity] = arr[(front + i - 1) % capacity];
		}
		arr[(front + index) % capacity] = data;
		size++;
		rear = (rear + 1) % capacity;
	}

	void remove(int index)
	{
		if (empty() || index >= size)
			cout << -1 << '\n';
		else
		{
			cout << arr[(front + index) % capacity] << '\n';
			for (int i = index; i < size - 1; i++)
			{
				arr[(front + i) % capacity] = arr[(front + i + 1) % capacity];
			}
			size--;
			if (rear == 0) rear = capacity;
			rear = (rear - 1) % capacity;

			if (size <= capacity / 2 && capacity > 2)
				this->doublingDown();
		}
	}

	void push_front(int data) {
		insert(0, data);
	}

	void push_back(int data)
	{
		
		if (size == capacity) {
			this->doublingUp();
		}
		arr[(rear++) % capacity] = data;
		size++;
		
	}

	void pop_front() {
		remove(0);
	}

	void pop_back() {
		remove(rear-1);
	}

	int getSize() { return size; }
	void print()
	{
		if (empty())
		{
			cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < size; i++)
		{
			cout << arr[(front + i) % capacity] << ' ';
		}
		cout << '\n';
	}
};

int main()
{
	int N;
	cin >> N;

	Vector vector;
	for (int n = 0; n < N; n++)
	{

		int index = 0;
		int data = 0;
		string command;
		cin >> command;


		if (command == "at")
		{
			int index;
			cin >> index;
			cout << vector.at(index) << '\n';
		}
		else if (command == "set")
		{
			cin >> index >> data;
			vector.set(index, data);
		}
		else if (command == "insert")
		{
			cin >> index >> data;
			vector.insert(index, data);
		}
		else if (command == "remove")
		{
			cin >> index;
			vector.remove(index);
		}
		else if (command == "push_back")
		{
			cin >> data;
			vector.push_back(data);
		}
		else if (command == "push_front")
		{
			cin >> data;
			vector.push_front(data);
		}
		else if (command == "pop_front")
		{
			vector.pop_front();

		}
		else if (command == "pop_back")
		{
			vector.pop_back();
		}
		else if (command == "getSize")
		{
			cout << vector.getSize() << '\n';
		}
		else if (command == "empty")
		{
			cout << vector.empty() << '\n';
		}
		else if (command == "print")
		{
			vector.print();
		}
	}
	return 0;
}