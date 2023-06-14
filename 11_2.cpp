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
	int count = 0;
	BST() {
		root = NULL;
		this->depth = 0;//count�� depth �ʱ�ȭ �����ִ� �� ����� �ʱ�!!
		this->count = 0;
	}
	node* search(node* curNode, int key) {
		if (curNode == NULL) {
			return NULL;
		}
		if (curNode->key == key) {
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
			cout << 0 << endl;
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

		cout << printDepth(newNode) << endl;
		depth = 0;
	}
	void remove(int key) {
		node* delNode = search(root, key);

		cout << printDepth(delNode) << endl;
		depth = 0;


		node* parNode = delNode->parent;	// ������ ����� �θ� ����� �ּҸ� �����ϴ� ����
		node* childNode;					// ������ ����� �θ� ��忡 ���Ӱ� ������ �ڽ��� �ּҸ� �����ϴ� ����

		if (delNode->left == NULL && delNode->right == NULL) {	// ������ ����� �ڽ��� �������� �ʴ� ���
			childNode = NULL;
		}
		else if (delNode->left == NULL && delNode->right != NULL) {	// ������ ����� ������ �ڽĸ� �����ϴ� ���
			childNode = delNode->right;
		}
		else if (delNode->left != NULL && delNode->right == NULL) {	// ������ ����� ���� �ڽĸ� �����ϴ� ���
			childNode = delNode->left;
		}
		else{									// ������ ����� �ڽ��� �� �� �����ϴ� ���
			childNode = delNode->right;
			while (childNode->left != nullptr) {	// ������ ����Ʈ������ ���� ����� ��(���� ����) Ž��					
				childNode = childNode->left;
			}
			delNode->key = childNode->key; // inorder-successor�� key�� �ο����� (������ �̰͸� ���ָ� �ȴ�.)
			//�Ʒ����� �ٲ� delnode�� ��������
			delNode = childNode;// delnode�� ������ �Ʒ� ���� ��������
			parNode = delNode->parent; // delnode�� parent�� child�� �����ϱ� ���� parent�� child�� �����´�.
			childNode = delNode->right; // inorder-success�� ���� �ڽ��� ���� �� �����Ƿ� ������ �ڽĸ� ������.
		}								//���� �ڽ��� ������ childnode�� NULL�� �޴´�.

		//�Ʒ����ʹ� parnode�� �Ű澲�� �ȴ�. childnode�� �Ű� x
		//parnode�� null�϶�, �θ��� ���� �ڽ��� ��, ������ �ڽ��� ���� �Ű澲��
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
	int printDepth(node* v) {//class ������ depth�� ���� �׻� �ʱ�ȭ ���ֱ�
		if (v->parent == NULL) {
			return depth;
		}
		else {
			depth++;
			printDepth(v->parent);
		}
	}

	int printHeight(node* current) {
		if (current->left == NULL && current->right == NULL) {
			return 0;
		}
		else if (current->left == NULL && current->right != NULL) {	//������ �ڽĸ� �ִ� ���
			return printHeight(current->right) + 1;
		}
		else if (current->left != NULL && current->right == NULL) {	//���� �ڽĸ� �ִ� ���
			return printHeight(current->left) + 1;
		}
		else {														//�ڽ��� �� �� �ִ� ���
			int max = 0;
			if (printHeight(current->left) > printHeight(current->right)) {
				return printHeight(current->left) + 1;
			}
			else {
				return printHeight(current->right) + 1;
			}
		}
	}

	void inOrder(node* current,int k) {
		if (current->left != NULL) {
			inOrder(current->left,k);
		}
		if (++count == k) {
			cout << current->key << endl;
			return;
		}
		if (current->right != NULL) {
			inOrder(current->right,k);
		}
	}

	void printMin(int k) {
		inOrder(root, k);
		count = 0;
	}

}; // insert,delete,printMin �̿ܿ��� ��� node* �Ķ���͸� ����Ѵ�.

int main() {
	int t,x;
	cin >> t;
	string command;
	BST tree;
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (command == "insert") {
			cin >> x;
			tree.insert(x);
		}
		else if (command == "delete") {
			cin >> x;
			tree.remove(x);
		}
		else if (command == "min") {
			cin >> x;
			tree.printMin(x);
		}
		else if (command == "height") {
			cin >> x;
			cout << tree.printHeight(tree.search(tree.root,x)) <<endl;// �����ϰ� cmd�ε� node*�� �޴� �Լ�
		}
	}
	return 0;
}