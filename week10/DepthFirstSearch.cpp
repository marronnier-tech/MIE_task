#if 0

#endif
#include <bits/stdc++.h>
using namespace std;

int t = 0;
int n, u, v, k;
int vis[110];
int d[110];
int f[110];
vector<stack<int>> edge[110];

void dfs(int cur) {
    t++;
    d[cur] = t;

    while (edge[cur].size() > 0) {
        dfs(edge[cur].top());
        edge[cur].pop();
    }

    f[cur] = t;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            cin >> v;
            v--;
            edge[j].push(v);
        }
    }

    vector<int> d(n + 1);
    vector<int> f(n + 1);
    t = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
            dst(i);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", i, d[i], f[i]);
    }
}