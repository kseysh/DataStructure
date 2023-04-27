#include <iostream>
#include <vector>
using namespace std;
class Heap {
public:
	vector <int> v;
	int heap_size;

	Heap() {
		v.push_back(-1);//heap은 이거 꼭 해줘야함 첫칸 띄워놓는데 그 값은 -1로
		this->heap_size = 0;
	}
	void swap(int& data1, int& data2) {
		int tmp = data1;
		data1 = data2;
		data2 = tmp;
	}
	void upheap(int data) { // leaf를 넣는다. 여기선 마지막 원소인덱스를 넣음
		if (v[data] < v[data / 2]) {
			swap(v[data], v[data / 2]); //그 자식과 부모의 값을바꾸고
			upheap(data / 2); //그 부모 인덱스를 줘서 새롭게 바뀐 부모의 값과 그 부모의 부모값을 비교하게 반복함
		}
		else {}
	}

	void downheap(int data) { //root 원소 인덱스를 넣음
		if (data * 2 == heap_size) { //왼쪽 자식만 있을 때
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
				else if (v[data * 2] <= v[data * 2 + 1]) {//자식들의 값이 동일할 경우, 왼쪽 자식을 조절한다.
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
			downheap(1); //1을 넘김
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