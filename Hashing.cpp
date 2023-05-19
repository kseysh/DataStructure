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
		int index = hashFnc(key);// ù ��° ���� ��ġ�� �ؽ��Լ��� �����
		int probe = 1;//����Ƚ��

		while (table[index].valid == ISITEM && probe <= capacity) {// ���� �����Ͱ� ����Ǿ������� ���

			index = hashFnc(index + 1); // linear probing
			probe++;

		}
		if (probe > capacity) {
			return;
		}
		table[index] = entry(key, value); // hash table�� index��ġ�� ���һ���
		return;
	}
	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {// ���� �����Ͱ� �ְų� available�̸� Ž������
			if (table[index].valid == ISITEM && table[index].key == key) {
				table[index].erase();// ������ key�� ��ġ�ϴ� key�� ���� ��Ʈ���� ã���� �����ϰ� �Լ� ����
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