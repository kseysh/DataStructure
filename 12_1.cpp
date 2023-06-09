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
	int size;
	int hashFnc(int key) {
		return key % capacity;
	}
public:
	hashTable(int N) {
		capacity = N;
		size = 0;
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
		cout << probe + index << endl;
		size++;

		return;
	}
	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;
		string s = "None";

		while (table[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (table[index].valid == ISITEM && table[index].key == key) {
				s = table[index].value;
				table[index].erase();// 삭제할 key와 일치하는 key를 가진 엔트리를 찾으면 삭제하고 함수 종료
				size--;
				cout << s << endl;
				return;
			}
			index = hashFnc(index + 1);
			probe++;
		}
		cout << "None" << endl;

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
		return "None";
	}

	void vacant() {
		cout << capacity - size << endl;
	}
};

int main() {
	int t,k,n;
	cin >> t >> n;
	string command,s;
	hashTable table(n);
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (command == "put") {
			cin >> k >> s;
			table.put(k, s);
		}
		else if (command == "erase") {
			cin >> k;
			table.erase(k);
		}
		else if (command == "find") {
			cin >> k;
			cout << table.find(k) << endl;

		}
		else if (command == "vacant") {
			table.vacant();
		}
	}

	return 0;
}