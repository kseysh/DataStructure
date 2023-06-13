#include<iostream>
#include<string>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct nameEntry {
	int studentNum;
	string division;
	string name;
	int valid;
	bool isPresent = false;

	nameEntry() {// 비어있는 엔트리 생성자
		division = "";
		name = "";
		valid = NOITEM;
	}

	nameEntry(int num,string division, string name) { // 데이터가 저장된 엔트리 생성자
		this->studentNum = num;
		this->division = division;
		this->name = name;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}

};

struct studentNumEntry {
	int studentNum;
	string division;
	string name;
	int valid;
	bool isPresent = false;

	studentNumEntry() {// 비어있는 엔트리 생성자
		division = "";
		name = "";
		valid = NOITEM;

	}

	studentNumEntry(int num, string division, string name) { // 데이터가 저장된 엔트리 생성자
		this->studentNum = num;
		this->division = division;
		this->name = name;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}

};

class hashTable {
public:
	nameEntry* nameTable;
	studentNumEntry* studentNumTable;
	int capacity;
	int hashcode;
	int nowPresent = 0;
	int hashFncForName(string name, int probe) {
		hashcode = 0;
		for (int i = 0; i < name.size(); i++) {
			int num = 1;
			for (int j = 0; j < i; j++) {
				num = 26 * num;
			}
			hashcode += (name[i] - 'a') * num;
		}
		return (hashcode + probe) % capacity;
	}
	int hashFncForNum(int studentNum) {
		return studentNum % capacity;
	}
	hashTable(int N) {
		capacity = N;
		studentNumTable = new studentNumEntry[capacity];
		nameTable = new nameEntry[capacity];

		return;
	}
	void add(int studentNum,string division, string name) {
		int index1 = hashFncForNum(studentNum);// 첫 번째 조사 위치는 해시함수의 결과값
		int index2 = hashFncForName(name,0);// 첫 번째 조사 위치는 해시함수의 결과값

		int probe = 1;//조사횟수

		while (studentNumTable[index1].valid == ISITEM && probe <= capacity) {// 셀에 데이터가 저장되어있으면 계속
			index1 = hashFncForNum(index1+1); // linear probing
			probe++;

		}
		if (probe > capacity) {
			return;
		}
		probe = 1;

		while (nameTable[index2].valid == ISITEM && probe <= capacity) {// 셀에 데이터가 저장되어있으면 계속
			index2 = hashFncForName(name ,probe); // linear probing
			probe++;

		}
		studentNumTable[index1] = studentNumEntry(studentNum, division, name); // hash studentNumTable의 index위치에 원소삽입
		nameTable[index2] = nameEntry(studentNum, division, name); // hash studentNumTable의 index위치에 원소삽입
		return;
	}
	void change(int studentNum, string division) {
		int index = hashFncForNum(studentNum);

		int probe = 1;

		while (studentNumTable[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (studentNumTable[index].valid == ISITEM && studentNumTable[index].studentNum == studentNum) {
				studentNumTable[index].division = division;
				break;
			}
			index = hashFncForNum(index);
			probe++;
		}

		string name = studentNumTable[index].name;
		int index2 = hashFncForName(name, 0);
		probe = 1;
		while (nameTable[index2].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (nameTable[index2].valid == ISITEM && nameTable[index2].name== name) {
				nameTable[index2].division = division;
				break;
			}
			index2 = hashFncForName(name,probe);
			probe++;
		}
		return;
	}

	void name(int studentNum) {
		int index = hashFncForNum(studentNum);
		int probe = 1;
		while (studentNumTable[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (studentNumTable[index].valid == ISITEM && studentNumTable[index].studentNum == studentNum) {
				cout << studentNumTable[index].name << endl;
				break;
			}
			index = hashFncForNum(index);
			probe++;
		}
		return;
	}

	void remove(int studentNum) {
		int index = hashFncForNum(studentNum);
		int probe = 1;
		string name = "";
		while (studentNumTable[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (studentNumTable[index].valid == ISITEM && studentNumTable[index].studentNum == studentNum) {
				cout << studentNumTable[index].name<<" "<<studentNumTable[index].division << endl;
				name = studentNumTable[index].name;
				studentNumTable[index].erase();
				break;
			}
			index = hashFncForNum(index);
			probe++;
		}
		index = hashFncForName(name, 0);
		probe = 1;
		while (nameTable[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (nameTable[index].valid == ISITEM && nameTable[index].name == name) {
				if (nameTable[index].isPresent == true) {
					nowPresent--;
				}
				nameTable[index].erase();
				break;
			}
			index = hashFncForName(name, probe);
			probe++;
		}

	}

	void present(string name) {

		int probe = 1;
		int index2 = hashFncForName(name, 0);
		while (nameTable[index2].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (nameTable[index2].valid == ISITEM && nameTable[index2].name == name) {
				nameTable[index2].isPresent=true;
				break;
			}
			index2 = hashFncForName(name, probe);
			probe++;
		}

		if (nameTable[index2].valid != ISITEM || probe > capacity) {
			cout << "Invalid" << endl;
			return;
		}

		int studentNum = nameTable[index2].studentNum;
		int index = hashFncForNum(studentNum);

		probe = 1;
		while (studentNumTable[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (studentNumTable[index].valid == ISITEM && studentNumTable[index].studentNum == studentNum) {
				if (studentNumTable[index].isPresent == false) {
					nowPresent++;
					studentNumTable[index].isPresent = true;
				}
				break;

			}
			index = hashFncForNum(index);
			probe++;
		}

		cout << studentNumTable[index].studentNum << " " << studentNumTable[index].division << endl;

		return;
	}

	void absent(string name) {

		int probe = 1;
		int index2 = hashFncForName(name, 0);
		while (nameTable[index2].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (nameTable[index2].valid == ISITEM && nameTable[index2].name == name) {
				nameTable[index2].isPresent = false;
				break;
			}
			index2 = hashFncForName(name, probe);
			probe++;
		}

		if (nameTable[index2].valid != ISITEM || probe > capacity) {
			cout << "Invalid" << endl;
			return;
		}

		int studentNum = nameTable[index2].studentNum;
		int index = hashFncForNum(studentNum);


		probe = 1;
		while (studentNumTable[index].valid != NOITEM && probe <= capacity) {// 셀에 데이터가 있거나 available이면 탐색지속
			if (studentNumTable[index].valid == ISITEM && studentNumTable[index].studentNum == studentNum) {
				if (studentNumTable[index].isPresent == true) {
					nowPresent--;
					studentNumTable[index].isPresent = false;

				}
				break;
			}
			index = hashFncForNum(index);
			probe++;
		}

		cout << studentNumTable[index].studentNum << " " << studentNumTable[index].division << endl;

		return;
	}

};

int main() {
	int t,x;
	cin >> t;
	string command, s, c;
	hashTable table(500009);
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (command == "add") {
			cin >> x >> c >> s;
			table.add(x,c, s);
		}
		else if (command == "delete") {
			cin >> x;
			table.remove(x);
		}
		else if (command == "name") {
			cin >> x;
			table.name(x);

		}
		else if (command == "change") {
			cin >> x >> c;
			table.change(x, c);
		}
		else if (command == "present") {
			cin >> s;
			table.present(s);
		}
		else if (command == "absent") {
			cin >> s;
			table.absent(s);
		}
	}
	cout << table.nowPresent << endl;

	return 0;
}