// https://atcoder.jp/contests/typical90/tasks/typical90_d

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    vector<int> row_sum(H, 0), col_sum(W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A.at(i).at(j);
            row_sum.at(i) += A.at(i).at(j);
            col_sum.at(j) += A.at(i).at(j);
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j < W - 1) cout << row_sum.at(i) + col_sum.at(j) - A.at(i).at(j) << " ";
            else cout << row_sum.at(i) + col_sum.at(j) - A.at(i).at(j) << endl;
        }
    }
    return 0;
}