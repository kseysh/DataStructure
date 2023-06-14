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
	BST() {
		root = NULL;
	}
	node* search(node* curNode, int key) {//while�����ε�, ��ͷε� �ص� �ȴ�.
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
		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		while (curNode != NULL) {// �� ������ �ڷ� ���� �������� parent�� current�� ��� null��ä�� while���� ����
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
	
	void printLeftSubtreeSum(int x, int y) {//postorder�� printLeftSubtreeSum�� �����ϴ� ���� �߿�!
		node* a = search(root, x);
		node* b = search(root, y);
		int value1 = 0;
		int value2 = 0;

		if (a->left != NULL) { // NULL ó���� ���� �ʾ� �ð��� �����ɸ�
			value1 = postorder(a->left);
		}
		if (b->left != NULL) {
			value2 = postorder(b->left);
		}

		cout << value1 + value2 << endl;

	}
	
	int postorder(node* x) {
		int leftCount = 0;
		int rightCount = 0;
		if (x->left != NULL) {
			leftCount = postorder(x->left);
		}
		if (x->right != NULL) {// Ʋ�ȴ� ���� : else if�� �������� �� ��!!!
			rightCount = postorder(x->right);
		}
		return 1 + leftCount + rightCount;
	}
	

	

};

int main() {
	int n, m, x, y;
	BST tree;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		tree.insert(x);
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		tree.printLeftSubtreeSum(x,y);
	}

	return 0;
}