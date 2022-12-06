#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, n;
	cin >> N >> K;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	int sum = 0, sub = 0;
	for (int i = 1; i <= K; i++) {
		sum += v[N - i] - sub;
		sub++;
	}
	cout << sum;
}