#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A, B;
vector <int> v[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		cout << v[i].size() << "\n";
	}
}