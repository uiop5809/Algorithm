#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

//감소한 경우가 0인 경우 N가지
//감소한 경우가 2이상인 경우 0
//감소한 경우가 1인 경우 

int N;
int a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    a[0] = -1000000000;
    a[N + 1] = 1000000000;

    int cnt = 0;
    int pos = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        if (a[i] < a[i - 1]) {
            cnt++;
            pos = i;
        }
    }

    if (cnt == 0) {
        cout << N;
    }
    else if (cnt == 1) {
        int ans = 0;
        if (a[pos - 2] <= a[pos]) {
            ans++;
        }
        if (a[pos - 1] <= a[pos + 1]) {
            ans++;
        }
        cout << ans;
    }
    else {
        cout << 0;
    }
}