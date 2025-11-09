// https://atcoder.jp/contests/typical90/tasks/typical90_ar

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    // ioの高速化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    // 0-based indexing
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    long long shift_count = 0;
    for (int i = 0; i < Q; i++) {
        // x, y は 1-based indexing
        int T, x, y;
        cin >> T >> x >> y;
        if (T == 1) {
            int idx_x = (x - 1 - shift_count % N + N) % N;
            int idx_y = (y - 1 - shift_count % N + N) % N;
            swap(A.at(idx_x), A.at(idx_y));
        }
        if (T == 2) {
            shift_count++;
        }
        if (T == 3) {
            int idx = (x - 1 - shift_count % N + N) % N;
            cout << A.at(idx) << endl;
        }
    }
    return 0;
}