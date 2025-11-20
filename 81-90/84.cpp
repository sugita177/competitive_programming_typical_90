// https://atcoder.jp/contests/typical90/tasks/typical90_cf

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char prev_s = S.at(0);
    int cnt = 1;
    vector<int> seq_count;
    for (int i = 1; i < N; i++) {
        char current_s = S.at(i);
        if (prev_s != current_s) {
            seq_count.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
        prev_s = current_s;
    }
    seq_count.push_back(cnt);
    long long ans = 1LL * N * (N - 1) / 2;
    for (int i = 0; i < seq_count.size(); i++) {
        int c = seq_count.at(i);
        ans -= 1LL * c * (c - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}