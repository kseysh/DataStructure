#include <iostream>
#include <vector>
using namespace std;
class MinHeap {
public:
	vector <int> v;
	int heap_size;

	MinHeap() {
		v.push_back(-1);// heap은 index 1부터 사용한다.
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
		}//data가 1일 때는 1/2=0과 비교해(v[0]=-1 이므로) swap하지 않고 upheap이 끝나도록 한다.
	}

	void downheap(int data) { //root 원소 인덱스를 넣음
		if (data * 2 == heap_size) {			// 왼쪽 자식만 있을 때 
			if (v[data] > v[data * 2]) {	//(최소 힙이므로 차곡차곡 쌓이므로 오른쪽 자식만 있을 수는 없음)
				swap(v[data], v[data * 2]);						
				downheap(data * 2);
			}
		}
		else if (data * 2 <= heap_size && data * 2 + 1 <= heap_size) { //왼쪽, 오른쪽 자식 다 있을 때
			if (v[data] > v[data * 2] || v[data] > v[data * 2 + 1]) {// 자신이 왼쪽,오른쪽 자식들보다 크면
				if (v[data * 2] > v[data * 2 + 1]) { // 두 자식을 비교해서
					swap(v[data], v[data * 2 + 1]);  // 더 작은 쪽과 swap한다.(최소 힙이므로 작은 값을 올려준다.)
					downheap(data * 2 + 1);
				}
				else if (v[data * 2] <= v[data * 2 + 1]) {
					swap(v[data], v[data * 2]);
					downheap(data * 2);
				}
			}
		}

	}// 즉 자식 원투로 나뉜다.

	void insert(int e) {
			heap_size++;
			v.push_back(e);
			upheap(heap_size); //방금 넣어준 마지막 원소인덱스를 던져줌
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

	void print() {
		if (isEmpty()) {
			cout << "-1";
		}
		for (int i = 1; i < heap_size + 1; i++) {	//0에는 -1이 들어가 있으므로 heap_size번 만큼 돌리려면 
													//1부터 heap_size + 1 만큼 돌려야 함 
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
			cout << "잘못 입력" << endl;
		}
	}
}