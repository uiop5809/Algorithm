#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int H, N;
long long arr[31][31];

void dynamic() {
	for (int i = 0; i < 31; i++) {
		arr[0][i] = 1;
	}
	for (int i = 1; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> H >> N;
	dynamic();
	int res = abs(H - N);
	cout << arr[res][res];
}