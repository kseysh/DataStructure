#include <iostream>
#include <vector>
using namespace std;
class Heap {
public:
	vector <int> v;
	int heap_size;

	Heap() {
		v.push_back(-1);//heap�� �̰� �� ������� ùĭ ������µ� �� ���� -1��
		this->heap_size = 0;
	}
	void swap(int& data1, int& data2) {
		int tmp = data1;
		data1 = data2;
		data2 = tmp;
	}
	void upheap(int data) { // leaf�� �ִ´�. ���⼱ ������ �����ε����� ����
		if (v[data] < v[data / 2]) {
			swap(v[data], v[data / 2]); //�� �ڽİ� �θ��� �����ٲٰ�
			upheap(data / 2); //�� �θ� �ε����� �༭ ���Ӱ� �ٲ� �θ��� ���� �� �θ��� �θ��� ���ϰ� �ݺ���
		}
		else {}
	}

	void downheap(int data) { //root ���� �ε����� ����
		if (data * 2 == heap_size) { //���� �ڽĸ� ���� ��
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
				else if (v[data * 2] <= v[data * 2 + 1]) {//�ڽĵ��� ���� ������ ���, ���� �ڽ��� �����Ѵ�.
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
	int top() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return v[1];
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
	int size() {
		return heap_size;
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
			cout << "-1" << endl;
		}
		else {
			for (int i = 1; i <= heap_size; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Heap a;
	int num1 = 0;
	int num2 = 0;
	string word = " ";
	cin >> num1;
	for (int i = 1; i <= num1; i++) {
		cin >> word;
		if (word == "insert") {
			cin >> num2;
			a.insert(num2);
		}
		else if (word == "size") {
			cout << a.size() << endl;
		}
		else if (word == "isEmpty") {
			cout << a.isEmpty() << endl;
		}
		else if (word == "print") {
			a.print();
		}
		else if (word == "pop") {
			cout << a.pop() << endl;
		}
		else if (word == "top") {
			cout << a.top() << endl;
		}
	}
}