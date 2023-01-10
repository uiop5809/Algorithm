#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, sum;
	cin >> N;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && a == c && b == c) {
			sum = 10000 + a * 1000;
		}
		else if (a == b || a == c) {
			sum = 1000 + a * 100;
		}
		else if (b == c) {
			sum = 1000 + b * 100;
		}
		else {
			sum = max(max(a, b), c) * 100;
		}
		v.push_back(sum);
	}
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res = max(res, v[i]);
	}
	cout << res;
}