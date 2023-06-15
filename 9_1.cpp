#include <iostream>
#include <vector>

using namespace std;

class sortedSeqPQ { // ���� ����
public:
	vector<int> seq;
	void insertion(int e) {// pq�� �̰͸� ����� ������ �� ��!
		int idx = 0;
		for (idx = 0; idx < seq.size(); idx++) {// idx�� �������� seq.size()�� �������� for���� ������ ��
			if (seq[idx]< e) {
				break;
			}
		}
		seq.insert(seq.begin() + idx, e); // ���� �̷��� �ϸ� �� �ڿ� insert�ȴ�.
	}
	int removeMin() {
		int minVal = seq.back();
		seq.pop_back();//������ ����ϹǷ�, �ּ� ���̸� �ּڰ��� ���� �ڿ� ���� �����ؾ� �Ѵ�.
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