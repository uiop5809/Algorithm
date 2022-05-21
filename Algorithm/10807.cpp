#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, num[101], v, res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> v;
	for (int i = 0; i < N; i++) {
		if (v == num[i]) res++;
	}
	cout << res;
}