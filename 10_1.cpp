#include <iostream>
#include <vector>
using namespace std;
class MinHeap {
public:
	vector <int> v;
	int heap_size;

	MinHeap() {
		v.push_back(-1);
		this->heap_size = 0;
	}
	void swap(int& data1, int& data2) {
		int tmp = data1;
		data1 = data2;
		data2 = tmp;
	}
	void upheap(int data) { //leaf�� �ִ´�. ���⼱ ������ �����ε����� ����
		if (v[data] < v[data / 2]) {
			swap(v[data], v[data / 2]); //�� �ڽİ� �θ��� �����ٲٰ�
			upheap(data / 2); //�� �θ��ε����� �༭ ���Ӱ� �ٲ� �θ��� ���� �� �θ��Ǻθ��� ���ϰ� �ݺ���
		}
		else {}
	}

	void downheap(int data) { //root ���� �ε����� ����
		if (data * 2 <= heap_size && data * 2 + 1 > heap_size) { //���� �ڽĸ� ���� ��
			if (v[data] > v[data * 2]) {
				swap(v[data], v[data * 2]);
				downheap(data * 2);
			}
			else { return; }
		}
		else if (data * 2 <= heap_size && data * 2 + 1 <= heap_size) { //����, ������ �ڽ� �� ���� ��
			if (v[data] > v[data * 2] || v[data] > v[data * 2 + 1]) {
				if (v[data * 2] > v[data * 2 + 1]) {
					swap(v[data], v[data * 2 + 1]);
					downheap(data * 2 + 1);
				}
				else if (v[data * 2] <= v[data * 2 + 1]) {
					swap(v[data], v[data * 2]);
					downheap(data * 2);
				}
				else { return; }
			}
			else { return; }
		}
		else { //�Ѵ� ���� ��
			return;
		}

	}

	void insert(int e) {
		if (heap_size == 0) {
			heap_size++;
			v.push_back(e);
		}
		else {
			heap_size++;
			v.push_back(e);
			upheap(heap_size); //��� �־��� ������ �����ε����� ������
		}
	}

	int pop() {
		if (isEmpty()) {
			return -1;
		}
		else {
			int result = v[1];
			swap(v[1], v[heap_size]);
			v.pop_back();
			heap_size--;
			downheap(1); //1�� �ѱ�
			return result;
		}
	}


	bool isEmpty() {
		if (heap_size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void print() {
		if (isEmpty()) {
			cout << "-1";
		}
		for (int i = 1; i < heap_size+1; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	void top() {
		if (isEmpty()) {
			cout << -1 << endl;
		}
		else {
			cout << v[1] << endl;
		}
	}
};

int main() {
	int t,num;
	string command;
	cin >> t;
	MinHeap heap;
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (command == "insert") {
			cin >> num;
			heap.insert(num);
		}
		else if (command == "size") {
			cout << heap.heap_size << endl;
		}
		else if (command == "isEmpty") {
			cout << heap.isEmpty()<<endl;
		}
		else if (command == "pop") {
			cout << heap.pop() << endl;
		}
		else if (command == "top") {
			heap.top();
		}
		else if (command == "print") {
			heap.print();
		}
		else {
			cout << "�߸� �Է�" << endl;
		}
	}
}