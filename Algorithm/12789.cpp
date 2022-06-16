#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int N, num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	int cnt = 1;
	queue <int> q;
	stack <int> s;
	for (int i = 0; i < N; i++) {
		cin >> num;
		q.push(num);
	}
	while (!q.empty()) {
		if (cnt == q.front()) {
			cnt++;
			q.pop();
		}
		else{
			if (!s.empty() && cnt == s.top()){
				s.pop();
				cnt++;
			}
			else{
				s.push(q.front());
				q.pop();
			}
		}
	}
	while (!s.empty()) {
		if (s.top() != cnt) {
			break;
		}
		else {
			s.pop();
			cnt++;
		}
	}

	if (cnt == N + 1) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}
}