#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M, num[1001], x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		num[x]++;
	}
	sort(num, num + N);
	cout << num[N - 1];
}