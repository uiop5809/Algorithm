#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}
}