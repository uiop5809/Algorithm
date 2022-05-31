#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void postOrder(string preOrder, string inOrder) {
	if (!preOrder.size()) return;

	int num = preOrder.size();
	const char root = preOrder[0];
	// ���� ����Ʈ���� ũ��
	const int left = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
	// ������ ����Ʈ���� ũ��
	const int right = num - left - 1;
	// ���� ����Ʈ��
	postOrder(preOrder.substr(1, left), inOrder.substr(0, left));
	// ������ ����Ʈ��
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