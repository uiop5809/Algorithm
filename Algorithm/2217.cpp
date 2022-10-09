#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector <int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());

	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, (i + 1) * v[i]);
	}
	cout << res;
}