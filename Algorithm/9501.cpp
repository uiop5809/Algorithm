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
			int v, f, c; // 최고속도, 연료양, 연료소비율
			cin >> v >> f >> c;
			if (v * f / c >= D) res++;
		}
		cout << res << "\n";
	}
}