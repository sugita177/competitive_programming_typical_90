// https://atcoder.jp/contests/typical90/tasks/typical90_r

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

// 仰角の計算
double calc_angle(vector<double> r1, vector<double> r2) {
    double distance
      = sqrt((r1.at(0) - r2.at(0))*(r1.at(0) - r2.at(0))
       + (r1.at(1) - r2.at(1))*(r1.at(1) - r2.at(1)));
    double height = abs(r1.at(2) - r2.at(2));
    // 度数法で返す
    return atan2(height, distance) * 180.0 / PI;
}

// 観覧車の位置の計算
vector<double> calc_position(int t, int T, int L) {
    double phase = -2.0 * PI / (double)T * (double)t + 1.5 * PI;
    double y = 0.5 * (double)L * cos(phase);
    double z = 0.5 * (double)L * sin(phase) + 0.5 * (double)L;
    return {0.0, y, z};
}

int main() {
    int T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;
    vector<double> R = {(double)X, (double)Y, 0.0};
    // 小数点以下を12桁に設定
    cout << fixed << setprecision(12);
    for (int i = 0; i < Q; i++) {
        int E;
        cin >> E;
        vector<double> r = calc_position(E, T, L);
        double angle = calc_angle(r, R);
        cout << angle << endl;
    }
    return 0;
}