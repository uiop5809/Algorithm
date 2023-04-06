#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main() {
	int n;
	int sum = 0;

	vector <pair <int, int>> num(8);
	for (int i = 0; i < 8; i++) {
		cin >> n;
		num[i].first = n;
		num[i].second = i + 1;
	}

	sort(num.begin(), num.end(), compare);
	vector <int> res;
	for (int i = 0; i < 5; i++) {
		sum += num[i].first;
		res.push_back(num[i].second);
	}
	cout << sum << "\n";

	sort(res.begin(), res.end());
	for (int i = 0; i < 5; i++) {
		cout << res[i] << " ";
	}
}