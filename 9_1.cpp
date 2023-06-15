#include <iostream>
#include <vector>

using namespace std;

class sortedSeqPQ { // 삽입 정렬
public:
	vector<int> seq;
	void insertion(int e) {// pq는 이것만 기억해 놓으면 될 듯!
		int idx = 0;
		for (idx = 0; idx < seq.size(); idx++) {// idx가 마지막에 seq.size()와 같아져서 for문이 끝나는 것
			if (seq[idx]< e) {
				break;
			}
		}
		seq.insert(seq.begin() + idx, e); // 따라서 이렇게 하면 맨 뒤에 insert된다.
	}
	int removeMin() {
		int minVal = seq.back();
		seq.pop_back();//스택을 사용하므로, 최소 힙이면 최솟값이 가장 뒤에 가게 정렬해야 한다.
		return minVal;
	}
};

int main() {
	int t,n,num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		sortedSeqPQ pq;
		vector<int> sortedArr;
		vector<int> sum;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.insertion(num);
		}
		for (int j = 0; j < n; j++) {
			sortedArr.push_back(pq.removeMin());
			if (j != 0) {
				sum.push_back(sortedArr.front() + sortedArr.back());
			}
		}
		for (int j = 0; j < n; j++) {
			cout << sortedArr[j] << " ";
		}
		cout << endl;
		for (int j = 0; j < n-1; j++) {
			cout << sum[j] << " ";
		}
		cout << endl;
	}
	return 0;
}