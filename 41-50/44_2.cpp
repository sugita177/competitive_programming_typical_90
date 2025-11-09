// https://atcoder.jp/contests/typical90/tasks/typical90_ar

// 44の別解：dequeを使用する
// 参考）https://atcoder.jp/contests/typical90/editorial/6398

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int main() {
    // ioの高速化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    // 0-based indexing
    deque<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < Q; i++) {
        // x, y は 1-based indexing
        int T, x, y;
        cin >> T >> x >> y;
        if (T == 1) {
            swap(A.at(x-1), A.at(y-1));
        }
        if (T == 2) {
            int tmp = A.back();
            A.pop_back();
            A.push_front(tmp);
        }
        if (T == 3) {
            cout << A.at(x-1) << endl;
        }
    }
    return 0;
}