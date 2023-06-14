#include <iostream>
#include <vector>

using namespace std;

class unsortedSeqPQ { // 삽입 정렬
public:
	vector<int> seq;

	void insert(int e, vector<int>& v) {
		v.push_back(e);
	}
	int removeMin(vector<int>& v) { // removeMin return 해주기!!
		int maxIdx = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] > v[maxIdx]) {
				maxIdx = i;
			}
		}
		int maxVal = v[maxIdx];
		v.erase(v.begin() + maxIdx);
		return maxVal;
	}
};

int main() {
	int t, n, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		unsortedSeqPQ pq;
		vector<int> sortedArr;
		vector<int> sum;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.insert(num,pq.seq);
		}
		for (int j = 0; j < n; j++) {
			sortedArr.push_back(pq.removeMin(pq.seq));
			if (j != 0) {
				sum.push_back(sortedArr.front() - sortedArr.back());
			}
		}
		for (int j = 0; j < n; j++) {
			cout << sortedArr[j] << " ";
		}
		cout << endl;
		for (int j = 0; j < n - 1; j++) {
			cout << sum[j] << " ";
		}
		cout << endl;
	}
	return 0;
}