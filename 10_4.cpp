#include<iostream>
#include<vector>
using namespace std;

class MinHeap {
public:
	vector<int> arr;
	int newObjectCount;
	MinHeap() {
		arr.push_back(0);
		newObjectCount = 0;
	}
	int size() {
		return arr.size() - 1;
	}

	bool empty() {
		return (arr.size() == 1);
	}
	void swap(int& idx1, int& idx2) {
		int temp = idx1;
		idx1 = idx2;
		idx2 = temp;
	}
	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}
	int removeMin() {
		int min = arr[1];
		swap(arr[1], arr[size()]);
		arr.pop_back();
		downHeap(1);
		return min;
	}

	void upHeap(int idx) {
		int parent = idx / 2;
		if (arr[parent] > arr[idx]) {
			swap(arr[parent], arr[idx]);
			upHeap(parent);
		}
	}

	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;

		if (left == size()) {
			if (arr[left] < arr[idx]) {
				swap(arr[left], arr[idx]);
				downHeap(left);
			}
		}
		else if (left <= size() && right <= size()) {
			if (arr[idx] > arr[left] || arr[idx] > arr[right]) {
				if (arr[left] <= arr[right]) {
					swap(arr[left], arr[idx]);
					downHeap(left);

				}
				else {
					swap(arr[right], arr[idx]);
					downHeap(right);
				}
			}

		}
	}

	void postorder(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;

		if (left <= size()) {
			postorder(left);
		}
		if (right <= size()) {
			postorder(right);
		}
		cout << arr[idx] << " ";
	}

	void print() {
		for (int i = 0; i < size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	


	bool makeNewObject(int target) {
		if (arr[1] >= target) {
			cout << newObjectCount << endl;

			postorder(1);
			cout << endl;
			return false;
		}
		else {
			if (size() <= 2) {
				cout << "False" << endl;
				return false;
			}
		}
		int min1 = removeMin(); // 가장 낮은 온도
		int min2 = removeMin();
		int min3 = removeMin();
		int result = -1;
		if (min2 > min3) {
			result = (min1 + min2) / 2;
		}
		else {
			result = (min1 + min3) / 2;
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
		MinHeap h;
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