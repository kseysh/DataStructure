#include<iostream>
#include<string>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	string id;
	string pw;
	int valid;
	bool isLogin = false;

	entry() {// ����ִ� ��Ʈ�� ������
		id = "";
		pw = "";
		valid = NOITEM;
	}

	entry(string id, string pw) { // �����Ͱ� ����� ��Ʈ�� ������
		this->id = id;
		this->pw = pw;
		valid = ISITEM;
	}

};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashcode;
	int hashFnc(string id,int probe) {
		hashcode = 0;
		for (int i = 0; i < id.size(); i++) {
			int num = 1;
			for (int j = 0; j < i; j++) {
				num = 26 * num;
			}
			hashcode += (id[i]-'a') * num;
		}
		return (hashcode + probe) % capacity;
	}
public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
		return;
	}
	void put(string id, string pw) {
		int index = hashFnc(id,0);// ù ��° ���� ��ġ�� �ؽ��Լ��� �����
		int probe = 1;//����Ƚ��

		while (table[index].valid == ISITEM && probe <= capacity) {// ���� �����Ͱ� ����Ǿ������� ���
			if (table[index].id == id) {
				cout << "Invalid " << table[index].pw << endl;
				return;
			}
			index = hashFnc(id, probe); // linear probing
			probe++;

		}
		if (probe > capacity) {
			return;
		}
		cout << "Submit" << endl;
		table[index] = entry(id, pw); // hash table�� index��ġ�� ���һ���
		return;
	}
	void change(string id, string pw) {
		int index = hashFnc(id,0);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {// ���� �����Ͱ� �ְų� available�̸� Ž������
			if (table[index].valid == ISITEM && table[index].id == id) {
				table[index].pw = pw;
				cout << "Submit" << endl;
				return;
			}
			index = hashFnc(id, probe);
			probe++;
		}

		return;
	}

	void logout(string id) {
		int index = hashFnc(id, 0);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {// ���� �����Ͱ� �ְų� available�̸� Ž������
			if (table[index].valid == ISITEM && table[index].id == id) {
				table[index].isLogin = false;
				cout << "Submit" << endl;
				return;
			}
			index = hashFnc(id, probe);
			probe++;
		}
	}

	void login(string id, string pw) {
		int index = hashFnc(id, 0);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {// ���� �����Ͱ� �ְų� available�̸� Ž������
			if (table[index].valid == ISITEM && table[index].id == id) {
				if (table[index].pw == pw && table[index].isLogin == false) {
					table[index].isLogin = true;
					cout << "Submit" << endl;
					return;

				}
				else if (table[index].pw == pw && table[index].isLogin == true) {
					cout << "Quit" << endl;
					return;

				}
			}
			index = hashFnc(id, probe);
			probe++;
		}


		cout << "Invalid" << endl;

		return;
	}
};

int main() {
	int t;
	cin >> t;
	string command, s,p;
	hashTable table(500009);
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (command == "signup") {
			cin >> s >> p;
			table.put(s, p);
		}
		else if (command == "login") {
			cin >> s >> p;
			table.login(s, p);
		}
		else if (command == "logout") {
			cin >> s;
			table.logout(s);

		}
		else if (command == "change") {
			cin >> s >> p;
			table.change(s, p);
		}
	}

	return 0;
}