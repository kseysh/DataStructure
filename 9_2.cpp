#include <iostream>
#include <vector>

using namespace std;


class unsortedSeqPQ { // »ðÀÔ Á¤·Ä
public:
	vector<int> seq;

	void insert(int e) {
		seq.push_back(e);
	}
	int removeMin() {
		int maxIdx = 0;
		for (int i = 0; (unsigned int)i < seq.size(); i++) {
			if (seq[i]%5==0) {
				if (seq[maxIdx] % 5 != 0) {
					maxIdx = i;
				}
				else if (seq[maxIdx] < seq[i]) {
					maxIdx = i;
				}
			}
			else {
				if (seq[maxIdx] % 5 != 0 && seq[maxIdx] < seq[i]) {
					maxIdx = i;
				}
			}
		}
		int maxVal = seq[maxIdx];
		seq.erase(seq.begin() + maxIdx);
		return maxVal;
	}
};

int main() {
	int t, n, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		unsortedSeqPQ pq;
		vector<int> v;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.insert(num);
		}
		for (int j = 0; j < n; j++) {
			cout << pq.removeMin() << " ";
		}
		cout << endl;
	}

	return 0;
}