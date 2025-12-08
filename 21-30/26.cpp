// https://atcoder.jp/contests/typical90/tasks/typical90_z

// 木構造のある1つのエッジを定め、そこから偶奇のどちらのステップで進めるかでノードを分類する
// 異なる分類のノード間のエッジを削除する

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 配色 (color = 0 or 1)
void paint_color(vector<vector<int>> &G, vector<int> &c, int color, int idx) {
    c.at(idx) = color;
    for (int i: G.at(idx)) {
        if (c.at(i) != -1) continue;  // 配色済み
        paint_color(G, c, 1-color, i);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<int> color(N, -1);  // エッジの配色を格納する
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a-1).push_back(b-1);
        G.at(b-1).push_back(a-1);
    }

    // 配色
    paint_color(G, color, 0, 0);

    vector<int> G1, G2;
    for (int i = 0; i < N; i++) {
        if (color.at(i) == 0) G1.push_back(i+1);
        if (color.at(i) == 1) G2.push_back(i+1);
    }
    if (G1.size() >= G2.size()) {
        for (int i = 0; i < N / 2; i++) {
            cout << G1.at(i);
            if (i < N/2 - 1) cout << " ";
            else cout << endl;
        }
    } else {
        for (int i = 0; i < N / 2; i++) {
            cout << G2.at(i);
            if (i < N/2 - 1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}