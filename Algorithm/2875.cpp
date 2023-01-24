#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string N;
	int B, cnt = 0, sum = 0;
	cin >> N >> B;

	for(int i = N.size() - 1; i >= 0; i--) {
		if ('A' <= N[i] && N[i] <= 'Z') {
			sum += (N[i] - 'A' + 10) * pow(B, cnt);
		}
		else sum += (N[i] - '0') * pow(B, cnt);
		cnt++;
	}
	cout << sum;
}