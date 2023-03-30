#include<iostream>
#include<vector>
using namespace std;

int arr[30][2];


void preorder(int index) {
	if (index == -1) {
		return;
	}
	cout << (char)(index + 'A');
	preorder(arr[index][0]);
	preorder(arr[index][1]);
}

void inorder(int index) {
	if (index == -1) {
		return;
	}
	inorder(arr[index][0]);
	cout << (char)(index + 'A');
	inorder(arr[index][1]);
}

void postorder(int index) {
	if (index == -1) {
		return;
	}
	postorder(arr[index][0]);
	postorder(arr[index][1]);
	cout << (char)(index + 'A');
}

int main() {
	int commandCount = 0;
	char parent = 'A';
	char leftChild = 'A';
	char rightChild = 'B';
	cin >> commandCount;
	for (int i = 0; i < commandCount; i++) {
		cin >> parent >> leftChild >> rightChild;
		if (leftChild == '.') {
			arr[parent - 'A'][0] = -1;
		}
		else {
			arr[parent - 'A'][0] = leftChild - 'A';
		}
		if (rightChild == '.') {
			arr[parent - 'A'][1] = -1;
		}
		else {
			arr[parent - 'A'][1] = rightChild - 'A';
		}

	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);


	return 0;
}