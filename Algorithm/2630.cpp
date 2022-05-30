#include <iostream>
using namespace std;

int white, blue;
int arr[130][130];

void get_cnt(int y, int x, int size) {
	int color = arr[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (color != arr[i][j]) {
				get_cnt(y, x, size / 2); // 왼쪽 위
				get_cnt(y, x + size / 2, size / 2); // 오른쪽 위
				get_cnt(y + size / 2, x, size / 2); // 왼쪽 아래
				get_cnt(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래
				return;
			}
		}
	}
	if (color == 1) blue++;
	else if (color == 0) white++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	get_cnt(0, 0, n); // y, x, size
	cout << white << "\n" << blue;
}