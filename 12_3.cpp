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

	entry() {// ����ִ� ��Ʈ�� ������
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) { // �����Ͱ� ����� ��Ʈ�� ������
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	void erase() {// ��Ʈ���� Available�� ����
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int size;
	int m;
	int hashFnc(int key) {
		return key % capacity;
	}
	int doubleHashFnc(int key) {
		return (m - key % m);
	}
public:
	hashTable(int N, int M) {
		capacity = N;
		m = M;
		size = 0;
		table = new entry[capacity];
		return;
	}
	void put(int key, string value) {
		int index = hashFnc(key);// ù ��° ���� ��ġ�� �ؽ��Լ��� �����
		int probe = 1;//����Ƚ��

		while (table[index].valid == ISITEM && probe <= capacity) {// ���� �����Ͱ� ����Ǿ������� ���

			index = (hashFnc(key) + probe * doubleHashFnc(key)) % capacity; // linear probing
			probe++;

		}
		if (probe > capacity) {
			return;
		}
		table[index] = entry(key, value); // hash table�� index��ġ�� ���һ���
		cout << probe + index << endl;
		size++;

		return;
	}
	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;
		string s = "None";

		while (table[index].valid != NOITEM && probe <= capacity) {// ���� �����Ͱ� �ְų� available�̸� Ž������
			if (table[index].valid == ISITEM && table[index].key == key) {
				s = table[index].value;
				table[index].erase();// ������ key�� ��ġ�ϴ� key�� ���� ��Ʈ���� ã���� �����ϰ� �Լ� ����
				size--;
				cout << s << endl;
				return;
			}
			index = (hashFnc(key) + probe * doubleHashFnc(key)) % capacity;
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
			index = (hashFnc(key) + probe * doubleHashFnc(key)) % capacity;
			probe++;
		}
		return "None";
	}

	void vacant() {
		cout << capacity - size << endl;
	}
};

int main() {
	int t, k, n , m;
	cin >> t >> n >> m;
	string command, s;
	hashTable table(n, m);
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