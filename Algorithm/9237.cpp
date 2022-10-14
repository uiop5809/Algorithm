#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.rbegin(), v.rend());

	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, v[i] + i + 1);
	}
	cout << res + 1;
}