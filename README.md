# knapsack-dp-recursive
C言語によるナップサック問題の動的計画法（再帰関数）実装。講義資料の遷移式を忠実に再現。（An implementation of the Knapsack Problem using Dynamic Programming (Recursive approach) in C, faithfully replicating the lecture formulation.）

# Knapsack Problem - Dynamic Programming Implementation in C

動的計画法（DP）の遷移式を、C言語の再帰関数を用いて忠実に再現・可視化するためのプログラムです。

## 📌 概要

このプログラムは、ナップサック問題に対する最適性の原理（Principle of Optimality）に基づき、アイテム数 $n$ および各アイテムのサイズ・価値から、すべての部分問題 $f(l, r)$ の最大価値を計算して表形式で出力します。

### 表現されている数式 
- **初期条件 ($l = 1$ の場合)**
  $$f(1, r) = \begin{cases} v_1 & (r = s_1) \\ 0 & (r = 0) \\ -\infty & (\text{それ以外}) \end{cases}$$
- **再帰の関係 ($l \ge 2$ の場合)**
  $$f(l, r) = \begin{cases} \max\{f(l-1, r), f(l-1, r-s_l) + v_l\} & (r \ge s_l) \\ f(l-1, r) & (r < s_l) \end{cases}$$

---

## 🛠️ コードの特徴

1. **関数 `f` による数式の再現**
   遷移式をそのまま `f(l, r, n, data)` という再帰関数で実装しています。
2. **適切な型枠の確保 (`LL` リテラル)**
   存在しない状態を表すために $-\infty$（プログラム内では `-INF` として `-9999999999LL`）を定義し、オーバーフローを防ぐために `long long` 型で統一しています。
3. **安全なエラー判定**
   再帰計算の中で `-INF` にアイテムの価値が足されて値が少し変化しても正しく検出できるよう、表示処理では `< -INF + 10000` による閾値判定を行っています。

---

## 🚀 使い方

### 1. コンパイル
標準的なC言語コンパイラ（gccなど）でコンパイルします。

```bash
gcc -o knapsack main.c

```

#### 入力データ
```text
4
16 19 23 28
2 3 4 5
```

#### 出力データ
```text
r
14   -    -    -    86   
13   -    -    -    -    
12   -    -    -    70   
11   -    -    -    67   
10   -    -    -    63   
9    -    -    58   58   
8    -    -    -    47   
7    -    -    42   44   
6    -    -    39   39   
5    -    35   35   35   
4    -    -    23   23   
3    -    19   19   19   
2    16   16   16   16   
1    -    -    -    -    
0    0    0    0    0 
```
