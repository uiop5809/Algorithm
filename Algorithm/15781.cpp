#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	vector <int> h(N);
	vector <int> a(M);
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> a[i];
	}
	sort(h.begin(), h.end());
	sort(a.begin(), a.end());
	cout << h[N - 1] + a[M - 1];
}