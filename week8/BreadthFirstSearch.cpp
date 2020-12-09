#if 0
12/9 14:57 AC
所要時間：3時間程度
最初は、M[][]の部分をそれぞれ分けた配列（前回のsrc、dstのように）でトライしたが、
なぜか最後のラストケースだけいくつかの終点（6や40など）で値が2ずれてしまった。
始点と終点をインデックスにするとうまくいったが、原因がよくわからない。
また、M[][]をbool型にした場合もうまく行かなかった。

Red and BlackはまだACできていません……もうちょっと頑張ります。
#endif

#include <bits/stdc++.h>
using namespace std;
int n, u, k, v;
queue<int> Q;
int D[150];
int M[150][150];

void bfs(int src) {
    Q.push(src);
    D[src] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int vi = 0; vi <= n; vi++) {
            if (M[u][vi] != 0 && D[vi] == -1) {
                D[vi] = D[u] + 1;
                Q.push(vi);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, D[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            M[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v;
            M[u][v] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        D[i] = -1;
    }
    bfs(1);
}