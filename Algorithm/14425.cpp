#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	string str, res;
	map <string, bool> m;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str] = true;
	}
	int cnt = 0;
	while (M--) {
		cin >> res;
		if (m[res]) cnt++;
	}
	cout << cnt;
}