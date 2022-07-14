#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int NUM = 4000001;
int prime[NUM];

vector <int> v;

void primeNum() {
	for (int i = 2; i <= NUM; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= sqrt(NUM); i++) {
		if (prime[i] == 0) continue;
		for (int j = i * i; j <= NUM; j += i) {
			prime[j] = 0;
		}
	}
	for (int i = 2; i <= NUM; i++) {
		if (prime[i] != 0) {
			v.push_back(prime[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	primeNum();

	int sum = 0;
	int start = 0, end = 0, cnt = 0;
	while (1) {
		if (sum >= N) {
			sum -= v[start++];
		}
		else if (end == v.size()) break;
		else if (sum < N) {
			sum += v[end++];
		}
		if (sum == N) cnt++;
	}
	cout << cnt;
}