#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector <int> v;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	vector <pair<char, int>> alpha;
	for (int i = 0; i < 3; i++) {
		alpha.push_back({ 'A' + i, v[i]});
	}

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < alpha.size(); j++) {
			if (str[i] == alpha[j].first) cout << alpha[j].second << " ";
		}
	}
}