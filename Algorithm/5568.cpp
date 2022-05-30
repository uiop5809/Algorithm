#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector <int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	set <string> s;
	do {
		string res;
		for (int i = 0; i < k; i++) {
			res += to_string(v[i]);
		}
		s.insert(res);
	} while (next_permutation(v.begin(), v.end()));
	cout << s.size();
}