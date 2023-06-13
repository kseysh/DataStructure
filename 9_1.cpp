#include <iostream>
#include <vector>

using namespace std;

class sortedSeqPQ { // »ðÀÔ Á¤·Ä
public:
	vector<int> seq;
	void insertion(int e) {
		int idx = 0;
		for (idx = 0; idx < seq.size(); idx++) {
			if (seq[idx]< e) {
				break;
			}
		}
		seq.insert(seq.begin() + idx, e);
	}
	int removeMin() {
		int minVal = seq.back();
		seq.pop_back();
		return minVal;
	}
};

int main() {
	int t,n,num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		sortedSeqPQ pq;
		vector<int> temp;
		vector<int> sum;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.insertion(num);
		}
		for (int j = 0; j < n; j++) {
			temp.push_back(pq.removeMin());
			if (j != 0) {
				sum.push_back(temp.front() + temp.back());
			}
		}
		for (int j = 0; j < n; j++) {
			cout << temp[j] << " ";
		}
		cout << endl;
		for (int j = 0; j < n-1; j++) {
			cout << sum[j] << " ";
		}
		cout << endl;
	}
	return 0;
}