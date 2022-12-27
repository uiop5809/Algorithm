#include <iostream>
#include <algorithm>
using namespace std;

int N, plug[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> plug[i];
		sum += plug[i];
	}
	cout << sum - (N - 1);
}
