#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
char arr1[11][11], arr2[11][11];

int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr2[i][j];
		}
	}
	
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cnt = 0;
			if (arr2[i][j] == 'x') {
				int x = i;
				int y = j;

				// Áö·Ú°¡ ÀÖ´Â Ä­ÀÌ ¿­·Á ÅÍÁü
				if (arr1[i][j] == '*') {
					flag = true; 
					continue;
				}
				for (int k = 0; k < 8; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
					if (arr1[nx][ny] == '*') cnt++;
				}
				arr2[i][j] = cnt + '0';
			}
		}
	}
	if (flag) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr1[i][j] == '*') {
					arr2[i][j] = '*';
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr2[i][j];
		}
		cout << "\n";
	}
}