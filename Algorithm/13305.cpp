#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	long long dist[100001], price[100001];
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i]; // ������ ����
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i]; // ������ ���ʹ� ����
	}
	long long min = 1e9, sum = 0;
	for (int i = 0; i < N - 1; i++) {
		if (min > price[i]) {
			min = price[i];
		}
		sum += min * dist[i];
	}
	cout << sum;
}