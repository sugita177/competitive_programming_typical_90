// https://atcoder.jp/contests/typical90/tasks/typical90_bk

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> P.at(i).at(j);
        }
    }
    int ans = 0;
    for (int c = 0; c < (1 << H); c++) {
        vector<bool> same(W, true);
        vector<int> base(W, 0);
        bool is_first = true;
        int H_count = 0;
        for (int i = 0; i < H; i++) {
            if ((c & (1 << i)) == 0) {
                continue;
            }
            H_count++;
            if (is_first) {
                for (int j = 0; j < W; j++) base.at(j) = P.at(i).at(j);
                is_first = false;
            } else {
                for (int j = 0; j < W; j++) {
                    if (P.at(i).at(j) != base.at(j) && same.at(j) == true) same.at(j) = false;
                }
            }
        }
        vector<int> R;
        for (int j = 0; j < W; j++) {
            if (same.at(j) == true) R.push_back(base.at(j));
        }
        int W_count = 0;
        map<int, int> count_map;
        for (int i = 0; i < R.size(); i++) {
            count_map[R.at(i)] += 1;
            W_count = max(W_count, count_map.at(R.at(i)));
        }
        
        ans = max(ans, H_count * W_count);
    }
    cout << ans << endl;
    return 0;
}