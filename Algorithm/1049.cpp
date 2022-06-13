#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, a, b, n1 = 1e9, n2 = 1e9;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		n1 = min(n1, a); // ��Ű��
		n2 = min(n2, b); // ����
	}
	cout << min({ (N / 6 + 1) * n1, N / 6 * n1 + N % 6 * n2, N * n2 });
}