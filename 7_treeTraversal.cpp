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
	vector <node*> nodeList; //트리에 추가되는 모든 노드들을 여기에 저장
	//노드 리스트는 트리를 위한 것 보다 트리에 대한 함수를 도와주기 위한 것..?

	Tree(int data) {
		this->depth = 0;
		this->h = 0;
		this->max = -1;
		this->root = new node(data, nullptr);
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
		if (find(data, nodeList) != -1) {
			cout << -1 << endl;//data가 nodeList에 있는 값인지 (중복된 값인지) 확인하고 없으면 -1 출력
			return;
		}
		int index = find(parentData, nodeList);
		if (index == -1) {
			cout << -1 << endl;// 부모 노드가 존재하지 않으면　－１　출력
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


	int goDepth(node* currentNode) {// 노드의 깊이를 반환하는 함수
		if (currentNode->parent != NULL) {//현재 노드가 루트 노드가 아니면 depth를 1 증가
			depth++;
			goDepth(currentNode->parent);//parent의 노드로 이동
		}
		else if (currentNode->parent == NULL) {//만약 현재 노드가 루트 노드이면 지금까지 더한 depth를 출력
			return depth;
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

	void height() {
		for (int i = 0; i < nodeList.size(); i++) {
			depth = 0;
			h = goDepth(nodeList[i]);//depth중에 가장 큰 값이 h이다.
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
		tree.preorder(tree.root);// 전위 순회한 결과 출력
		cout << endl;
		tree.postorder(tree.root);// 후위 순회한 결과 출력
		cout << endl;
		tree.height();//트리의 depth 출력
	}

}