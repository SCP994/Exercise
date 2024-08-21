#include <cstdio>
#include <vector>

#include "pat.h"

const int maxp = 801;
const int maxc = 1451;
const int INF = 0x3F3F3F3F;

int pos[maxp];
int dis[maxp];

int g[maxp][maxp];

struct cmp {
    bool operator()(const auto &a, const auto &b) { return dis[a] > dis[b]; }
};
std::priority_queue<int, std::vector<int>, cmp> q;

int n, p, c;

void init() {
    for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= p; ++j)
            g[i][j] = INF;
}

void initDis(int s) {
    for (int i = 1; i <= p; ++i)
        dis[i] = INF;
    dis[s] = 0;
}

void relax(int u, int v) {
    if (dis[u] > dis[v] + g[v][u]) {
        dis[u] = dis[v] + g[v][u];
        q.push(u);
    }
}

void solution(int s) {
    std::vector<bool> vis(p + 1, false);
    q.push(s);
    while (!q.empty()) {
        int v = q.top();
        q.pop();
        vis[v] = true;
        for (int u = 1; u <= p; ++u)
            if (!vis[u] && g[u][v] != INF)
                relax(u, v);
    }
}

int main() {
    scanf("%d%d%d", &n, &p, &c);

    for (int i = 0; i < n; ++i)
        scanf("%d", &pos[i]);

    init();
    for (int i = 0, u, v, w; i < c; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = g[v][u] = w;
    }

    int maxSum = INF;
    for (int i = 1; i <= p; ++i) {
        initDis(i);
        solution(i);
        int tmpSum = 0;
        for (int i = 0; i < n; ++i) {
            if (dis[pos[i]] == INF) {
                tmpSum = INF;
                break;
            }
            tmpSum += dis[pos[i]];
        }
        if (tmpSum < maxSum)
            maxSum = tmpSum;
    }

    printf("%d\n", maxSum);

    return 0;
}
