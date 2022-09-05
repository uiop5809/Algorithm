#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map <int, int> m;
map <int, int> m1;
vector <pair <int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return m1[a.second] < m1[b.second];
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, C, num;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> num;
		m[num]++;
		if (!m1[num]) m1[num] = i + 1;
	}
	for (auto i : m) v.emplace_back(i.second, i.first);
	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
}