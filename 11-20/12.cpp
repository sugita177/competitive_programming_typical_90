// https://atcoder.jp/contests/typical90/tasks/typical90_l

// Union Find

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class UnionFind {
    private:
        // parent[i] は要素 i の親を表す。
        // parent[i] < 0 の場合、i は根であり、値の絶対値は集合のサイズを表す。
        vector<int> parent;

    public:
        UnionFind(int n) {
            parent.assign(n, -1);
        }

        // 根を見つける
        int find(int i) {
            if (parent.at(i) < 0) return i;
            return parent.at(i) = find(parent.at(i));
        }

        // 集合を結合する
        // 結合した場合はtrue, 結合済みの場合はfalseを返す
        bool unite(int a, int b) {
            int root_a = find(a);
            int root_b = find(b);

            if (root_a == root_b) return false;

            if (parent.at(root_a) > parent.at(root_b)) swap(root_a, root_b);
            parent.at(root_a) += parent.at(root_b);
            parent.at(root_b) = root_a;
            return true;
        }

        // 要素 a と b が同じ集合に属するか判定する
        bool same(int a, int b) {
            return find(a) == find(b);
        }

        // 要素 i が属する集合のサイズを返す
        int size(int i) {
            // find() で根を取得し、その親の値の絶対値がサイズ
            return -parent[find(i)];
        }
};

// 2次元インデックスを1次元インデックスに変換する (0-based index)
int convert_idx(int i, int j, const int COLS) {
    return i * COLS + j;
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    UnionFind uf(H*W);
    vector<int> color(H*W, 0);// 0 : white, 1 : red
    for (int i = 0; i < Q; i++) {
        int query_number;
        cin >> query_number;
        if (query_number == 1) {
            int r, c;
            cin >> r >> c;
            int idx = convert_idx(r-1, c-1, W);
            color.at(idx) = 1;
            if (r-1 > 0 && color.at(convert_idx(r-2, c-1, W)) == 1) {
                uf.unite(idx, convert_idx(r-2, c-1, W));
            }
            if (c-1 > 0 && color.at(convert_idx(r-1, c-2, W)) == 1) {
                uf.unite(idx, convert_idx(r-1, c-2, W));
            }
            if (r < H && color.at(convert_idx(r, c-1, W)) == 1) {
                uf.unite(idx, convert_idx(r, c-1, W));
            }
            if (c < W && color.at(convert_idx(r-1, c, W)) == 1) {
                uf.unite(idx, convert_idx(r-1, c, W));
            }
        }
        if (query_number == 2) {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            int idx_a = convert_idx(ra-1, ca-1, W);
            int idx_b = convert_idx(rb-1, cb-1, W);
            if (color.at(idx_a) == 1 && uf.same(idx_a, idx_b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}