// https://atcoder.jp/contests/typical90/tasks/typical90_bc

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long P, Q;
    cin >> N >> P >> Q;
    vector<long long> A(N, 0LL);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    long long count = 0;

    // N <= 100 なので、5重ループでも計算時間内に収まる
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                for (int l = k + 1; l < N; l++) {
                    for (int m = l + 1; m < N; m++) {
                        long long product = 1;
                        product = (product * A.at(i)) % P;
                        product = (product * A.at(j)) % P;
                        product = (product * A.at(k)) % P;
                        product = (product * A.at(l)) % P;
                        product = (product * A.at(m)) % P;

                        if (product == Q) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}