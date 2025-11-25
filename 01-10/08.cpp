// https://atcoder.jp/contests/typical90/tasks/typical90_h

// dynamic programming

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long mod = 1000000007LL;
const string target = "atcoder";

int main() {
    int N;
    string S;
    cin >> N >> S;
    // dp.at(i).at(j) -- 1-based index
    //  : Sのi番目までの範囲で"atcoder"のj番目までが何通りかを格納する
    vector<vector<long long>> dp(N+1, vector<long long>(8, 0));
    // Sの何番目でも空文字列は作成できる
    for (int i = 0; i <= N; i++) dp.at(i).at(0) = 1;
    // main loop
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 7; j++) {
            dp.at(i).at(j) = dp.at(i-1).at(j);
            dp.at(i).at(j) %= mod;
            // stringは、0-based indexであることに注意
            if (S.at(i-1) == target.at(j-1)) {
                dp.at(i).at(j) += dp.at(i-1).at(j-1);
                dp.at(i).at(j) %= mod;
            }
        }
    }
    cout << dp.at(N).at(7) % mod << endl;
    return 0;
}