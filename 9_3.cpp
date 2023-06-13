#include <iostream>
#include <vector>

using namespace std;

class unsortedSeqPQ { // »ðÀÔ Á¤·Ä
public:
	vector<int> seq;

	void insert(int e, vector<int>& v) {
		v.push_back(e);
	}
	int removeMin(vector<int>& v) {
		int maxIdx = 0;

		for (int i = 0; (unsigned int)i < v.size(); i++) {
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
		vector<int> temp;
		vector<int> sum;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.insert(num,pq.seq);
		}
		for (int j = 0; j < n; j++) {
			temp.push_back(pq.removeMin(pq.seq));
			if (j != 0) {
				sum.push_back(temp.front() - temp.back());
			}
		}
		for (int j = 0; j < n; j++) {
			cout << temp[j] << " ";
		}
		cout << endl;
		for (int j = 0; j < n - 1; j++) {
			cout << sum[j] << " ";
		}
		cout << endl;
	}
	return 0;
}