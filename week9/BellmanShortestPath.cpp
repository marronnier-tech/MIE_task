#if 0
12/9 18:22 AC
所要時間：30分程度
配布資料通りの方針で、まずは各辺の起点・終点・重みをそれぞれ配列に入れ、
各頂点における重みの最大値を始点のみ0、他をInfとして大きな値をとった。
その後、それぞれの頂点について、0から順に始点からの経路が存在している点（C[t] < Inf）を
元の重みよりも小さな重み和となる場合のみ値を更新した。

#endif

#include <bits/stdc++.h>
using namespace std;
int V, E, R, S[500010], T[500010], D[500010];
int C[100010];
const int Inf = 10000 * 100000 + 100;

int main() {
    cin >> V >> E >> R;
    for (int i = 0; i < E; i++) {
        cin >> S[i] >> T[i] >> D[i];
    }
    for (int i = 0; i < V; i++) {
        if (i == R) {
            C[i] = 0;
        } else {
            C[i] = Inf;
        }
    }
    for (int t = 0; t < V; t++) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            int s = S[i], t = T[i], d = D[i];
            if (C[s] < Inf && C[t] > C[s] + d) {
                C[t] = C[s] + d;
                update = true;
            }
        }
        if (!update) break;
    }
    for (int i = 0; i < V; i++) {
        if (C[i] == Inf) {
            cout << "INF" << endl;
        } else {
            cout << C[i] << endl;
        }
    }
}