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
	vector <node*> nodeList; //Ʈ���� �߰��Ǵ� ��� ������ ���⿡ ����
	//��� ����Ʈ�� Ʈ���� ���� �� ���� Ʈ���� ���� �Լ��� �����ֱ� ���� ��..?

	Tree(int data) {
		this->depth = 0;
		this->root = new node(data,nullptr);
		this->nodeList.push_back(root);
	}
	
	int find(int data, vector<node*>& list) {//��������� ���Ϳ��� Ư�� ��带 ã�� �Լ�
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) { // ��带 ã���� ���, �ε����� ��ȯ
				return i;
			}
		}
		return -1; // ��尡 �������� ���� ���, -1�� ��ȯ
	}

	void insertNode(int parentData, int data) { //parentData�� ���� ��忡 data�� ���� ��带 �ڽ����� �ִ´�.
		if (find(data, nodeList) != -1) {//data�� nodeList�� �ִ� ������ (�ߺ��� ������) Ȯ��
			cout << -1 << endl;
			return;
		}
		int index = find(parentData, nodeList);
		if (index == -1) {// �θ� ��尡 �������� ����
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
		if (index == -1) { // ������ �����Ͱ� ���� ���
			cout << -1 << endl;
			return;
		}

		node* delNode = nodeList[index]; // delNode�� �����Ϸ��� ����� �ּ� ����
		if (delNode == root) { // �����Ϸ��� ��尡 root�� ���, �������� ����
			return;
		}

		node* parentNode = delNode->parent;// parentNode�� �����Ϸ��� ����� �θ� ��� �ּҸ� ����
		for (int i = 0; i < delNode->children.size(); i++) {
			parentNode->children.push_back(delNode->children[i]);//delNode�� �ڽĵ��� parNode�� �ڽ����� ����
			delNode->children[i]->parent = parentNode; // �����Ϸ��� ����� �ڽĵ��� �θ� parentNode�� ����
		}

		vector<node*>& child = parentNode->children;
		child.erase(child.begin() + find(data, child));//find�� �ε����� Ȯ�� �� �� �ε����� �����ϴ� �Լ�
		// vector.erase(vector.begin()+index)ó�� ����Ѵ�.
		nodeList.erase(nodeList.begin() + index);
		delete delNode;
		return;
	}

	void printParent(int data) {
		int index = find(data, nodeList);
		if (index == -1) { // ��尡 �������� ����
			cout << -1 << endl;
			return;
		}

		node* curNode = nodeList[index];
		cout << curNode->parent->data << endl; // �θ� ���
	}

	void printChild(int data) {//����� �ڽĵ��� ����ϴ� �Լ�
		int index = find(data, nodeList);
		if (index == -1) { // ��尡 �������� ����
			cout << -1 << endl;
			return;
		}
		vector<node*>& child = nodeList[index]->children;
		if (child.size() == 0) {
			cout << 0;//����� �ڽ� ��尡 ���� ��� 0�� ���
		}
		else {
			for (int i = 0; i < child.size(); i++) {// �ڽĵ��� ��� ���
				cout << child[i]->data << " ";
			}
		}
		cout << endl;
	}
	void goDepth(node* currentNode) {
		if (currentNode->parent != NULL) {//���� ��尡 ��Ʈ ��尡 �ƴϸ� depth�� 1 ����
			depth++;
			goDepth(currentNode->parent);//parent�� ���� �̵�
		}
		else if (currentNode->parent == NULL) {//���� ���� ��尡 ��Ʈ ����̸� ���ݱ��� ���� depth�� ���
			cout << depth << endl;
			depth = 0;
		}
	}

	void printDepth(int data) {
		int index = find(data, nodeList);
		if (index == -1) { 
			cout << -1 << endl; // print �� �����Ͱ� ���� ��� -1 ���
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
			cout << "�� �� �Է��ϼ̽��ϴ�.\n";
		}
	}
	
	
	
}