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

int T;
int wine[10001], dp[10001];

int dynamic(int T) {
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for (int i = 3; i <= T; i++) {
        dp[i] = wine[i] + max(dp[i - 2], wine[i - 1] + dp[i - 3]);
        //wine[i-1] 안 마실 때 //wine[i-1] 마실 때
        dp[i] = max(dp[i], dp[i - 1]);
        //wine[i] 마실 때 //wine[i] 안 마실 때
    }
    return dp[T];
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> wine[i];
    }
    cout << dynamic(T);
}