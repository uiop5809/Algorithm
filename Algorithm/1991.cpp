#include <iostream>
using namespace std;

int N;
char x, L, R;

struct node {
	char left;
	char right;
} node[26];

void preOrder(char alpha) { // 전위 순회
	if (alpha == '.') return;
	char left = node[alpha - 'A'].left;
	char right = node[alpha - 'A'].right;

	cout << alpha;
	preOrder(left);
	preOrder(right);
}

void inOrder(char alpha) { // 중위 순회
	if (alpha == '.') return;
	char left = node[alpha - 'A'].left;
	char right = node[alpha - 'A'].right;

	inOrder(left);
	cout << alpha;
	inOrder(right);
}

void postOrder(char alpha) { // 후위 순회
	if (alpha == '.') return;
	char left = node[alpha - 'A'].left;
	char right = node[alpha - 'A'].right;

	postOrder(left);
	postOrder(right);
	cout << alpha;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> L >> R;
		node[x - 'A'].left = L;
		node[x - 'A'].right = R;
	}
	preOrder('A');
	cout << "\n";
	inOrder('A');
	cout << "\n";
	postOrder('A');
	cout << "\n";
}