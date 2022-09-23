#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, parent[101];
double x, y;

vector <pair <double, double>> star;
vector <pair <double, pair <int, int>>> v;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		star.push_back({ x, y });
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < star.size(); j++) {
			double cost = sqrt(pow(star[j].first - star[i].first, 2) + pow(star[j].second - star[i].second, 2));
			v.push_back({ cost, {i, j} });
		}
	}
	sort(v.begin(), v.end());

	double sum = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		double cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		int a = getParent(x);
		int b = getParent(y);

		if (a == b) continue;
		if (a > b) parent[a] = b;
		else parent[b] = a;

		sum += cost;
		cnt++;
		if (cnt == n - 1) {
			cout.precision(3);
			cout << sum;
		}
	}
}