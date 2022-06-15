#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, file[51], cl;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> file[i];
	}
	cin >> cl;

	long long sum = 0, res = 0;
	for (int i = 0; i < N; i++) {
		sum = file[i] / cl * cl;
		if (file[i] % cl == 0) res += sum;
		else if (file[i] % cl > 0) res += sum + cl;
	}
	cout << res;
}