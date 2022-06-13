#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string start, end;
	cin >> start >> end;
	
	int startH = stoi(start.substr(0, 2));
	int startM = stoi(start.substr(3, 2));
	int startS = stoi(start.substr(6, 2));

	int endH = stoi(end.substr(0, 2));
	int endM = stoi(end.substr(3, 2));
	int endS = stoi(end.substr(6, 2));

	int endSum = endH * 3600 + endM * 60 + endS;
	int startSum = startH * 3600 + startM * 60 + startS;

	if (startSum > endSum) endSum += 3600 * 24;
	int sum = endSum - startSum;
	
	int resH = sum / 3600;
	if (resH == 24) resH = 0;
	int resM = sum % 3600 / 60;
	int resS = sum % 60;

	if (to_string(resH).size() == 1) cout << "0" << resH << ":";
	else cout << resH << ":";
	if (to_string(resM).size() == 1) cout << "0" << resM << ":";
	else cout << resM << ":";
	if (to_string(resS).size() == 1) cout << "0" << resS;
	else cout << resS;
}