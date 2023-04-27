#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) {
		//operator() 함수는 괄호 연산자 오버로딩 함수임.
		return e1 < e2;
	}
};

class unsortedSeqPQ { // 삽입 정렬
public:
	vector<int> seq;

	int size(vector<int>& v) {
		return v.size();
	}
	bool empty(vector<int>& v) {
		return (v.size() == 0);
	}
	void insert(int e,vector<int>& v) {
		v.push_back(e);
	}
	int min(vector<int>& v) {
		if (empty(v)) {
			return -1;
		}
		compare C;
		int minVal = v[0];

		for (int i = 0; (unsigned int)i < v.size(); i++) {
			if (C(v[i], minVal)) {
				minVal = v[i];
			}
		}

		return minVal;
	}
	int removeMin(vector<int>& v) {
		if (empty(v)) {
			return -1;
		}
		compare C;
		int minIdx = 0;

		for (int i = 0; (unsigned int)i < v.size(); i++) {
			if (C(v[i], v[minIdx])) {
				minIdx = i;
			}
		}
		int minVal = v[minIdx];
		v.erase(v.begin() + minIdx);
		return minVal;
	}

	void insertionSort() {
		if (empty(seq)) {
			cout << -1 << endl;//비어있을 시 -1 출력
			return;
		}
		vector<int> pq;
		int size = seq.size();
		for (int i = 0; i < size; i++) {
			int value = seq.back();
			seq.pop_back();
			insert(value, pq);
		}
		for (int i = 0; i < size; i++) {
			int val = removeMin(pq);
			seq.push_back(val);
		}

	}

	void print() {
		if (empty(seq)) {
			cout << -1 << endl;//비어있을 시 -1 출력
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

	unsortedSeqPQ pq;

	for (int i = 0; i < commandCount; i++) {
		cin >> command;
		if (command == "size") {
			cout << pq.size(pq.seq) << endl;
		}
		else if (command == "empty") {
			if (pq.empty(pq.seq)) {
				cout << 1 << endl; // 비어있다면 1 반환
			}
			else {
				cout << 0 << endl; // 안비어있다면 0 반환
			}

		}
		else if (command == "insert") {
			cin >> value;
			pq.insert(value,pq.seq);
		}
		else if (command == "min") {
			cout << pq.min(pq.seq) << endl;
		}
		else if (command == "removeMin") {
			cout << pq.removeMin(pq.seq) << endl;
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
