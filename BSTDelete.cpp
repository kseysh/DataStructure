#include<iostream>
using namespace std;

struct node {
	int key;
	node* parent;
	node* left;
	node* right;
	node(int key) {
		this->key = key;
		parent = left = right = NULL;
	}
};

class BST {
public:
	node* root;
	int depth;
	int max;
	BST() {
		root = NULL;
		this->depth = 0;
		this->max = -1;
	}
	node* search(node* curNode, int key) {
		if (curNode == NULL) {
			return NULL;
		}
		if (curNode->key == key) {
			cout << printHeight(curNode) << endl;
			return curNode;
		}
		else if (curNode->key < key) {
			return search(curNode->right, key);
		}
		else {
			return search(curNode->left, key);
		}
	}
	void insert(int key) {
		if (search(root, key) != NULL) {
			return;
		}
		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		while (curNode != NULL) {
			parNode = curNode;
			if (curNode->key < key) {
				curNode = curNode->right;
			}
			else {
				curNode = curNode->left;
			}
		}

		newNode->parent = parNode;
		if (parNode->key < key) {
			parNode->right = newNode;
		}
		else {
			parNode->left = newNode;
		}
	}
	void remove(int key) {
		node* delNode = search(root, key);
		if (delNode == NULL) {
			return;
		}

		node* parNode = delNode->parent;	// ������ ����� �θ� ����� �ּҸ� �����ϴ� ����
		node* childNode;					// ������ ����� �θ� ��忡 ���Ӱ� ������ �ڽ��� �ּҸ� �����ϴ� ����

		if (delNode->left == NULL && delNode->right == NULL) {	// ������ ����� �ڽ��� �������� �ʴ� ���
			childNode = NULL;
		}
		else if (delNode->left == NULL && delNode->right != NULL) {	// ������ ����� ������ �ڽĸ� �����ϴ� ���
			childNode = delNode->right;
		}
		else if (delNode->left == NULL && delNode->right == NULL) {	// ������ ����� ���� �ڽĸ� �����ϴ� ���
			childNode = delNode->left;
		}
		else {									// ������ ����� �ڽ��� �� �� �����ϴ� ���
			childNode = delNode->right;
			while (childNode->left != NULL) {	// ������ ����Ʈ������ ���� ����� ��(���� ����) Ž��					
				childNode = childNode->left;
			}
			delNode->key = childNode->key;
			delNode = childNode;
			parNode = delNode->parent;
			childNode = delNode->right;
		}
		if (parNode == NULL) {// �θ� �������� �ʴ� ���, �� root�� �����ϴ� ���
			root = childNode;
			root->parent = NULL;
		}
		else if (delNode == parNode->left) {// ������ ��尡 �θ��� ���� �ڽ��� ���
			parNode->left = childNode;		// childNode�� �θ��� ���ο� ���� �ڽ����� ����
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		else {								// ������ ��尡 �θ��� ������ �ڽ��̾��� ���
			parNode->right = childNode;		// childNode�� �θ��� ���ο� ������ �ڽ����� ����
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		delete delNode;

	}
	int printDepth(node* v) {
		if (v->parent == NULL) {
			return depth;
			//depth = 0; //void�� print�� ���� �ʿ�
		}
		else {
			depth++;
			printDepth(v->parent);
		}
	}
	void printDegree(node* v) {
		if (v->left == NULL && v->right == NULL) {
			cout << '0' << " ";
		}
		else if (v->left != NULL && v->right != NULL) {
			cout << '2' << " ";
		}
		else if (v->left != NULL && v->right == NULL) {
			cout << '1' << " ";
		}
		else if (v->left == NULL && v->right != NULL) {
			cout << '1' << " ";
		}
	}

	int printHeight(node* current) {
		if (current->left == NULL && current->right == NULL) {
			return 0;
		}
		else if (current->left == NULL && current->right != NULL) {
			return printHeight(current->right) + 1;
		}
		else if (current->left != NULL && current->right == NULL) {
			return printHeight(current->left) + 1;
		}
		else {
			int max = 0;
			if (printHeight(current->left) > printHeight(current->right)) {
				return printHeight(current->left) + 1;
			}
			else {
				return printHeight(current->right) + 1;
			}
		}
	}

	void preOrder(node* current) {
		cout << current->key << ' ';
		if (current->left != NULL) {
			preOrder(current->left);
		}
		if (current->right != NULL) {
			preOrder(current->right);
		}
	}

};

int main() {
	int t, n, m, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		BST tree;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			tree.insert(num);
		}
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> num;
			tree.remove(num);
		}
		tree.preOrder(tree.root);
		cout << endl;
	}
	return 0;
}