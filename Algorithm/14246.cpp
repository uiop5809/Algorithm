#include <iostream>
#include <vector>
using namespace std;

int num[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int N, K;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    cin >> K;

    int left = 0, right = 0;
    long long cnt = 0, sum = num[0];
    while (left <= right && right < N) {
        if (sum <= K) {
            sum += num[++right];
        }
        else {
            cnt += N - right;
            sum -= num[left++];
            if (left > right) {
                right = left;
                sum = num[left];
            }
        }
    }
    cout << cnt;
}
