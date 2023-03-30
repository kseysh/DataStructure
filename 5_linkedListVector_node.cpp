#include<iostream>
#include<string>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
};

class nodeList {
public:
	nodeList();
	bool empty();
	int size();
	node* begin();
	node* end();
	void at(node* position); // node로 접근하는 at
	void set(node* position, int data); // node로 접근하는 set
	void erase(node* position); // node로 접근하는 erase
	void insert(node* position, int data); // node로 접근하는 insert
	void push_back(int data);
	void push_front(int data);
	void pop_back();
	void pop_front();
	void print();
	node* searchTarget(int targetData);
private:
	node* header;
	node* trailer;
	int listSize;
};

nodeList::nodeList() {
	header = new node();
	trailer = new node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = trailer->next = NULL;
	listSize = 0;
}
bool nodeList::empty() {
	return (listSize == 0);
}
int nodeList::size() {
	return listSize;
}

node* nodeList::begin() {
	return header->next;
}

node* nodeList::end() {
	return trailer;
}


void nodeList::at(node* position) {
	if (position == NULL) {
		cout << -1 << endl; // target이 NULL인 경우 -1 출력 
		return;
	}
	else {
		cout << position->data << endl; // 해당하는 데이터 값 출력
	}
}
void nodeList::set(node* position, int data) {
	if (position==NULL) {
		cout << -1 << endl; // target이 NULL인 경우 -1 출력
		return;
	}
	position->data = data;
}

void nodeList::erase(node* position) {
	if (position == NULL || position == trailer|| listSize==0) {
		cout << -1 << endl;
		return;
	}

	cout << position->data << endl;
	position->prev->next = position->next;
	position->next->prev = position->prev;
	delete position;
	listSize--;
}
void nodeList::insert(node* position, int data) {
	if (position == NULL) {
		cout << -1 << endl;
		return;
	}
	node* newNode = new node();
	newNode->data = data;
	newNode->prev = position->prev;
	newNode->next = position;
	position->prev->next = newNode;
	position->prev = newNode;
	listSize++;

}

node* nodeList::searchTarget(int index) {
	if (index < 0 || index >= listSize) {
		return NULL;
	}
	node* curNode = header;
	int currentData = 0;
	for (int i = 0; i < index+1; i++) {
		curNode = curNode->next;
	}
	
	return curNode;
}



void nodeList::push_back(int data) {
	insert(end(), data);
}
void nodeList::push_front(int data) {
	insert(begin(), data);
}
void nodeList::pop_back() {
	erase(end()->prev);
}
void nodeList::pop_front() {
	erase(begin());
}

void nodeList::print() {
	if (empty()) {
		cout << "-1" << endl; // 비어있을 경우 -1 출력
		return;
	}
	node* curNode = header;
	for (int i = 0; i < listSize; i++) {
		curNode = curNode->next;
		cout << curNode->data << ' ';
	}
	cout << endl;
}

int main() {
	int commandCount = 0;
	string command = "";
	int data = 0;
	int target = 0;
	nodeList list;

	cin >> commandCount;
	for (int i = 0; i < commandCount; i++) {
		cin >> command;
		if (command == "at") {
			cin >> target;
			list.at(list.searchTarget(target));
		}
		else if (command == "set") {
			cin >> target >> data;
			list.set(list.searchTarget(target), data);
		}
		else if (command == "insert") {
			cin >> target >> data;
			list.insert(list.searchTarget(target), data);
		}
		else if (command == "remove") {
			cin >> data;
			list.erase(list.searchTarget(data));
		}
		else if (command == "push_back") {
			cin >> data;
			list.push_back(data);
		}
		else if (command == "push_front") {
			cin >> data;
			list.push_front(data);
		}
		else if (command == "getSize") {
			cout << list.size() << endl;
		}
		else if (command == "empty") {
			if (list.empty()) {
				cout << 1 << endl; // 비어있을 경우 1 출력
			}
			else {
				cout << 0 << endl; // 비어있지 않을 경우 0 출력
			}
		}
		else if (command == "print") {
			list.print();
		}
		else if (command == "pop_front") {
			list.pop_front();
		}
		else if (command == "pop_back") {
			list.pop_back();
		}
		else {
			cout << "잘못 입력하셨습니다" << endl; // command 잘못 입력한 경우
		}
	}


	return 0;
}
