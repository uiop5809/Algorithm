#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 28; i++) {
		cin >> n;
		s[n]++;
	}
	vector<int> v;
	for (int i = 1; i <= 30; i++) {
		if (!s[i]) v.push_back(i);
	}
	sort(v.begin(), v.end());
	cout << v[0] << "\n" << v[1];
}