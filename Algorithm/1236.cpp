#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, m, f = 0, r = 0, c = 0;
    char a[50][50];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') f = 1;
        }
        if (f == 0) r++;
        f = 0;
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 'X') f = 1;
        }
        if (f == 0) c++;
        f = 0;
    }
    int res = (r > c) ? r : c;
    cout << res;
}
