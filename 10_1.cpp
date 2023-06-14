#include <iostream>
#include <vector>
using namespace std;
class MinHeap {
public:
	vector <int> v;
	int heap_size;

	MinHeap() {
		v.push_back(-1);// heap�� index 1���� ����Ѵ�.
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
		}//data�� 1�� ���� 1/2=0�� ����(v[0]=-1 �̹Ƿ�) swap���� �ʰ� upheap�� �������� �Ѵ�.
	}

	void downheap(int data) { //root ���� �ε����� ����
		if (data * 2 == heap_size) {			// ���� �ڽĸ� ���� �� 
			if (v[data] > v[data * 2]) {	//(�ּ� ���̹Ƿ� �������� ���̹Ƿ� ������ �ڽĸ� ���� ���� ����)
				swap(v[data], v[data * 2]);						
				downheap(data * 2);
			}
		}
		else if (data * 2 <= heap_size && data * 2 + 1 <= heap_size) { //����, ������ �ڽ� �� ���� ��
			if (v[data] > v[data * 2] || v[data] > v[data * 2 + 1]) {// �ڽ��� ����,������ �ڽĵ麸�� ũ��
				if (v[data * 2] > v[data * 2 + 1]) { // �� �ڽ��� ���ؼ�
					swap(v[data], v[data * 2 + 1]);  // �� ���� �ʰ� swap�Ѵ�.(�ּ� ���̹Ƿ� ���� ���� �÷��ش�.)
					downheap(data * 2 + 1);
				}
				else if (v[data * 2] <= v[data * 2 + 1]) {
					swap(v[data], v[data * 2]);
					downheap(data * 2);
				}
			}
		}

	}// �� �ڽ� ������ ������.

	void insert(int e) {
			heap_size++;
			v.push_back(e);
			upheap(heap_size); //��� �־��� ������ �����ε����� ������
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
		for (int i = 1; i < heap_size + 1; i++) {	//0���� -1�� �� �����Ƿ� heap_size�� ��ŭ �������� 
													//1���� heap_size + 1 ��ŭ ������ �� 
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