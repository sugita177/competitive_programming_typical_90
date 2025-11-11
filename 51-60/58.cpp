// https://atcoder.jp/contests/typical90/tasks/typical90_bf

#include <iostream>
#include <vector>

using namespace std;

const int mod = 100000;

int convert(int a) {
    int b = 0;
    while (a > 0)
    {
        b = b + a % 10;
        a = a / 10;
    }
    return b;
}

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> visited_time(100009, -1);

    // 周期性を利用する
    int x = N;
    int count = 0;
    visited_time.at(x) = count;
    count++;
    while (true)
    {
        x = x + convert(x);
        x = x % mod;
        if (visited_time.at(x) >= 0) break;
        visited_time.at(x) = count;
        count++;
    }
    int T = count - visited_time.at(x);
    if (K >= count) K = (K - count) % T + visited_time.at(x);
    int ans = -1;
    for (int i = 0; i < mod; i++) {
        if (visited_time.at(i) == K) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}