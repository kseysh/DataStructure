#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
public:
	vector<int> arr;
	int newObjectCount;
	MaxHeap() {
		arr.push_back(1001);//maxheap이면 최댓값, minheap이면 최솟값 넣어주기 꼭!
		newObjectCount = 0;
	}
	int size() {
		return arr.size() - 1;
	}

	void swap(int& idx1, int& idx2) {
		int temp =  idx1;
		idx1 = idx2;
		idx2 = temp;
	}
	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}
	int removeMax() {
		int max = arr[1];
		swap(arr[1], arr[size()]);
		arr.pop_back();
		downHeap(1);
		return max;
	}

	void upHeap(int idx) {
		int parent = idx / 2;
		if (arr[parent] < arr[idx]) {
			swap(arr[parent], arr[idx]);
			upHeap(parent);
		}
	}

	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;

		if (left == size()) {
			if (arr[left] > arr[idx]) {
				swap(arr[left], arr[idx]);
				downHeap(left);
			}
		}
		else if (left <= size() && right <= size()) {
			if (arr[idx] < arr[left] || arr[idx] < arr[right]) {
				if (arr[left] >= arr[right]) {
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