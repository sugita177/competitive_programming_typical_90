// https://atcoder.jp/contests/typical90/tasks/typical90_b

#include <iostream>
#include <string>

using namespace std;


int main() {
    int N;
    cin >> N;
    // 奇数の場合は（と）の個数が一致しないので、正しいかっこ列は作れない。
    if (N % 2 == 1) {
        return 0;
    }
    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        string str = "";
        bool is_correct = true;
        for (int j = N-1; j >= 0; j--) {
            int bit = i & (1 << j);
            sum += bit == 0 ? 1 : -1;
            str += bit == 0 ? "(" : ")";
            if (sum < 0) {
                is_correct = false;
                break;
            }
        }
        if (sum != 0) is_correct = false;
        if (is_correct) cout << str << endl;
    }
    return 0;
}