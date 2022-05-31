#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void postOrder(string preOrder, string inOrder) {
	if (!preOrder.size()) return;

	int num = preOrder.size();
	const char root = preOrder[0];
	// 왼쪽 서브트리의 크기
	const int left = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
	// 오른쪽 서브트리의 크기
	const int right = num - left - 1;
	// 왼쪽 서브트리
	postOrder(preOrder.substr(1, left), inOrder.substr(0, left));
	// 오른쪽 서브트리
	postOrder(preOrder.substr(left + 1, num), inOrder.substr(left + 1, num));

	cout << root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string preOrder, inOrder;
		cin >> preOrder >> inOrder;

		if (!preOrder.size()) break;
		postOrder(preOrder, inOrder);
		cout << "\n";
	}
	return 0;
}