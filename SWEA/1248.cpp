/* 1248. [S/W 문제해결 응용] 3일차 - 공통조상 */
#include <iostream>
#include <vector>
using namespace std;

typedef struct node* treePtr;
typedef struct node {
	int data;
	treePtr left, right, parent;
} node;

int inorder(treePtr tree) {
	int ret = 0;
	if (tree) {
		ret += inorder(tree->left);
		ret++;
		ret += inorder(tree->right);
	}
	return ret;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int v, e, n1, n2;
		cin >> v >> e >> n1 >> n2;
		vector<node> nodes(v + 1);
		for (int i = 1; i <= v; i++) {
			nodes[i].data = i;
			nodes[i].right = NULL;
			nodes[i].left = NULL;
			nodes[i].parent = NULL;
		}

		for (int i = 0; i < e; i++) {
			int p, c;
			cin >> p >> c;
			if (!nodes[p].left) nodes[p].left = &nodes[c];
			else nodes[p].right = &nodes[c];
			nodes[c].parent = &nodes[p];
		}

		vector<int> p;
		while (n1 != 1) {
			treePtr parent = nodes[n1].parent;
			n1 = parent->data;
			p.push_back(parent->data);
		}

		int ans = 0;
		while (true) {
			treePtr parent = nodes[n2].parent;
			n2 = parent->data;
			for (int i = 0; i < p.size(); i++) {
				if (p[i] == n2) ans = n2;
			}
			if (ans) break;
		}

		cout << "#" << tc << " " << ans << " " << inorder(&nodes[ans]) << '\n';
	}

	return 0;
}