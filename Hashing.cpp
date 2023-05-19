#include<iostream>
#include<string>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;

	entry() {// 비어있는 엔트리 생성자
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) { // 데이터가 저장된 엔트리 생성자
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	void erase() {// 엔트리를 Available로 변경
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashFnc(int key) {
		return key % capacity;
	}
public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
		return;
	}
	void put(int key, string value) {
		int index = hashFnc(key);// 첫 번째 조사 위치는 해시함수의 결과값
		int probe = 1;//조사횟수

		while (table[index].valid == ISITEM && probe <= capacity) {// 셀에 데이터가 저장되어있으면 계속

			index = hashFnc(index + 1); // linear probing
			probe++;

		}
		if (probe > capacity) {
			return;
		}
		table[index] = entry(key, value); // hash table의 index위치에 원소삽입
		return;
	}
	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (table[index].valid == ISITEM && table[index].key == key) {
				table[index].erase();// 삭제할 key와 일치하는 key를 가진 엔트리를 찾으면 삭제하고 함수 종료
				cout << 1 << probe <<endl;
				return;
			}
			index = hashFnc(index + 1);
			probe++;
		}
		cout << 0 << probe <<endl;

		return;
	}
	string find(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				return table[index].value;
			}
			index = hashFnc(index + 1);
			probe++;
		}
		return "";
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n,num;
		cin >> n;
		hashTable table(353333);
		for (int j = 0; j < n; j++) {
			cin >> num;
			table.put(num,to_string(num));
		}

		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int num1;
			cin >> num1;
			table.erase(num1);
		}
	}

	return 0;
}