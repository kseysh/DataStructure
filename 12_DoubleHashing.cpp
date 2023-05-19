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

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int divisor;
	int hashFnc(int key) {
		return key % capacity;
	}
	int hashFnc2(int key) {
		return divisor - (key % divisor);
	}
public:
	hashTable(int N, int M) {
		capacity = N;
		divisor = M;
		table = new entry[capacity];
		return;
	}
	void put(int key, string value) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid == ISITEM && probe <= capacity) {

			index = hashFnc(index + hashFnc2(key));
			probe++;

		}
		if (probe > capacity) {
			return;
		}
		table[index] = entry(key, value);
		return;
	}
	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				table[index].erase();
				return;
			}
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		return;
	}
	string find(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				cout << 1 << probe << endl;
				return table[index].value;
			}
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		cout << 0 << probe << endl;
		return "";
	}
};

int main() {
	int t, n, m, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		hashTable table(353333, 17);
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			table.put(num, to_string(num));
		}
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> num;
			table.find(num);
		}
	}
	return 0;
}
