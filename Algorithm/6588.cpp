#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int prime[1000001];
const int num = 1000001;

void primeNum() {
	for (int i = 2; i <= num; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (prime[i] == 0) continue;
		for (int j = i * i; j <= num; j += i) {
			prime[j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	primeNum();
	while (1) {
		cin >> n;
		if (n == 0) break;

		vector <int> v;
		for (int i = 2; i <= n; i++) {
			if (prime[i] != 0 && prime[n - i] != 0) {
				v.push_back(i);
				v.push_back(n - i);
				break;
			}
		}
		sort(v.begin(), v.end());
		cout << n << " = " << v[0] << " + " << v[1] << "\n";
	}
}