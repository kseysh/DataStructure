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

		node* parNode = delNode->parent;
		node* childNode;

		if (delNode->left == NULL && delNode->right == NULL) {
			childNode = NULL;
		}
		else if (delNode->left == NULL && delNode->right != NULL) {
			childNode = delNode->right;
		}
		else if (delNode->left == NULL && delNode->right == NULL) {
			childNode = delNode->left;
		}
		else {
			childNode = delNode->right;
			while (childNode->left != NULL) {
				childNode = childNode->left;
			}
			delNode->key = childNode->key;
			delNode = childNode;
			parNode = delNode->parent;
			childNode = delNode->right;
			{

			}
		}
		if (parNode == NULL) {
			root = childNode;
			root->parent = NULL;
		}
		else if (delNode == parNode->left) {
			parNode->left = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		else {
			parNode->right = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		delete delNode;

	}
	int printDepth(node* v) {
		if (v->parent == NULL) {
			return depth;
			//depth = 0; //void로 print할 때는 필요
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

};

int main() {
	int t, n,num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		BST tree;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			tree.insert(num);
		}
		cout << tree.printHeight(tree.root);
	}
	return 0;
}