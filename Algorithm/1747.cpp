#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

const int NUM = 2000000;
int num[NUM + 1];

void PrimeNum() {
	for (int i = 2; i <= NUM; i++) {
		num[i] = i;
	}
	for (int i = 2; i <= sqrt(NUM); i++) {
		if (num[i] == 0) continue;
		for (int j = i * i; j <= NUM; j += i) {
			num[j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	PrimeNum();
	for (int i = N; i <= NUM; i++) {
		string str = to_string(i);
		reverse(str.begin(), str.end());
		if (num[i] && i == stoi(str)) {
			cout << i;
			break;
		}
	}
}