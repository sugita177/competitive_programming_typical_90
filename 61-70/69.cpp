// https://atcoder.jp/contests/typical90/tasks/typical90_bq

#include <iostream>

using namespace std;

const long long mod = 1000000007LL;

int power(int x, long long n) {
    int ans = 1;
    while (n != 0)
    {
        // 乗算によるint のオーバーフロー防止のために、計算中はlong long にする。
        if (n % 2 == 1) {
            ans = (long long)ans * x % mod;
        }
        x = (long long)x * x % mod;
        n /= 2;
    }
    return ans;
}

int main() {
    long long N;
    int K;
    cin >> N >> K;
    int ans = 0;
    if (K == 1) ans = N == 1 ? 1 : 0;
    else if (N == 1) ans = K;
    else if (N == 2) ans = K * (K-1) % mod;
    // 乗算によるint のオーバーフロー防止のために、計算中はlong long にする。
    else if (N > 2 && K > 1) ans = ((long long)K * (K - 1) % mod) * power(K-2, N-2) % mod;
    cout << ans % mod << endl;
}