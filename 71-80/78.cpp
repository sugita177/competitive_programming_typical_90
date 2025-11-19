// https://atcoder.jp/contests/typical90/tasks/typical90_bz

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a-1).push_back(b-1);
        G.at(b-1).push_back(a-1);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j : G.at(i)) {
            if (i > j) cnt++;
        }
        if (cnt == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}