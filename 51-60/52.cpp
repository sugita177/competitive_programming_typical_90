// https://atcoder.jp/contests/typical90/tasks/typical90_az

#include <iostream>
#include <vector>

using namespace std;

const long long divide = 1000000007LL;

int main() {
    int N;
    cin >> N;
    long long ans = 1LL;
    for (int i = 0; i < N; i++) {
        long long sum = 0;
        for (int j = 0; j < 6; j++) {
            long long A;
            cin >> A;
            sum += A % divide;
        }
        ans = ans * (sum % divide) % divide;
    }
    cout << ans % divide << endl;
    return 0;
}