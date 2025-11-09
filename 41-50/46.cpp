// https://atcoder.jp/contests/typical90/tasks/typical90_at

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a_div(46, 0);
    vector<int> b_div(46, 0);
    vector<int> c_div(46, 0);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        a_div.at(A % 46)++;
    }
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B;
        b_div.at(B % 46)++;
    }
    for (int i = 0; i < N; i++) {
        int C;
        cin >> C;
        c_div.at(C % 46)++;
    }

    long long ans = 0LL;
    for (int ra = 0; ra < 46; ra++) {
        for (int rb = 0; rb < 46; rb++) {
            for (int rc = 0; rc < 46; rc++) {
                // オーバーフロー防止のために long long で型キャストする
                if ((ra + rb + rc) % 46 == 0) ans += (long long)a_div[ra] * b_div[rb] * c_div[rc];
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}