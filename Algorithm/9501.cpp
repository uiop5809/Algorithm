#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, D, res = 0;
		cin >> N >> D;
		while (N--) {
			int v, f, c; // �ְ�ӵ�, �����, ����Һ���
			cin >> v >> f >> c;
			if (v * f / c >= D) res++;
		}
		cout << res << "\n";
	}
}