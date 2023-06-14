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
	node* search(node* curNode, int key) {//while문으로도, 재귀로도 해도 된다.
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

		while (curNode != NULL) {// 이 문장이 뒤로 가면 마지막에 parent와 current가 모두 null인채로 while문이 끝남
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
	
	void printLeftSubtreeSum(int x, int y) {//postorder와 printLeftSubtreeSum을 구분하는 것이 중요!
		node* a = search(root, x);
		node* b = search(root, y);
		int value1 = 0;
		int value2 = 0;

		if (a->left != NULL) { // NULL 처리를 하지 않아 시간이 오래걸림
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
		if (x->right != NULL) {// 틀렸던 내용 : else if로 착각하지 말 것!!!
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