#include <iostream>
#include <string>
using namespace std;

int n;
char c[5000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];
	long long sum = 0;
	string str = "";
	for (int i = 0; i < n; i++) {
		if ('a' <= c[i] && c[i] <= 'z' || 'A' <= c[i] && c[i] <= 'Z') {
			if (str != "") {
				sum += stoi(str);
				str = "";
			}
		}
		else str += c[i];
	}
	if (str != "") sum += stoi(str);
	cout << sum;
}