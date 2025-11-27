// https://atcoder.jp/contests/typical90/tasks/typical90_j

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    // 累積和を求める
    // sum1.at(i) : クラス1の学籍番号がi以下の生徒の合計点数
    // sum2.at(i) : クラス2の学籍番号がi以下の生徒の合計点数
    vector<int> sum1(N+1, 0), sum2(N+1, 0);
    sum1.at(0) = 0;
    sum2.at(0) = 0;
    for (int i = 1; i <= N; i++) {
        int C, P;
        cin >> C >> P;
        if (C == 1) {
            sum1.at(i) = sum1.at(i-1) + P;
            sum2.at(i) = sum2.at(i-1);
        }
        if (C == 2) {
            sum1.at(i) = sum1.at(i-1);
            sum2.at(i) = sum2.at(i-1) + P;
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << sum1.at(R) - sum1.at(L-1) << " ";
        cout << sum2.at(R) - sum2.at(L-1) << endl;
    }
    return 0;
}