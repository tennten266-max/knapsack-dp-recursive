#include <stdio.h>

long long max(long long a, long long b) {
    return a < b ? b : a;
}

// 100億には LL が必要
long long INF = 9999999999LL; 

// 【修正点1】2次元配列を引数で渡すときは、2次元目の要素数（ここでは列数。最大で n+1）が必要です。
// ここでは、可変長配列（VLA）の文脈を利用して、関数の引数順序を調整し、
// data のサイズを引数の n を使って long long data[2][n + 1] と明記します。
long long f(long long l, long long r, long long n, long long data[2][n + 1]) {
    if(l == 1) {
        if(r == data[1][l]) {
            return data[0][l]; // r == s_1 のとき v_1
        } else if (r == 0){
            return 0;          // r == 0 のとき 0
        } else {
            return -INF;       // それ以外は -∞
        }
    }
    
    if(r >= data[1][l]) {
        return max(f(l - 1, r, n, data), f(l - 1, r - data[1][l], n, data) + data[0][l]);
    } else {
        return f(l - 1, r, n, data); 
    }
}

int main(void) {
    long long n;    // アイテム数
    if (scanf("%lld", &n) != 1) return 1;

    // data[0][]が価値、data[1][]がサイズ
    long long data[2][n + 1];   
    for (int i = 0; i < 2; i++) {   
        for (int j = 1; j < n + 1; j++) {  
            if(scanf("%lld", &data[i][j]) != 1) return 1;
        }   
    }

    // ナップサックの容量の最大値（すべてのアイテムのサイズの合計）を計算
    long long r = 0;
    for (int i = 1; i <= n; i++) { // 入力が 1 から n + 1 なので、i=1 から計算
        r += data[1][i];
    }

    // iが行（サイズ 0〜r）、jが列（アイテム 1〜n）
    long long map[r + 1][n + 1];
    for (int j = 1; j < n + 1; j++) {  
        for (int i = 0; i < r + 1; i++) {
            // main側は j がアイテム、i がサイズなので、f(j, i, n, data) と渡す
            map[i][j] = f(j, i, n, data);
        }   
    }

    // 結果をパッと見やすくするためにスペースを入れて出力します
    printf("r\n");
    for (int i = r; i >= 0; i--) { 
        printf("%-5d", i);
        for (int j = 1; j < n + 1; j++) {  
            if (map[i][j] < -INF + 10000) {
                printf("-    "); // -INF の場合はハイフンで綺麗に表示
            } else {
                printf("%-5lld", map[i][j]);
            }
        }  
        printf("\n");
    }

    return 0;
}
