#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;
	string H, N;
	cin >> H >> N;
	for (int i = 0; i <= H.size() - N.size(); i++) {
		if (H.substr(i, N.size()) == N) cnt++;
	}
	cout << cnt;
}