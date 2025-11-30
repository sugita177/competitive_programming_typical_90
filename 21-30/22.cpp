// https://atcoder.jp/contests/typical90/tasks/typical90_v

// 最大公約数を求める

#include <iostream>
#include <cmath>

using namespace std;

long long calc_gcd(long long a, long long b) {
    while (b != 0)
    {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long gcd = calc_gcd(calc_gcd(a, b), c);
    long long ans = (a/gcd - 1LL) + (b/gcd - 1LL) + (c/gcd - 1LL);
    cout << ans << endl;
    return 0;
}