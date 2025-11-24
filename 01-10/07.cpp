// https://atcoder.jp/contests/typical90/tasks/typical90_g

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    cin >> Q;
    sort(A.begin(), A.end());
    for (int i = 0; i < Q; i++) {
        int B;
        cin >> B;
        int idx = lower_bound(A.begin(), A.end(), B) - A.begin();
        int ans;
        if (idx == 0) ans = abs(A.at(idx) - B);
        else if (idx == N) ans = abs(A.at(idx-1) - B);
        else ans = min(abs(A.at(idx) - B), abs(A.at(idx-1) - B));
        cout << ans << endl;
    }
    return 0;
}