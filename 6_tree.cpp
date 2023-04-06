#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	node* parent;
	vector <node*> children;

	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}

};

class Tree {
public:
	node* root;
	int depth;
	vector <node*> nodeList; //트리에 추가되는 모든 노드들을 여기에 저장
	//노드 리스트는 트리를 위한 것 보다 트리에 대한 함수를 도와주기 위한 것..?

	Tree(int data) {
		this->depth = 0;
		this->root = new node(data,nullptr);
		this->nodeList.push_back(root);
	}
	
	int find(int data, vector<node*>& list) {//노드포인터 벡터에서 특정 노드를 찾는 함수
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) { // 노드를 찾았을 경우, 인덱스를 반환
				return i;
			}
		}
		return -1; // 노드가 존재하지 않을 경우, -1을 반환
	}

	void insertNode(int parentData, int data) { //parentData을 가진 노드에 data를 가진 노드를 자식으로 넣는다.
		if (find(data, nodeList) != -1) {//data가 nodeList에 있는 값인지 (중복된 값인지) 확인
			cout << -1 << endl;
			return;
		}
		int index = find(parentData, nodeList);
		if (index == -1) {// 부모 노드가 존재하지 않음
			cout << -1 << endl;
			return;
		}

		node* parentNode = nodeList[index];
		node* newNode = new node(data, parentNode);
		parentNode->children.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}

	void deleteNode(int data) {
		int index = find(data, nodeList);
		if (index == -1) { // 삭제할 데이터가 없는 경우
			cout << -1 << endl;
			return;
		}

		node* delNode = nodeList[index]; // delNode에 삭제하려는 노드의 주소 저장
		if (delNode == root) { // 삭제하려는 노드가 root일 경우, 삭제하지 않음
			return;
		}

		node* parentNode = delNode->parent;// parentNode에 삭제하려는 노드의 부모 노드 주소를 저장
		for (int i = 0; i < delNode->children.size(); i++) {
			parentNode->children.push_back(delNode->children[i]);//delNode의 자식들을 parNode의 자식으로 삽입
			delNode->children[i]->parent = parentNode; // 삭제하려는 노드의 자식들의 부모를 parentNode로 설정
		}

		vector<node*>& child = parentNode->children;
		child.erase(child.begin() + find(data, child));//find로 인덱스를 확인 후 그 인덱스를 삭제하는 함수
		// vector.erase(vector.begin()+index)처럼 사용한다.
		nodeList.erase(nodeList.begin() + index);
		delete delNode;
		return;
	}

	void printParent(int data) {
		int index = find(data, nodeList);
		if (index == -1) { // 노드가 존재하지 않음
			cout << -1 << endl;
			return;
		}

		node* curNode = nodeList[index];
		cout << curNode->parent->data << endl; // 부모를 출력
	}

	void printChild(int data) {//노드의 자식들을 출력하는 함수
		int index = find(data, nodeList);
		if (index == -1) { // 노드가 존재하지 않음
			cout << -1 << endl;
			return;
		}
		vector<node*>& child = nodeList[index]->children;
		if (child.size() == 0) {
			cout << 0;//노드의 자식 노드가 없을 경우 0을 출력
		}
		else {
			for (int i = 0; i < child.size(); i++) {// 자식들을 모두 출력
				cout << child[i]->data << " ";
			}
		}
		cout << endl;
	}
	void goDepth(node* currentNode) {
		if (currentNode->parent != NULL) {//현재 노드가 루트 노드가 아니면 depth를 1 증가
			depth++;
			goDepth(currentNode->parent);//parent의 노드로 이동
		}
		else if (currentNode->parent == NULL) {//만약 현재 노드가 루트 노드이면 지금까지 더한 depth를 출력
			cout << depth << endl;
			depth = 0;
		}
	}

	void printDepth(int data) {
		int index = find(data, nodeList);
		if (index == -1) { 
			cout << -1 << endl; // print 할 데이터가 없는 경우 -1 출력
			return;
		}
		else {
			for (int i = 0; i < nodeList.size(); i++) {
				if (nodeList[i]->data == data) {
					goDepth(nodeList[i]);
				}
			}
		}
	
	}
};

int main() {
	
	Tree a(1);
	int commandCount = 0;
	int parentNode = 0;
	int childNode = 0;
	int target = 0;

	string word = " ";
	cin >> commandCount;
	for (int i = 1; i <= commandCount; i++) {
		cin >> word;
		if (word == "insert") {
			cin >> parentNode;
			cin >> childNode;
			a.insertNode(parentNode, childNode);
		}
		else if (word == "printChild") {
			cin >> target;
			a.printChild(target);
		}
		else if (word == "printDepth") {
			cin >> target;
			a.printDepth(target);
		}
		else if (word == "printParent") {
			cin >> target;
			a.printParent(target);
		}
		else if (word == "delete") {
			cin >> target;
			a.deleteNode(target);
		}
		else {
			cout << "잘 못 입력하셨습니다.\n";
		}
	}
	
	
	
}