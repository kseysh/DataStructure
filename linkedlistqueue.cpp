#include<iostream>
#include<string>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class listQueue {
public:
	listQueue();
	bool empty();
	int size();
	int front();
	int back();
	void enqueue_front(int data);
	void enqueue_back(int data);
	void dequeue_front();
	void dequeue_back();
	void print();
private:
	node* header;
	node* frontNode;
	node* rearNode;
	int queueSize; //큐의 크기를 저장하는 변수
	node* trailer;
	int listSize;
};

listQueue::listQueue() {
	frontNode = NULL;
	rearNode = NULL;
	header = new node;
	trailer = new node;
	queueSize = 0;
}
bool listQueue::empty() {
	return (queueSize == 0);
}
int listQueue::size() {
	return queueSize;
}
int listQueue::front() {
	if (empty()) {
		cout << "empty" << endl;
		return -1;
	}
	else {
		return frontNode->data;
	}
}
int listQueue::back() {
	if (empty()) {
		cout << "empty" << endl;
		return -1;
	}
	else {
		return rearNode->data;
	}
}
void listQueue::enqueue_front(int data) {
	node* newNode = new node;
	newNode->data = data;
	if (empty()) {
		frontNode = rearNode = newNode;

		header->next = frontNode;
		trailer->prev = rearNode;
	}
	else {
		newNode->next = frontNode;
		newNode->prev = header;
		header->next = newNode;
		frontNode->prev = newNode;
		frontNode = newNode;
	}
	queueSize++;
}
void listQueue::enqueue_back(int data) {
	node* newNode = new node;
	newNode->data = data;
	if (empty()) {
		frontNode = rearNode = newNode;
	}
	else {
		rearNode->next = newNode;
		newNode->next = trailer;
		trailer->prev = newNode;
		newNode->prev = rearNode;
		rearNode = newNode;
	}
	queueSize++;
}
void listQueue::dequeue_front() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	node* curNode = frontNode;
	if (size() == 1) {
		frontNode = rearNode = NULL;
	}
	else {
		header->next = frontNode->next;
		frontNode->next->prev = header;
		frontNode = frontNode->next;
	}
	delete curNode;
	queueSize--;
}
void listQueue::dequeue_back() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	node* curNode = rearNode;
	if (size() == 1) {
		frontNode = rearNode = NULL;
	}
	else {
		rearNode->prev->next = trailer;
		trailer->prev = rearNode->prev;
		rearNode = rearNode->prev;
	}
	delete curNode;
	queueSize--;
}
void listQueue::print() {
	node* curNode = header->next;
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	else {
		for (int i = 0; i < queueSize; i++) {
			cout << curNode->data << ' ';
			curNode = curNode->next;
		}
		cout << endl;
	}

}





int main() {
	int commandCount = 0;
	string command = "";
	int inputValue = 0;

	cin >> commandCount; // 순서 확인하기

	listQueue queue;

	for (int i = 0; i < commandCount; i++) {
		cin >> command;
		if (command == "empty") {
			if (queue.empty()) {
				cout << "empty" << endl;
			}
			else {
				cout << "unempty" << endl;
			}
		}
		else if (command == "size") {
			cout << queue.size() << endl;
		}
		else if (command == "front") {
			if (queue.front() == -1) {
				cout << "empty" << endl;
			}
			else {
				cout << queue.front() << endl;
			}
		}
		else if (command == "back") {
			if (queue.back() == -1) {
				cout << "empty" << endl;
			}
			else {
				cout << queue.back() << endl;
			}
		}
		else if (command == "enqueue_front") {
			cin >> inputValue;
			queue.enqueue_front(inputValue);
		}
		else if (command == "enqueue_back") {
			cin >> inputValue;
			queue.enqueue_back(inputValue);
		}
		else if (command == "dequeue_front") {
			queue.dequeue_front();
		}
		else if (command == "dequeue_back") {
			queue.dequeue_back();
		}
		else if (command == "print") {
			queue.print();
		}
		else {
			cout << "잘못 입력하셨습니다" << endl;
		}

	}



	return 0;
}