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
	void upheap(int data) { //leaf를 넣는다. 여기선 마지막 원소인덱스를 넣음
		if (v[data] < v[data / 2]) {
			swap(v[data], v[data / 2]); //그 자식과 부모의 값을바꾸고
			upheap(data / 2); //그 부모인덱스를 줘서 새롭게 바뀐 부모의 값과 그 부모의부모값을 비교하게 반복함
		}
		else {}
	}

	void downheap(int data) { //root 원소 인덱스를 넣음
		if (data * 2 <= heap_size && data * 2 + 1 > heap_size) { //왼쪽 자식만 있을 때
			if (v[data] > v[data * 2]) {
				swap(v[data], v[data * 2]);
				downheap(data * 2);
			}
			else { return; }
		}
		else if (data * 2 <= heap_size && data * 2 + 1 <= heap_size) { //왼쪽, 오른쪽 자식 다 있을 때
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
		else { //둘다 없을 때
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
			upheap(heap_size); //방금 넣어준 마지막 원소인덱스를 던져줌
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
			downheap(1); //1을 넘김
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
	void upheap(int data) { //External 친구들을 넣어줄꺼임,여기선 마지막 원소인덱스를 넣음
		if (v[data] > v[data / 2]) {
			swap(v[data], v[data / 2]); //그 자식과 부모의 값을바꾸고
			upheap(data / 2); //그 부모인덱스를 줘서 새롭게 바뀐 부모의 값과 그 부모의부모값을 비교하게 반복함
		}
		else {}
	}

	void downheap(int data) { //root 원소 인덱스를 넣음
		if (data * 2 <= heap_size && data * 2 + 1 > heap_size) { //왼쪽 자식만 있을 때
			if (v[data] < v[data * 2]) {
				swap(v[data], v[data * 2]);
				downheap(data * 2);
			}
			else { return; }
		}
		else if (data * 2 <= heap_size && data * 2 + 1 <= heap_size) { //왼쪽, 오른쪽 자식 다 있을 때
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
		else { //둘다 없을 때
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
			upheap(heap_size); //방금 넣어준 마지막 원소인덱스를 던져줌
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
			downheap(1); //1을 넘김
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