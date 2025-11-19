// https://atcoder.jp/contests/typical90/tasks/typical90_bw

#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;
    long long cnt = 0LL;
    // 素因数分解
    long long rem = N;
    for (long long i = 2; i*i <= N ; i++) {
        while (rem % i == 0)
        {
            rem /= i;
            cnt++;
        }
    }
    if (rem != 1) cnt++;
    long long current_power_of_2 = 1;
    int ans = 0;
    while (current_power_of_2 < cnt)
    {
        current_power_of_2 *= 2;
        ans++;
    }
    
    cout << ans << endl;

    return 0;
}