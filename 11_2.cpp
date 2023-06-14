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
		this->depth = 0;//count와 depth 초기화 시켜주는 것 까먹지 않기!!
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


		node* parNode = delNode->parent;	// 삭제할 노드의 부모 노드의 주소를 저장하는 변수
		node* childNode;					// 삭제할 노드의 부모 노드에 새롭게 연결할 자식의 주소를 저장하는 변수

		if (delNode->left == NULL && delNode->right == NULL) {	// 삭제할 노드의 자식이 존재하지 않는 경우
			childNode = NULL;
		}
		else if (delNode->left == NULL && delNode->right != NULL) {	// 삭제할 노드의 오른쪽 자식만 존재하는 경우
			childNode = delNode->right;
		}
		else if (delNode->left != NULL && delNode->right == NULL) {	// 삭제할 노드의 왼쪽 자식만 존재하는 경우
			childNode = delNode->left;
		}
		else{									// 삭제할 노드의 자식이 둘 다 존재하는 경우
			childNode = delNode->right;
			while (childNode->left != nullptr) {	// 오른쪽 서브트리에서 가장 가까운 값(가장 왼쪽) 탐색					
				childNode = childNode->left;
			}
			delNode->key = childNode->key; // inorder-successor의 key를 부여해줌 (위쪽은 이것만 해주면 된다.)
			//아래부터 바뀐 delnode의 삭제과정
			delNode = childNode;// delnode를 삭제할 아래 노드로 변경해줌
			parNode = delNode->parent; // delnode의 parent와 child를 연결하기 위해 parent와 child를 가져온다.
			childNode = delNode->right; // inorder-success는 왼쪽 자식이 있을 수 없으므로 오른쪽 자식만 가져옴.
		}								//만약 자식이 없더라도 childnode를 NULL로 받는다.

		//아래부터는 parnode만 신경쓰면 된다. childnode는 신경 x
		//parnode가 null일때, 부모의 왼쪽 자식일 때, 오른쪽 자식일 때만 신경쓰기
		if (parNode == NULL) {// 부모가 존재하지 않는 경우, 즉 root를 삭제하는 경우
			root = childNode;
			root->parent = NULL;
		}
		else if (delNode == parNode->left) {// 삭제할 노드가 부모의 왼쪽 자식인 경우
			parNode->left = childNode;		// childNode를 부모의 새로운 왼쪽 자식으로 연결
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		else {								// 삭제할 노드가 부모의 오른쪽 자식이었던 경우
			parNode->right = childNode;		// childNode를 부모의 새로운 오른쪽 자식으로 연결
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		delete delNode;

	}
	int printDepth(node* v) {//class 변수로 depth를 사용시 항상 초기화 해주기
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
		else if (current->left == NULL && current->right != NULL) {	//오른쪽 자식만 있는 경우
			return printHeight(current->right) + 1;
		}
		else if (current->left != NULL && current->right == NULL) {	//좌측 자식만 있는 경우
			return printHeight(current->left) + 1;
		}
		else {														//자식이 둘 다 있는 경우
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

}; // insert,delete,printMin 이외에는 모두 node* 파라미터를 사용한다.

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
			cout << tree.printHeight(tree.search(tree.root,x)) <<endl;// 유일하게 cmd인데 node*로 받는 함수
		}
	}
	return 0;
}