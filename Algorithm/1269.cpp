#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int asize, bsize, res;
int a[200001], b[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	map <int, int> m;
	cin >> asize >> bsize;
	for (int i = 0; i < asize; i++) cin >> a[i];
	for (int i = 0; i < bsize; i++) cin >> b[i];

	for (int i = 0; i < asize; i++) m[a[i]]++;
	for (int i = 0; i < bsize; i++) if (m[b[i]]) res++;

	cout << asize + bsize - res * 2;
}