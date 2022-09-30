#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, A, B, x[10], y[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> A >> B;
	for (int i = 0; i < 10; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < 8 - N; i++) {
		A += x[i] * 3;
		if (x[i] + y[i] > 6) {
			y[i] = 6 - x[i];
		}
		B += (x[i] + y[i]) * 3;
	}
	if (A >= 66 && B >= 130) cout << "Nice";
	else cout << "Nae ga wae";
}