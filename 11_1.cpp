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
	
	void printLeftSubtreeSum(int x, int y) {
		node* a = search(root, x);
		node* b = search(root, y);
		int value1 = 0;
		int value2 = 0;

		if (a->left != NULL) {
			value1 = postorder(a->left, 0);
		}
		if (b->left != NULL) {
			value2 = postorder(b->left, 0);
		}

		cout << value1 + value2 << endl;

	}
	
	int postorder(node* x, int count) {
		int leftCount = 0;
		int rightCount = 0;
		if (x->left != NULL) {
			leftCount = postorder(x->left, count);
		}
		if (x->right != NULL) {
			rightCount = postorder(x->right, count);
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