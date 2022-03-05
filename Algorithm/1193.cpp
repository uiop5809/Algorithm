#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    int N, i;
    cin >> N;

    for (i = 0; i < N; i++) {
        N -= i;
    }
    if (i % 2 == 1)
        cout << i + 1 - N << "/" << N;
    else
        cout << N << "/" << i + 1 - N;
}