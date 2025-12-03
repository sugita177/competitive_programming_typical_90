// https://atcoder.jp/contests/typical90/tasks/typical90_x

// sum(abs(A[i] - B[i])) - K == 0 (mod 2) の場合、AとBを一致させることができる

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B;
        sum += abs(A.at(i) - B);
    }
    if ((sum - K) % 2 == 0 && sum <= K) cout << "Yes" << endl;
    else cout << "No" << endl;
}