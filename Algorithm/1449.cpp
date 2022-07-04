#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, L, loc[1001];
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> loc[i];
	}
	sort(loc, loc + N);

	int start = loc[0], res = 1;
	for (int i = 1; i < N; i++) {
		if (loc[i] - start + 1 > L) {
			res++;
			start = loc[i];
		}
	}
	cout << res;
}