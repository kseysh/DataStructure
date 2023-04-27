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

	void print(int data) {
		if (isEmpty()) {
			cout << "-1" << endl;
		}
		else {
			cout << v[data] << endl;
		}
	}
};
class MaxHeap {
public:
	vector <int> v;
	int heap_size;


	MaxHeap() {
		v.push_back(-1);
		this->heap_size = 0;
	}
	void swap(int& data1, int& data2) {
		int tmp = data1;
		data1 = data2;
		data2 = tmp;
	}
	void upheap(int data) { //External ģ������ �־��ٲ���,���⼱ ������ �����ε����� ����
		if (v[data] > v[data / 2]) {
			swap(v[data], v[data / 2]); //�� �ڽİ� �θ��� �����ٲٰ�
			upheap(data / 2); //�� �θ��ε����� �༭ ���Ӱ� �ٲ� �θ��� ���� �� �θ��Ǻθ��� ���ϰ� �ݺ���
		}
		else {}
	}

	void downheap(int data) { //root ���� �ε����� ����
		if (data * 2 <= heap_size && data * 2 + 1 > heap_size) { //���� �ڽĸ� ���� ��
			if (v[data] < v[data * 2]) {
				swap(v[data], v[data * 2]);
				downheap(data * 2);
			}
			else { return; }
		}
		else if (data * 2 <= heap_size && data * 2 + 1 <= heap_size) { //����, ������ �ڽ� �� ���� ��
			if (v[data] < v[data * 2] || v[data] < v[data * 2 + 1]) {
				if (v[data * 2] >= v[data * 2 + 1]) {
					swap(v[data], v[data * 2]);
					downheap(data * 2);
				}
				else if (v[data * 2] < v[data * 2 + 1]) {
					swap(v[data], v[data * 2 + 1]);
					downheap(data * 2 + 1);
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

	void print(int data) {
		if (isEmpty()) {
			cout << "-1" << endl;
		}
		else {
			cout << v[data] << endl;
		}
	}
};

int main() {
	int testCount = 0;
	int N = 0;
	int p = 0;
	int num = 0;
	cin >> testCount;
	for (int i = 1; i <= testCount; i++) {
		MinHeap a;
		MaxHeap b;
		cin >> N;
		cin >> p;
		for (int i = 1; i <= N; i++) {
			cin >> num;
			a.insert(num);
			b.insert(num);
		}
		a.print(p);
		for (int i = 1; i <= p; i++) {
			if (i == p) {
				cout << a.pop() << endl;
			}
			else {
				a.pop();
			}
		}
		b.print(p);
		for (int i = 1; i <= p; i++) {
			if (i == p) {
				cout << b.pop() << endl;
			}
			else {
				b.pop();
			}
		}
	}
}