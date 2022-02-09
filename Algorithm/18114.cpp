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

int N, C;
int arr[5050];

int search() {
    int sumoftwo;
    for (int i = 0; i < N; i++) {
        if (arr[i] == C)
            return 1;
        else {
            for (int j = i + 1; j < N; j++) {
                sumoftwo = arr[i] + arr[j];
                if (sumoftwo == C)
                    return 1;
                else {
                    if (binary_search(&arr[j + 1], &arr[N], C - sumoftwo))
                        return 1;
                }
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);

    printf("%d", search());

    return 0;
}