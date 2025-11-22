// https://atcoder.jp/contests/typical90/tasks/typical90_c

// 無向木
// 幅優先探索

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

tuple<int, int> find_farthest_node(int start, int N, const vector<vector<int>>& G) {
    vector<int> dist(N, -1);
    queue<int> q;
    dist.at(start) = 0;
    q.push(start);

    int farthest_node = start;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist.at(u) > max_dist) {
            max_dist = dist.at(u);
            farthest_node = u;
        }

        for (int v : G.at(u)) {
            if (dist.at(v) == -1) {
                dist.at(v) = dist.at(u) + 1;
                q.push(v);
            }
        }
    }

    return {farthest_node, max_dist};
}

int main () {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        G.at(A-1).push_back(B-1);
        G.at(B-1).push_back(A-1);
    }
    tuple<int, int> x = find_farthest_node(0, N, G);
    tuple<int, int> y = find_farthest_node(get<0>(x), N, G);
    cout << get<1>(y) + 1 << endl;

    return 0;
}