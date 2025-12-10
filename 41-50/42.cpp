// https://atcoder.jp/contests/typical90/tasks/typical90_ap

#include <iostream>

using namespace std;

const long long MAX_VAL = 1000000000000000000LL;

long long gcd(long long x, long long y) {
    if (x < y) {
        long long tmp = x;
        x = y;
        y = tmp;
    }
    while (y != 0)
    {
        long long r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    long long A, B;
    cin >> A >> B;
    long long G = gcd(A, B);
    long long A_prime = A / G;
    // オーバーフロー防止
    if (A_prime > MAX_VAL / B)  cout << "Large" << endl;
    else cout << A_prime * B << endl;
}