#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string S;
int preSum[200001][26], q, x, y;
char c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S;
	int sum = 0;
	for (int i = 0; i < S.size(); i++) {
		if (i != 0) {
			for (int j = 0; j < 26; j++) {
				preSum[i][j] = preSum[i - 1][j];
			}
		}
		preSum[i][S[i] - 'a']++;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> c >> x >> y;
		
		int num1 = x > 0 ? preSum[x - 1][c - 'a'] : 0;
		int num2 = preSum[y][c - 'a'];
		cout << num2 - num1 << "\n";
	}
}