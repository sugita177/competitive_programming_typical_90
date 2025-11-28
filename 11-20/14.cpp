// https://atcoder.jp/contests/typical90/tasks/typical90_n

// 貪欲法

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long ans = 0LL;
    for (int i = 0; i < N; i++) {
        ans += abs(0LL + A.at(i) - B.at(i));
    }
    cout << ans << endl;
    return 0;
}