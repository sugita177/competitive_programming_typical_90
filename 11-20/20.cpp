// https://atcoder.jp/contests/typical90/tasks/typical90_t

#include <iostream>

using namespace std;

long long power(int x, int n) {
    long long ans = 1LL;
    for (int i = 1; i <= n; i++) {
        ans = ans * (1LL * x);
    }
    return ans;
}

int main() {
    long long a;
    int b, c;
    cin >> a >> b >> c;
    long long p = power(c, b);
    if (a < p) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}