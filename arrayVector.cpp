#include<iostream>
#include<string>
using namespace std;

class arrayVector {
public:
	arrayVector();
	bool empty();
	int size();
	void at(int index);
	void set(int index, int data);
	void erase(int index);
	void insert(int index, int data);
	void push_back(int data);
	void push_front(int data);
	void pop_back();
	void pop_front();
	void print();
private:
	int capacity; // ������ �ִ� ũ��
	int vectorSize = 0; // ������ ���� ũ��
	int* arr;
	void reserve(int size); // ������ �ִ� ũ�⸦ size�� �����ϴ� �Լ�
};

arrayVector::arrayVector() {
	capacity = 1;
	vectorSize = 0;
	arr = new int[1];
}
bool arrayVector::empty() {
	return (vectorSize == 0);
}
int arrayVector::size() {
	return vectorSize;
}
void arrayVector::at(int index) {
	if (index < 0 || vectorSize <= index) {
		cout << -1 << endl; // �ش��ϴ� �ε��� ���� ���� ��� -1 ��� 
		return;
	}
	else {
		cout << arr[index] << endl; // �ش��ϴ� �ε��� �� ���
	}
}
void arrayVector::set(int index, int data) {
	if (index < 0 || vectorSize <= index) {
		cout << -1 << endl; // �ش��ϴ� �ε��� ���� ���� ��� -1 ���
		return;
	}
	arr[index] = data;
}
void arrayVector::erase(int index) {
	if (index < 0 || vectorSize <= index) {
		cout << -1 << endl; //�ش��ϴ� �ε��� ���� ���� ��� -1 ���
		return; 
	}
	cout << arr[index] << endl; // ������ �� ���
	for (int i = index + 1; i < vectorSize; i++) {
		arr[i - 1] = arr[i];
	}
	vectorSize--;
}
void arrayVector::insert(int index, int data) {
	if (index < 0 || vectorSize < index) {
		cout << -1 << endl;//�ش��ϴ� �ε��� ���� ���� ��� -1 ���
		return;
	}
	if (vectorSize == capacity) {
		reserve(2 + capacity);
	}
	for (int i = vectorSize - 1; i >= index; i--) {
		arr[i + 1] = arr[i];
	}
	arr[index] = data;
	vectorSize++;
}
void arrayVector::reserve(int size) {
	if (size<=capacity) {
		return;
	}
	int* tempArr = new int[size];
	for (int i = 0; i < vectorSize; i++) {
		tempArr[i] = arr[i];
	}

	if (arr != NULL) {
		delete[] arr;
	}
	arr = tempArr;
	capacity = size;
}

void arrayVector::push_back(int data) {
	insert(vectorSize, data);
}
void arrayVector::push_front(int data) {
	insert(0, data);
}
void arrayVector::pop_back() {
	erase(vectorSize - 1);
}
void arrayVector::pop_front() {
	erase(0);
}

void arrayVector::print() {
	if (empty()) {
		cout << "-1" << endl; // ������� ��� -1 ���
		return;
	}
	for (int i = 0; i < vectorSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	int commandCount = 0;
	string command = "";
	int data = 0;
	int index = 0;
	cin >> commandCount;
	arrayVector vector;
	for (int i = 0; i < commandCount; i++) {
		cin >> command;
		if (command == "at") {
			cin >> index;
			vector.at(index);
		}
		else if (command == "set") {
			cin >> index >> data;
			vector.set(index, data);
		}
		else if (command == "insert") {
			cin >> index >> data;
			vector.insert(index, data);
		}
		else if (command == "remove") {
			cin >> index;
			vector.erase(index);
		}
		else if (command == "push_back") {
			cin >> data;
			vector.push_back(data);
		}
		else if (command == "push_front") {
			cin >> data;
			vector.push_front(data);
		}
		else if (command == "getSize") {
			cout << vector.size() << endl;
		}
		else if (command == "empty") {
			if (vector.empty()) {
				cout << 1 << endl; // ������� ��� 1 ���
			}
			else {
				cout << 0 << endl; // ������� ���� ��� 0 ���
			}
		}
		else if (command == "print") {
			vector.print();
		}
		else if (command == "pop_front") {
			vector.pop_front();
		}
		else if (command == "pop_back") {
			vector.pop_back();
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl; // command �߸� �Է��� ���
		}
	}


	return 0;
}