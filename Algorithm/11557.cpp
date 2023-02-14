#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	vector <pair<string, int>> v;
	while (T--) {
		int N, L, max = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s >> L;
			v.push_back({ s, L });
			if (max < L) max = L;
		}
		for (int i = 0; i < N; i++) {
			if (v[i].second == max) {
				cout << v[i].first << "\n";
			}
		}
		v.clear();
	}
}