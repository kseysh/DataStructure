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
	int max;
	int h;
	vector <node*> nodeList; //Ʈ���� �߰��Ǵ� ��� ������ ���⿡ ����
	//��� ����Ʈ�� Ʈ���� ���� �� ���� Ʈ���� ���� �Լ��� �����ֱ� ���� ��..?

	Tree(int data) {
		this->depth = 0;
		this->h = 0;
		this->max = -1;
		this->root = new node(data, nullptr);
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
		if (find(data, nodeList) != -1) {
			cout << -1 << endl;//data�� nodeList�� �ִ� ������ (�ߺ��� ������) Ȯ���ϰ� ������ -1 ���
			return;
		}
		int index = find(parentData, nodeList);
		if (index == -1) {
			cout << -1 << endl;// �θ� ��尡 �������� �����顡���������
			return;
		}

		node* parentNode = nodeList[index];
		node* newNode = new node(data, parentNode);
		parentNode->children.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}

	void visit(node* currentNode) {
		cout << currentNode->data << " ";
	}

	void preorder(node* currentNode) {
		visit(currentNode);
		for (int i = 0; i < currentNode->children.size(); i++) {
			preorder(currentNode->children[i]);
		}
	}
	void postorder(node* currentNode) {
		for (int i = 0; i < currentNode->children.size(); i++) {
			postorder(currentNode->children[i]);
		}
		visit(currentNode);
	}


	int goDepth(node* currentNode) {// ����� ���̸� ��ȯ�ϴ� �Լ�
		if (currentNode->parent != NULL) {//���� ��尡 ��Ʈ ��尡 �ƴϸ� depth�� 1 ����
			depth++;
			goDepth(currentNode->parent);//parent�� ���� �̵�
		}
		else if (currentNode->parent == NULL) {//���� ���� ��尡 ��Ʈ ����̸� ���ݱ��� ���� depth�� ���
			return depth;
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

	void height() {
		for (int i = 0; i < nodeList.size(); i++) {
			depth = 0;
			h = goDepth(nodeList[i]);//depth�߿� ���� ū ���� h�̴�.
			if (max < h) {
				max = h;
			}
		}
		cout << max << endl;
		max = 0;
	}
};

int main() {

	int treeCount = 0;
	int nodeCount = 0;
	int parent = 0;
	int child = 0;
	cin >> treeCount;
	for (int i = 1; i <= treeCount; i++) {
		Tree tree(1);
		cin >> nodeCount;
		for (int i = 1; i <= nodeCount; i++) {
			cin >> parent;
			cin >> child;
			tree.insertNode(parent, child);
		}
		tree.preorder(tree.root);// ���� ��ȸ�� ��� ���
		cout << endl;
		tree.postorder(tree.root);// ���� ��ȸ�� ��� ���
		cout << endl;
		tree.height();//Ʈ���� depth ���
	}

}