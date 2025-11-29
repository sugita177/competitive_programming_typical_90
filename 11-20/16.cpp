// https://atcoder.jp/contests/typical90/tasks/typical90_p

#include <iostream>
#include <vector>

using namespace std;

// 最大枚数 9999 を定数として使用
const int MAX_COUNT = 9999;

int main () {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    // 答えの初期値は最大枚数+1
    int ans = MAX_COUNT + 1;

    // i の上限: 金額の制約 N / A と、枚数の制約 MAX_COUNT の小さい方
    int i_max = min(N / A, MAX_COUNT);
    
    for (int i = 0; i <= i_max; i++) {
        int cur_A_val = i * A;
        int remaining_val = N - cur_A_val;
        
        // j の上限: 残りの枚数の制約 MAX_COUNT - i 
        // かつ、金額の制約 remaining_val / B の小さい方
        int j_max = min(remaining_val / B, MAX_COUNT - i);

        for (int j = 0; j <= j_max; j++) {
            // 現在の i, j での合計金額
            int cur_val = cur_A_val + j * B; 

            // 残りの金額が C で割り切れるか
            if ((N - cur_val) % C == 0) {
                // 残りの金額を C で割った枚数 k
                int k = (N - cur_val) / C; 
                
                // i+j+k が 9999 以下であることを確認する（j_max の設定により i+j <= 9999 は保証されている）
                if (i + j + k <= MAX_COUNT) {
                    ans = min(ans, i + j + k);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}