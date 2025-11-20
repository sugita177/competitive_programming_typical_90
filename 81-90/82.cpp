// https://atcoder.jp/contests/typical90/tasks/typical90_cd

// 公式解答を参照して作成
// https://github.com/E869120/kyopro_educational_90/blob/main/sol/082a.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;
vector<unsigned long long> power_of_10(22);


void init() {
    power_of_10.at(0) = 1LL;
    for (int i = 1; i <= 19; i++) {
        power_of_10.at(i) = power_of_10.at(i-1) * 10ULL;
    }
}

long long calc_sum(long long x) {
    long long inv = (mod + 1) / 2;
    // 各行は1つずつmodで余りを求めて変数に格納する（オーバーフロー防止）
    long long v1 = x % mod;
    long long v2 = (x + 1) % mod;
    long long sum =  v1 * v2 % mod;
    sum = sum * inv;
    return sum;
}


int main() {
    init();
    unsigned long long L, R;
    cin >> L >> R;
    long long cnt = 0LL;
    // 桁数ごとに文字数を加算する
    for (int i = 1; i <= 19; i++) {
        unsigned long long start = max(L, power_of_10.at(i-1));
        unsigned long long end = min(R, power_of_10.at(i) - 1ULL);
        if (start > end) continue;
        long long partial_sum = (calc_sum(end) - calc_sum(start - 1));
        if (partial_sum < 0) partial_sum += mod;
        // 一度cntを求めてからmodで余りを求める
        cnt += 1LL * i * partial_sum;
        cnt %= mod;
    }
    if (cnt < 0) cnt += mod;
    cout << cnt << endl;
    return 0;
}