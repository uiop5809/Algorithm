#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, L;
	cin >> K >> L;
	unordered_map <string, int> um;
	for (int i = 0; i < L; i++) {
		string str;
		cin >> str;
		um[str] = i;
	}
	vector<pair<string, int>> v;
	for (auto i : um) v.push_back(i);

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < min(K, (int)v.size()); i++) {
		cout << v[i].first << "\n";
	}
}