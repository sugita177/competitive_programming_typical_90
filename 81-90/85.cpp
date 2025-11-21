// https://atcoder.jp/contests/typical90/tasks/typical90_cg

#include <iostream>

using namespace std;

int main () {
    long long K;
    cin >> K;
    long long cnt = 0LL;
    for (long long a = 1; a * a * a <= K; a++) {
        if (K % a != 0) continue;
        for (long long b = a; a * b * b <= K; b++) {
            if (K % (a * b) != 0) continue;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}