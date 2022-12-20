#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	stack <int> s;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		s.push(h);
	}

	int cnt = 1, top = s.top();
	while (1) {
		s.pop();
		if (s.empty()) break;

		if (top < s.top()) {
			top = s.top();
			cnt++;
		}
	}
	cout << cnt;
}