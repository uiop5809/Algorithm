#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M, P, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	vector <int> cnt(M + 1, 0);
	vector <int> container[101];
	queue <pair <int, int>> q;

	for (int i = 0; i < N; i++) {
		cin >> P >> W;
		q.push({ P, W });
		cnt[P]++;
	}

	int ans = 0;
	while (!q.empty()) {
		int Pnow = q.front().first;
		int Wnow = q.front().second;
		q.pop();

		if (Pnow != M) {
			ans += Wnow;
			q.push({Pnow, Wnow});
		}
		else {
			ans += Wnow;
			cnt[M]--;

			if (!cnt[M]) M--;
			if (container[Pnow].empty()) {
				container[Pnow].push_back(Wnow);
			}
			else {
				for (int i = 0; i < container[Pnow].size(); i++) {
					if (container[Pnow][i] < Wnow) ans += 2 * container[Pnow][i];
					else break;
				}
				container[Pnow].push_back(Wnow);
				sort(container[Pnow].begin(), container[Pnow].end());
			}
		}
	}
	cout << ans;
}