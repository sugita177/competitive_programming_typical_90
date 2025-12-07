// https://atcoder.jp/contests/typical90/tasks/typical90_ag

// コーナーケースに気を付ける

#include <iostream>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << H * W << endl;
        return 0;
    }
    int ans = (H / 2 + H % 2) * (W / 2 + W % 2);
    cout << ans << endl;
    return 0;
}