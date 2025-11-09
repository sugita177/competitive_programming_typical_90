// https://atcoder.jp/contests/typical90/tasks/typical90_ax

// dynamic programming を用いる

#include <iostream>
#include <vector>

using namespace std;

long long divide = 1000000007LL;

int main() {
    int N, L;
    cin >> N >> L;
    vector<long long> dp(N+1, 0);
    dp.at(0) = 1;
    for (int i = 1; i <= N; i++) {
        dp.at(i) += dp.at(i-1) % divide;
        if (i >= L) dp.at(i) += dp.at(i-L) % divide;
    }
    cout << dp.at(N) % divide << endl;

    return 0;
}