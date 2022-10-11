#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, A, B, x, y;
vector<pair<int, int>> v;
set<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> A >> B;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		s.insert({ v[i].first, v[i].second});
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		x = v[i].first;
		y = v[i].second;
		
		if (s.find({ x + A, y }) == s.end()) continue;
		if (s.find({ x, y + B }) == s.end()) continue;
		if (s.find({ x + A, y + B }) == s.end()) continue;
		res++;
	}
	cout << res;
}