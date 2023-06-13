#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
public:
	vector<int> arr;
	int newObjectCount;
	MaxHeap() {
		arr.push_back(0);
		newObjectCount = 0;
	}
	int size() {
		return arr.size() - 1;
	}

	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}
	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}
	int removeMax() {
		int max = arr[1];
		swap(1, size());
		arr.pop_back();
		downHeap(1);
		return max;
	}

	void upHeap(int idx) {
		if (idx == 1) {
			return;
		}
		int parent = idx / 2;
		if (arr[parent] < arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}

	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] >= arr[right]) {
				child = left;
			}
			else {
				child = right;
			}
		}
		if (arr[child] > arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}

	void preorder(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		cout << arr[idx] << " ";
		if (left <= size()) {
			preorder(left);
		}
		if (right <= size()) {
			preorder(right);
		}
	}

	void print() {
		for (int i = 0; i < size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}



	bool makeNewObject(int target) {
		if (arr[1] <= target) {
			cout << newObjectCount << endl;

			preorder(1);
			cout << endl;
			return false;
		}
		else {
			if (size() <= 2) {
				cout << "False" << endl;
				return false;
			}
		}
		int max1 = removeMax(); // 가장 높은 온도
		int max2 = removeMax();
		int max3 = removeMax();
		int result = -1;
		if (max2 < max3) {
			result = (max1 + max2) / 2;
		}
		else {
			result = (max1 + max3) / 2;
		}
		insert(result);
		newObjectCount++;



		return true;
	}


};


int main() {
	int t, n, p, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		MaxHeap h;
		cin >> n >> p;
		for (int j = 0; j < n; j++) {
			cin >> num;
			h.insert(num);
		}
		while (true) {
			if (!h.makeNewObject(p)) {
				break;
			}
		}
	}


	return 0;
}