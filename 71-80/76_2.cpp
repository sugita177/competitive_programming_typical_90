// https://atcoder.jp/contests/typical90/tasks/typical90_bx

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N, 0LL);
    // 累積和
    vector<long long> acum(2*N + 1, 0LL);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        acum.at(i+1) = acum.at(i) + A.at(i);
    }
    if (acum.at(N) % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    long long one_tenth = acum.at(N) / 10;
    for (int i = 0; i < N; i++) {
        acum.at(i+1+N) = acum.at(i+N) + A.at(i);
    }

    // 二分探索を用いる
    bool ans = false;
    for (int i = 0; i <= N; i++) {
        long long target = one_tenth + acum.at(i);
        int idx = lower_bound(acum.begin(), acum.end(), target) - acum.begin();
        if (idx == 2 * N + 1) continue;
        if (acum.at(idx) == target) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}