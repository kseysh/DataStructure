#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) {
		//operator() 함수는 괄호 연산자 오버로딩 함수임.
		return e1 < e2;
	}
};

class sortedSeqPQ { // 삽입 정렬
public:
	vector<int> seq;

	int size() {
		return seq.size();

	}
	bool empty() {
		return (seq.size() == 0);
	}
	void insert(int data) {
		seq.push_back(data);

	}
	void insertion(int e,vector<int>& v) {
		compare C;
		int idx = 0;
		for (idx = 0; (unsigned int)idx < v.size(); idx++) {
			if (C(v[idx], e)) {
				break;
			}
		}
		v.insert(v.begin() + idx, e);
	}
	int min() {
		if (empty()) {
			return -1;
		}
		return seq.back();
	}
	int removeMin() {
		if (empty()) {
			return -1;
		}
		int minVal = seq.back();
		seq.pop_back();
		return minVal;
	}

	void insertionSort() {
		vector<int> pq;
		int size = seq.size();
		for (int i = 0; i < size; i++) {
			int data = seq.back();
			seq.pop_back();
			insertion(data, pq);

		}
		for (int i = 0; i < size; i++) {
			seq.push_back(pq.back());
			pq.pop_back();
		}
	}

	void print() {
		if (empty()) {
			return;
		}
		for (int i = 0; (unsigned int)i < seq.size(); i++) {
			cout << seq[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int commandCount = 0;
	int value = 0;
	string command = "";
	cin >> commandCount;

	sortedSeqPQ pq;

	for (int i = 0; i < commandCount; i++) {
		cin >> command;
		if (command == "size") {
			cout << pq.size() << endl;
		}
		else if (command == "empty") {
			if (pq.empty()) {
				cout << 1 << endl; // 비어있다면 1 반환
			}
			else {
				cout << 0 << endl; // 안비어있다면 0 반환
			}

		}
		else if (command == "insert") {
			cin >> value;
			pq.insert(value);
		}
		else if (command == "min") {
			cout << pq.min() << endl;
		}
		else if (command == "removeMin") {
			cout << pq.removeMin() << endl;
		}
		else if (command == "insertionSort") {
			pq.insertionSort();
		}
		else if (command == "print") {
			pq.print();
		}
	}

	return 0;
}
