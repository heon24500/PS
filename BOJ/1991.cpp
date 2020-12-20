#include <iostream>
using namespace std;

struct Node {
	char ch;
	struct Node* left;
	struct Node* right;
};

struct Node* nodes[26];

void addNode(char ch, char left, char right) {
	int idx = ch - 'A';
	nodes[idx]->ch = ch;
	if (left != '.') {
		int leftIdx = left - 'A';
		nodes[idx]->left = nodes[leftIdx];
	}
	else nodes[idx]->left = NULL;

	if (right != '.') {
		int rightIdx = right - 'A';
		nodes[idx]->right = nodes[rightIdx];
	}
	else nodes[idx]->right = NULL;
}

void preorder(Node* node) {
	if (node == NULL) return;
	cout << node->ch;
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node* node) {
	if (node == NULL) return;
	inorder(node->left);
	cout << node->ch;
	inorder(node->right);
}

void postorder(Node* node) {
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->ch;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) nodes[i] = (struct Node*)malloc(sizeof(struct Node));

	while (n--) {
		char now, left, right;
		cin >> now >> left >> right;
		addNode(now, left, right);
	}

	preorder(nodes[0]);
	cout << "\n";
	inorder(nodes[0]);
	cout << "\n";
	postorder(nodes[0]);

	for (int i = 0; i < n; i++) free(nodes[i]);
	return 0;
}