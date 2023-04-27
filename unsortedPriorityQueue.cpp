#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) {
		//operator() �Լ��� ��ȣ ������ �����ε� �Լ���.
		return e1 < e2;
	}
};

class unsortedSeqPQ { // ���� ����
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
			cout << -1 << endl;//������� �� -1 ���
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
			cout << -1 << endl;//������� �� -1 ���
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
				cout << 1 << endl; // ����ִٸ� 1 ��ȯ
			}
			else {
				cout << 0 << endl; // �Ⱥ���ִٸ� 0 ��ȯ
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