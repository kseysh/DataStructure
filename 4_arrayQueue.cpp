#include<iostream>
using namespace std;
class arrayQueue {
public:
	arrayQueue(int capacity);
	bool empty();
	int size();
	int front();
	int back();
	void enqueue_front(int data);
	void enqueue_back(int data);
	void dequeue_front();
	void dequeue_back();
	void print();
	void printTest() {
		cout << "frontIndex : " << frontIndex << " rearIndex : " << rearIndex << endl;
		for (int i = 0; i < capacity; i++) {
			cout << "index : " << i << " value : " << arr[i] << endl;
		}
	}// for test please delete
private:
	int* arr; // 큐의 원소를 저장하는 배열
	int capacity; // 큐의 최대 크기를 저장하는 변수
	int frontIndex; // 배열에서 큐의 front의 위치를 저장하는 변수
	int rearIndex; // 배열에서 큐의 rear의 위치 + 1 을 저장하는 변수 
	int queueSize; //큐의 크기를 저장하는 변수
};
arrayQueue::arrayQueue(int capacity) {
	this->capacity = capacity;
	arr = new int[capacity];
	frontIndex = rearIndex = 0;
	queueSize = 0;
}
bool arrayQueue::empty() {
	return (queueSize == 0);
}

int arrayQueue::size() {
	return queueSize;
}

int arrayQueue::front() {
	if (empty()) {
		return -1;
	}
	return arr[frontIndex];
}
int arrayQueue::back() {
	if (empty()) {
		return -1;
	}
	else if (rearIndex == 0) {
		return arr[capacity - 1];
	}
	else {
		return arr[rearIndex-1];
	}
}
void arrayQueue::enqueue_front(int data) {
	if (size() == capacity) {
		cout << "full" << endl;
		return;
	}
	else if (empty()) {
		arr[frontIndex] = data;
		if (frontIndex == capacity - 1) {
			rearIndex = 0;
		}
		else {
			rearIndex = frontIndex + 1;
		}
	}
	else if (frontIndex == 0) {
		frontIndex = capacity - 1;
		arr[frontIndex] = data;
	}
	else {
		arr[--frontIndex] = data;
	}
	queueSize++;
}
void arrayQueue::enqueue_back(int data) {
	if (size() == capacity) {
		cout << "full" << endl;
		return;
	}
	arr[rearIndex] = data;
	rearIndex = (rearIndex + 1) % capacity;
	queueSize++;
}
void arrayQueue::dequeue_front() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	else {
		cout << arr[frontIndex] << endl;
		frontIndex = (frontIndex + 1) % capacity;
		queueSize--;
	}

}
void arrayQueue::dequeue_back() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	else if (rearIndex== 0) {
		cout << arr[0] << endl;
		rearIndex = capacity - 1;
	}
	else {

		cout << rearIndex-- << endl;
	}
	queueSize--;
}

void arrayQueue::print() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	int iterateIndex = frontIndex;
	for (int i = 0; i < queueSize; i++) {
		cout << arr[iterateIndex] << "  ";
		if (iterateIndex == capacity - 1) {
			iterateIndex = 0;
		}
		else {
			iterateIndex++;
		}
	}
	cout << endl;
}


int main() {
	int commandCount = 0;
	int capacity = 0;
	string command = "";
	int inputValue = 0;

	cin >> commandCount >> capacity; // 순서 확인하기

	arrayQueue queue(capacity);

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
		else if (command == "test") {// for test please delete
			queue.printTest();
		}
		else {
			cout << "잘못 입력하셨습니다"<<endl;
		}

	}



	return 0;
}
